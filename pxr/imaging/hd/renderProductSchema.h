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

#ifndef PXR_IMAGING_HD_RENDER_PRODUCT_SCHEMA_H
#define PXR_IMAGING_HD_RENDER_PRODUCT_SCHEMA_H

#include "pxr/imaging/hd/api.h"

#include "pxr/imaging/hd/schema.h" 

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

#define HDRENDERPRODUCT_SCHEMA_TOKENS \
    (renderProduct) \
    (path) \
    (type) \
    (name) \
    (resolution) \
    (renderVars) \
    (cameraPrim) \
    (pixelAspectRatio) \
    (aspectRatioConformPolicy) \
    (apertureSize) \
    (dataWindowNDC) \
    (disableMotionBlur) \
    (namespacedSettings) \

TF_DECLARE_PUBLIC_TOKENS(HdRenderProductSchemaTokens, HD_API,
    HDRENDERPRODUCT_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdRenderProductSchema : public HdSchema
{
public:
    HdRenderProductSchema(HdContainerDataSourceHandle container)
    : HdSchema(container) {}

    //ACCESSORS

    HD_API
    HdPathDataSourceHandle GetPath();
    HD_API
    HdTokenDataSourceHandle GetType();
    HD_API
    HdTokenDataSourceHandle GetName();
    HD_API
    HdVec2iDataSourceHandle GetResolution();
    HD_API
    HdRenderVarVectorSchema GetRenderVars();
    HD_API
    HdPathDataSourceHandle GetCameraPrim();
    HD_API
    HdFloatDataSourceHandle GetPixelAspectRatio();
    HD_API
    HdTokenDataSourceHandle GetAspectRatioConformPolicy();
    HD_API
    HdVec2fDataSourceHandle GetApertureSize();
    HD_API
    HdVec4fDataSourceHandle GetDataWindowNDC();
    HD_API
    HdBoolDataSourceHandle GetDisableMotionBlur();
    HD_API
    HdContainerDataSourceHandle GetNamespacedSettings();

    // RETRIEVING AND CONSTRUCTING

    /// Builds a container data source which includes the provided child data
    /// sources. Parameters with nullptr values are excluded. This is a
    /// low-level interface. For cases in which it's desired to define
    /// the container with a sparse set of child fields, the Builder class
    /// is often more convenient and readable.
    HD_API
    static HdContainerDataSourceHandle
    BuildRetained(
        const HdPathDataSourceHandle &path,
        const HdTokenDataSourceHandle &type,
        const HdTokenDataSourceHandle &name,
        const HdVec2iDataSourceHandle &resolution,
        const HdVectorDataSourceHandle &renderVars,
        const HdPathDataSourceHandle &cameraPrim,
        const HdFloatDataSourceHandle &pixelAspectRatio,
        const HdTokenDataSourceHandle &aspectRatioConformPolicy,
        const HdVec2fDataSourceHandle &apertureSize,
        const HdVec4fDataSourceHandle &dataWindowNDC,
        const HdBoolDataSourceHandle &disableMotionBlur,
        const HdContainerDataSourceHandle &namespacedSettings
    );

    /// \class HdRenderProductSchema::Builder
    /// 
    /// Utility class for setting sparse sets of child data source fields to be
    /// filled as arguments into BuildRetained. Because all setter methods
    /// return a reference to the instance, this can be used in the "builder
    /// pattern" form.
    class Builder
    {
    public:
        HD_API
        Builder &SetPath(
            const HdPathDataSourceHandle &path);
        HD_API
        Builder &SetType(
            const HdTokenDataSourceHandle &type);
        HD_API
        Builder &SetName(
            const HdTokenDataSourceHandle &name);
        HD_API
        Builder &SetResolution(
            const HdVec2iDataSourceHandle &resolution);
        HD_API
        Builder &SetRenderVars(
            const HdVectorDataSourceHandle &renderVars);
        HD_API
        Builder &SetCameraPrim(
            const HdPathDataSourceHandle &cameraPrim);
        HD_API
        Builder &SetPixelAspectRatio(
            const HdFloatDataSourceHandle &pixelAspectRatio);
        HD_API
        Builder &SetAspectRatioConformPolicy(
            const HdTokenDataSourceHandle &aspectRatioConformPolicy);
        HD_API
        Builder &SetApertureSize(
            const HdVec2fDataSourceHandle &apertureSize);
        HD_API
        Builder &SetDataWindowNDC(
            const HdVec4fDataSourceHandle &dataWindowNDC);
        HD_API
        Builder &SetDisableMotionBlur(
            const HdBoolDataSourceHandle &disableMotionBlur);
        HD_API
        Builder &SetNamespacedSettings(
            const HdContainerDataSourceHandle &namespacedSettings);

        /// Returns a container data source containing the members set thus far.
        HD_API
        HdContainerDataSourceHandle Build();

    private:
        HdPathDataSourceHandle _path;
        HdTokenDataSourceHandle _type;
        HdTokenDataSourceHandle _name;
        HdVec2iDataSourceHandle _resolution;
        HdVectorDataSourceHandle _renderVars;
        HdPathDataSourceHandle _cameraPrim;
        HdFloatDataSourceHandle _pixelAspectRatio;
        HdTokenDataSourceHandle _aspectRatioConformPolicy;
        HdVec2fDataSourceHandle _apertureSize;
        HdVec4fDataSourceHandle _dataWindowNDC;
        HdBoolDataSourceHandle _disableMotionBlur;
        HdContainerDataSourceHandle _namespacedSettings;
    };

    /// Retrieves a container data source with the schema's default name token
    /// "renderProduct" from the parent container and constructs a
    /// HdRenderProductSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    HD_API
    static HdRenderProductSchema GetFromParent(
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
    /// where the resolution data source can be found.
    /// This is often useful for checking intersection against the
    /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
    HD_API
    static const HdDataSourceLocator &GetResolutionLocator();

    /// Returns an HdDataSourceLocator (relative to the prim-level data source)
    /// where the rendervars data source can be found.
    /// This is often useful for checking intersection against the
    /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
    HD_API
    static const HdDataSourceLocator &GetRenderVarsLocator();

    /// Returns an HdDataSourceLocator (relative to the prim-level data source)
    /// where the namespacedsettings data source can be found.
    /// This is often useful for checking intersection against the
    /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
    HD_API
    static const HdDataSourceLocator &GetNamespacedSettingsLocator();

};

PXR_NAMESPACE_CLOSE_SCOPE

#endif