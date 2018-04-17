#include "gameruleripendot.hpp"
#include "dot.hpp"
#include "game.hpp"

void GameRuleRipenDot::apply(Game* game)
{
    auto dots = game->getDotIterator();
    while (dots.moveNext()) {
        auto dot = dots.getValue();
        dot->ripen();
    }
}
