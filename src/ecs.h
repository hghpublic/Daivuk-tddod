/*
    Useful typedefs to simplify templated EnTT objects.
*/

#ifndef ECS_H_INCLUDED
#define ECS_H_INCLUDED

#include <entt/entt.hpp>

using Registry = entt::registry;
using Entity = entt::entity;

static const Entity NULL_ENTITY = entt::null;

#endif
