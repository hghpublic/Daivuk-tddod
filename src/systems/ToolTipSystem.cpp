#include "constants.h"
#include "tags.h"

#include "components/Inputs.h"
#include "components/Name.h"
#include "components/TextRenderer.h"
#include "components/UIContext.h"
#include "systems/ToolTipSystem.h"

void updateToolTipSystem(Registry &registry)
{
    auto &inputs = registry.get<Inputs>(registry.attachee<Tag::Inputs>());
    auto &uiContext = registry.get<UIContext>(registry.attachee<Tag::UIContext>());
    auto toolTipEntity = registry.attachee<Tag::Tooltip>();

    if (uiContext.hover != NULL_ENTITY)
    {
        const auto &text = registry.get<Name>(uiContext.hover).name;
        float w = (float)text.size() * TEXT_ADVANCE;
        float align = std::max(inputs.worldMouse.x + 0.5f + w - 21.0f, 0.0f) / w;

        registry.emplace_or_replace<Position>(toolTipEntity, Position{ inputs.worldMouse.x + 0.5f, inputs.worldMouse.y + 0.5f });
        registry.emplace_or_replace<Color>(toolTipEntity, Color{ 0.75f, 0.75f, 0.85f, 1.0f });
        registry.emplace_or_replace<TextRenderer>(toolTipEntity, text, Color{ 0, 0.125f, 0.25f, 0.75f }, align);
    }
    else
    {
        registry.reset<TextRenderer>(toolTipEntity);
    }
}
