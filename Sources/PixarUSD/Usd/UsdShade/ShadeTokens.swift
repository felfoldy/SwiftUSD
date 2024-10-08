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

import UsdShade

public extension UsdShade
{
  /**
   * Private struct to hold the static
   * data for the UsdShade library. */
  private struct StaticData
  {
    static let shared = StaticData()
    private init()
    {}

    let tokens = Pixar.UsdShadeTokensType()
  }
}

public extension UsdShade
{
  /**
   * # UsdShade.Tokens
   *
   * ## Overview
   *
   * Public, client facing api to access
   * the static UsdShade tokens. */
  enum Tokens: CaseIterable
  {
    case allPurpose
    case bindMaterialAs
    case coordSys
    case coordSys_MultipleApplyTemplate_Binding
    case displacement
    case fallbackStrength
    case full
    case id
    case infoId
    case infoImplementationSource
    case inputs
    case interfaceOnly
    case materialBind
    case materialBinding
    case materialBindingCollection
    case materialVariant
    case outputs
    case outputsDisplacement
    case outputsSurface
    case outputsVolume
    case preview
    case sdrMetadata
    case sourceAsset
    case sourceCode
    case strongerThanDescendants
    case subIdentifier
    case surface
    case universalRenderContext
    case universalSourceType
    case volume
    case weakerThanDescendants
    case connectableAPI
    case coordSysAPI
    case material
    case materialBindingAPI
    case nodeDefAPI
    case nodeGraph
    case shader

    public func getToken() -> Tf.Token
    {
      switch self
      {
        case .allPurpose: StaticData.shared.tokens.allPurpose
        case .bindMaterialAs: StaticData.shared.tokens.bindMaterialAs
        case .coordSys: StaticData.shared.tokens.coordSys
        case .coordSys_MultipleApplyTemplate_Binding: StaticData.shared.tokens.coordSys_MultipleApplyTemplate_Binding
        case .displacement: StaticData.shared.tokens.displacement
        case .fallbackStrength: StaticData.shared.tokens.fallbackStrength
        case .full: StaticData.shared.tokens.full
        case .id: StaticData.shared.tokens.id
        case .infoId: StaticData.shared.tokens.infoId
        case .infoImplementationSource: StaticData.shared.tokens.infoImplementationSource
        case .inputs: StaticData.shared.tokens.inputs
        case .interfaceOnly: StaticData.shared.tokens.interfaceOnly
        case .materialBind: StaticData.shared.tokens.materialBind
        case .materialBinding: StaticData.shared.tokens.materialBinding
        case .materialBindingCollection: StaticData.shared.tokens.materialBindingCollection
        case .materialVariant: StaticData.shared.tokens.materialVariant
        case .outputs: StaticData.shared.tokens.outputs
        case .outputsDisplacement: StaticData.shared.tokens.outputsDisplacement
        case .outputsSurface: StaticData.shared.tokens.outputsSurface
        case .outputsVolume: StaticData.shared.tokens.outputsVolume
        case .preview: StaticData.shared.tokens.preview
        case .sdrMetadata: StaticData.shared.tokens.sdrMetadata
        case .sourceAsset: StaticData.shared.tokens.sourceAsset
        case .sourceCode: StaticData.shared.tokens.sourceCode
        case .strongerThanDescendants: StaticData.shared.tokens.strongerThanDescendants
        case .subIdentifier: StaticData.shared.tokens.subIdentifier
        case .surface: StaticData.shared.tokens.surface
        case .universalRenderContext: StaticData.shared.tokens.universalRenderContext
        case .universalSourceType: StaticData.shared.tokens.universalSourceType
        case .volume: StaticData.shared.tokens.volume
        case .weakerThanDescendants: StaticData.shared.tokens.weakerThanDescendants
        case .connectableAPI: StaticData.shared.tokens.ConnectableAPI
        case .coordSysAPI: StaticData.shared.tokens.CoordSysAPI
        case .material: StaticData.shared.tokens.Material
        case .materialBindingAPI: StaticData.shared.tokens.MaterialBindingAPI
        case .nodeDefAPI: StaticData.shared.tokens.NodeDefAPI
        case .nodeGraph: StaticData.shared.tokens.NodeGraph
        case .shader: StaticData.shared.tokens.Shader
      }
    }
  }
}
