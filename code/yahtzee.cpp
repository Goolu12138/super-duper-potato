#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>


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
};

void printDice(const std::vector<int> &dice){
    for (int die:dice)
        std::cout << die << " ";
    std::cout << std::endl;
}

int main() {
    // 创建一个Dice对象
    Dice dice;
    const int numberOfDice = 5;
    int maxRerolls = 2;

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
    return 0;
}

