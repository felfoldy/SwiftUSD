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

#ifndef PXR_IMAGING_HD_COORD_SYS_BINDING_SCHEMA_H
#define PXR_IMAGING_HD_COORD_SYS_BINDING_SCHEMA_H

#include "Hd/api.h"

#include "Hd/schema.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

#define HDCOORDSYSBINDING_SCHEMA_TOKENS (coordSysBinding)

TF_DECLARE_PUBLIC_TOKENS(HdCoordSysBindingSchemaTokens, HD_API, HDCOORDSYSBINDING_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdCoordSysBindingSchema : public HdSchema {
 public:
  HdCoordSysBindingSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  HD_API
  static HdContainerDataSourceHandle BuildRetained(size_t count,
                                                   const TfToken *names,
                                                   const HdDataSourceBaseHandle *values);

  HD_API
  HdPathDataSourceHandle GetCoordSysBinding(TfToken const &name);

  /// Retrieves a container data source with the schema's default name token
  /// "coordSysBinding" from the parent container and constructs a
  /// HdCoordSysBindingSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdCoordSysBindingSchema GetFromParent(
      const HdContainerDataSourceHandle &fromParentContainer);

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
