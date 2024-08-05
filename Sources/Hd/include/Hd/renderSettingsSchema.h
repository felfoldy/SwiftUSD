//
// Copyright 2023 Pixar
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
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* ** This file is generated by a script.  Do not edit directly.  Edit     ** */
/* ** defs.py or the (*)Schema.template.h files to make changes.           ** */
/* ************************************************************************** */

#ifndef PXR_IMAGING_HD_RENDER_SETTINGS_SCHEMA_H
#define PXR_IMAGING_HD_RENDER_SETTINGS_SCHEMA_H

#include "Hd/api.h"

#include "Hd/schema.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

#define HDRENDERSETTINGS_SCHEMA_TOKENS \
  (renderSettings)(namespacedSettings)( \
      active)(renderProducts)(includedPurposes)(materialBindingPurposes)(renderingColorSpace)

TF_DECLARE_PUBLIC_TOKENS(HdRenderSettingsSchemaTokens, HD_API, HDRENDERSETTINGS_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdRenderSettingsSchema : public HdSchema {
 public:
  HdRenderSettingsSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  // ACCESSORS

  HD_API
  HdContainerDataSourceHandle GetNamespacedSettings();
  HD_API
  HdBoolDataSourceHandle GetActive();
  HD_API
  HdRenderProductVectorSchema GetRenderProducts();
  HD_API
  HdTokenArrayDataSourceHandle GetIncludedPurposes();
  HD_API
  HdTokenArrayDataSourceHandle GetMaterialBindingPurposes();
  HD_API
  HdTokenDataSourceHandle GetRenderingColorSpace();

  // RETRIEVING AND CONSTRUCTING

  /// Builds a container data source which includes the provided child data
  /// sources. Parameters with nullptr values are excluded. This is a
  /// low-level interface. For cases in which it's desired to define
  /// the container with a sparse set of child fields, the Builder class
  /// is often more convenient and readable.
  HD_API
  static HdContainerDataSourceHandle BuildRetained(
      const HdContainerDataSourceHandle &namespacedSettings,
      const HdBoolDataSourceHandle &active,
      const HdVectorDataSourceHandle &renderProducts,
      const HdTokenArrayDataSourceHandle &includedPurposes,
      const HdTokenArrayDataSourceHandle &materialBindingPurposes,
      const HdTokenDataSourceHandle &renderingColorSpace);

  /// \class HdRenderSettingsSchema::Builder
  ///
  /// Utility class for setting sparse sets of child data source fields to be
  /// filled as arguments into BuildRetained. Because all setter methods
  /// return a reference to the instance, this can be used in the "builder
  /// pattern" form.
  class Builder {
   public:
    HD_API
    Builder &SetNamespacedSettings(const HdContainerDataSourceHandle &namespacedSettings);
    HD_API
    Builder &SetActive(const HdBoolDataSourceHandle &active);
    HD_API
    Builder &SetRenderProducts(const HdVectorDataSourceHandle &renderProducts);
    HD_API
    Builder &SetIncludedPurposes(const HdTokenArrayDataSourceHandle &includedPurposes);
    HD_API
    Builder &SetMaterialBindingPurposes(
        const HdTokenArrayDataSourceHandle &materialBindingPurposes);
    HD_API
    Builder &SetRenderingColorSpace(const HdTokenDataSourceHandle &renderingColorSpace);

    /// Returns a container data source containing the members set thus far.
    HD_API
    HdContainerDataSourceHandle Build();

   private:
    HdContainerDataSourceHandle _namespacedSettings;
    HdBoolDataSourceHandle _active;
    HdVectorDataSourceHandle _renderProducts;
    HdTokenArrayDataSourceHandle _includedPurposes;
    HdTokenArrayDataSourceHandle _materialBindingPurposes;
    HdTokenDataSourceHandle _renderingColorSpace;
  };

  /// Retrieves a container data source with the schema's default name token
  /// "renderSettings" from the parent container and constructs a
  /// HdRenderSettingsSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdRenderSettingsSchema GetFromParent(
      const HdContainerDataSourceHandle &fromParentContainer);

  /// Returns a token where the container representing this schema is found in
  /// a container by default.
  HD_API
  static const TfToken &GetSchemaToken();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the container representing this schema is found by default.
  HD_API
  static const HdDataSourceLocator &GetDefaultLocator();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the namespacedsettings data source can be found.
  /// This is often useful for checking intersection against the
  /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
  HD_API
  static const HdDataSourceLocator &GetNamespacedSettingsLocator();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the active data source can be found.
  /// This is often useful for checking intersection against the
  /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
  HD_API
  static const HdDataSourceLocator &GetActiveLocator();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the renderproducts data source can be found.
  /// This is often useful for checking intersection against the
  /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
  HD_API
  static const HdDataSourceLocator &GetRenderProductsLocator();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the includedpurposes data source can be found.
  /// This is often useful for checking intersection against the
  /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
  HD_API
  static const HdDataSourceLocator &GetIncludedPurposesLocator();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the materialbindingpurposes data source can be found.
  /// This is often useful for checking intersection against the
  /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
  HD_API
  static const HdDataSourceLocator &GetMaterialBindingPurposesLocator();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the renderingcolorspace data source can be found.
  /// This is often useful for checking intersection against the
  /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
  HD_API
  static const HdDataSourceLocator &GetRenderingColorSpaceLocator();
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
