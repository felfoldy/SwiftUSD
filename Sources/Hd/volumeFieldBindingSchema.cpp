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

#include "Hd/volumeFieldBindingSchema.h"
#include "Hd/retainedDataSource.h"

#include "Trace/traceImpl.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdVolumeFieldBindingSchemaTokens, HDVOLUMEFIELDBINDING_SCHEMA_TOKENS);

TfTokenVector HdVolumeFieldBindingSchema::GetVolumeFieldBindingNames()
{
  HdContainerDataSourceHandle container = GetContainer();
  if (!container) {
    return {};
  }
  return container->GetNames();
}

HdPathDataSourceHandle HdVolumeFieldBindingSchema::GetVolumeFieldBinding(TfToken const &name)
{
  return _GetTypedDataSource<HdPathDataSource>(name);
}

/*static*/
HdContainerDataSourceHandle HdVolumeFieldBindingSchema::BuildRetained(
    size_t count, TfToken *names, HdDataSourceBaseHandle *values)
{
  return HdRetainedContainerDataSource::New(count, names, values);
}

/*static*/
HdVolumeFieldBindingSchema HdVolumeFieldBindingSchema::GetFromParent(
    const HdContainerDataSourceHandle &fromParentContainer)
{
  return HdVolumeFieldBindingSchema(
      fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                HdVolumeFieldBindingSchemaTokens->volumeFieldBinding)) :
                            nullptr);
}

/*static*/
const TfToken &HdVolumeFieldBindingSchema::GetSchemaToken()
{
  return HdVolumeFieldBindingSchemaTokens->volumeFieldBinding;
}
/*static*/
const HdDataSourceLocator &HdVolumeFieldBindingSchema::GetDefaultLocator()
{
  static const HdDataSourceLocator locator(HdVolumeFieldBindingSchemaTokens->volumeFieldBinding);
  return locator;
}
PXR_NAMESPACE_CLOSE_SCOPE
