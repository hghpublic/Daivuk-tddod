#include "components/Bank.h"
#include "helpers/BankHelpers.h"

namespace Money
{
    bool withdraw(Registry &registry, Entity from, int amount)
    {
        if (!registry.all_of<Bank>(from)) return false;

        auto &bank = registry.get<Bank>(from);
        if (bank.amount >= (float)amount)
        {
            bank.amount -= (float)amount;
            return true;
        }
        return false;
    }

    void transfer(Registry &registry, Entity from, Entity to)
    {
        if (from == to) return;
        if (registry.all_of<Bank>(from) && registry.all_of<Bank>(to))
        {
            auto &fromBank = registry.get<Bank>(from);
            auto &toBank = registry.get<Bank>(to);
            toBank.amount += fromBank.amount;
            fromBank.amount = 0.0f;
        }
    }
};
