#include "KillSystem.h"

#include "components/Dead.h"

void updateKillSystem(Registry &registry)
{
    // registry.destroy<Dead>();

    auto view = registry.view<Dead>();
    std::vector<Entity> toDestroy;
    toDestroy.reserve(view.size());

    for (auto entity : view)
    {
        toDestroy.push_back(entity);
    }

    for (auto entity : toDestroy)
    {
        registry.destroy(entity);
    }
}
