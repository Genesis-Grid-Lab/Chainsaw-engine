#pragma once
#include "Core.h"
#include "yaml-cpp/emittermanip.h"
#include <yaml-cpp/yaml.h>

namespace YAML
{
    template<>
    struct convert<Vector3>
    {
        CSE_INLINE static Node encode(const Vector3 &rhs)
        {
            Node node;
            node.push_back(rhs.x);
            node.push_back(rhs.y);
            node.push_back(rhs.z);
            node.SetStyle(EmitterStyle::Flow);
            return node;
        }

        CSE_INLINE static bool decode(const Node &node, Vector3 &rhs)
        {
            if(!node.IsSequence() || node.size() != 3)
            {
                return false;
            }

            rhs.x = node[0].as<float>();
            rhs.y = node[1].as<float>();
            rhs.z = node[2].as<float>();

            return true;
        }
    };

    // stream operator
    CSE_INLINE Emitter &operator << (Emitter &emitter, const Vector3 &v)
    {
        emitter << Flow;
        emitter << BeginSeq << v.x << v.y << v.z << EndSeq;
        return emitter;
    }
}
