//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// vec.template.h file to make changes.

#ifndef PXR_BASE_GF_VEC3I_H
#define PXR_BASE_GF_VEC3I_H

/// \file gf/vec3i.h
/// \ingroup group_gf_LinearAlgebra

#include "Gf/api.h"
#include "Gf/gfLimits.h"
#include "Gf/traits.h"
#include "Tf/diagnostic.h"
#include "Tf/hash.h"
#include "pxr/pxrns.h"

#include <cstddef>

#include <iosfwd>

PXR_NAMESPACE_OPEN_SCOPE

class GfVec3i;

template<> struct GfIsGfVec<class GfVec3i> {
  static const bool value = true;
};

/// \class GfVec3i
/// \ingroup group_gf_LinearAlgebra
///
/// Basic type for a vector of 3 int components.
///
/// Represents a vector of 3 components of type \c int.
/// It is intended to be fast and simple.
///
class GfVec3i {
 public:
  /// Scalar element type and dimension.
  typedef int ScalarType;
  static const size_t dimension = 3;

  /// Default constructor does no initialization.
  GfVec3i() = default;

  /// Initialize all elements to a single value.
  constexpr explicit GfVec3i(int value) : _data{value, value, value} {}

  /// Initialize all elements with explicit arguments.
  constexpr GfVec3i(int s0, int s1, int s2) : _data{s0, s1, s2} {}

  /// Construct with pointer to values.
  template<class Scl> constexpr explicit GfVec3i(Scl const *p) : _data{p[0], p[1], p[2]} {}

  /// Create a unit vector along the X-axis.
  static GfVec3i XAxis()
  {
    GfVec3i result(0);
    result[0] = 1;
    return result;
  }
  /// Create a unit vector along the Y-axis.
  static GfVec3i YAxis()
  {
    GfVec3i result(0);
    result[1] = 1;
    return result;
  }
  /// Create a unit vector along the Z-axis.
  static GfVec3i ZAxis()
  {
    GfVec3i result(0);
    result[2] = 1;
    return result;
  }

  /// Create a unit vector along the i-th axis, zero-based.  Return the zero
  /// vector if \p i is greater than or equal to 3.
  static GfVec3i Axis(size_t i)
  {
    GfVec3i result(0);
    if (i < 3)
      result[i] = 1;
    return result;
  }

  /// Set all elements with passed arguments.
  GfVec3i &Set(int s0, int s1, int s2)
  {
    _data[0] = s0;
    _data[1] = s1;
    _data[2] = s2;
    return *this;
  }

  /// Set all elements with a pointer to data.
  GfVec3i &Set(int const *a)
  {
    return Set(a[0], a[1], a[2]);
  }

  /// Direct data access.
  int const *data() const
  {
    return _data;
  }
  int *data()
  {
    return _data;
  }
  int const *GetArray() const
  {
    return data();
  }

  /// Indexing.
  int const &operator[](size_t i) const
  {
    return _data[i];
  }
  int &operator[](size_t i)
  {
    return _data[i];
  }

  /// Hash.
  friend inline size_t hash_value(GfVec3i const &vec)
  {
    return TfHash::Combine(vec[0], vec[1], vec[2]);
  }

  /// Equality comparison.
  bool operator==(GfVec3i const &other) const
  {
    return _data[0] == other[0] && _data[1] == other[1] && _data[2] == other[2];
  }
  bool operator!=(GfVec3i const &other) const
  {
    return !(*this == other);
  }

  // TODO Add inequality for other vec types...
  /// Equality comparison.
  GF_API
  bool operator==(class GfVec3d const &other) const;
  /// Equality comparison.
  GF_API
  bool operator==(class GfVec3f const &other) const;
  /// Equality comparison.
  GF_API
  bool operator==(class GfVec3h const &other) const;

  /// Create a vec with negated elements.
  GfVec3i operator-() const
  {
    return GfVec3i(-_data[0], -_data[1], -_data[2]);
  }

  /// Addition.
  GfVec3i &operator+=(GfVec3i const &other)
  {
    _data[0] += other[0];
    _data[1] += other[1];
    _data[2] += other[2];
    return *this;
  }
  friend GfVec3i operator+(GfVec3i const &l, GfVec3i const &r)
  {
    return GfVec3i(l) += r;
  }

  /// Subtraction.
  GfVec3i &operator-=(GfVec3i const &other)
  {
    _data[0] -= other[0];
    _data[1] -= other[1];
    _data[2] -= other[2];
    return *this;
  }
  friend GfVec3i operator-(GfVec3i const &l, GfVec3i const &r)
  {
    return GfVec3i(l) -= r;
  }

  /// Multiplication by scalar.
  GfVec3i &operator*=(double s)
  {
    _data[0] *= s;
    _data[1] *= s;
    _data[2] *= s;
    return *this;
  }
  GfVec3i operator*(double s) const
  {
    return GfVec3i(*this) *= s;
  }
  friend GfVec3i operator*(double s, GfVec3i const &v)
  {
    return v * s;
  }

  /// Division by scalar.
  GfVec3i &operator/=(int s)
  {
    _data[0] /= s;
    _data[1] /= s;
    _data[2] /= s;
    return *this;
  }
  GfVec3i operator/(int s) const
  {
    return GfVec3i(*this) /= s;
  }

  /// See GfDot().
  int operator*(GfVec3i const &v) const
  {
    return _data[0] * v[0] + _data[1] * v[1] + _data[2] * v[2];
  }

  /// Returns the projection of \p this onto \p v. That is:
  /// \code
  /// v * (*this * v)
  /// \endcode
  GfVec3i GetProjection(GfVec3i const &v) const
  {
    return v * (*this * v);
  }

  /// Returns the orthogonal complement of \p this->GetProjection(b).
  /// That is:
  /// \code
  ///  *this - this->GetProjection(b)
  /// \endcode
  GfVec3i GetComplement(GfVec3i const &b) const
  {
    return *this - this->GetProjection(b);
  }

  /// Squared length.
  int GetLengthSq() const
  {
    return *this * *this;
  }

 private:
  int _data[3];
};

/// Output a GfVec3i.
/// \ingroup group_gf_DebuggingOutput
GF_API std::ostream &operator<<(std::ostream &, GfVec3i const &);

/// Returns component-wise multiplication of vectors \p v1 and \p v2.
inline GfVec3i GfCompMult(GfVec3i const &v1, GfVec3i const &v2)
{
  return GfVec3i(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

/// Returns component-wise quotient of vectors \p v1 and \p v2.
inline GfVec3i GfCompDiv(GfVec3i const &v1, GfVec3i const &v2)
{
  return GfVec3i(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

/// Returns the dot (inner) product of two vectors.
inline int GfDot(GfVec3i const &v1, GfVec3i const &v2)
{
  return v1 * v2;
}

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_BASE_GF_VEC3I_H
