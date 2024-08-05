//
// Copyright 2016 Pixar
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
#include "Usd/schemaBase.h"
#include "UsdSkel/bindingAPI.h"

#include "Sdf/primSpec.h"

#include "Tf/pyAnnotatedBoolResult.h"
#include "Tf/pyContainerConversions.h"
#include "Tf/pyResultConversions.h"
#include "Tf/pyUtils.h"
#include "Tf/wrapTypeHelpers.h"
#include "Usd/pyConversions.h"

#include <boost/python.hpp>

#include <string>

using namespace boost::python;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

#define WRAP_CUSTOM template<class Cls> static void _CustomWrapCode(Cls &_class)

// fwd decl.
WRAP_CUSTOM;

static UsdAttribute _CreateSkinningMethodAttr(UsdSkelBindingAPI &self,
                                              object defaultVal,
                                              bool writeSparsely)
{
  return self.CreateSkinningMethodAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token),
                                       writeSparsely);
}

static UsdAttribute _CreateGeomBindTransformAttr(UsdSkelBindingAPI &self,
                                                 object defaultVal,
                                                 bool writeSparsely)
{
  return self.CreateGeomBindTransformAttr(
      UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Matrix4d), writeSparsely);
}

static UsdAttribute _CreateJointsAttr(UsdSkelBindingAPI &self,
                                      object defaultVal,
                                      bool writeSparsely)
{
  return self.CreateJointsAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->TokenArray),
                               writeSparsely);
}

static UsdAttribute _CreateJointIndicesAttr(UsdSkelBindingAPI &self,
                                            object defaultVal,
                                            bool writeSparsely)
{
  return self.CreateJointIndicesAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->IntArray),
                                     writeSparsely);
}

static UsdAttribute _CreateJointWeightsAttr(UsdSkelBindingAPI &self,
                                            object defaultVal,
                                            bool writeSparsely)
{
  return self.CreateJointWeightsAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->FloatArray),
                                     writeSparsely);
}

static UsdAttribute _CreateBlendShapesAttr(UsdSkelBindingAPI &self,
                                           object defaultVal,
                                           bool writeSparsely)
{
  return self.CreateBlendShapesAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->TokenArray),
                                    writeSparsely);
}

static std::string _Repr(const UsdSkelBindingAPI &self)
{
  std::string primRepr = TfPyRepr(self.GetPrim());
  return TfStringPrintf("UsdSkel.BindingAPI(%s)", primRepr.c_str());
}

struct UsdSkelBindingAPI_CanApplyResult : public TfPyAnnotatedBoolResult<std::string> {
  UsdSkelBindingAPI_CanApplyResult(bool val, std::string const &msg)
      : TfPyAnnotatedBoolResult<std::string>(val, msg)
  {
  }
};

static UsdSkelBindingAPI_CanApplyResult _WrapCanApply(const UsdPrim &prim)
{
  std::string whyNot;
  bool result = UsdSkelBindingAPI::CanApply(prim, &whyNot);
  return UsdSkelBindingAPI_CanApplyResult(result, whyNot);
}

}  // anonymous namespace

void wrapUsdSkelBindingAPI()
{
  typedef UsdSkelBindingAPI This;

  UsdSkelBindingAPI_CanApplyResult::Wrap<UsdSkelBindingAPI_CanApplyResult>("_CanApplyResult",
                                                                           "whyNot");

  class_<This, bases<UsdAPISchemaBase>> cls("BindingAPI");

  cls.def(init<UsdPrim>(arg("prim")))
      .def(init<UsdSchemaBase const &>(arg("schemaObj")))
      .def(TfTypePythonClass())

      .def("Get", &This::Get, (arg("stage"), arg("path")))
      .staticmethod("Get")

      .def("CanApply", &_WrapCanApply, (arg("prim")))
      .staticmethod("CanApply")

      .def("Apply", &This::Apply, (arg("prim")))
      .staticmethod("Apply")

      .def("GetSchemaAttributeNames",
           &This::GetSchemaAttributeNames,
           arg("includeInherited") = true,
           return_value_policy<TfPySequenceToList>())
      .staticmethod("GetSchemaAttributeNames")

      .def("_GetStaticTfType",
           (TfType const &(*)())TfType::Find<This>,
           return_value_policy<return_by_value>())
      .staticmethod("_GetStaticTfType")

      .def(!self)

      .def("GetSkinningMethodAttr", &This::GetSkinningMethodAttr)
      .def("CreateSkinningMethodAttr",
           &_CreateSkinningMethodAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetGeomBindTransformAttr", &This::GetGeomBindTransformAttr)
      .def("CreateGeomBindTransformAttr",
           &_CreateGeomBindTransformAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetJointsAttr", &This::GetJointsAttr)
      .def("CreateJointsAttr",
           &_CreateJointsAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetJointIndicesAttr", &This::GetJointIndicesAttr)
      .def("CreateJointIndicesAttr",
           &_CreateJointIndicesAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetJointWeightsAttr", &This::GetJointWeightsAttr)
      .def("CreateJointWeightsAttr",
           &_CreateJointWeightsAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetBlendShapesAttr", &This::GetBlendShapesAttr)
      .def("CreateBlendShapesAttr",
           &_CreateBlendShapesAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetAnimationSourceRel", &This::GetAnimationSourceRel)
      .def("CreateAnimationSourceRel", &This::CreateAnimationSourceRel)

      .def("GetSkeletonRel", &This::GetSkeletonRel)
      .def("CreateSkeletonRel", &This::CreateSkeletonRel)

      .def("GetBlendShapeTargetsRel", &This::GetBlendShapeTargetsRel)
      .def("CreateBlendShapeTargetsRel", &This::CreateBlendShapeTargetsRel)
      .def("__repr__", ::_Repr);

  _CustomWrapCode(cls);
}

// ===================================================================== //
// Feel free to add custom code below this line, it will be preserved by
// the code generator.  The entry point for your custom code should look
// minimally like the following:
//
// WRAP_CUSTOM {
//     _class
//         .def("MyCustomMethod", ...)
//     ;
// }
//
// Of course any other ancillary or support code may be provided.
//
// Just remember to wrap code in the appropriate delimiters:
// 'namespace {', '}'.
//
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

namespace {

object _GetSkeleton(const UsdSkelBindingAPI &binding)
{
  UsdSkelSkeleton skel;
  return binding.GetSkeleton(&skel) ? object(skel) : object();
}

object _GetAnimationSource(const UsdSkelBindingAPI &binding)
{
  UsdPrim prim;
  return binding.GetAnimationSource(&prim) ? object(prim) : object();
}

tuple _ValidateJointIndices(TfSpan<const int> jointIndices, size_t numJoints)
{
  std::string reason;
  bool valid = UsdSkelBindingAPI::ValidateJointIndices(jointIndices, numJoints, &reason);
  return boost::python::make_tuple(valid, reason);
}

WRAP_CUSTOM
{
  using This = UsdSkelBindingAPI;

  _class
      .def("GetJointIndicesPrimvar", &This::GetJointIndicesPrimvar)

      .def("CreateJointIndicesPrimvar",
           &This::CreateJointIndicesPrimvar,
           (arg("constant"), arg("elementSize") = -1))

      .def("GetJointWeightsPrimvar", &This::GetJointWeightsPrimvar)

      .def("CreateJointWeightsPrimvar",
           &This::CreateJointWeightsPrimvar,
           (arg("constant"), arg("elementSize") = -1))

      .def("SetRigidJointInfluence",
           &This::SetRigidJointInfluence,
           (arg("jointIndex"), arg("weight") = 1.0f))

      .def("GetSkeleton", &_GetSkeleton)

      .def("GetAnimationSource", &_GetAnimationSource)

      .def("GetInheritedSkeleton", &This::GetInheritedSkeleton)

      .def("GetInheritedAnimationSource", &This::GetInheritedAnimationSource)

      .def("ValidateJointIndices", &_ValidateJointIndices, (arg("jointIndices"), arg("numJoints")))
      .staticmethod("ValidateJointIndices");
}

}  // namespace
