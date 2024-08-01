#ifndef YAHTZEE_COMBINATION_H
#define YAHTZEE_COMBINATION_H

#include <vector>
#include <map>
#include <string>

class YahtzeeCombination
{
public:
    YahtzeeCombination();
    void isSame(const std::vector<int>& dice) const;
    void isStraight(const std::vector<int>& dice) const;
    bool addScore(const std::string& category, int score);
    int getScore(const std::string& category) const;
    void resetScores();
    void printScores() const;
    int getTotalScore() const;

private:
    std::map<std::string, int> scores;
    std::map<std::string, bool> scoreFilled;
};


#endif