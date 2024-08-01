#ifndef DICE_H
#define DICE_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "globals.h"

class Dice {
public:
    // 构造函数，初始化随机数生成器
    Dice();
    // 掷骰子的方法，返回1到6之间的随机数
    int roll();
    // 一次掷多颗骰子的方法，返回包含结果的vector
    std::vector<int> rollMultiple(int numberOfDice);
    // 重新掷指定的骰子
    void reroll(std::vector<int>& dice, const std::vector<bool>& rerollFlags);
    // 求所有骰子点数的总和
    int sumDice(const std::vector<int>& dice) const;
    // 求1-6对应元素综合
    int sumSpecificElement(const std::vector<int>& dice, int element) const;
};

#endif