#include "TargetingSystem.h"

#include "components/Cooldown.h"
#include "components/FindTarget.h"
#include "components/Position.h"
#include "components/Target.h"
#include "components/TargetScore.h"
#include "components/Targeter.h"

void updateTargetingSystem(Registry &registry, [[maybe_unused]] float dt)
{
// FIXME
#if 0
    registry.view<Targeter, FindTarget, Position>().each([&registry](auto entity, const Targeter &targeter, [[maybe_unused]] const FindTarget &findTarget, const Position &position)
    {
        auto rangeSqr = targeter.range * targeter.range;
        auto score = 0.0f;
        auto targetEntity = NULL_ENTITY;
        registry.view<Target, Position, TargetScore>().each([&rangeSqr, &position, &targetEntity, &targeter, &score](auto entity, const Target &target, const Position &critterPosition, const TargetScore &targetScore)
        {
            if (target.mask & targeter.targetMask)
            {
                auto dx = critterPosition.x - position.x;
                auto dy = critterPosition.y - position.y;
                auto distSqr = dx * dx + dy * dy;
                if (distSqr <= rangeSqr && targetScore.score >= score)
                {
                    targetEntity = entity;
                    score = targetScore.score;
                }
            }
        });

        if (targetEntity != NULL_ENTITY)
        {
            // Shoot at target
            registry.remove<FindTarget>(entity);
            registry.emplace<Cooldown>(entity, Cooldown{targeter.cooldown});
            (*targeter.shoot)(registry, targetEntity, entity);
        }
    });
#endif
}
