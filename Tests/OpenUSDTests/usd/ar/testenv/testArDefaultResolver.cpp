//
// Copyright 2018 Pixar
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
#include "pxr/pxr.h"

#include "pxr/usd/ar/asset.h"
#include "pxr/usd/ar/filesystemAsset.h"
#include "pxr/usd/ar/resolvedPath.h"
#include "pxr/usd/ar/resolver.h"
#include "pxr/base/tf/diagnostic.h"
#include "Arch/fileSystem.h"
#include "Arch/systemInfo.h"

PXR_NAMESPACE_USING_DIRECTIVE;

static void
TestOpenAsset()
{
  // Write some content out to a temporary file in the current
  // working directory.
  std::string tmpPath;
  int fd = ArchMakeTmpFile(
      ArchGetCwd(), "testArDefaultResolver_CPP", &tmpPath);
  TF_AXIOM(fd != -1);

  FILE *tmpFile = ArchFdOpen(fd, "w");
  TF_AXIOM(tmpFile);

  const std::string contents =
      "Test file generated by testArDefaultResolver_CPP";
  fputs(contents.c_str(), tmpFile);
  fclose(tmpFile);

  // Now, try to open it via ArResolver::OpenAsset and check
  // that the contents are what we expect.
  std::shared_ptr<ArAsset> asset =
      ArGetResolver().OpenAsset(ArResolvedPath(tmpPath));
  TF_AXIOM(asset);
  TF_AXIOM(dynamic_cast<ArFilesystemAsset *>(asset.get()));

  const size_t assetSize = asset->GetSize();
  TF_AXIOM(assetSize ==
           static_cast<size_t>(ArchGetFileLength(tmpPath.c_str())));
  TF_AXIOM(assetSize == contents.length());

  std::shared_ptr<const char> buffer = asset->GetBuffer();
  TF_AXIOM(buffer);
  TF_AXIOM(std::string(buffer.get(), assetSize) == contents);

  std::unique_ptr<char[]> array(new char[assetSize]);
  TF_AXIOM(asset->Read(array.get(), assetSize, 0) == assetSize);
  TF_AXIOM(std::string(array.get(), assetSize) == contents);

  TF_AXIOM(asset->Read(array.get(), /* count */ 5, /* offset */ 10) == 5);
  TF_AXIOM(std::string(array.get(), 5) == contents.substr(10, 5));

  TF_AXIOM(asset->GetFileUnsafe().first != nullptr);
  TF_AXIOM(asset->GetFileUnsafe().second == 0);

  // Clean up the temporary file.
  ArchUnlinkFile(tmpPath.c_str());
}

int main(int argc, char **argv)
{
  // Set the preferred resolver to ArDefaultResolver before
  // running any test cases.
  ArSetPreferredResolver("ArDefaultResolver");

  printf("TestOpenAsset...\n");
  TestOpenAsset();

  printf("Passed!\n");

  return EXIT_SUCCESS;
  ;
}
