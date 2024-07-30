#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>


const int numberOfDice = 5;     //骰子数量
const int maxRerolls = 2;       //重新掷骰子次数

bool Four_of_a_kind = false;
bool Yahtzee = false;

class Dice {
public:
    // 构造函数，初始化随机数生成器
    Dice() {
        std::srand(std::time(nullptr));
    }

    // 掷骰子的方法，返回1到6之间的随机数
    int roll() {
        return std::rand() % 6 + 1;
    }

    std::vector<int> rollMultiple(int numberOfDice) {
        std::vector<int> results(numberOfDice);
        for (int& result : results)
        {
            result = roll();
        }
        return results;
    }

    void reroll(std::vector<int> &dice, const std::vector<bool>& rerollFlags){
        for (size_t i = 0;i < dice.size(); ++i){
            if (rerollFlags[i])
                dice[i] = roll();
        }
    }

    int sumDice(std::vector<int> &dices)
    {
        int sum = 0;
        for(auto dice : dices)
        {
            sum += dice;
        }
        return sum;
    }

    //四色同花和快艇
    void isStraight(std::vector<int> &dice)
    {
        std::sort(dice.begin(), dice.end());

        int temp_four_or_five = 1;
        for(int i=1;i<numberOfDice;i++)
        {
            if(dice[i] != dice[i-1]+1){
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

};

void printDice(const std::vector<int> &dice){
    for (int die:dice)
        std::cout << die << " ";
    std::cout << std::endl;
}

int main() {
    // 创建一个Dice对象
    Dice dice;

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

    dice.isStraight(results);
    return 0;
}

