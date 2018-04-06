#ifndef __SNAKEMOVERULEINBOUNDS_HPP__
#define __SNAKEMOVERULEINBOUNDS_HPP__

#include "snakemoverule.hpp"

class SnakeMoveRuleInBounds : public SnakeMoveRule
{
    public:
        SnakeMoveRuleInBounds(int minx, int miny, int minz, int maxx, int maxy, int maxz);
        void apply(Snake*, SnakeMoveEvaluator*) override;

    private:
        int _minx;
        int _miny;
        int _minz;
        int _maxx;
        int _maxy;
        int _maxz;
};

#endif