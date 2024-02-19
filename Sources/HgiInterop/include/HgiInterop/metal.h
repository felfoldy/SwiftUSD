//
// Copyright 2020 Pixar
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
#ifndef PXR_IMAGING_HGIINTEROP_HGIINTEROPMETAL_H
#define PXR_IMAGING_HGIINTEROP_HGIINTEROPMETAL_H

#if PXR_METAL_SUPPORT_ENABLED

#include "Garch/glApi.h"

#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <OpenGL/OpenGL.hpp>

#include <pxr/pxrns.h>
#include "Gf/vec4i.h"
#include "Hgi/texture.h"
#include "HgiInterop/api.h"

PXR_NAMESPACE_OPEN_SCOPE

class Hgi;
class HgiMetal;
class VtValue;

/// \class HgiInteropMetal
///
/// Provides Metal/GL interop
///
class HgiInteropMetal final
{
public:
  HGIINTEROP_API
  HgiInteropMetal(Hgi *hgi);

  HGIINTEROP_API
  ~HgiInteropMetal();

  /// Copy/Present provided color (and optional depth) textures to app.
  HGIINTEROP_API
  void CompositeToInterop(
      HgiTextureHandle const &color,
      HgiTextureHandle const &depth,
      VtValue const &framebuffer,
      GfVec4i const &compRegion);

private:
  HgiInteropMetal() = delete;

  enum
  {
    ShaderContextColor,
    ShaderContextColorDepth,

    ShaderContextCount
  };

  struct ShaderContext
  {
    uint32_t program;
    uint32_t vao;
    uint32_t vbo;
    int32_t posAttrib;
    int32_t texAttrib;
    int32_t samplerColorLoc;
    int32_t samplerDepthLoc;
    uint32_t blitTexSizeUniform;
  };

  struct VertexAttribState
  {
    int32_t enabled;
    int32_t size;
    int32_t type;
    int32_t normalized;
    int32_t stride;
    int32_t bufferBinding;
    void *pointer;
  };

  void _BlitToOpenGL(VtValue const &framebuffer, GfVec4i const &compRegion,
                     int shaderIndex);
  void _FreeTransientTextureCacheRefs();
  void _CaptureOpenGlState();
  void _RestoreOpenGlState();
  void _CreateShaderContext(
      int32_t vertexSource,
      int32_t fragmentSource,
      ShaderContext &shader);
  void _SetAttachmentSize(int width, int height);
  void _ValidateGLContext();

  HgiMetal *_hgiMetal;

  MTL::Device *_device;

  MTL::Texture *_mtlAliasedColorTexture;
  MTL::Texture *_mtlAliasedDepthRegularFloatTexture;

  MTL::Library *_defaultLibrary;
  MTL::Function *_computeDepthCopyProgram;
  MTL::Function *_computeColorCopyProgram;
  MTL::ComputePipelineState *_computePipelineStateColor;
  MTL::ComputePipelineState *_computePipelineStateDepth;

#if 0
  // XXX: Add these into the CXX Apple headers.
    CVPixelBufferRef _pixelBuffer;
    CVPixelBufferRef _depthBuffer;
    CVMetalTextureCacheRef _cvmtlTextureCache;
    CVMetalTextureRef _cvmtlColorTexture;
    CVMetalTextureRef _cvmtlDepthTexture;

    CVOpenGLTextureCacheRef _cvglTextureCache;
    CVOpenGLTextureRef _cvglColorTexture;
    CVOpenGLTextureRef _cvglDepthTexture;
#endif // 0

  uint32_t _glColorTexture;
  uint32_t _glDepthTexture;

  ShaderContext _shaderProgramContext[ShaderContextCount];

#if 0
  // XXX: OpenGLContext just need the inlined impl in the header left.
    NSGL::OpenGLContext* _currentOpenGLContext;
#endif // 0

  int32_t _restoreDrawFbo;
  int32_t _restoreVao;
  int32_t _restoreVbo;
  bool _restoreDepthTest;
  bool _restoreDepthWriteMask;
  bool _restoreStencilWriteMask;
  bool _restoreCullFace;
  int32_t _restoreFrontFace;
  int32_t _restoreDepthFunc;
  int32_t _restoreViewport[4];
  bool _restoreblendEnabled;
  int32_t _restoreColorOp;
  int32_t _restoreAlphaOp;
  int32_t _restoreColorSrcFnOp;
  int32_t _restoreAlphaSrcFnOp;
  int32_t _restoreColorDstFnOp;
  int32_t _restoreAlphaDstFnOp;
  bool _restoreAlphaToCoverage;
  int32_t _restorePolygonMode;
  int32_t _restoreActiveTexture;
  int32_t _restoreTexture[2];
  VertexAttribState _restoreVertexAttribState[2];
  int32_t _restoreProgram;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif /* PXR_METAL_SUPPORT_ENABLED */

#endif /* PXR_IMAGING_HGIINTEROP_HGIINTEROPMETAL_H */
