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

// Raylib
#include "raylib.h"

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
    // runtime type
    template<typename T>
    CSE_INLINE constexpr uint32_t TypeID()
    {
        return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(&typeid(T)));
    }
}

// free allocated memory
#define CSE_DELETE(ptr) if (ptr != nullptr) { delete (ptr); ptr = nullptr;}
#define CSE_ERROR(error) std::cout << error << std::endl;
