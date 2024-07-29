#include "yahtzee_combination.h"
#include "globals.h"
#include <algorithm>
#include <unordered_map>

//四色同花和快艇
void YahtzeeCombination::isStraight(const std::vector<int> &dice) const
{
    std::vector<int> sortedDice = dice;
    std::sort(sortedDice.begin(), sortedDice.end());
    sortedDice.erase(std::unique(sortedDice.begin(), sortedDice.end()), sortedDice.end());

    int temp_four_or_five = 1;
    for(int i=1;i<numberOfDice;i++)
    {
        if(sortedDice[i] != sortedDice[i-1]+1){
            temp_four_or_five++;
        }
        else
        {
            temp_four_or_five = 1;
        }

        if(temp_four_or_five == 5)
        {
            Four_of_a_kind = false;
            Five_of_a_kind = true;
        }
        else if(temp_four_or_five == 4)
        {
            Four_of_a_kind = true;
        }
    }
    
    if(Five_of_a_kind)
    {
        Four_of_a_kind = false;
    }
}