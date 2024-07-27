
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int SIZE = 9;

bool isSafe(std::vector<std::vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(std::vector<std::vector<int>>& board, int row, int col) {
    if (row == SIZE) return true; // 解决了一个数独题
    if (col == SIZE) return solveSudoku(board, row + 1, 0); // 移动到下一行

    if (board[row][col] != 0) return solveSudoku(board, row, col + 1); // 跳过已填充的数字

    for (int num = 1; num <= SIZE; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1)) return true;
            board[row][col] = 0; // 回溯
        }
    }
    return false;
}

void generateSudoku(std::vector<std::vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = 0;
        }
    }
    srand(time(0)); // 设置随机数种子
    solveSudoku(board, 0, 0);
}

void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " ";
            if (j % 3 == 2 && j < 8) std::cout << "|";
        }
        std::cout << std::endl;
        if (i % 3 == 2 && i < 8) std::cout << "------------|-----------|------------" << std::endl;
    }
}

void playSudoku() {
    std::vector<std::vector<int>> board(SIZE, std::vector<int>(SIZE));
    generateSudoku(board);
    printBoard(board);

    char quit = 'y';
    while (quit != 'q') {
        int row, col, num;
        std::cout << "Enter your move (row col num) or 'q' to quit: ";
        std::cin >> row >> col >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cin.clear(); // 清除错误状态
            continue;
        }

        if (row == -1 && col == -1) {
            quit = 'q';
            break;
        }

        // 确保输入的行、列和数字在有效范围内
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= SIZE) {
            if (board[row][col] == 0) {
                board[row][col] = num;
                printBoard(board);
            } else {
                std::cout << "This cell is already filled with a number. Please choose another cell." << std::endl;
            }
        } else {
            std::cout << "Invalid move. Please enter numbers within the range." << std::endl;
        }
    }
    std::cout << "Game over. Thanks for playing!" << std::endl;
}

int main() {
    std::cout << "Welcome to Sudoku!" << std::endl;
    playSudoku();
    return 0;
}

