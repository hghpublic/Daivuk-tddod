#include "HudSystem.h"
#include "tags.h"

#include "components/Bank.h"
#include "components/Hud.h"
#include "components/TextRenderer.h"
#include "components/WavesController.h"

void updateHudSystem(Registry &registry)
{
    auto &hud = registry.get<Hud>(registry.view<Tag::Hud>().front());

    {
        auto &textRenderer = registry.get<TextRenderer>(hud.currentWaveLabel);
        auto wavesControllerEntity = registry.view<Tag::WavesController>().front();
        if (wavesControllerEntity != NULL_ENTITY)
        {
            auto &wavesController = registry.get<WavesController>(wavesControllerEntity);
            textRenderer.text = "Wave: " + std::to_string(wavesController.currentWaveIndex + 1);
        }
        else
        {
            textRenderer.text = "Finished";
        }
    }
    {
        auto &playerBank = registry.get<Bank>(registry.view<Tag::Player>().front());
        auto &textRenderer = registry.get<TextRenderer>(hud.cashLabel);
        textRenderer.text = "Cash: $" + std::to_string((int)playerBank.amount);
    }
}
