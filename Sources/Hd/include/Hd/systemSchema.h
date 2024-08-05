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

#ifndef PXR_IMAGING_HD_SYSTEM_SCHEMA_H
#define PXR_IMAGING_HD_SYSTEM_SCHEMA_H

#include "Hd/api.h"
#include "Hd/schema.h"

#include "Tf/declarePtrs.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

#define HDSYSTEM_SCHEMA_TOKENS (system)

TF_DECLARE_PUBLIC_TOKENS(HdSystemSchemaTokens, HD_API, HDSYSTEM_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

TF_DECLARE_REF_PTRS(HdSceneIndexBase);

/// The HdSystemSchema specifies a container that will hold "system"
/// data.  Each piece of system data is identified by a key within the
/// container.  A piece of system data is evaluated at a given location by
/// walking up the namespace looking for a system container that contains the
/// corresponding key.
class HdSystemSchema : public HdSchema {
 public:
  HdSystemSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  /// Evaluates the \p key at \p fromPath.  If \p key is found, the return
  /// value will be non-null and \p foundAtPath will contain the path at
  /// which the non-null result was found.  Otherwise, this returns null.
  ///
  /// This operation will be linear in the length of \p fromPath.
  HD_API
  static HdDataSourceBaseHandle GetFromPath(HdSceneIndexBaseRefPtr const &inputScene,
                                            SdfPath const &fromPath,
                                            TfToken const &key,
                                            SdfPath *foundAtPath);

  /// Composes the system container in at \p fromPath by walking up the
  /// prim.dataSources in \p inputScene and composing any system containers
  /// it encounters.
  ///
  /// If no system containers were found, this returns null.
  /// Otherwise, this will return a container data source with the composed
  /// system data sources. If non-null, \p foundAtPath will be the last prim
  /// at which system data was found.
  HD_API
  static HdContainerDataSourceHandle Compose(HdSceneIndexBaseRefPtr const &inputScene,
                                             SdfPath const &fromPath,
                                             SdfPath *foundAtPath);

  /// Similar to `Compose` but this return value would be suitable for using
  /// with HdOverlayContainerDataSource for a prim's dataSource:
  /// ```
  /// prim.dataSource = HdOverlayContainerDataSource::New(
  ///   HdSystemSchema::ComposeAsPrimDataSource(...),
  ///   prim.dataSource);
  /// ```
  HD_API
  static HdContainerDataSourceHandle ComposeAsPrimDataSource(
      HdSceneIndexBaseRefPtr const &inputScene, SdfPath const &fromPath, SdfPath *foundAtPath);

  /// Retrieves a container data source with the schema's default name token
  /// "system" from the parent container and constructs a
  /// HdSystemSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdSystemSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

  /// Returns a token where the container representing this schema is found in
  /// a container by default.
  HD_API
  static const TfToken &GetSchemaToken();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the container representing this schema is found by default.
  HD_API
  static const HdDataSourceLocator &GetDefaultLocator();
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
