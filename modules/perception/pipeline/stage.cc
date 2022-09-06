/******************************************************************************
 * Copyright 2022 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/perception/pipeline/stage.h"

#include "modules/perception/pipeline/plugin_factory.h"


namespace apollo {
namespace perception {
namespace pipeline {


bool Stage::Initialize(const StageConfig& stage_config) {
  Clear();

  for (const auto& plugin_config : stage_config.plugin_config()) {
    plugin_config_map_[plugin_config.plugin_type()] = &plugin_config;
  }

  for (int i = 0; i < stage_config.plugin_config_size(); ++i) {
    auto plugin_type = stage_config.plugin_type(i);
    if (!common::util::ContainsKey(plugin_config_map_, plugin_type)) {
      AERROR << "Plugin type : " << PluginType_Name(plugin_type)
             << " has no config";
      return false;
    }

    Plugin* plugin_ptr = PluginFactory::CreatePlugin(stage_config);

    if (plugin_ptr == nullptr) {
      AERROR << "Create task type : " << PluginType_Name(plugin_type)
             << " failed!";
      return false;
    }
  }

  return true;
}

void Stage::Clear() {
  plugin_config_map_.clear();
}


} // namespace pipeline
} // namespace perception
} // namespace apollo
