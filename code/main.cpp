#include "dice.h"
#include "globals.h"
#include "yahtzee_combination.h"
#include <iostream>
#include <vector>

void printDice(const std::vector<int>& dice) {
    for (int die : dice) {
        std::cout << die << " ";
    }
    std::cout << std::endl;
}

int main()
{
      // 创建一个Dice对象
    Dice dice;
    YahtzeeCombination yahtzeeCombination;
    // 掷骰子并输出结果
    std::vector<int> results = dice.rollMultiple(numberOfDice);
    std::cout << "第一次骰子为: " ;
    printDice(results);

    for(int rerollCount=0; rerollCount < maxRerolls; ++rerollCount)
    {
        std::vector<bool> rerollFlags(numberOfDice, false);
        char choice;
        std::cout << "是否重新掷骰子?(y/n): ";
        std::cin >> choice;

        if (choice == 'n')
            break;
        
        std::cout << "输入要重新掷的骰子的编号 (1-" << numberOfDice << "), 用空格分隔: ";
        int dieIndex;
        while(std::cin >> dieIndex)
        {
            if (dieIndex >= 1 && dieIndex <= numberOfDice)
            {
                rerollFlags[dieIndex - 1] = true;
            }
            if (std::cin.peek() == '\n') {
                break;
            }
        }

        dice.reroll(results, rerollFlags);
        std::cout << "重掷骰子为："; 
        printDice(results);
         
    }

    std::cout << "最终骰子为: ";
    printDice(results);

    int sum = dice.sumDice(results);
    std::cout << "骰子总和为: "  << sum << std::endl;

    // 检查并输出特殊的骰面组合
    yahtzeeCombination.isStraight(results);
    yahtzeeCombination.isSame(results);

    if (Four_of_a_kind) {
        std::cout << "四色同花" << std::endl;
    }
    if (Yahtzee) {
        std::cout << "快艇" << std::endl;
    }
    if (Small_straight) {
        std::cout << "小顺" << std::endl;
    }
    if (Large_straight) {
        std::cout << "大顺" << std::endl;
    }
    if (Full_house) {
        std::cout << "葫芦" << std::endl;
    }

    return 0;
}