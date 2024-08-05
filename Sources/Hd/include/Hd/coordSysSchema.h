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

#ifndef PXR_IMAGING_HD_COORD_SYS_SCHEMA_H
#define PXR_IMAGING_HD_COORD_SYS_SCHEMA_H

#include "Hd/api.h"

#include "Hd/schema.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

#define HDCOORDSYS_SCHEMA_TOKENS (coordSys)(name)

TF_DECLARE_PUBLIC_TOKENS(HdCoordSysSchemaTokens, HD_API, HDCOORDSYS_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdCoordSysSchema : public HdSchema {
 public:
  HdCoordSysSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  // ACCESSORS

  HD_API
  HdTokenDataSourceHandle GetName();

  // RETRIEVING AND CONSTRUCTING

  /// Builds a container data source which includes the provided child data
  /// sources. Parameters with nullptr values are excluded. This is a
  /// low-level interface. For cases in which it's desired to define
  /// the container with a sparse set of child fields, the Builder class
  /// is often more convenient and readable.
  HD_API
  static HdContainerDataSourceHandle BuildRetained(const HdTokenDataSourceHandle &name);

  /// \class HdCoordSysSchema::Builder
  ///
  /// Utility class for setting sparse sets of child data source fields to be
  /// filled as arguments into BuildRetained. Because all setter methods
  /// return a reference to the instance, this can be used in the "builder
  /// pattern" form.
  class Builder {
   public:
    HD_API
    Builder &SetName(const HdTokenDataSourceHandle &name);

    /// Returns a container data source containing the members set thus far.
    HD_API
    HdContainerDataSourceHandle Build();

   private:
    HdTokenDataSourceHandle _name;
  };

  /// Retrieves a container data source with the schema's default name token
  /// "coordSys" from the parent container and constructs a
  /// HdCoordSysSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdCoordSysSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

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
