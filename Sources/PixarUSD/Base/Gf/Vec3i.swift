/* ----------------------------------------------------------------
 * :: :  M  E  T  A  V  E  R  S  E  :                            ::
 * ----------------------------------------------------------------
 * This software is Licensed under the terms of the Apache License,
 * version 2.0 (the "Apache License") with the following additional
 * modification; you may not use this file except within compliance
 * of the Apache License and the following modification made to it.
 * Section 6. Trademarks. is deleted and replaced with:
 *
 * Trademarks. This License does not grant permission to use any of
 * its trade names, trademarks, service marks, or the product names
 * of this Licensor or its affiliates, except as required to comply
 * with Section 4(c.) of this License, and to reproduce the content
 * of the NOTICE file.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND without even an
 * implied warranty of MERCHANTABILITY, or FITNESS FOR A PARTICULAR
 * PURPOSE. See the Apache License for more details.
 *
 * You should have received a copy for this software license of the
 * Apache License along with this program; or, if not, please write
 * to the Free Software Foundation Inc., with the following address
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *         Copyright (C) 2024 Wabi Foundation. All Rights Reserved.
 * ----------------------------------------------------------------
 *  . x x x . o o o . x x x . : : : .    o  x  o    . : : : .
 * ---------------------------------------------------------------- */

import Gf

/* note: the typealiases are documented the same way twice,
 * keep it like this so that sourcekit shows documentation
 * regardless of which typealias a user might use in their
 * code. */

/**
 * # GfVec3i
 *
 * Basic type for a vector of 3 int components.
 *
 * Represents a vector of 3 components of type **int**.
 * It is intended to be fast and simple.
 */
public typealias GfVec3i = Pixar.GfVec3i

public extension Gf
{
  /**
   * # GfVec3i
   *
   * Basic type for a vector of 3 int components.
   *
   * Represents a vector of 3 components of type **int**.
   * It is intended to be fast and simple.
   */
  typealias Vec3i = GfVec3i
}

extension Gf.Vec3i: Scalar
{
  /// Axis count of the vector.
  public typealias AxisCount = Axis3

  /// Create a unit vector along the specified axis.
  public static func axis(_ axis: AxisCount) -> Self
  {
    switch axis
    {
      case .x:
        XAxis()

      case .y:
        YAxis()

      case .z:
        ZAxis()
    }
  }

  /// Set all elements with explicit arguments.
  public mutating func set(_ s0: Int32, _ s1: Int32, _ s2: Int32) -> Self
  {
    Set(s0, s1, s2).pointee
  }

  /// Set all elements with an array as the argument.
  public mutating func set(_ a: [ScalarType]) -> Self
  {
    Set(a).pointee
  }

  /// Get the elements of this vector as an array.
  public func getArray() -> [ScalarType]
  {
    let buffer = UnsafeBufferPointer(start: GetArray(), count: GfVec3i.scalarCount)

    return Array(buffer)
  }

  /// Returns the projection of this vector onto **other**,
  /// that is:
  /// ```
  /// other * (self * other)
  /// ```
  public func getProjection(_ other: Self) -> Self
  {
    GetProjection(other)
  }

  /// Returns the orthogonal complement of this vector onto
  /// **other**, that is:
  /// ```
  ///  self - self.getProjection(b)
  /// ```
  public func getComplement(_ normal: Self) -> Self
  {
    GetComplement(normal)
  }

  /// Returns the squared length of this vector,
  /// that is:
  /// ```
  ///  self * self
  /// ```
  public func getLengthSq() -> Int32
  {
    GetLengthSq()
  }
}

extension Gf.Vec3i: SIMD
{
  public typealias Scalar = Self.ScalarType
  public typealias SIMDStorage = SIMD3<Scalar>
  public typealias MaskStorage = SIMD3<Scalar>.MaskStorage

  public var scalarCount: Int { 3 }

  public var simd: SIMD3<Scalar>
  {
    get
    {
      SIMD3<Scalar>(
        Scalar(data()[0]),
        Scalar(data()[1]),
        Scalar(data()[2])
      )
    }
    set
    {
      dataMutating()[0] = Scalar(newValue[0])
      dataMutating()[1] = Scalar(newValue[1])
      dataMutating()[2] = Scalar(newValue[2])
    }
  }

  public init(_ simd: SIMD3<Scalar>)
  {
    self.init()

    self.simd = simd
  }
}
