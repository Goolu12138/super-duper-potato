#include "yahtzee_combination.h"
#include "globals.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <unordered_map>


YahtzeeCombination::YahtzeeCombination() {
    resetScores();
}
//四色同花,快艇和葫芦
void YahtzeeCombination::isSame(const std::vector<int> &dice) const
{
    std::vector<int> sortedDice = dice;
    std::sort(sortedDice.begin(), sortedDice.end());
    
    bool temp_four_a_kind = false;
    std::unordered_map<int, int> elementCount;
    for (int num : sortedDice) {
        elementCount[num]++;
        if (elementCount[num] > 3) {
            temp_four_a_kind = true;
        }
    }

    sortedDice.erase(std::unique(sortedDice.begin(), sortedDice.end()), sortedDice.end());

    int size = sortedDice.size();
    if(size == 2 && temp_four_a_kind)
    {
        Four_of_a_kind = true;
    }
    else if(size == 2 && !temp_four_a_kind)
    {
        Full_house = true;
    }
    else if(size == 1)
    {
        Yahtzee = true;
    }
}

//大顺小顺
void YahtzeeCombination::isStraight(const std::vector<int> &dice) const
{
    std::vector<int> sortedDice = dice;
    std::sort(sortedDice.begin(), sortedDice.end());
    sortedDice.erase(std::unique(sortedDice.begin(), sortedDice.end()), sortedDice.end());
    assert(numberOfDice >= 0);
    if(sortedDice.size() < numberOfDice)
    {
        return;
    }

    int temp_four_or_five = 1;
    for(int i = sortedDice.size(); i >= 0 ; i-- )
    {
        if(sortedDice[i] == sortedDice[i-1]+1){
            temp_four_or_five++;
        }
        else
        {
            temp_four_or_five = 1;
        }

        if(temp_four_or_five == 5)
        {
            Large_straight = true;
        }
        else if(temp_four_or_five == 4)
        {
            Small_straight = true;
        }
    }
}

void YahtzeeCombination::printScores() const {
    for (const auto& entry : scores) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}

int YahtzeeCombination::getTotalScore() const {
    int total = 0;
    for (const auto& entry : scores) {
        total += entry.second;
    }
    return total;
}

int YahtzeeCombination::getScore(const std::string& category) const {
    auto it = scores.find(category);
    if (it != scores.end()) {
        return it->second;
    }
    return 0;
}


void YahtzeeCombination::resetScores() {
    scores.clear();
    scoreFilled.clear();
    std::vector<std::string> categories = {
        "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", 
        "Four of a kind", "Full house", "Small straight", 
        "Large straight", "All choose", "Yahtzee"
    };
    for (const auto& category : categories) {
        scores[category] = 0;
        scoreFilled[category] = false;
    }

    Four_of_a_kind = false;
    Yahtzee = false;
    Small_straight = false;
    Large_straight = false;
    Full_house = false;
    All_choose = true;
}

bool YahtzeeCombination::addScore(const std::string& category, int score) {
    if (scoreFilled[category]) {
        std::cerr << "Score for " << category << " already filled!" << std::endl;
        return false;
    }

    scores[category] = score;
    scoreFilled[category] = true;
    return true;
}