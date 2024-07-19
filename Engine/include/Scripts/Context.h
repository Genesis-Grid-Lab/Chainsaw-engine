#pragma once
#include "Window/Window.h"
#include "Auxiliaries/ECS.h"

namespace CSE
{
    struct ScriptContext
    {
        CSE_INLINE ScriptContext(EntityRegistry* scene, AppWindow* window)
        {
            //import lua libraries
            m_Lua.open_libraries(sol::lib::base);

            // load chainsaw api module
            m_Lua.require_file("Inputs", "Resources/Scripts/Engine/Input.lua");
            m_Lua.require_file("Core", "Resources/Scripts/Engine/Core.lua");

            // runtime type identifiers
            m_Lua["TRANSFORM"] = TypeID<TransformComponent>();

            // add transform data type
            m_Lua.new_usertype<Transform3D>("Transform3D",
                "Translate", &Transform3D::Translate,
                "Rotation", &Transform3D::Rotation,
                "Scale", &Transform3D::Scale
            );

            // add vec3 data type
            m_Lua.new_usertype<Vector3>("Vec3",
                sol::constructors<Vector3(), Vector3(float, float, float)>(),
                "x", &Vector3::x,
                "y", &Vector3::y,
                "z", &Vector3::z
            );

            // register window inputs callbacks
            SetApiFunctions(scene, window);
        }

        // creates instance of existing script
        CSE_INLINE bool AttachScript(Entity& entity, const std::string& name)
        {
            // check if handle is correct and has a constructor
            if (!m_Lua[name].valid() && !m_Lua[name]["Constructor"].valid())
            {
                CSE_ERROR("failed to create script: invalid script name!");
                return false;
            }

            // create instance script
            auto object = m_Lua[name]["Constructor"](entity.ID());

            // check if obj is valid
            if(!object.valid())
            {
                // handle failure
                sol::error error = object;
                sol::call_status status = object.status();
                CSE_ERROR("failed to create script: {}", error.what());
                return false;
            }

            auto& instance = entity.Get<ScriptComponent>().Instance;
            instance = std::make_unique<Script>(object, name);
            instance->OnStart();
            return true;
        }

        // loads script into lua state
        CSE_INLINE std::string LoadScript(const std::string& filepath)
        {
            std::filesystem::path path(filepath);
            auto scriptName = path.stem().string();

            // check if already loaded
            if(m_Lua[scriptName].valid())
            {
                return scriptName;
            }

            // check if modules are loaded
            if(!m_Lua["Initializer"].valid())
            {
                CSE_ERROR("failed to load script! core not initialized!");
                return "";
            }

            // check if script file exits
            if(!std::filesystem::exists(path))
            {
                CSE_ERROR("failed to load script: invalid file path!");
                return "";
            }

            // create script class handle
            m_Lua[scriptName] = m_Lua["Initializer"]();
            m_Lua.script_file(filepath);
            return scriptName;
        }

      private:
        // register function to interact with entity
        CSE_INLINE void SetApiFunctions(EntityRegistry* scene, AppWindow* window)
        {
            // api function to get entity transform
            m_Lua.set_function("ApiGetTransform", [this, scene] (EntityID entity)
            {
                return std::ref(scene->get<TransformComponent>(entity).Transform);
            });

            // api function to destroy entity
            m_Lua.set_function("ApiDestroy", [this, scene] (EntityID entity)
                {
                    // return if entity is dead!
                    if(scene->valid(entity) == false) { return; }

                    // entity has script component
                    if(scene->all_of<ScriptComponent>(entity))
                    {
                        // call on destroy function
                        scene->get<ScriptComponent>(entity).Instance->OnDestroy();
                    }

                    // destroy entity from scene
                    scene->destroy(entity);
                });
        }

      private:
        sol::state m_Lua;
    };
}
