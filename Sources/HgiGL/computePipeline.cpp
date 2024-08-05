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
#include "Tf/diagnostic.h"

#include "HgiGL/computePipeline.h"
#include "HgiGL/conversions.h"
#include "HgiGL/diagnostic.h"
#include "HgiGL/resourceBindings.h"
#include "HgiGL/shaderFunction.h"
#include "HgiGL/shaderProgram.h"

PXR_NAMESPACE_OPEN_SCOPE

HgiGLComputePipeline::HgiGLComputePipeline(HgiComputePipelineDesc const &desc)
    : HgiComputePipeline(desc)
{
}

HgiGLComputePipeline::~HgiGLComputePipeline() = default;

void HgiGLComputePipeline::BindPipeline()
{
  //
  // Shader program
  //
  HgiGLShaderProgram *glProgram = static_cast<HgiGLShaderProgram *>(
      _descriptor.shaderProgram.Get());
  if (glProgram) {
    glUseProgram(glProgram->GetProgramId());
  }

  HGIGL_POST_PENDING_GL_ERRORS();
}

PXR_NAMESPACE_CLOSE_SCOPE
