//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// vec.template.h file to make changes.

#ifndef PXR_BASE_GF_VEC3D_H
#define PXR_BASE_GF_VEC3D_H

/// \file gf/vec3d.h
/// \ingroup group_gf_LinearAlgebra

#include "Gf/api.h"
#include "Gf/gfLimits.h"
#include "Gf/gfMath.h"
#include "Gf/traits.h"
#include "Tf/diagnostic.h"
#include "Tf/hash.h"
#include "pxr/pxrns.h"

#include <cmath>
#include <cstddef>

#include <iosfwd>

PXR_NAMESPACE_OPEN_SCOPE

class GfVec3d;

template<> struct GfIsGfVec<class GfVec3d> {
  static const bool value = true;
};

/// \class GfVec3d
/// \ingroup group_gf_LinearAlgebra
///
/// Basic type for a vector of 3 double components.
///
/// Represents a vector of 3 components of type \c double.
/// It is intended to be fast and simple.
///
class GfVec3d {
 public:
  /// Scalar element type and dimension.
  typedef double ScalarType;
  static const size_t dimension = 3;

  /// Default constructor does no initialization.
  GfVec3d() = default;

  /// Initialize all elements to a single value.
  constexpr explicit GfVec3d(double value) : _data{value, value, value} {}

  /// Initialize all elements with explicit arguments.
  constexpr GfVec3d(double s0, double s1, double s2) : _data{s0, s1, s2} {}

  /// Construct with pointer to values.
  template<class Scl> constexpr explicit GfVec3d(Scl const *p) : _data{p[0], p[1], p[2]} {}

  /// Implicitly convert from GfVec3f.
  GfVec3d(class GfVec3f const &other);

  /// Implicitly convert from GfVec3h.
  GfVec3d(class GfVec3h const &other);

  /// Implicitly convert from GfVec3i.
  GfVec3d(class GfVec3i const &other);

  /// Create a unit vector along the X-axis.
  static GfVec3d XAxis()
  {
    GfVec3d result(0);
    result[0] = 1;
    return result;
  }
  /// Create a unit vector along the Y-axis.
  static GfVec3d YAxis()
  {
    GfVec3d result(0);
    result[1] = 1;
    return result;
  }
  /// Create a unit vector along the Z-axis.
  static GfVec3d ZAxis()
  {
    GfVec3d result(0);
    result[2] = 1;
    return result;
  }

  /// Create a unit vector along the i-th axis, zero-based.  Return the zero
  /// vector if \p i is greater than or equal to 3.
  static GfVec3d Axis(size_t i)
  {
    GfVec3d result(0);
    if (i < 3)
      result[i] = 1;
    return result;
  }

  /// Set all elements with passed arguments.
  GfVec3d &Set(double s0, double s1, double s2)
  {
    _data[0] = s0;
    _data[1] = s1;
    _data[2] = s2;
    return *this;
  }

  /// Set all elements with a pointer to data.
  GfVec3d &Set(double const *a)
  {
    return Set(a[0], a[1], a[2]);
  }

  /// Direct data access.
  double const *data() const
  {
    return _data;
  }
  double *data()
  {
    return _data;
  }
  double const *GetArray() const
  {
    return data();
  }

  /// Indexing.
  double const &operator[](size_t i) const
  {
    return _data[i];
  }
  double &operator[](size_t i)
  {
    return _data[i];
  }

  /// Hash.
  friend inline size_t hash_value(GfVec3d const &vec)
  {
    return TfHash::Combine(vec[0], vec[1], vec[2]);
  }

  /// Equality comparison.
  bool operator==(GfVec3d const &other) const
  {
    return _data[0] == other[0] && _data[1] == other[1] && _data[2] == other[2];
  }
  bool operator!=(GfVec3d const &other) const
  {
    return !(*this == other);
  }

  // TODO Add inequality for other vec types...
  /// Equality comparison.
  GF_API
  bool operator==(class GfVec3f const &other) const;
  /// Equality comparison.
  GF_API
  bool operator==(class GfVec3h const &other) const;
  /// Equality comparison.
  GF_API
  bool operator==(class GfVec3i const &other) const;

  /// Create a vec with negated elements.
  GfVec3d operator-() const
  {
    return GfVec3d(-_data[0], -_data[1], -_data[2]);
  }

  /// Addition.
  GfVec3d &operator+=(GfVec3d const &other)
  {
    _data[0] += other[0];
    _data[1] += other[1];
    _data[2] += other[2];
    return *this;
  }
  friend GfVec3d operator+(GfVec3d const &l, GfVec3d const &r)
  {
    return GfVec3d(l) += r;
  }

  /// Subtraction.
  GfVec3d &operator-=(GfVec3d const &other)
  {
    _data[0] -= other[0];
    _data[1] -= other[1];
    _data[2] -= other[2];
    return *this;
  }
  friend GfVec3d operator-(GfVec3d const &l, GfVec3d const &r)
  {
    return GfVec3d(l) -= r;
  }

  /// Multiplication by scalar.
  GfVec3d &operator*=(double s)
  {
    _data[0] *= s;
    _data[1] *= s;
    _data[2] *= s;
    return *this;
  }
  GfVec3d operator*(double s) const
  {
    return GfVec3d(*this) *= s;
  }
  friend GfVec3d operator*(double s, GfVec3d const &v)
  {
    return v * s;
  }

  /// Division by scalar.
  // TODO should divide by the scalar type.
  GfVec3d &operator/=(double s)
  {
    // TODO This should not multiply by 1/s, it should do the division.
    // Doing the division is more numerically stable when s is close to
    // zero.
    return *this *= (1.0 / s);
  }
  GfVec3d operator/(double s) const
  {
    return *this * (1.0 / s);
  }

  /// See GfDot().
  double operator*(GfVec3d const &v) const
  {
    return _data[0] * v[0] + _data[1] * v[1] + _data[2] * v[2];
  }

  /// Returns the projection of \p this onto \p v. That is:
  /// \code
  /// v * (*this * v)
  /// \endcode
  GfVec3d GetProjection(GfVec3d const &v) const
  {
    return v * (*this * v);
  }

  /// Returns the orthogonal complement of \p this->GetProjection(b).
  /// That is:
  /// \code
  ///  *this - this->GetProjection(b)
  /// \endcode
  GfVec3d GetComplement(GfVec3d const &b) const
  {
    return *this - this->GetProjection(b);
  }

  /// Squared length.
  double GetLengthSq() const
  {
    return *this * *this;
  }

  /// Length
  double GetLength() const
  {
    return GfSqrt(GetLengthSq());
  }

  /// Normalizes the vector in place to unit length, returning the
  /// length before normalization. If the length of the vector is
  /// smaller than \p eps, then the vector is set to vector/\c eps.
  /// The original length of the vector is returned. See also GfNormalize().
  ///
  /// \todo This was fixed for bug 67777. This is a gcc64 optimizer bug.
  /// By tickling the code, it no longer tries to write into
  /// an illegal memory address (in the code section of memory).
  double Normalize(double eps = GF_MIN_VECTOR_LENGTH)
  {
    // TODO this seems suspect...  suggest dividing by length so long as
    // length is not zero.
    double length = GetLength();
    *this /= (length > eps) ? length : eps;
    return length;
  }

  GfVec3d GetNormalized(double eps = GF_MIN_VECTOR_LENGTH) const
  {
    GfVec3d normalized(*this);
    normalized.Normalize(eps);
    return normalized;
  }

  /// Orthogonalize and optionally normalize a set of basis vectors. This
  /// uses an iterative method that is very stable even when the vectors are
  /// far from orthogonal (close to colinear).  The number of iterations and
  /// thus the computation time does increase as the vectors become close to
  /// colinear, however. Returns a bool specifying whether the solution
  /// converged after a number of iterations.  If it did not converge, the
  /// returned vectors will be as close as possible to orthogonal within the
  /// iteration limit. Colinear vectors will be unaltered, and the method
  /// will return false.
  GF_API
  static bool OrthogonalizeBasis(GfVec3d *tx,
                                 GfVec3d *ty,
                                 GfVec3d *tz,
                                 const bool normalize,
                                 double eps = GF_MIN_ORTHO_TOLERANCE);

  /// Sets \c v1 and \c v2 to unit vectors such that v1, v2 and *this are
  /// mutually orthogonal.  If the length L of *this is smaller than \c eps,
  /// then v1 and v2 will have magnitude L/eps.  As a result, the function
  /// delivers a continuous result as *this shrinks in length.
  GF_API
  void BuildOrthonormalFrame(GfVec3d *v1, GfVec3d *v2, double eps = GF_MIN_VECTOR_LENGTH) const;

 private:
  double _data[3];
};

/// Output a GfVec3d.
/// \ingroup group_gf_DebuggingOutput
GF_API std::ostream &operator<<(std::ostream &, GfVec3d const &);

PXR_NAMESPACE_CLOSE_SCOPE

#include "Gf/vec3f.h"
#include "Gf/vec3h.h"
#include "Gf/vec3i.h"

PXR_NAMESPACE_OPEN_SCOPE

inline GfVec3d::GfVec3d(class GfVec3f const &other)
{
  _data[0] = other[0];
  _data[1] = other[1];
  _data[2] = other[2];
}
inline GfVec3d::GfVec3d(class GfVec3h const &other)
{
  _data[0] = other[0];
  _data[1] = other[1];
  _data[2] = other[2];
}
inline GfVec3d::GfVec3d(class GfVec3i const &other)
{
  _data[0] = other[0];
  _data[1] = other[1];
  _data[2] = other[2];
}

/// Returns component-wise multiplication of vectors \p v1 and \p v2.
inline GfVec3d GfCompMult(GfVec3d const &v1, GfVec3d const &v2)
{
  return GfVec3d(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

/// Returns component-wise quotient of vectors \p v1 and \p v2.
inline GfVec3d GfCompDiv(GfVec3d const &v1, GfVec3d const &v2)
{
  return GfVec3d(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

/// Returns the dot (inner) product of two vectors.
inline double GfDot(GfVec3d const &v1, GfVec3d const &v2)
{
  return v1 * v2;
}

/// Returns the geometric length of \c v.
inline double GfGetLength(GfVec3d const &v)
{
  return v.GetLength();
}

/// Normalizes \c *v in place to unit length, returning the length before
/// normalization. If the length of \c *v is smaller than \p eps then \c *v is
/// set to \c *v/eps.  The original length of \c *v is returned.
inline double GfNormalize(GfVec3d *v, double eps = GF_MIN_VECTOR_LENGTH)
{
  return v->Normalize(eps);
}

/// Returns a normalized (unit-length) vector with the same direction as \p v.
/// If the length of this vector is smaller than \p eps, the vector divided by
/// \p eps is returned.
inline GfVec3d GfGetNormalized(GfVec3d const &v, double eps = GF_MIN_VECTOR_LENGTH)
{
  return v.GetNormalized(eps);
}

/// Returns the projection of \p a onto \p b. That is:
/// \code
/// b * (a * b)
/// \endcode
inline GfVec3d GfGetProjection(GfVec3d const &a, GfVec3d const &b)
{
  return a.GetProjection(b);
}

/// Returns the orthogonal complement of \p a.GetProjection(b). That is:
/// \code
///  a - a.GetProjection(b)
/// \endcode
inline GfVec3d GfGetComplement(GfVec3d const &a, GfVec3d const &b)
{
  return a.GetComplement(b);
}

/// Tests for equality within a given tolerance, returning \c true if the
/// length of the difference vector is less than or equal to \p tolerance.
inline bool GfIsClose(GfVec3d const &v1, GfVec3d const &v2, double tolerance)
{
  GfVec3d delta = v1 - v2;
  return delta.GetLengthSq() <= tolerance * tolerance;
}

GF_API bool GfOrthogonalizeBasis(
    GfVec3d *tx, GfVec3d *ty, GfVec3d *tz, bool normalize, double eps = GF_MIN_ORTHO_TOLERANCE);

GF_API void GfBuildOrthonormalFrame(GfVec3d const &v0,
                                    GfVec3d *v1,
                                    GfVec3d *v2,
                                    double eps = GF_MIN_VECTOR_LENGTH);

/// Returns the cross product of \p v1 and \p v2.
inline GfVec3d GfCross(GfVec3d const &v1, GfVec3d const &v2)
{
  return GfVec3d(
      v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]);
}

/// Returns the cross product of \p v1 and \p v2.
/// \see GfCross()
inline GfVec3d operator^(GfVec3d const &v1, GfVec3d const &v2)
{
  return GfCross(v1, v2);
}

/// Spherical linear interpolation in three dimensions.
GF_API GfVec3d GfSlerp(double alpha, GfVec3d const &v0, GfVec3d const &v1);

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_BASE_GF_VEC3D_H
