#include "constants.h"
#include "data.h"
#include "tags.h"

#include "components/EndWaveChecker.h"
#include "components/Position.h"
#include "components/Spawner.h"
#include "components/WavesController.h"
#include "components/Wave.h"
#include "helpers/WaveHelpers.h"

namespace Waves
{
    Entity createWavesController(Registry &registry)
    {
        auto entity = registry.create();
        registry.emplace<Tag::WavesController>(entity);
        registry.emplace<WavesController>(entity, 0, WAVE_COUNT, (Wave*)WAVES);
        return entity;
    }

    void startWave(Registry &registry, int index)
    {
        auto wavesControllerEntity  = registry.view<Tag::WavesController>().front();
        auto &wavesController       = registry.get<WavesController>(wavesControllerEntity);

        registry.emplace<EndWaveChecker>(wavesControllerEntity);

        // Spawner
        {
            auto entity = registry.create();
            registry.emplace<Wave>(entity, Wave{ wavesController.pWaves[wavesController.currentWaveIndex] });
            registry.emplace<Position>(entity, WAVE_START_POSITION);
            registry.emplace<Spawner>(entity, WAVE_START_TIME);
        }
    }
};
