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
/* ** defs.py or the (*)Schema.template.cpp files to make changes.         ** */
/* ************************************************************************** */

#include "Hd/visibilitySchema.h"
#include "Hd/retainedDataSource.h"

#include "Trace/traceImpl.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdVisibilitySchemaTokens, HDVISIBILITY_SCHEMA_TOKENS);

HdBoolDataSourceHandle HdVisibilitySchema::GetVisibility()
{
  return _GetTypedDataSource<HdBoolDataSource>(HdVisibilitySchemaTokens->visibility);
}

/*static*/
HdContainerDataSourceHandle HdVisibilitySchema::BuildRetained(
    const HdBoolDataSourceHandle &visibility)
{
  TfToken names[1];
  HdDataSourceBaseHandle values[1];

  size_t count = 0;
  if (visibility) {
    names[count] = HdVisibilitySchemaTokens->visibility;
    values[count++] = visibility;
  }

  return HdRetainedContainerDataSource::New(count, names, values);
}

/*static*/
HdVisibilitySchema HdVisibilitySchema::GetFromParent(
    const HdContainerDataSourceHandle &fromParentContainer)
{
  return HdVisibilitySchema(fromParentContainer ?
                                HdContainerDataSource::Cast(fromParentContainer->Get(
                                    HdVisibilitySchemaTokens->visibility)) :
                                nullptr);
}

/*static*/
const TfToken &HdVisibilitySchema::GetSchemaToken()
{
  return HdVisibilitySchemaTokens->visibility;
}
/*static*/
const HdDataSourceLocator &HdVisibilitySchema::GetDefaultLocator()
{
  static const HdDataSourceLocator locator(HdVisibilitySchemaTokens->visibility);
  return locator;
}
HdVisibilitySchema::Builder &HdVisibilitySchema::Builder::SetVisibility(
    const HdBoolDataSourceHandle &visibility)
{
  _visibility = visibility;
  return *this;
}

HdContainerDataSourceHandle HdVisibilitySchema::Builder::Build()
{
  return HdVisibilitySchema::BuildRetained(_visibility);
}

PXR_NAMESPACE_CLOSE_SCOPE
