#include "dice.h"
#include "globals.h"
#include "yahtzee_combination.h"
#include <iostream>
#include <vector>
#include <unordered_map>

void printDice(const std::vector<int>& dice) {
    for (int die : dice) {
        std::cout << die << " ";
    }
    std::cout << std::endl;
}

std::pair<std::string, int> chooseScoreCategory(const Dice& dice, const std::vector<int>& results, const YahtzeeCombination& yahtzeeCombination) {
    int element;
    std::string category;
    int score;

    while (true) {
        std::cout << "选择分数类别? 输入数字以选择类别:\n"
                  << "1. Ones\n"
                  << "2. Twos\n"
                  << "3. Threes\n"
                  << "4. Fours\n"
                  << "5. Fives\n"
                  << "6. Sixes\n"
                  << "7. Four of a kind\n"
                  << "8. Full house\n"
                  << "9. Small straight\n"
                  << "10. Large straight\n"
                  << "11. All choose\n"
                  << "12. Yahtzee\n";
        std::cin >> element;

        if (element >= 1 && element <= 6) {
            std::string categories[] = {"Ones", "Twos", "Threes", "Fours", "Fives", "Sixes"};
            category = categories[element - 1];
            score = dice.sumSpecificElement(results, element);
            break;
        } else {
            std::unordered_map<int, std::string> specialCategories = {
                {7, "Four of a kind"}, {8, "Full house"},
                {9, "Small straight"}, {10, "Large straight"},
                {11, "All choose"}, {12, "Yahtzee"}
            };
            if (specialCategories.find(element) != specialCategories.end()) {
                category = specialCategories[element];
                score = dice.sumDice(results);
                break;
            } else {
                std::cerr << "无效的选择! 请重新输入。" << std::endl;
            }
        }
    }

    return {category, score};
}

int main()
{
      // 创建一个Dice对象
    Dice dice;
    YahtzeeCombination yahtzeeCombination;
    const int rounds = 12;
    for(int round=0;round < rounds; ++round)
    {
        // 掷骰子并输出结果
        std::vector<int> results = dice.rollMultiple(numberOfDice);
        std::cout << "第 " << (round + 1) << " 轮开始..." << std::endl;
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

        // 检查并输出特殊的骰面组合
        yahtzeeCombination.isStraight(results);
        yahtzeeCombination.isSame(results);

        int score = 0;
        std::string message = "";

        if (Four_of_a_kind) {
            Four_of_a_kind = false;
            message = "四色同花，骰子总数为： ";
        } else if (Yahtzee) {
            Yahtzee = false;
            message = "快艇，骰子总数为： ";
        } else if (Small_straight) {
            Small_straight = false;
            message = "小顺，骰子总数为： ";
        } else if (Large_straight) {
            Large_straight = false;
            message = "大顺，骰子总数为： ";
        } else if (Full_house) {
            Full_house = false;
            message = "葫芦，骰子总数为： ";
        }
        
        if (!message.empty()) {
            score = dice.sumDice(results);
            std::cout << message << score << std::endl;
        }

        auto [chosenCategory, chosenScore] = chooseScoreCategory(dice, results, yahtzeeCombination);

        if (yahtzeeCombination.addScore(chosenCategory, chosenScore)) {
            std::cout << "得分已记录!" << std::endl;
        }

        yahtzeeCombination.printScores();
        std::cout << "总得分: " << yahtzeeCombination.getTotalScore() << std::endl;
    }
    return 0;
}