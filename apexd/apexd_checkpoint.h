/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_APEXD_APEXD_CHECKPOINT_H_
#define ANDROID_APEXD_APEXD_CHECKPOINT_H_

#include <string>

#include "status_or.h"

namespace android {
namespace apex {

class CheckpointInterface {
 public:
  virtual ~CheckpointInterface() {}

  virtual StatusOr<bool> SupportsFsCheckpoints() = 0;

  virtual StatusOr<bool> NeedsCheckpoint() = 0;
  virtual StatusOr<bool> NeedsRollback() = 0;
  virtual Status StartCheckpoint(int32_t numRetries) = 0;

  virtual Status AbortChanges(const std::string& msg, bool retry) = 0;
};

}  // namespace apex
}  // namespace android

#endif  // ANDROID_APEXD_APEXD_CHECKPOINT_H_
