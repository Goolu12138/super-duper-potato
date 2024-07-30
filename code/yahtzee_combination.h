#ifndef YAHTZEE_COMBINATION_H
#define YAHTZEE_COMBINATION_H

#include <vector>

class YahtzeeCombination
{
public:
    void isSame(const std::vector<int>& dice) const;
    void isStraight(const std::vector<int>& dice) const;
    void isFullhouse(const std::vector<int>& dice) const;
};

#endif