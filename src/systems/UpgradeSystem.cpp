#include "tags.h"

#include "components/Inputs.h"
#include "components/UIContext.h"
#include "components/Upgradable.h"
#include "systems/UpgradeSystem.h"
#include "helpers/BankHelpers.h"

void updateUpgradeSystem(Registry &registry)
{
    auto &inputs = registry.get<Inputs>(registry.view<Tag::Inputs>().front());
    auto &uiContext = registry.get<UIContext>(registry.view<Tag::UIContext>().front());

    if (inputs.upgradeKeyState == InputState::JustDown &&
        uiContext.hover != NULL_ENTITY)
    {
        if (registry.all_of<Upgradable>(uiContext.hover))
        {
            const auto &upgradable = registry.get<Upgradable>(uiContext.hover);

            if (Money::withdraw(registry, registry.view<Tag::Player>().front(), (int)upgradable.cost))
            {
                upgradable.upgrade(registry, uiContext.hover);
                inputs.upgradeKeyState = InputState::Down; // Consume input
            }
        }
    }
}
