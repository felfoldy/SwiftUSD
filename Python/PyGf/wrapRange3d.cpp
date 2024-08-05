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
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// wrapRange.template.cpp file to make changes.

#include <pxr/pxrns.h>

#include "Gf/range3d.h"
#include "Gf/range3f.h"

#include "Tf/hash.h"
#include "Tf/pyContainerConversions.h"
#include "Tf/pyUtils.h"
#include "Tf/wrapTypeHelpers.h"

#include <boost/python/class.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/operators.hpp>
#include <boost/python/return_arg.hpp>

#include <string>

using namespace boost::python;

using std::string;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

static const int _dimension = 3;

static string _Repr(GfRange3d const &self)
{
  return TF_PY_REPR_PREFIX + "Range3d(" + TfPyRepr(self.GetMin()) + ", " +
         TfPyRepr(self.GetMax()) + ")";
}

static GfRange3d __truediv__(const GfRange3d &self, double value)
{
  return self / value;
}

static GfRange3d &__itruediv__(GfRange3d &self, double value)
{
  return self /= value;
}

static size_t __hash__(GfRange3d const &r)
{
  return TfHash{}(r);
}

}  // anonymous namespace

void wrapRange3d()
{
  object getMin = make_function(&GfRange3d::GetMin, return_value_policy<return_by_value>());

  object getMax = make_function(&GfRange3d::GetMax, return_value_policy<return_by_value>());

  class_<GfRange3d> cls("Range3d", init<>());
  cls.def(init<GfRange3d>())
      .def(init<const GfVec3d &, const GfVec3d &>())

      .def(init<GfRange3f>())

      .def(TfTypePythonClass())

      .def_readonly("dimension", _dimension)

      .add_property("min", getMin, &GfRange3d::SetMin)
      .add_property("max", getMax, &GfRange3d::SetMax)

      .def("GetMin", getMin)
      .def("GetMax", getMax)

      .def("GetSize", &GfRange3d::GetSize)
      .def("GetMidpoint", &GfRange3d::GetMidpoint)

      .def("SetMin", &GfRange3d::SetMin)
      .def("SetMax", &GfRange3d::SetMax)

      .def("IsEmpty", &GfRange3d::IsEmpty)

      .def("SetEmpty", &GfRange3d::SetEmpty)

      .def("Contains", (bool(GfRange3d::*)(const GfVec3d &) const) & GfRange3d::Contains)
      .def("Contains", (bool(GfRange3d::*)(const GfRange3d &) const) & GfRange3d::Contains)

      .def("GetUnion", &GfRange3d::GetUnion)
      .staticmethod("GetUnion")

      .def("UnionWith",
           (const GfRange3d &(GfRange3d::*)(const GfVec3d &)) & GfRange3d::UnionWith,
           return_self<>())
      .def("UnionWith",
           (const GfRange3d &(GfRange3d::*)(const GfRange3d &)) & GfRange3d::UnionWith,
           return_self<>())

      .def("GetIntersection", &GfRange3d::GetIntersection)
      .staticmethod("GetIntersection")

      .def("IntersectWith",
           (const GfRange3d &(GfRange3d::*)(const GfRange3d &)) & GfRange3d::IntersectWith,
           return_self<>())

      .def("GetDistanceSquared", &GfRange3d::GetDistanceSquared)

      .def(str(self))
      .def(self += self)
      .def(self -= self)
      .def(self *= double())
      .def(self /= double())
      .def(self + self)
      .def(self - self)
      .def(double() * self)
      .def(self * double())
      .def(self / double())
      .def(self == GfRange3f())
      .def(self != GfRange3f())
      .def(self == self)
      .def(self != self)
      .def("__repr__", _Repr)
      .def("__hash__", __hash__)

      .def("GetCorner", &GfRange3d::GetCorner)
      .def("GetOctant", &GfRange3d::GetOctant)
      .def_readonly("unitCube", &GfRange3d::UnitCube)

      ;
  to_python_converter<std::vector<GfRange3d>, TfPySequenceToPython<std::vector<GfRange3d>>>();

  if (!PyObject_HasAttrString(cls.ptr(), "__truediv__")) {
    // __truediv__ not added by .def( self / double() ) above, which
    // happens when building with python 2, but we need it to support
    // "from __future__ import division"
    cls.def("__truediv__", __truediv__);
  }
  if (!PyObject_HasAttrString(cls.ptr(), "__itruediv__")) {
    // __itruediv__ not added by .def( self /= double() ) above, which
    // happens when building with python 2, but we need it to support
    // "from __future__ import division". This is also a workaround for a
    // bug in the current version of boost::python that incorrectly wraps
    // in-place division with __idiv__ when building with python 3.
    cls.def("__itruediv__", __itruediv__, return_self<>());
  }
}
