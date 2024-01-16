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
import PackagePlugin

@main
struct UsdGenSchemaPlugin: CommandPlugin
{
  /// This entry point is called when operating on a Swift package.
  func performCommand(context: PluginContext, arguments: [String]) throws
  {
    let genSchema = try context.tool(named: "UsdGenSchema")

    try run(command: genSchema.path, with: arguments)
  }
}

#if canImport(XcodeProjectPlugin)
  import XcodeProjectPlugin

  extension UsdGenSchemaPlugin: XcodeCommandPlugin
  {
    /// This entry point is called when operating on an Xcode project.
    func performCommand(context: XcodePluginContext, arguments: [String]) throws
    {
      let genSchema = try context.tool(named: "UsdGenSchema")

      try run(command: genSchema.path, with: arguments)
    }
  }
#endif

extension UsdGenSchemaPlugin
{
  /// Run a command with the given arguments.
  func run(command: Path, with arguments: [String]) throws
  {
    let exec = URL(fileURLWithPath: command.string)

    let process = try Process.run(exec, arguments: arguments)
    process.waitUntilExit()

    // Check whether the subprocess invocation was successful.
    if process.terminationReason == .exit,
       process.terminationStatus == 0
    {
      print("UsdGenSchemaPlugin succesfully completed.")
    }
    else
    {
      let problem = "\(process.terminationReason):\(process.terminationStatus)"
      Diagnostics.error("UsdGenSchemaPlugin failed: \(problem)")
    }
  }
}
