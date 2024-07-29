#include <iostream>
#include <vector>
#include <cstdlib> // 包含用于rand和srand的头文件
#include <ctime>   // 包含用于time的头文件

// 定义花色枚举
enum Suit {
    Clubs,    // 梅花
    Diamonds, // 方块
    Hearts,   // 红心
    Spades    // 黑桃
};

// 定义数值枚举
enum Rank {
    Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King, Ace
};

// 定义扑克牌类
class Card {
public:
    Rank rank;
    Suit suit;

    Card(Rank r, Suit s) : rank(r), suit(s) {}

    // 打印图形化的扑克牌
    void printGraphically() const {
        const char* suits[4] = {
            "♣", // 梅花
            "♦", // 方块
            "♥", // 红心
            "♠" // 黑桃
        };

        const char* ranks[14] = {
            "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
        };

        std::cout << " " << suits[suit] << " " << ranks[rank - Two] << " ";
    }
};

int main() {
    // 初始化随机数种子
    srand(static_cast<unsigned int>(time(nullptr)));

    // 创建一副扑克牌
    std::vector<Card> deck;
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            deck.emplace_back(static_cast<Rank>(rank), static_cast<Suit>(suit));
        }
    }

    // 洗牌
    for (size_t i = 0; i < deck.size(); ++i) {
        size_t randomIndex = i + rand() % (deck.size() - i);
        std::swap(deck[i], deck[randomIndex]);
    }

    // 输出图形化的扑克牌
    for (const Card& card : deck) {
        card.printGraphically();
        std::cout << std::endl;
    }

    return 0;
}