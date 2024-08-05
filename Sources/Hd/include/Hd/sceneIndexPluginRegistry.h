//
// Copyright 2021 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef PXR_IMAGING_HD_SCENE_INDEX_PLUGIN_REGISTRY_H
#define PXR_IMAGING_HD_SCENE_INDEX_PLUGIN_REGISTRY_H

#include "Hd/api.h"
#include "Hd/sceneIndex.h"
#include "Hf/pluginRegistry.h"
#include "Tf/singleton.h"
#include "Tf/staticTokens.h"
#include <pxr/pxrns.h>

PXR_NAMESPACE_OPEN_SCOPE

#define HDSCENEINDEXPLUGINREGISTRY_TOKENS ((rendererDisplayName, "__rendererDisplayName"))

TF_DECLARE_PUBLIC_TOKENS(HdSceneIndexPluginRegistryTokens,
                         HD_API,
                         HDSCENEINDEXPLUGINREGISTRY_TOKENS);

class HdSceneIndexPlugin;

class HdSceneIndexPluginRegistry final : public HfPluginRegistry {
 public:
  ///
  /// Returns the singleton registry for \c HdSceneIndexPlugin
  ///
  HD_API
  static HdSceneIndexPluginRegistry &GetInstance();

  ///
  /// Entry point for defining an HdSceneIndexPlugin plugin.
  ///
  template<typename T, typename... Bases> static void Define();

  ///
  /// Given a specific scene index plug-in id, give the plug-in a chance
  /// to add scene indices to the end of the chain. Return value is the
  /// last scene index -- or inputScene if the plug-in chooses not to act.
  /// Input arguments may be nullptr if not relevant to this plug-in.
  HD_API
  HdSceneIndexBaseRefPtr AppendSceneIndex(const TfToken &sceneIndexPluginId,
                                          const HdSceneIndexBaseRefPtr &inputScene,
                                          const HdContainerDataSourceHandle &inputArgs);

  ///
  /// Append scene indices generated by plug-ins registered (via
  /// RegisterSceneIndexForRenderer) for this renderer. Return value is the
  /// last scene index -- or inputScene if no plugins are registered or
  /// taking action. This also includes plug-ins registered for all
  /// renderers (via an empty rendererDisplayName) to be added in advance
  /// of any registered for the specified rendeer.
  HD_API
  HdSceneIndexBaseRefPtr AppendSceneIndicesForRenderer(
      const std::string &rendererDisplayName,
      const HdSceneIndexBaseRefPtr &inputScene,
      const std::string &renderInstanceId = std::string());

  enum InsertionOrder {
    InsertionOrderAtStart,
    InsertionOrderAtEnd,
  };

  using InsertionPhase = int;

  ///
  /// Register a scene index to be instantiated for a specified
  /// renderer (or all renderers if rendererDisplayName is empty).
  ///
  /// Insertion phase is a broad ordering value with lower values indicating
  /// earlier instantiation (possibly given render plugin-specific meaning
  /// via enum values). Insertion order indicates whether this entry
  /// should go at the start or end of the specified phase.
  HD_API
  void RegisterSceneIndexForRenderer(const std::string &rendererDisplayName,
                                     const TfToken &sceneIndexPluginId,
                                     const HdContainerDataSourceHandle &inputArgs,
                                     InsertionPhase insertionPhase,
                                     InsertionOrder insertionOrder);

  using SceneIndexAppendCallback =
      std::function<HdSceneIndexBaseRefPtr(const std::string &renderInstanceId,
                                           const HdSceneIndexBaseRefPtr &inputScene,
                                           const HdContainerDataSourceHandle &inputArgs)>;

  ///
  /// Register a scene index to be instantiated via a callback for a
  /// specified renderer (or all renderers if rendererDisplayName is empty).
  ///
  /// This is most useful for application-specific behavior which wants to
  /// append and manage scene index instances associated with a specific
  /// render. To aid in that association, the callback is provided a
  /// renderInstanceId value typically defined by the application itself.
  ///
  /// Insertion phase is a broad ordering value with lower values indicating
  /// earlier instantiation (possibly given render plugin-specific meaning
  /// via enum values). Insertion order indicates whether this entry
  /// should go at the start or end of the specified phase.
  ///
  /// \note This method should be invoked *before* render index construction
  ///       when Hydra scene index emulation is enabled.
  ///
  HD_API
  void RegisterSceneIndexForRenderer(const std::string &rendererDisplayName,
                                     SceneIndexAppendCallback callback,
                                     const HdContainerDataSourceHandle &inputArgs,
                                     InsertionPhase insertionPhase,
                                     InsertionOrder insertionOrder);

 protected:
  void _CollectAdditionalMetadata(const PlugRegistry &plugRegistry,
                                  const TfType &pluginType) override;

 private:
  friend class TfSingleton<HdSceneIndexPluginRegistry>;

  // Singleton gets private constructed
  HdSceneIndexPluginRegistry();
  ~HdSceneIndexPluginRegistry() override;

  HdSceneIndexPlugin *_GetSceneIndexPlugin(const TfToken &pluginId);

  struct _Entry {
    _Entry(const TfToken &sceneIndexPluginId, const HdContainerDataSourceHandle &args)
        : sceneIndexPluginId(sceneIndexPluginId), args(args)
    {
    }

    _Entry(SceneIndexAppendCallback callback, const HdContainerDataSourceHandle &args)
        : args(args), callback(callback)
    {
    }

    TfToken sceneIndexPluginId;
    HdContainerDataSourceHandle args;
    SceneIndexAppendCallback callback;
  };

  using _EntryList = std::vector<_Entry>;
  using _PhasesMap = std::map<InsertionPhase, _EntryList>;
  using _RenderersMap = std::map<std::string, _PhasesMap>;

  HdSceneIndexBaseRefPtr _AppendForPhases(const HdSceneIndexBaseRefPtr &inputScene,
                                          const _PhasesMap &phasesMap,
                                          const HdContainerDataSourceHandle &argsUnderlay,
                                          const std::string &renderInstanceId);

  _RenderersMap _sceneIndicesForRenderers;

  // Used to track plugins whose plugInfo entries contain "loadWithRenderer"
  // values to load when the specified renderer or renderers are used.
  // Loading the plug-in allows for further registration code to run when
  // a plug-in wouldn't be loaded elsewhere.
  using _PreloadMap = std::map<std::string, TfTokenVector>;
  _PreloadMap _preloadsForRenderer;
};

template<typename T, typename... Bases> void HdSceneIndexPluginRegistry::Define()
{
  HfPluginRegistry::Define<T, HdSceneIndexPlugin, Bases...>();
}

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_IMAGING_HD_SCENE_INDEX_PLUGIN_REGISTRY_H
