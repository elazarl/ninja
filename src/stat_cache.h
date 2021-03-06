// Copyright 2011 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef NINJA_STAT_CACHE_H_
#define NINJA_STAT_CACHE_H_

#include <string>

#include "hash_map.h"

struct FileStat;

/// Mapping of path -> FileStat.
struct StatCache {
  FileStat* GetFile(const std::string& path);

  /// Dump the mapping to stdout (useful for debugging).
  void Dump();
  void Reload();

  typedef hash_map<std::string, FileStat*> Paths;
  Paths paths_;
};

#endif  // NINJA_STAT_CACHE_H_
