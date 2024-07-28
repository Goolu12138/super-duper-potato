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
        std::vector<int> results;
        for (int i; i <numberOfDice; i++ )
        {
            results.push_back(roll());
        }
        return results;
    }

    viod reroll(){
        for (){
            roll();
        }
    }
};

int main() {
    // 创建一个Dice对象
    Dice dice;

    // 掷骰子并输出结果
    std::vector<int> results = dice.rollMultiple(5);
    std::cout << "你掷出的骰子是: " ;
    for (int result : results)
        std::cout << result << " ";
    std::cout << std::endl;

    return 0;
}

