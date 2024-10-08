//
// Copyright 2023 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdSchemaDefs.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "UsdImaging/directMaterialBindingSchema.h"

#include "Hd/retainedDataSource.h"

#include "Trace/traceImpl.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(UsdImagingDirectMaterialBindingSchemaTokens,
                        USD_IMAGING_DIRECT_MATERIAL_BINDING_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdPathDataSourceHandle UsdImagingDirectMaterialBindingSchema::GetMaterialPath() const
{
  return _GetTypedDataSource<HdPathDataSource>(
      UsdImagingDirectMaterialBindingSchemaTokens->materialPath);
}

HdTokenDataSourceHandle UsdImagingDirectMaterialBindingSchema::GetBindingStrength() const
{
  return _GetTypedDataSource<HdTokenDataSource>(
      UsdImagingDirectMaterialBindingSchemaTokens->bindingStrength);
}

/*static*/
HdContainerDataSourceHandle UsdImagingDirectMaterialBindingSchema::BuildRetained(
    const HdPathDataSourceHandle &materialPath, const HdTokenDataSourceHandle &bindingStrength)
{
  TfToken _names[2];
  HdDataSourceBaseHandle _values[2];

  size_t _count = 0;

  if (materialPath) {
    _names[_count] = UsdImagingDirectMaterialBindingSchemaTokens->materialPath;
    _values[_count++] = materialPath;
  }

  if (bindingStrength) {
    _names[_count] = UsdImagingDirectMaterialBindingSchemaTokens->bindingStrength;
    _values[_count++] = bindingStrength;
  }
  return HdRetainedContainerDataSource::New(_count, _names, _values);
}

UsdImagingDirectMaterialBindingSchema::Builder &UsdImagingDirectMaterialBindingSchema::Builder::
    SetMaterialPath(const HdPathDataSourceHandle &materialPath)
{
  _materialPath = materialPath;
  return *this;
}

UsdImagingDirectMaterialBindingSchema::Builder &UsdImagingDirectMaterialBindingSchema::Builder::
    SetBindingStrength(const HdTokenDataSourceHandle &bindingStrength)
{
  _bindingStrength = bindingStrength;
  return *this;
}

HdContainerDataSourceHandle UsdImagingDirectMaterialBindingSchema::Builder::Build()
{
  return UsdImagingDirectMaterialBindingSchema::BuildRetained(_materialPath, _bindingStrength);
}

/*static*/
UsdImagingDirectMaterialBindingSchema UsdImagingDirectMaterialBindingSchema::GetFromParent(
    const HdContainerDataSourceHandle &fromParentContainer)
{
  return UsdImagingDirectMaterialBindingSchema(
      fromParentContainer ?
          HdContainerDataSource::Cast(fromParentContainer->Get(
              UsdImagingDirectMaterialBindingSchemaTokens->directMaterialBinding)) :
          nullptr);
}

/*static*/
const TfToken &UsdImagingDirectMaterialBindingSchema::GetSchemaToken()
{
  return UsdImagingDirectMaterialBindingSchemaTokens->directMaterialBinding;
}

/*static*/
const HdDataSourceLocator &UsdImagingDirectMaterialBindingSchema::GetDefaultLocator()
{
  static const HdDataSourceLocator locator(GetSchemaToken());
  return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
