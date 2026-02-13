/*
    Tag names to singleton entities.
*/

#ifndef TAGS_H_INCLUDED
#define TAGS_H_INCLUDED

#include "ecs.h"

#pragma warning(push)
#pragma warning(disable: 4307) // EnTT throws a warning with the hashing here in VS2017

// #define LABEL(__name__) using __name__ = entt::label<#__name__ ## _hs>

namespace Tag
{
    struct WavesController{};
    struct Resources{};
    struct Hud{};
    struct Player{};
    struct UIContext{};
    struct Inputs{};
    struct Tooltip{};
};

#pragma warning(pop)

#endif
