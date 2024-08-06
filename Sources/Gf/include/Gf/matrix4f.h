//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// matrix4.template.h file to make changes.

#ifndef PXR_BASE_GF_MATRIX4F_H
#define PXR_BASE_GF_MATRIX4F_H

/// \file gf/matrix4f.h
/// \ingroup group_gf_LinearAlgebra

#include "Gf/api.h"
#include "Gf/declare.h"
#include "Gf/homogeneous.h"
#include "Gf/gfLimits.h"
#include "Gf/gfMath.h"
#include "Gf/matrixData.h"
#include "Gf/traits.h"
#include "Gf/vec3f.h"
#include "Gf/vec4f.h"
#include "Tf/hash.h"
#include "pxr/pxrns.h"

#include <iosfwd>
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE

template<> struct GfIsGfMatrix<class GfMatrix4f> {
  static const bool value = true;
};

class GfMatrix4d;
class GfMatrix4f;
class GfQuatf;
class GfRotation;
class GfMatrix3f;

/// \class GfMatrix4f
/// \ingroup group_gf_LinearAlgebra
///
/// Stores a 4x4 matrix of \c float elements. A basic type.
///
/// Matrices are defined to be in row-major order, so <c>matrix[i][j]</c>
/// indexes the element in the \e i th row and the \e j th column.
///
/// <h3>3D Transformations</h3>
///
/// The following methods interpret a GfMatrix4f as a 3D
/// transformation: SetRotate(), SetScale(), SetTranslate(), SetLookAt(),
/// Factor(), ExtractTranslation(), ExtractRotation(), Transform(), TransformDir().
/// By convention, vectors are treated primarily as row vectors,
/// implying the following:
/// \li Transformation matrices are organized to deal with row
///        vectors, not column vectors. For example, the last row of a matrix
///        contains the translation amounts.
/// \li Each of the Set() methods below completely rewrites the
///        matrix; for example, SetTranslate() yields a matrix
///        which does nothing but translate.
/// \li When multiplying two transformation matrices, the matrix
///        on the left applies a more local transformation to a row
///        vector. For example, if R represents a rotation
///        matrix and T represents a translation matrix, the
///        product R*T will rotate a row vector, then translate
///        it.
class GfMatrix4f {
 public:
  typedef float ScalarType;

  static const size_t numRows = 4;
  static const size_t numColumns = 4;

  /// Default constructor. Leaves the matrix component values undefined.
  GfMatrix4f() = default;

  /// Constructor. Initializes the matrix from 16 independent
  /// \c float values, specified in row-major order. For example,
  /// parameter \e m10 specifies the value in row 1 and column 0.
  GfMatrix4f(float m00,
             float m01,
             float m02,
             float m03,
             float m10,
             float m11,
             float m12,
             float m13,
             float m20,
             float m21,
             float m22,
             float m23,
             float m30,
             float m31,
             float m32,
             float m33)
  {
    Set(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33);
  }

  /// Constructor. Initializes the matrix from a 4x4 array
  /// of \c float values, specified in row-major order.
  GfMatrix4f(const float m[4][4])
  {
    Set(m);
  }

  /// Constructor. Explicitly initializes the matrix to \e s times the
  /// identity matrix.
  explicit GfMatrix4f(float s)
  {
    SetDiagonal(s);
  }

  /// Constructor. Explicitly initializes the matrix to diagonal form,
  /// with the \e i th element on the diagonal set to <c>v[i]</c>.
  explicit GfMatrix4f(const GfVec4f &v)
  {
    SetDiagonal(v);
  }

  /// Constructor.  Initialize the matrix from a vector of vectors of
  /// double. The vector is expected to be 4x4. If it is
  /// too big, only the first 4 rows and/or columns will be used.
  /// If it is too small, uninitialized elements will be filled in with
  /// the corresponding elements from an identity matrix.
  ///
  GF_API
  explicit GfMatrix4f(const std::vector<std::vector<double>> &v);

  /// Constructor.  Initialize the matrix from a vector of vectors of
  /// float. The vector is expected to be 4x4. If it is
  /// too big, only the first 4 rows and/or columns will be used.
  /// If it is too small, uninitialized elements will be filled in with
  /// the corresponding elements from an identity matrix.
  ///
  GF_API
  explicit GfMatrix4f(const std::vector<std::vector<float>> &v);

  /// Constructor.  Initialize the matrix from 4 row vectors of
  /// double.  Each vector is expected to length 4.  If it is too
  /// big, only the first 4 items will be used.  If it is too small,
  /// uninitialized elements will be filled in with the
  /// corresponding elements from an identity matrix.
  ///
  GF_API
  explicit GfMatrix4f(const std::vector<double> &r0,
                      const std::vector<double> &r1,
                      const std::vector<double> &r2,
                      const std::vector<double> &r3);

  /// Constructor.  Initialize the matrix from 4 row vectors of
  /// float.  Each vector is expected to length 4.  If it is too
  /// big, only the first 4 items will be used.  If it is too small,
  /// uninitialized elements will be filled in with the
  /// corresponding elements from an identity matrix.
  ///
  GF_API
  explicit GfMatrix4f(const std::vector<float> &r0,
                      const std::vector<float> &r1,
                      const std::vector<float> &r2,
                      const std::vector<float> &r3);

  /// Constructor. Initializes a transformation matrix to perform the
  /// indicated rotation and translation.
  GF_API
  GfMatrix4f(const GfRotation &rotate, const GfVec3f &translate);

  /// Constructor. Initializes a transformation matrix to perform the
  /// indicated rotation and translation.
  GF_API
  GfMatrix4f(const GfMatrix3f &rotmx, const GfVec3f &translate);
  /// This explicit constructor converts a "double" matrix to a "float" matrix.
  GF_API
  explicit GfMatrix4f(const class GfMatrix4d &m);

  /// Sets a row of the matrix from a Vec4.
  void SetRow(int i, const GfVec4f &v)
  {
    _mtx[i][0] = v[0];
    _mtx[i][1] = v[1];
    _mtx[i][2] = v[2];
    _mtx[i][3] = v[3];
  }

  /// Sets a column of the matrix from a Vec4.
  void SetColumn(int i, const GfVec4f &v)
  {
    _mtx[0][i] = v[0];
    _mtx[1][i] = v[1];
    _mtx[2][i] = v[2];
    _mtx[3][i] = v[3];
  }

  /// Gets a row of the matrix as a Vec4.
  GfVec4f GetRow(int i) const
  {
    return GfVec4f(_mtx[i][0], _mtx[i][1], _mtx[i][2], _mtx[i][3]);
  }

  /// Gets a column of the matrix as a Vec4.
  GfVec4f GetColumn(int i) const
  {
    return GfVec4f(_mtx[0][i], _mtx[1][i], _mtx[2][i], _mtx[3][i]);
  }

  /// Sets the matrix from 16 independent \c float values,
  /// specified in row-major order. For example, parameter \e m10 specifies
  /// the value in row 1 and column 0.
  GfMatrix4f &Set(float m00,
                  float m01,
                  float m02,
                  float m03,
                  float m10,
                  float m11,
                  float m12,
                  float m13,
                  float m20,
                  float m21,
                  float m22,
                  float m23,
                  float m30,
                  float m31,
                  float m32,
                  float m33)
  {
    _mtx[0][0] = m00;
    _mtx[0][1] = m01;
    _mtx[0][2] = m02;
    _mtx[0][3] = m03;
    _mtx[1][0] = m10;
    _mtx[1][1] = m11;
    _mtx[1][2] = m12;
    _mtx[1][3] = m13;
    _mtx[2][0] = m20;
    _mtx[2][1] = m21;
    _mtx[2][2] = m22;
    _mtx[2][3] = m23;
    _mtx[3][0] = m30;
    _mtx[3][1] = m31;
    _mtx[3][2] = m32;
    _mtx[3][3] = m33;
    return *this;
  }

  /// Sets the matrix from a 4x4 array of \c float
  /// values, specified in row-major order.
  GfMatrix4f &Set(const float m[4][4])
  {
    _mtx[0][0] = m[0][0];
    _mtx[0][1] = m[0][1];
    _mtx[0][2] = m[0][2];
    _mtx[0][3] = m[0][3];
    _mtx[1][0] = m[1][0];
    _mtx[1][1] = m[1][1];
    _mtx[1][2] = m[1][2];
    _mtx[1][3] = m[1][3];
    _mtx[2][0] = m[2][0];
    _mtx[2][1] = m[2][1];
    _mtx[2][2] = m[2][2];
    _mtx[2][3] = m[2][3];
    _mtx[3][0] = m[3][0];
    _mtx[3][1] = m[3][1];
    _mtx[3][2] = m[3][2];
    _mtx[3][3] = m[3][3];
    return *this;
  }

  /// Sets the matrix to the identity matrix.
  GfMatrix4f &SetIdentity()
  {
    return SetDiagonal(1);
  }

  /// Sets the matrix to zero.
  GfMatrix4f &SetZero()
  {
    return SetDiagonal(0);
  }

  /// Sets the matrix to \e s times the identity matrix.
  GF_API
  GfMatrix4f &SetDiagonal(float s);

  /// Sets the matrix to have diagonal (<c>v[0], v[1], v[2], v[3]</c>).
  GF_API
  GfMatrix4f &SetDiagonal(const GfVec4f &);

  /// Fills a 4x4 array of \c float values with the values in
  /// the matrix, specified in row-major order.
  GF_API
  float *Get(float m[4][4]) const;

  /// Returns raw access to components of matrix as an array of
  /// \c float values.  Components are in row-major order.
  float *data()
  {
    return _mtx.GetData();
  }

  /// Returns const raw access to components of matrix as an array of
  /// \c float values.  Components are in row-major order.
  const float *data() const
  {
    return _mtx.GetData();
  }

  /// Returns vector components as an array of \c float values.
  float *GetArray()
  {
    return _mtx.GetData();
  }

  /// Returns vector components as a const array of \c float values.
  const float *GetArray() const
  {
    return _mtx.GetData();
  }

  /// Accesses an indexed row \e i of the matrix as an array of 4 \c
  /// float values so that standard indexing (such as <c>m[0][1]</c>)
  /// works correctly.
  float *operator[](int i)
  {
    return _mtx[i];
  }

  /// Accesses an indexed row \e i of the matrix as an array of 4 \c
  /// float values so that standard indexing (such as <c>m[0][1]</c>)
  /// works correctly.
  const float *operator[](int i) const
  {
    return _mtx[i];
  }

  /// Hash.
  friend inline size_t hash_value(GfMatrix4f const &m)
  {
    return TfHash::Combine(m._mtx[0][0],
                           m._mtx[0][1],
                           m._mtx[0][2],
                           m._mtx[0][3],
                           m._mtx[1][0],
                           m._mtx[1][1],
                           m._mtx[1][2],
                           m._mtx[1][3],
                           m._mtx[2][0],
                           m._mtx[2][1],
                           m._mtx[2][2],
                           m._mtx[2][3],
                           m._mtx[3][0],
                           m._mtx[3][1],
                           m._mtx[3][2],
                           m._mtx[3][3]);
  }

  /// Tests for element-wise matrix equality. All elements must match
  /// exactly for matrices to be considered equal.
  GF_API
  bool operator==(const GfMatrix4d &m) const;

  /// Tests for element-wise matrix equality. All elements must match
  /// exactly for matrices to be considered equal.
  GF_API
  bool operator==(const GfMatrix4f &m) const;

  /// Tests for element-wise matrix inequality. All elements must match
  /// exactly for matrices to be considered equal.
  bool operator!=(const GfMatrix4d &m) const
  {
    return !(*this == m);
  }

  /// Tests for element-wise matrix inequality. All elements must match
  /// exactly for matrices to be considered equal.
  bool operator!=(const GfMatrix4f &m) const
  {
    return !(*this == m);
  }

  /// Returns the transpose of the matrix.
  GF_API
  GfMatrix4f GetTranspose() const;

  /// Returns the inverse of the matrix, or FLT_MAX * SetIdentity() if the
  /// matrix is singular. (FLT_MAX is the largest value a \c float can have,
  /// as defined by the system.) The matrix is considered singular if the
  /// determinant is less than or equal to the optional parameter \e eps. If
  /// \e det is non-null, <c>*det</c> is set to the determinant.
  GF_API
  GfMatrix4f GetInverse(double *det = NULL, double eps = 0) const;

  /// Returns the determinant of the matrix.
  GF_API
  double GetDeterminant() const;

  /// Sets a row of the matrix from a Vec3.
  /// The fourth element of the row is ignored.
  void SetRow3(int i, const GfVec3f &v)
  {
    _mtx[i][0] = v[0];
    _mtx[i][1] = v[1];
    _mtx[i][2] = v[2];
  }

  /// Gets a row of the matrix as a Vec3.
  GfVec3f GetRow3(int i) const
  {
    return GfVec3f(_mtx[i][0], _mtx[i][1], _mtx[i][2]);
  }

  /// Returns the determinant of the upper 3x3 matrix. This method is useful
  /// when the matrix describes a linear transformation such as a rotation or
  /// scale because the other values in the 4x4 matrix are not important.
  double GetDeterminant3() const
  {
    return _GetDeterminant3(0, 1, 2, 0, 1, 2);
  }

  /// Returns true, if the row vectors of the upper 3x3 matrix form an
  /// orthogonal basis. Note they do not have to be unit length for this
  /// test to return true.
  bool HasOrthogonalRows3() const
  {
    // XXX Should add GfAreOrthogonal(v0, v1, v2) (which also
    //     GfRotation::Decompose() could use).
    GfVec3f axis0(GetRow3(0)), axis1(GetRow3(1)), axis2(GetRow3(2));
    return (GfAbs(GfDot(axis0, axis1)) < GF_MIN_ORTHO_TOLERANCE &&
            GfAbs(GfDot(axis0, axis2)) < GF_MIN_ORTHO_TOLERANCE &&
            GfAbs(GfDot(axis1, axis2)) < GF_MIN_ORTHO_TOLERANCE);
  }

  /// Makes the matrix orthonormal in place. This is an iterative method
  /// that is much more stable than the previous cross/cross method.  If the
  /// iterative method does not converge, a warning is issued.
  ///
  /// Returns true if the iteration converged, false otherwise.  Leaves any
  /// translation part of the matrix unchanged.  If \a issueWarning is true,
  /// this method will issue a warning if the iteration does not converge,
  /// otherwise it will be silent.
  GF_API
  bool Orthonormalize(bool issueWarning = true);

  /// Returns an orthonormalized copy of the matrix.
  GF_API
  GfMatrix4f GetOrthonormalized(bool issueWarning = true) const;

  /// Returns the sign of the determinant of the upper 3x3 matrix, i.e. 1
  /// for a right-handed matrix, -1 for a left-handed matrix, and 0 for a
  /// singular matrix.
  GF_API
  double GetHandedness() const;

  /// Returns true if the vectors in the upper 3x3 matrix form a
  /// right-handed coordinate system.
  bool IsRightHanded() const
  {
    return GetHandedness() == 1.0;
  }

  /// Returns true if the vectors in the upper 3x3 matrix form a left-handed
  /// coordinate system.
  bool IsLeftHanded() const
  {
    return GetHandedness() == -1.0;
  }

  /// Post-multiplies matrix \e m into this matrix.
  GF_API
  GfMatrix4f &operator*=(const GfMatrix4f &m);

  /// Multiplies the matrix by a float.
  GF_API
  GfMatrix4f &operator*=(double);

  /// Returns the product of a matrix and a float.
  friend GfMatrix4f operator*(const GfMatrix4f &m1, double d)
  {
    GfMatrix4f m = m1;
    return m *= d;
  }

  ///
  // Returns the product of a matrix and a float.
  friend GfMatrix4f operator*(double d, const GfMatrix4f &m)
  {
    return m * d;
  }

  /// Adds matrix \e m to this matrix.
  GF_API
  GfMatrix4f &operator+=(const GfMatrix4f &m);

  /// Subtracts matrix \e m from this matrix.
  GF_API
  GfMatrix4f &operator-=(const GfMatrix4f &m);

  /// Returns the unary negation of matrix \e m.
  GF_API
  friend GfMatrix4f operator-(const GfMatrix4f &m);

  /// Adds matrix \e m2 to \e m1
  friend GfMatrix4f operator+(const GfMatrix4f &m1, const GfMatrix4f &m2)
  {
    GfMatrix4f tmp(m1);
    tmp += m2;
    return tmp;
  }

  /// Subtracts matrix \e m2 from \e m1.
  friend GfMatrix4f operator-(const GfMatrix4f &m1, const GfMatrix4f &m2)
  {
    GfMatrix4f tmp(m1);
    tmp -= m2;
    return tmp;
  }

  /// Multiplies matrix \e m1 by \e m2.
  friend GfMatrix4f operator*(const GfMatrix4f &m1, const GfMatrix4f &m2)
  {
    GfMatrix4f tmp(m1);
    tmp *= m2;
    return tmp;
  }

  /// Divides matrix \e m1 by \e m2 (that is, <c>m1 * inv(m2)</c>).
  friend GfMatrix4f operator/(const GfMatrix4f &m1, const GfMatrix4f &m2)
  {
    return (m1 * m2.GetInverse());
  }

  /// Returns the product of a matrix \e m and a column vector \e vec.
  friend inline GfVec4f operator*(const GfMatrix4f &m, const GfVec4f &vec)
  {
    return GfVec4f(vec[0] * m._mtx[0][0] + vec[1] * m._mtx[0][1] + vec[2] * m._mtx[0][2] +
                       vec[3] * m._mtx[0][3],
                   vec[0] * m._mtx[1][0] + vec[1] * m._mtx[1][1] + vec[2] * m._mtx[1][2] +
                       vec[3] * m._mtx[1][3],
                   vec[0] * m._mtx[2][0] + vec[1] * m._mtx[2][1] + vec[2] * m._mtx[2][2] +
                       vec[3] * m._mtx[2][3],
                   vec[0] * m._mtx[3][0] + vec[1] * m._mtx[3][1] + vec[2] * m._mtx[3][2] +
                       vec[3] * m._mtx[3][3]);
  }

  /// Returns the product of row vector \e vec and a matrix \e m.
  friend inline GfVec4f operator*(const GfVec4f &vec, const GfMatrix4f &m)
  {
    return GfVec4f(vec[0] * m._mtx[0][0] + vec[1] * m._mtx[1][0] + vec[2] * m._mtx[2][0] +
                       vec[3] * m._mtx[3][0],
                   vec[0] * m._mtx[0][1] + vec[1] * m._mtx[1][1] + vec[2] * m._mtx[2][1] +
                       vec[3] * m._mtx[3][1],
                   vec[0] * m._mtx[0][2] + vec[1] * m._mtx[1][2] + vec[2] * m._mtx[2][2] +
                       vec[3] * m._mtx[3][2],
                   vec[0] * m._mtx[0][3] + vec[1] * m._mtx[1][3] + vec[2] * m._mtx[2][3] +
                       vec[3] * m._mtx[3][3]);
  }

  /// Sets matrix to specify a uniform scaling by \e scaleFactor.
  GF_API
  GfMatrix4f &SetScale(float scaleFactor);

  /// Returns the matrix with any scaling or shearing removed,
  /// leaving only the rotation and translation.
  /// If the matrix cannot be decomposed, returns the original matrix.
  GF_API
  GfMatrix4f RemoveScaleShear() const;

  /// \name 3D Transformation Utilities
  /// @{

  /// Sets the matrix to specify a rotation equivalent to \e rot,
  /// and clears the translation.
  GF_API
  GfMatrix4f &SetRotate(const GfQuatf &rot);

  /// Sets the matrix to specify a rotation equivalent to \e rot,
  /// without clearing the translation.
  GF_API
  GfMatrix4f &SetRotateOnly(const GfQuatf &rot);

  /// Sets the matrix to specify a rotation equivalent to \e rot,
  /// and clears the translation.
  GF_API
  GfMatrix4f &SetRotate(const GfRotation &rot);

  /// Sets the matrix to specify a rotation equivalent to \e rot,
  /// without clearing the translation.
  GF_API
  GfMatrix4f &SetRotateOnly(const GfRotation &rot);

  /// Sets the matrix to specify a rotation equivalent to \e mx,
  /// and clears the translation.
  GF_API
  GfMatrix4f &SetRotate(const GfMatrix3f &mx);

  /// Sets the matrix to specify a rotation equivalent to \e mx,
  /// without clearing the translation.
  GF_API
  GfMatrix4f &SetRotateOnly(const GfMatrix3f &mx);

  /// Sets the matrix to specify a nonuniform scaling in x, y, and z by
  /// the factors in vector \e scaleFactors.
  GF_API
  GfMatrix4f &SetScale(const GfVec3f &scaleFactors);

  /// Sets matrix to specify a translation by the vector \e trans,
  /// and clears the rotation.
  GF_API
  GfMatrix4f &SetTranslate(const GfVec3f &trans);

  /// Sets matrix to specify a translation by the vector \e trans,
  /// without clearing the rotation.
  GF_API
  GfMatrix4f &SetTranslateOnly(const GfVec3f &t);

  /// Sets matrix to specify a rotation by \e rotate and a
  /// translation by \e translate.
  GF_API
  GfMatrix4f &SetTransform(const GfRotation &rotate, const GfVec3f &translate);

  /// Sets matrix to specify a rotation by \e rotmx and a
  /// translation by \e translate.
  GF_API
  GfMatrix4f &SetTransform(const GfMatrix3f &rotmx, const GfVec3f &translate);

  /// Sets the matrix to specify a viewing matrix from parameters
  /// similar to those used by <c>gluLookAt(3G)</c>. \e eyePoint
  /// represents the eye point in world space. \e centerPoint
  /// represents the world-space center of attention. \e upDirection
  /// is a vector indicating which way is up.
  GF_API
  GfMatrix4f &SetLookAt(const GfVec3f &eyePoint,
                        const GfVec3f &centerPoint,
                        const GfVec3f &upDirection);

  /// Sets the matrix to specify a viewing matrix from a world-space
  /// \e eyePoint and a world-space rotation that rigidly rotates the
  /// orientation from its canonical frame, which is defined to be
  /// looking along the <c>-z</c> axis with the <c>+y</c> axis as the up
  /// direction.
  GF_API
  GfMatrix4f &SetLookAt(const GfVec3f &eyePoint, const GfRotation &orientation);

  /// Factors the matrix into 5 components:
  /// \li <c>\e M = r * s * -r * u * t</c>
  /// where
  /// \li \e t is a translation.
  /// \li \e u and \e r are rotations, and \e -r is the transpose
  ///     (inverse) of \e r. The \e u matrix may contain shear
  ///     information.
  /// \li \e s is a scale.
  /// Any projection information could be returned in matrix \e p,
  /// but currently p is never modified.
  ///
  /// Returns \c false if the matrix is singular (as determined by \e eps).
  /// In that case, any zero scales in \e s are clamped to \e eps
  /// to allow computation of \e u.
  GF_API
  bool Factor(
      GfMatrix4f *r, GfVec3f *s, GfMatrix4f *u, GfVec3f *t, GfMatrix4f *p, float eps = 1e-5) const;

  /// Returns the translation part of the matrix, defined as the first three
  /// elements of the last row.
  GfVec3f ExtractTranslation() const
  {
    return GfVec3f(_mtx[3][0], _mtx[3][1], _mtx[3][2]);
  }

  /// Returns the rotation corresponding to this matrix. This works well
  /// only if the matrix represents a rotation.
  ///
  /// For good results, consider calling Orthonormalize() before calling
  /// this method.
  GF_API
  GfRotation ExtractRotation() const;

  /// Return the rotation corresponding to this matrix as a quaternion.
  /// This works well only if the matrix represents a rotation.
  ///
  /// For good results, consider calling Orthonormalize() before calling
  /// this method.
  GF_API
  GfQuatf ExtractRotationQuat() const;

  /// Decompose the rotation corresponding to this matrix about 3 orthogonal
  /// axes.  If the axes are not orthogonal, warnings will be spewed.
  ///
  /// This is a convenience method that is equivalent to calling
  /// ExtractRotation().Decompose().
  GF_API
  GfVec3f DecomposeRotation(const GfVec3f &axis0,
                            const GfVec3f &axis1,
                            const GfVec3f &axis2) const;

  /// Returns the rotation corresponding to this matrix. This works well
  /// only if the matrix represents a rotation.
  ///
  /// For good results, consider calling Orthonormalize() before calling
  /// this method.
  GF_API
  GfMatrix3f ExtractRotationMatrix() const;

  /// Transforms the row vector \e vec by the matrix, returning the result.
  /// This treats the vector as a 4-component vector whose fourth component
  /// is 1.
  GfVec3d Transform(const GfVec3d &vec) const
  {
    return GfProject(
        GfVec4d(vec[0] * _mtx[0][0] + vec[1] * _mtx[1][0] + vec[2] * _mtx[2][0] + _mtx[3][0],
                vec[0] * _mtx[0][1] + vec[1] * _mtx[1][1] + vec[2] * _mtx[2][1] + _mtx[3][1],
                vec[0] * _mtx[0][2] + vec[1] * _mtx[1][2] + vec[2] * _mtx[2][2] + _mtx[3][2],
                vec[0] * _mtx[0][3] + vec[1] * _mtx[1][3] + vec[2] * _mtx[2][3] + _mtx[3][3]));
  }

  /// Transforms the row vector \e vec by the matrix, returning the result.
  /// This treats the vector as a 4-component vector whose fourth component
  /// is 1. This is an overloaded method; it differs from the other version
  /// in that it returns a different value type.
  GfVec3f Transform(const GfVec3f &vec) const
  {
    return (GfProject(
        GfVec4f(vec[0] * _mtx[0][0] + vec[1] * _mtx[1][0] + vec[2] * _mtx[2][0] + _mtx[3][0],
                vec[0] * _mtx[0][1] + vec[1] * _mtx[1][1] + vec[2] * _mtx[2][1] + _mtx[3][1],
                vec[0] * _mtx[0][2] + vec[1] * _mtx[1][2] + vec[2] * _mtx[2][2] + _mtx[3][2],
                vec[0] * _mtx[0][3] + vec[1] * _mtx[1][3] + vec[2] * _mtx[2][3] + _mtx[3][3])));
  }

  /// Transforms row vector \e vec by the matrix, returning the result. This
  /// treats the vector as a direction vector, so the translation
  /// information in the matrix is ignored. That is, it treats the vector as
  /// a 4-component vector whose fourth component is 0.
  GfVec3d TransformDir(const GfVec3d &vec) const
  {
    return GfVec3d(vec[0] * _mtx[0][0] + vec[1] * _mtx[1][0] + vec[2] * _mtx[2][0],
                   vec[0] * _mtx[0][1] + vec[1] * _mtx[1][1] + vec[2] * _mtx[2][1],
                   vec[0] * _mtx[0][2] + vec[1] * _mtx[1][2] + vec[2] * _mtx[2][2]);
  }

  /// Transforms row vector \e vec by the matrix, returning the result. This
  /// treats the vector as a direction vector, so the translation
  /// information in the matrix is ignored. That is, it treats the vector as
  /// a 4-component vector whose fourth component is 0.  This is an
  /// overloaded method; it differs from the other version in that it
  /// returns a different value type.
  GfVec3f TransformDir(const GfVec3f &vec) const
  {
    return GfVec3f(vec[0] * _mtx[0][0] + vec[1] * _mtx[1][0] + vec[2] * _mtx[2][0],
                   vec[0] * _mtx[0][1] + vec[1] * _mtx[1][1] + vec[2] * _mtx[2][1],
                   vec[0] * _mtx[0][2] + vec[1] * _mtx[1][2] + vec[2] * _mtx[2][2]);
  }

  /// Transforms the row vector \e vec by the matrix, returning the result.
  /// This treats the vector as a 4-component vector whose fourth component
  /// is 1 and ignores the fourth column of the matrix (i.e. assumes it is
  /// (0, 0, 0, 1)).
  GfVec3d TransformAffine(const GfVec3d &vec) const
  {
    return GfVec3d(vec[0] * _mtx[0][0] + vec[1] * _mtx[1][0] + vec[2] * _mtx[2][0] + _mtx[3][0],
                   vec[0] * _mtx[0][1] + vec[1] * _mtx[1][1] + vec[2] * _mtx[2][1] + _mtx[3][1],
                   vec[0] * _mtx[0][2] + vec[1] * _mtx[1][2] + vec[2] * _mtx[2][2] + _mtx[3][2]);
  }

  /// Transforms the row vector \e vec by the matrix, returning the result.
  /// This treats the vector as a 4-component vector whose fourth component
  /// is 1 and ignores the fourth column of the matrix (i.e. assumes it is
  /// (0, 0, 0, 1)).
  GfVec3f TransformAffine(const GfVec3f &vec) const
  {
    return GfVec3f(vec[0] * _mtx[0][0] + vec[1] * _mtx[1][0] + vec[2] * _mtx[2][0] + _mtx[3][0],
                   vec[0] * _mtx[0][1] + vec[1] * _mtx[1][1] + vec[2] * _mtx[2][1] + _mtx[3][1],
                   vec[0] * _mtx[0][2] + vec[1] * _mtx[1][2] + vec[2] * _mtx[2][2] + _mtx[3][2]);
  }
  /// @}

 private:
  /// Returns the determinant of the 3x3 submatrix specified by the three
  /// given row and column indices (0-3 for each).
  GF_API
  double _GetDeterminant3(
      size_t row1, size_t row2, size_t row3, size_t col1, size_t col2, size_t col3) const;

  /// Diagonalizes the upper 3x3 matrix of a matrix known to be symmetric.
  void _Jacobi3(GfVec3d *eigenvalues, GfVec3d eigenvectors[3]) const;

  /// Set the 3x3 submatrix to the rotation given by a quaternion,
  /// defined by the real component \p r and imaginary components \p i.
  void _SetRotateFromQuat(float r, const GfVec3f &i);

 private:
  /// Matrix storage, in row-major order.
  GfMatrixData<float, 4, 4> _mtx;

  // Friend declarations
  friend class GfMatrix4d;
};

/// Tests for equality within a given tolerance, returning \c true if the
/// difference between each component of the matrix is less than or equal
/// to \p tolerance, or false otherwise.
GF_API
bool GfIsClose(GfMatrix4f const &m1, GfMatrix4f const &m2, double tolerance);

/// Output a GfMatrix4f
/// \ingroup group_gf_DebuggingOutput
GF_API std::ostream &operator<<(std::ostream &, GfMatrix4f const &);

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_BASE_GF_MATRIX4F_H
