//
// Copyright 2022 Pixar
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
#ifndef EXT_RMANPKG_24_0_PLUGIN_RENDERMAN_PLUGIN_HD_PRMAN_SAMPLE_FILTER_H
#define EXT_RMANPKG_24_0_PLUGIN_RENDERMAN_PLUGIN_HD_PRMAN_SAMPLE_FILTER_H

#include <pxr/pxrns.h>
#include "Hd/sprim.h"
#include "Hd/material.h"

#include "Riley.h"

PXR_NAMESPACE_OPEN_SCOPE

class HdPrman_RenderParam;

class HdPrman_SampleFilter : public HdSprim
{
public:
  HdPrman_SampleFilter(SdfPath const &id);

  void Sync(HdSceneDelegate *sceneDelegate,
            HdRenderParam *renderParam,
            HdDirtyBits *dirtyBits) override;

  void Finalize(HdRenderParam *renderParam) override;

  HdDirtyBits GetInitialDirtyBitsMask() const override;

private:
  void _CreateRmanSampleFilter(HdSceneDelegate *sceneDelegate,
                               HdPrman_RenderParam *renderParam,
                               SdfPath const &filterPrimPath,
                               HdMaterialNode2 const &sampleFilterNode);
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // EXT_RMANPKG_24_0_PLUGIN_RENDERMAN_PLUGIN_HD_PRMAN_SAMPLE_FILTER_H
