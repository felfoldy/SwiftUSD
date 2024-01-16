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

import Foundation
import Usd

public protocol Prim
{
  var path: Pixar.Sdf.Path { get }

  var name: Pixar.Tf.Token { get }

  var children: [any Prim] { get }
}

public struct UsdPrim
{
  public var path: Pixar.Sdf.Path
  public var type: PrimType
  public var children: [UsdPrim]

  public init(_ path: String, type: PrimType = .token(Pixar.Tf.Token()), @StageBuilder children: () -> [UsdPrim] = { [] })
  {
    self.path = Pixar.Sdf.Path("/\(path)")
    self.type = type
    self.children = children()
  }
}

extension UsdPrim: Equatable
{
  public static func == (lhs: UsdPrim, rhs: UsdPrim) -> Bool
  {
    lhs.path.string == rhs.path.string
  }
}

public extension UsdPrim
{
  enum PrimType
  {
    case basisCurves
    case hermiteCurves
    case nurbsCurves
    case nurbsPatch
    case boundable
    case imageable
    case mesh
    case pointBased
    case pointInstancer
    case points
    case plane
    case camera
    case capsule
    case cone
    case cube
    case curves
    case cylinder
    case sphere
    case scope
    case geomSubset
    case gprim
    case distantLight
    case diskLight
    case rectLight
    case sphereLight
    case cylinderLight
    case geometryLight
    case domeLight
    case portalLight
    case xform
    case xformable
    case xformCommonAPI
    case lightAPI
    case meshLightAPI
    case volumeLightAPI
    case motionAPI
    case primvarsAPI
    case geomModelAPI
    case visibilityAPI
    case token(Pixar.Tf.Token)
    case group([UsdPrim])
  }
}
