//
// Copyright 2019 Pixar
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

#ifndef EXT_RMANPKG_24_0_PLUGIN_RENDERMAN_PLUGIN_RMAN_OSL_PARSER_RMAN_OSL_PARSER_H
#define EXT_RMANPKG_24_0_PLUGIN_RENDERMAN_PLUGIN_RMAN_OSL_PARSER_RMAN_OSL_PARSER_H

/// \file rmanOslParser/rmanOslParser.h

#include "Ndr/parserPlugin.h"
#include "RixShaderInfo.h"
#include "Sdr/declare.h"
#include "Vt/value.h"
#include <pxr/pxrns.h>

PXR_NAMESPACE_OPEN_SCOPE

// Forward declarations
class NdrNode;
struct NdrNodeDiscoveryResult;

/// \class RmanOslParserPlugin
///
/// Parses OSL nodes. For more information on parser plugins, see the
/// documentation for `NdrParserPlugin`.
///
/// \section metadata_schema Metadata Schema
/// The following metadata is pulled out of the shader and available on the
/// destination as outlined below.
///
/// \subsection node_metadata Node Metadata
///
/// OSL Metadata Key      | Destination
/// --------------------- | ------------
/// category              | GetCategory()
/// departments           | GetDepartments()
/// help                  | GetHelp()
/// label                 | GetLabel()
/// \ref pvars "primvars" | GetPrimvars(), GetAdditionalPrimvarProperties()
/// _everything else_     | GetMetadata()
///
///
/// \subsection property_metadata Property Metadata
///
/// OSL Metadata Key    | Destination
/// ------------------- | ------------
/// connectable         | IsConnectable()
/// sdrDefinitionName   | renames parameter, sends original osl param name to
///                     | SdrShaderProperty::GetImplementationName()
/// page                | GetPage()
/// help                | GetHelp()
/// label               | GetLabel()
/// isDynamicArray      | IsDynamicArray()
/// \ref opts "options" | GetOptions()
/// vstructMemberName   | GetVStructMemberName()
/// vstructMemberOf     | GetVStructMemberOf()
/// _everything else_   | GetMetadata()
///
///
/// \subsection opts Options Format
/// Multiple options are separated with the pipe '|' character; options can be
/// specified in one of two ways:
/// <ul>
///     <li>
///         key1|key2|key3|...
///     </li>
///     <li>
///         key1:value1|key2:value2|...
///     </li>
/// </ul>
///
/// In the first case, where the values are not specified, the value of the
/// option will be available on the node as an empty string.
///
///
/// \subsection pvars Primvar Format
/// Multiple primvars are separated with the pipe '|' character; primvars can be
/// specified in one of two ways:
/// <ul>
///     <li>
///         A string _not_ prefixed with a '$'; this indicates a normal primvar
///     </li>
///     <li>
///         A string prefixed with '$'; the part after the '$' indicates the
///         name of a string-typed input on the node whose value contains
///         additional primvars
///     </li>
/// </ul>
///
class RmanOslParserPlugin : public NdrParserPlugin {
 public:
  RmanOslParserPlugin();
  ~RmanOslParserPlugin();

  NdrNodeUniquePtr Parse(const NdrNodeDiscoveryResult &discoveryResult) override;

  const NdrTokenVec &GetDiscoveryTypes() const override;

  const TfToken &GetSourceType() const override;

 private:
  // Gets a vector of properties that are present on the specified OSL
  // query object
  NdrPropertyUniquePtrVec _getNodeProperties(const RixShaderQuery *sq,
                                             const NdrNodeDiscoveryResult &discoveryResult) const;

  // Gets all metadata for the node that's present on the specified OSL
  // query object
  NdrTokenMap _getNodeMetadata(const RixShaderQuery *sq, const NdrTokenMap &baseMetadata) const;

  // Gets all metadata for the specified OSL parameter
  NdrTokenMap _getPropertyMetadata(const RixShaderParameter *param,
                                   const NdrNodeDiscoveryResult &discoveryResult) const;

  // Injects any metadata that is generated by the parser. This type of
  // metadata provides additional hints to the property.
  void _injectParserMetadata(NdrTokenMap &metadata, const TfToken &typeName) const;

  // Gets a common type + array size (if array) from the OSL parameter
  std::tuple<TfToken, size_t> _getTypeName(const RixShaderParameter *param,
                                           const NdrTokenMap &metadata) const;

  // Gets the default value of the specified param.
  VtValue _getDefaultValue(const RixShaderParameter *param,
                           const std::string &oslType,
                           size_t arraySize,
                           const NdrTokenMap &metadata) const;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // EXT_RMANPKG_24_0_PLUGIN_RENDERMAN_PLUGIN_RMAN_OSL_PARSER_RMAN_OSL_PARSER_H
