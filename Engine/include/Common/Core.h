#pragma once
#include <atomic>
#include <cstdint>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <random>
#include <memory>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>
#include <iostream>
#include <stdio.h>

// Raylib
#include "entt/entity/fwd.hpp"
#include "raylib.h"

// entt
#include "entt/entt.hpp"

#define SCRNWIDTH 1280
#define SCRNHEIGHT 720

// runtime assertion
#define CSE_ASSERT assert

// compile assertion
#if defined(__clang__) || defined(__gcc__)
    #define CSE_STATIC_ASSERT _Static_assert
#else
    #define CSE_STATIC_ASSERT static_assert
#endif

// function inlining
#if defined(__clang__) || defined(__gcc__)
    #define CSE_INLINE __attribute__((always_inline)) inline
    #define CSE_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
    #define CSE_INLINE __forceinline
    #define CSE_NOINLINE __declspec(noinline)
#else
    #define CSE_INLINE inline
    #define CSE_NOINLINE
#endif

// core features
namespace CSE
{
    // entity identifier
    using EntityID = entt::entity;
    //null entity
    constexpr EntityID NENTT = entt::null;
    //entoty registry
    using EntityRegistry = entt::registry;

    // runtime type
    template<typename T>
    CSE_INLINE constexpr uint32_t TypeID()
    {
        return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(&typeid(T)));
    }

    // generate random 64 bit
    CSE_INLINE uint64_t RandomU64()
    {
        static std::random_device device;
        static std::mt19937_64 generator(device());
        static std::uniform_int_distribution<uint64_t> distribution;
        return distribution(generator);
        printf("");
    }
}

// free allocated memory
#define CSE_DELETE(ptr) if (ptr != nullptr) { delete (ptr); ptr = nullptr;}
#define CSE_ERROR(error...) printf(error);
