#include "components/Button.h"
#include "components/CashThresholdButtonToggler.h"
#include "components/Color.h"
#include "components/Hoverable.h"
#include "components/Name.h"
#include "components/Position.h"
#include "components/ShapeRenderer.h"
#include "components/Size.h"
#include "components/TextRenderer.h"
#include "helpers/ShapeHelpers.h"
#include "helpers/UIHelpers.h"

namespace UI
{
    Entity createLabel(Registry &registry, const char *text, const Position &position, const Color &color, float align)
    {
        auto entity = registry.create();
        registry.emplace<Position>(entity, position);
        registry.emplace<Color>(entity, color);
        registry.emplace<TextRenderer>(entity, text, Color{ 0,0,0,0 }, align);
        return entity;
    }

    Entity createTowerButton(Registry &registry, const char *caption, const Position &position, int price, ON_CLICK_FN onClick)
    {
        auto entity = registry.create();
        registry.emplace<Position>(entity, position);
        registry.emplace<Size>(entity, Size{ 2.5f, 0.4f });
        registry.emplace<Color>(entity, Color{ 0.6f, 0.7f, 0.5f, 1.0f });
        registry.emplace<TextRenderer>(entity, caption, Color{ 0,0,0,0 }, 0.5f);
        registry.emplace<Name>(entity, "$" + std::to_string(price));
        registry.emplace<ShapeRenderer>(entity, Shape::drawBox);
        registry.emplace<CashThresholdButtonToggler>(entity, (float)price);
        registry.emplace<Button>(entity, Color{ 0.3f, 0.3f, 0.3f, 1 }, onClick);
        registry.emplace<Hoverable>(entity, Color{ 0.6f, 0.7f, 0.5f, 1.0f }, Color{ 1, 1, 0.8f, 1 });
        return entity;
    }
};
