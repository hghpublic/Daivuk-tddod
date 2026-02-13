#include "EndWaveCheckSystem.h"

#include "components/Critter.h"
#include "components/EndWaveChecker.h"
#include "components/EndWaveDelay.h"
#include "components/Spawner.h"

static const float END_WAVE_WAIT_TIME = 1.0f;

void updateEndWaveCheckSystem(Registry &registry)
{
    if (!registry.view<Critter>().empty() || !registry.view<Spawner>().empty()) return; // Nothing to check if there are still critters alive or spawners
    
    registry.view<EndWaveChecker>().each([&registry](auto entity)
    {
        registry.remove<EndWaveChecker>(entity);
        registry.emplace<EndWaveDelay>(entity, END_WAVE_WAIT_TIME);
    });
}
