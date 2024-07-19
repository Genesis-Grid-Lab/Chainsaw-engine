#pragma once
#include "ECS.h"
#include "Common/YAML.h"

namespace CSE
{
    struct DataSerializer
    {
        CSE_INLINE void Serialize(EntityRegistry& scene, const std::string& path)
        {
            YAML::Emitter emitter;

            emitter << YAML::BeginMap;
            {
                /*scene.
                scene.each([&] (Entity entt)
                    {

                    });*/
            }
        }
    };
}
