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
// This file is generated by a script.  Do not edit directly.  Edit the
// wrapMatrix2.template.cpp file to make changes.

#include <pxr/pxrns.h>

#include "Gf/matrix2d.h"
#include "Gf/matrix2f.h"

#include "Gf/pyBufferUtils.h"

#include "Tf/hash.h"
#include "Tf/pyContainerConversions.h"
#include "Tf/pyUtils.h"
#include "Tf/wrapTypeHelpers.h"

#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/detail/api_placeholder.hpp>
#include <boost/python/errors.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/make_constructor.hpp>
#include <boost/python/operators.hpp>
#include <boost/python/return_arg.hpp>
#include <boost/python/tuple.hpp>

#include <string>
#include <vector>

using namespace boost::python;
using std::string;
using std::vector;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

////////////////////////////////////////////////////////////////////////
// Python buffer protocol support.

// Python's getbuffer interface function.
static int getbuffer(PyObject *self, Py_buffer *view, int flags) {
  if (view == NULL) {
    PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
    return -1;
  }

  // We don't support fortran order.
  if ((flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS) {
    PyErr_SetString(PyExc_ValueError, "Fortran contiguity unsupported");
    return -1;
  }

  GfMatrix2d &mat = extract<GfMatrix2d &>(self);

  view->obj = self;
  view->buf = static_cast<void *>(mat.GetArray());
  view->len = sizeof(GfMatrix2d);
  view->readonly = 0;
  view->itemsize = sizeof(double);
  if ((flags & PyBUF_FORMAT) == PyBUF_FORMAT) {
    view->format = Gf_GetPyBufferFmtFor<double>();
  } else {
    view->format = NULL;
  }
  if ((flags & PyBUF_ND) == PyBUF_ND) {
    view->ndim = 2;
    static Py_ssize_t shape[] = {2, 2};
    view->shape = shape;
  } else {
    view->ndim = 0;
    view->shape = NULL;
  }
  if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
    static Py_ssize_t strides[] = {2 * sizeof(double), sizeof(double)};
    view->strides = strides;
  } else {
    view->strides = NULL;
  }
  view->suboffsets = NULL;
  view->internal = NULL;

  Py_INCREF(self); // need to retain a reference to self.
  return 0;
}

// This structure serves to instantiate a PyBufferProcs instance with pointers
// to the right buffer protocol functions.
static PyBufferProcs bufferProcs = {
    (getbufferproc)getbuffer,
    (releasebufferproc)0,
};

// End python buffer protocol support.
////////////////////////////////////////////////////////////////////////

static string _Repr(GfMatrix2d const &self) {
  static char newline[] = ",\n            ";
  return TF_PY_REPR_PREFIX + "Matrix2d(" + TfPyRepr(self[0][0]) + ", " +
         TfPyRepr(self[0][1]) + newline + TfPyRepr(self[1][0]) + ", " +
         TfPyRepr(self[1][1]) + ")";
}

static GfMatrix2d GetInverseWrapper(const GfMatrix2d &self) {
  return self.GetInverse();
}

static void throwIndexErr(const char *msg) {
  PyErr_SetString(PyExc_IndexError, msg);
  boost::python::throw_error_already_set();
}

static int normalizeIndex(int index) {
  return TfPyNormalizeIndex(index, 2, true /*throw error*/);
}

// Return number of rows
static int __len__(GfMatrix2d const &self) { return 2; }

static double __getitem__double(GfMatrix2d const &self, tuple index) {
  int i1 = 0, i2 = 0;
  if (len(index) == 2) {
    i1 = normalizeIndex(extract<int>(index[0]));
    i2 = normalizeIndex(extract<int>(index[1]));
  } else
    throwIndexErr("Index has incorrect size.");

  return self[i1][i2];
}

static GfVec2d __getitem__vector(GfMatrix2d const &self, int index) {
  return GfVec2d(self[normalizeIndex(index)]);
}

static void __setitem__double(GfMatrix2d &self, tuple index, double value) {
  int i1 = 0, i2 = 0;
  if (len(index) == 2) {
    i1 = normalizeIndex(extract<int>(index[0]));
    i2 = normalizeIndex(extract<int>(index[1]));
  } else
    throwIndexErr("Index has incorrect size.");

  self[i1][i2] = value;
}

static void __setitem__vector(GfMatrix2d &self, int index, GfVec2d value) {
  int ni = normalizeIndex(index);
  self[ni][0] = value[0];
  self[ni][1] = value[1];
}

static bool __contains__double(const GfMatrix2d &self, double value) {
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if (self[i][j] == value)
        return true;
  return false;
}

// Check rows against GfVec
static bool __contains__vector(const GfMatrix2d &self, GfVec2d value) {
  for (int i = 0; i < 2; ++i)
    if (self.GetRow(i) == value)
      return true;
  return false;
}

static GfMatrix2d __truediv__(const GfMatrix2d &self, GfMatrix2d value) {
  return self / value;
}

static GfMatrix2d *__init__() {
  // Default constructor produces identity from python.
  return new GfMatrix2d(1);
}

// This adds support for python's builtin pickling library
// This is used by our Shake plugins which need to pickle entire classes
// (including code), which we don't support in pxml.
struct GfMatrix2d_Pickle_Suite : boost::python::pickle_suite {
  static boost::python::tuple getinitargs(const GfMatrix2d &m) {
    return boost::python::make_tuple(m[0][0], m[0][1], m[1][0], m[1][1]);
  }
};

static size_t __hash__(GfMatrix2d const &m) { return TfHash{}(m); }

static boost::python::tuple get_dimension() {
  // At one time this was a constant static tuple we returned for
  // dimension. With boost building for python 3 that results in
  // a segfault at shutdown. Building for python 2 with a static
  // tuple returned here seems to work fine.
  //
  // It seems likely that this has to do with the order of
  // destruction of these objects when deinitializing, but we did
  // not dig deeply into this difference.
  return make_tuple(2, 2);
}

} // anonymous namespace

void wrapMatrix2d() {
  typedef GfMatrix2d This;

  def("IsClose",
      (bool (*)(const GfMatrix2d &m1, const GfMatrix2d &m2, double))GfIsClose);

  class_<This> cls("Matrix2d", no_init);
  cls.def_pickle(GfMatrix2d_Pickle_Suite())
      .def("__init__", make_constructor(__init__))
      .def(init<const GfMatrix2d &>())
      .def(init<const GfMatrix2f &>())
      .def(init<int>())
      .def(init<double>())
      .def(init<double, double, double, double>())
      .def(init<const GfVec2d &>())
      .def(init<const vector<vector<float>> &>())
      .def(init<const vector<vector<double>> &>())

      .def(TfTypePythonClass())

      .add_static_property("dimension", get_dimension)
      .def("__len__", __len__, "Return number of rows")

      .def("__getitem__", __getitem__double)
      .def("__getitem__", __getitem__vector)
      .def("__setitem__", __setitem__double)
      .def("__setitem__", __setitem__vector)
      .def("__contains__", __contains__double)
      .def("__contains__", __contains__vector, "Check rows against GfVec")

      .def("Set",
           (This & (This::*)(double, double, double, double)) & This::Set,
           return_self<>())

      .def("SetIdentity", &This::SetIdentity, return_self<>())
      .def("SetZero", &This::SetZero, return_self<>())

      .def("SetDiagonal", (This & (This::*)(double)) & This::SetDiagonal,
           return_self<>())
      .def("SetDiagonal",
           (This & (This::*)(const GfVec2d &)) & This::SetDiagonal,
           return_self<>())

      .def("SetRow", &This::SetRow)
      .def("SetColumn", &This::SetColumn)
      .def("GetRow", &This::GetRow)
      .def("GetColumn", &This::GetColumn)

      .def("GetTranspose", &This::GetTranspose)
      .def("GetInverse", GetInverseWrapper)

      .def("GetDeterminant", &This::GetDeterminant)

      .def(str(self))
      .def(self == self)
      .def(self == GfMatrix2f())
      .def(self != self)
      .def(self != GfMatrix2f())
      .def(self *= self)
      .def(self * self)
      .def(self *= double())
      .def(self * double())
      .def(double() * self)
      .def(self += self)
      .def(self + self)
      .def(self -= self)
      .def(self - self)
      .def(-self)
      .def(self / self)
      .def(self * GfVec2d())
      .def(GfVec2d() * self)
      .def(self * GfVec2f())
      .def(GfVec2f() * self)

      .def("__repr__", _Repr)
      .def("__hash__", __hash__)

      ;
  to_python_converter<std::vector<This>,
                      TfPySequenceToPython<std::vector<This>>>();

  // Install buffer protocol: set the tp_as_buffer slot to point to a
  // structure of function pointers that implement the buffer protocol for
  // this type.
  auto *typeObj = reinterpret_cast<PyTypeObject *>(cls.ptr());
  typeObj->tp_as_buffer = &bufferProcs;

  if (!PyObject_HasAttrString(cls.ptr(), "__truediv__")) {
    // __truediv__ not added by .def( self / self ) above, which
    // happens when building with python 2, but we need it to support
    // "from __future__ import division"
    cls.def("__truediv__", __truediv__);
  }
}
