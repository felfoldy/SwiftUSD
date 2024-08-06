//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// matrix2.template.cpp file to make changes.

#include "Gf/matrix2f.h"
#include "Gf/matrix2d.h"
#include "pxr/pxrns.h"

#include "Gf/gfMath.h"
#include "Gf/ostreamHelpers.h"
#include "Tf/type.h"

#include <float.h>
#include <ostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType)
{
  TfType::Define<GfMatrix2f>();
}

std::ostream &operator<<(std::ostream &out, const GfMatrix2f &m)
{
  return out << "( (" << Gf_OstreamHelperP(m[0][0]) << ", " << Gf_OstreamHelperP(m[0][1]) << "), ("
             << Gf_OstreamHelperP(m[1][0]) << ", " << Gf_OstreamHelperP(m[1][1]) << ") )";
}

GfMatrix2f::GfMatrix2f(const GfMatrix2d &m)
{
  Set(m[0][0], m[0][1], m[1][0], m[1][1]);
}

GfMatrix2f::GfMatrix2f(const std::vector<std::vector<double>> &v)
{
  float m[2][2] = {{1.0, 0.0}, {0.0, 1.0}};
  for (size_t row = 0; row < 2 && row < v.size(); ++row) {
    for (size_t col = 0; col < 2 && col < v[row].size(); ++col) {
      m[row][col] = v[row][col];
    }
  }
  Set(m);
}

GfMatrix2f::GfMatrix2f(const std::vector<std::vector<float>> &v)
{
  float m[2][2] = {{1.0, 0.0}, {0.0, 1.0}};
  for (size_t row = 0; row < 2 && row < v.size(); ++row) {
    for (size_t col = 0; col < 2 && col < v[row].size(); ++col) {
      m[row][col] = v[row][col];
    }
  }
  Set(m);
}

GfMatrix2f &GfMatrix2f::SetDiagonal(float s)
{
  _mtx[0][0] = s;
  _mtx[0][1] = 0.0;
  _mtx[1][0] = 0.0;
  _mtx[1][1] = s;
  return *this;
}

GfMatrix2f &GfMatrix2f::SetDiagonal(const GfVec2f &v)
{
  _mtx[0][0] = v[0];
  _mtx[0][1] = 0.0;
  _mtx[1][0] = 0.0;
  _mtx[1][1] = v[1];
  return *this;
}

float *GfMatrix2f::Get(float m[2][2]) const
{
  m[0][0] = _mtx[0][0];
  m[0][1] = _mtx[0][1];
  m[1][0] = _mtx[1][0];
  m[1][1] = _mtx[1][1];
  return &m[0][0];
}

bool GfMatrix2f::operator==(const GfMatrix2d &m) const
{
  return (_mtx[0][0] == m._mtx[0][0] && _mtx[0][1] == m._mtx[0][1] && _mtx[1][0] == m._mtx[1][0] &&
          _mtx[1][1] == m._mtx[1][1]);
}

bool GfMatrix2f::operator==(const GfMatrix2f &m) const
{
  return (_mtx[0][0] == m._mtx[0][0] && _mtx[0][1] == m._mtx[0][1] && _mtx[1][0] == m._mtx[1][0] &&
          _mtx[1][1] == m._mtx[1][1]);
}

GfMatrix2f GfMatrix2f::GetTranspose() const
{
  GfMatrix2f transpose;
  transpose._mtx[0][0] = _mtx[0][0];
  transpose._mtx[1][0] = _mtx[0][1];
  transpose._mtx[0][1] = _mtx[1][0];
  transpose._mtx[1][1] = _mtx[1][1];

  return transpose;
}

GfMatrix2f GfMatrix2f::GetInverse(double *detPtr, double eps) const
{
  double det = GetDeterminant();

  if (detPtr) {
    // CODE_COVERAGE_OFF_NO_REPORT This is inaccessible from script and not
    // worth writing a whole C++ test for.
    *detPtr = det;
    // CODE_COVERAGE_ON_NO_REPORT
  }

  GfMatrix2f inverse;

  if (GfAbs(det) > eps) {

    double rcp = 1.0 / det;
    inverse._mtx[0][0] = static_cast<float>(_mtx[1][1] * rcp);
    inverse._mtx[0][1] = static_cast<float>(_mtx[0][1] * -rcp);
    inverse._mtx[1][0] = static_cast<float>(_mtx[1][0] * -rcp);
    inverse._mtx[1][1] = static_cast<float>(_mtx[0][0] * rcp);
  }
  else {
    inverse.SetDiagonal(FLT_MAX);
  }

  return inverse;
}

double GfMatrix2f::GetDeterminant() const
{
  return (_mtx[0][0] * _mtx[1][1] - _mtx[0][1] * _mtx[1][0]);
}

/*
** Scaling
*/
GfMatrix2f &GfMatrix2f::operator*=(double d)
{
  _mtx[0][0] *= d;
  _mtx[0][1] *= d;
  _mtx[1][0] *= d;
  _mtx[1][1] *= d;
  return *this;
}

/*
** Addition
*/
GfMatrix2f &GfMatrix2f::operator+=(const GfMatrix2f &m)
{
  _mtx[0][0] += m._mtx[0][0];
  _mtx[0][1] += m._mtx[0][1];
  _mtx[1][0] += m._mtx[1][0];
  _mtx[1][1] += m._mtx[1][1];
  return *this;
}

/*
** Subtraction
*/
GfMatrix2f &GfMatrix2f::operator-=(const GfMatrix2f &m)
{
  _mtx[0][0] -= m._mtx[0][0];
  _mtx[0][1] -= m._mtx[0][1];
  _mtx[1][0] -= m._mtx[1][0];
  _mtx[1][1] -= m._mtx[1][1];
  return *this;
}

/*
** Negation
*/
GfMatrix2f operator-(const GfMatrix2f &m)
{
  return GfMatrix2f(-m._mtx[0][0], -m._mtx[0][1], -m._mtx[1][0], -m._mtx[1][1]);
}

GfMatrix2f &GfMatrix2f::operator*=(const GfMatrix2f &m)
{
  // Save current values before they are overwritten
  GfMatrix2f tmp = *this;

  _mtx[0][0] = tmp._mtx[0][0] * m._mtx[0][0] + tmp._mtx[0][1] * m._mtx[1][0];

  _mtx[0][1] = tmp._mtx[0][0] * m._mtx[0][1] + tmp._mtx[0][1] * m._mtx[1][1];

  _mtx[1][0] = tmp._mtx[1][0] * m._mtx[0][0] + tmp._mtx[1][1] * m._mtx[1][0];

  _mtx[1][1] = tmp._mtx[1][0] * m._mtx[0][1] + tmp._mtx[1][1] * m._mtx[1][1];

  return *this;
}

bool GfIsClose(GfMatrix2f const &m1, GfMatrix2f const &m2, double tolerance)
{
  for (size_t row = 0; row < 2; ++row) {
    for (size_t col = 0; col < 2; ++col) {
      if (!GfIsClose(m1[row][col], m2[row][col], tolerance))
        return false;
    }
  }
  return true;
}

PXR_NAMESPACE_CLOSE_SCOPE
