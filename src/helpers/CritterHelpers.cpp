#include "data.h"

#include "components/Bank.h"
#include "components/BaseSpeed.h"
#include "components/Color.h"
#include "components/Critter.h"
#include "components/Health.h"
#include "components/Hoverable.h"
#include "components/Name.h"
#include "components/ShapeRenderer.h"
#include "components/Size.h"
#include "components/Speed.h"
#include "components/Target.h"
#include "components/TargetScore.h"
#include "components/Traveler.h"
#include "helpers/CritterHelpers.h"
#include "helpers/ShapeHelpers.h"

namespace Critters
{
    void createPeasant(Registry &registry, const Position &position)
    {
        auto entity = registry.create();

        auto size = 0.15f;
        auto speed = 45.0f / 60.0f;

        registry.emplace<Critter>(entity);
        registry.emplace<Position>(entity, position);
        registry.emplace<Size>(entity, size, size);
        registry.emplace<Color>(entity, Color{ 251.0f / 255.0f, 242.0f / 255.0f, 54.0f / 255.0f, 1.0f });
        registry.emplace<ShapeRenderer>(entity, Shape::drawCircle);
        registry.emplace<Traveler>(entity, 0, WAYPOINT_COUNT, (Position*)WAYPOINTS);
        registry.emplace<Name>(entity, "Peasant");
        registry.emplace<Health>(entity, 30.0f, 30.0f);
        registry.emplace<Bank>(entity, 10.0f);
        registry.emplace<Target>(entity, TargetMask::GROUND);
        registry.emplace<Hoverable>(entity);
        registry.emplace<TargetScore>(entity, 0.0f);
        registry.emplace<BaseSpeed>(entity, speed);
        registry.emplace<Speed>(entity, speed);
    }

    void createWarrior(Registry &registry, const Position &position)
    {
        auto entity = registry.create();

        auto size = 0.20f;
        auto speed = 45.0f / 60.0f;

        registry.emplace<Critter>(entity);
        registry.emplace<Position>(entity, position);
        registry.emplace<Size>(entity, size, size);
        registry.emplace<Color>(entity, Color{ 223.0f / 255.0f, 113.0f / 255.0f, 38.0f / 255.0f, 1.0f });
        registry.emplace<ShapeRenderer>(entity, Shape::drawCircle);
        registry.emplace<Traveler>(entity, 0, WAYPOINT_COUNT, (Position*)WAYPOINTS);
        registry.emplace<Name>(entity, "Warrior");
        registry.emplace<Health>(entity, 50.0f, 50.0f);
        registry.emplace<Bank>(entity, 10.0f);
        registry.emplace<Target>(entity, TargetMask::GROUND);
        registry.emplace<Hoverable>(entity);
        registry.emplace<TargetScore>(entity, 0.0f);
        registry.emplace<BaseSpeed>(entity, speed);
        registry.emplace<Speed>(entity, speed);
    }

    void createThief(Registry &registry, const Position &position)
    {
        auto entity = registry.create();

        auto size = 0.10f;
        auto speed = 45.0f / 60.0f * 4.0f;

        registry.emplace<Critter>(entity);
        registry.emplace<Position>(entity, position);
        registry.emplace<Size>(entity, size, size);
        registry.emplace<Color>(entity, Color{ 0.5f, 0.75f, 1.0f, 1.0f });
        registry.emplace<ShapeRenderer>(entity, Shape::drawCircle);
        registry.emplace<Traveler>(entity, 0, WAYPOINT_COUNT, (Position*)WAYPOINTS);
        registry.emplace<Name>(entity, "Thief");
        registry.emplace<Health>(entity, 30.0f, 30.0f);
        registry.emplace<Bank>(entity, 5.0f);
        registry.emplace<Target>(entity, TargetMask::GROUND);
        registry.emplace<Hoverable>(entity);
        registry.emplace<TargetScore>(entity, 0.0f);
        registry.emplace<BaseSpeed>(entity, speed);
        registry.emplace<Speed>(entity, speed);
    }

    void createFlyer(Registry &registry, const Position &position)
    {
        auto entity = registry.create();

        auto size = 0.20f;
        auto speed = 45.0f / 60.0f * 2.0f;

        registry.emplace<Critter>(entity);
        registry.emplace<Position>(entity, position);
        registry.emplace<Size>(entity, size, size);
        registry.emplace<Color>(entity, Color{ 1.0f, 0.0f, 1.0f, 1.0f });
        registry.emplace<ShapeRenderer>(entity, Shape::drawCircle);
        registry.emplace<Traveler>(entity, 0, AIR_WAYPOINT_COUNT, (Position*)AIR_WAYPOINTS);
        registry.emplace<Name>(entity, "Flyer");
        registry.emplace<Health>(entity, 30.0f, 30.0f);
        registry.emplace<Bank>(entity, 10.0f);
        registry.emplace<Target>(entity, TargetMask::AIR);
        registry.emplace<Hoverable>(entity);
        registry.emplace<TargetScore>(entity, 0.0f);
        registry.emplace<BaseSpeed>(entity, speed);
        registry.emplace<Speed>(entity, speed);
    }

    void createBehemoth(Registry &registry, const Position &position)
    {
        auto entity = registry.create();

        auto size = 0.40f;
        auto speed = 45.0f / 60.0f / 2.0f;

        registry.emplace<Critter>(entity);
        registry.emplace<Position>(entity, position);
        registry.emplace<Size>(entity, size, size);
        registry.emplace<Color>(entity, Color{ 1.0f, 0.25f, 0.25f, 1.0f });
        registry.emplace<ShapeRenderer>(entity, Shape::drawCircle);
        registry.emplace<Traveler>(entity, 0, WAYPOINT_COUNT, (Position*)WAYPOINTS);
        registry.emplace<Name>(entity, "Behemoth");
        registry.emplace<Health>(entity, 600.0f, 600.0f);
        registry.emplace<Bank>(entity, 50.0f);
        registry.emplace<Target>(entity, TargetMask::GROUND);
        registry.emplace<Hoverable>(entity);
        registry.emplace<TargetScore>(entity, 0.0f);
        registry.emplace<BaseSpeed>(entity, speed);
        registry.emplace<Speed>(entity, speed);
    }
};
