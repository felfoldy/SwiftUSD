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

#include "pxr/base/tf/bitUtils.h"
#include "pxr/base/tf/diagnosticLite.h"
#include "pxr/base/tf/regTest.h"
#include "pxr/pxr.h"

#include "Arch/defines.h"

PXR_NAMESPACE_USING_DIRECTIVE

enum _TestEnum {
  Test0,
  Test1,
  Test2,
  Test3,
  Test4,
  Test5,
  Test6,
  Test7,
  Test8,
  Test9,
  Test10,
  Test11,
  Test12,
  Test13,
  Test14,
  Test15,
  Test16,
  Test17,
  Test18,
  Test65535 = 65535,
  Test65536 = 65536,
  Test65537 = 65537,
};

static bool TestTF_BITS_FOR_VALUES()
{
  TF_AXIOM(TF_BITS_FOR_VALUES(Test1) == 1);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test2) == 1);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test3) == 2);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test4) == 2);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test5) == 3);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test6) == 3);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test7) == 3);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test8) == 3);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test9) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test10) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test11) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test12) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test13) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test14) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test15) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test16) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test17) == 5);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test18) == 5);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test65535) == 16);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test65536) == 16);
  TF_AXIOM(TF_BITS_FOR_VALUES(Test65537) == 17);

  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test1) == 2);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test2) == 2);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test3) == 3);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test4) == 3);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test5) == 4);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test6) == 4);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test7) == 4);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test8) == 4);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test9) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test10) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test11) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test12) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test13) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test14) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test15) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test16) == 5);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test17) == 6);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test18) == 6);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test65535) == 17);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test65536) == 17);
  TF_AXIOM(TF_BITS_FOR_ENUM_VALUES(Test65537) == 18);

  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000001ULL) == 1);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000002ULL) == 1);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000003ULL) == 2);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000004ULL) == 2);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000005ULL) == 3);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000008ULL) == 3);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000009ULL) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000010ULL) == 4);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000011ULL) == 5);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000020ULL) == 5);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000021ULL) == 6);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000040ULL) == 6);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000041ULL) == 7);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000080ULL) == 7);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000081ULL) == 8);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000100ULL) == 8);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000101ULL) == 9);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000200ULL) == 9);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000201ULL) == 10);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000400ULL) == 10);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000401ULL) == 11);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000800ULL) == 11);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000000801ULL) == 12);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000001000ULL) == 12);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000001001ULL) == 13);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000002000ULL) == 13);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000002001ULL) == 14);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000004000ULL) == 14);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000004001ULL) == 15);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000008000ULL) == 15);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000008001ULL) == 16);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000010000ULL) == 16);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000010001ULL) == 17);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000020000ULL) == 17);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000020001ULL) == 18);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000040000ULL) == 18);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000040001ULL) == 19);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000080000ULL) == 19);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000080001ULL) == 20);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000100000ULL) == 20);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000100001ULL) == 21);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000200000ULL) == 21);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000200001ULL) == 22);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000400000ULL) == 22);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000400001ULL) == 23);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000800000ULL) == 23);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000000800001ULL) == 24);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000001000000ULL) == 24);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000001000001ULL) == 25);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000002000000ULL) == 25);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000002000001ULL) == 26);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000004000000ULL) == 26);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000004000001ULL) == 27);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000008000000ULL) == 27);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000008000001ULL) == 28);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000010000000ULL) == 28);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000010000001ULL) == 29);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000020000000ULL) == 29);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000020000001ULL) == 30);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000040000000ULL) == 30);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000040000001ULL) == 31);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000080000000ULL) == 31);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000080000001ULL) == 32);
#ifdef ARCH_BITS_64
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000100000000ULL) == 32);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000100000001ULL) == 33);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000200000000ULL) == 33);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000200000001ULL) == 34);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000400000000ULL) == 34);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000400000001ULL) == 35);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000800000000ULL) == 35);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000000800000001ULL) == 36);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000001000000000ULL) == 36);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000001000000001ULL) == 37);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000002000000000ULL) == 37);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000002000000001ULL) == 38);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000004000000000ULL) == 38);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000004000000001ULL) == 39);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000008000000000ULL) == 39);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000008000000001ULL) == 40);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000010000000000ULL) == 40);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000010000000001ULL) == 41);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000020000000000ULL) == 41);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000020000000001ULL) == 42);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000040000000000ULL) == 42);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000040000000001ULL) == 43);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000080000000000ULL) == 43);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000080000000001ULL) == 44);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000100000000000ULL) == 44);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000100000000001ULL) == 45);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000200000000000ULL) == 45);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000200000000001ULL) == 46);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000400000000000ULL) == 46);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000400000000001ULL) == 47);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000800000000000ULL) == 47);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0000800000000001ULL) == 48);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0001000000000000ULL) == 48);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0001000000000001ULL) == 49);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0002000000000000ULL) == 49);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0002000000000001ULL) == 50);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0004000000000000ULL) == 50);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0004000000000001ULL) == 51);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0008000000000000ULL) == 51);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0008000000000001ULL) == 52);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0010000000000000ULL) == 52);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0010000000000001ULL) == 53);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0020000000000000ULL) == 53);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0020000000000001ULL) == 54);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0040000000000000ULL) == 54);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0040000000000001ULL) == 55);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0080000000000000ULL) == 55);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0080000000000001ULL) == 56);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0100000000000000ULL) == 56);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0100000000000001ULL) == 57);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0200000000000000ULL) == 57);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0200000000000001ULL) == 58);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0400000000000000ULL) == 58);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0400000000000001ULL) == 59);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0800000000000000ULL) == 59);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x0800000000000001ULL) == 60);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x1000000000000000ULL) == 60);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x1000000000000001ULL) == 61);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x2000000000000000ULL) == 61);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x2000000000000001ULL) == 62);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x4000000000000000ULL) == 62);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x4000000000000001ULL) == 63);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x8000000000000000ULL) == 63);
  TF_AXIOM(TF_BITS_FOR_VALUES(0x8000000000000001ULL) == 64);
#endif

  return true;
}

static bool Test_TfBitUtils()
{
  return TestTF_BITS_FOR_VALUES();
}

TF_ADD_REGTEST(TfBitUtils);
