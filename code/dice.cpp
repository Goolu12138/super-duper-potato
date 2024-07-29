#include "dice.h"

Dice::Dice() {
    std::srand(std::time(nullptr));
}

int Dice::roll() {
    Four_of_a_kind = false;
    Five_of_a_kind = false;
    return std::rand() % 6 + 1;
}

std::vector<int> Dice::rollMultiple(int numberOfDice) {
    std::vector<int> results(numberOfDice);
    for (int& result : results) {
        result = roll();
    }
    return results;
}

void Dice::reroll(std::vector<int>& dice, const std::vector<bool>& rerollFlags) {
    for (size_t i = 0; i < dice.size(); ++i) {
        if (rerollFlags[i]) {
            dice[i] = roll();
        }
    }
}

int Dice::sumDice(const std::vector<int>& dice) const {
    int sum = 0;
    for (int die : dice) {
        sum += die;
    }
    return sum;
}