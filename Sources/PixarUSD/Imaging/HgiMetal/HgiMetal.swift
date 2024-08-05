/* ----------------------------------------------------------------
 * :: :  M  E  T  A  V  E  R  S  E  :                            ::
 * ----------------------------------------------------------------
 * Licensed under the terms set forth in the LICENSE.txt file, this
 * file is available at https://openusd.org/license.
 *
 *                                        Copyright (C) 2016 Pixar.
 *         Copyright (C) 2024 Wabi Foundation. All Rights Reserved.
 * ----------------------------------------------------------------
 *  . x x x . o o o . x x x . : : : .    o  x  o    . : : : .
 * ---------------------------------------------------------------- */

#if canImport(Metal)
  import CosmoGraph
  import HgiMetal

  public enum HgiMetal
  {
    public static func createHgi() -> Pixar.HgiMetalPtr
    {
      Pixar.HgiMetal.CreateHgi()
    }
  }

  public extension Pixar.HgiMetal
  {
    var apiVersion: Int
    {
      Int(GetAPIVersion())
    }

    private borrowing func GetPrimaryDeviceCopy() -> MTL.Device
    {
      GetPrimaryDevice()
    }

    var device: MTL.Device
    {
      GetPrimaryDeviceCopy()
    }
  }

  public extension Pixar.HgiMetalPtr
  {
    var apiVersion: Int
    {
      pointee.apiVersion
    }

    var device: MTL.Device
    {
      pointee.device
    }
  }
#endif /* canImport(Metal) */
