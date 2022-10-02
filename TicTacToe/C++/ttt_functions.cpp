#include <iostream>
#include <vector>
#include <algorithm>



void greet() {
    std::cout << "\n";
    std::cout << "=============================================================================\n";
    std::cout << "  __  .__                   __                            __" << "\n";                 
    std::cout << "_/  |_|__| ____           _/  |______    ____           _/  |_  ____   ____ " << "\n";  
    std::cout << "\\   __\\  |/ ___\\   ______ \\   __\\__  \\ _/ ___\\   ______ \\   __\\/  _ \\_/ __ \\ " << "\n"; 
    std::cout << " |  | |  \\  \\___  /_____/  |  |  / __ \\\\  \\___  /_____/  |  | (  <_> )  ___/ " << "\n"; 
    std::cout << " |__| |__|\\___  >          |__| (____  /\\___  >          |__|  \\____/ \\___  > " << "\n";
    std::cout << "              \\/                     \\/     \\/                            \\/ " << "\n";
    std::cout << "==============================================================================\n";
}

void makeBoard(char game[9]) {
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << game[0] << "  |  " << game[1] << "  |  " << game[2] << " \n";
    std::cout << "     |     |     " << "\n";
    std::cout << "-----+-----+-----" << "\n"; 
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << game[3] << "  |  " << game[4] << "  |  " << game[5] << " \n";
    std::cout << "     |     |     " << "\n";
    std::cout << "-----+-----+-----" << "\n"; 
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << game[6] << "  |  " << game[7] << "  |  " << game[8] << " \n";
    std::cout << "     |     |     " << "\n";
    std::cout << "======================\n";
}

void demoBoard() {
    char demo[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::cout << "==============================================================================\n";
    std::cout << "Here's a Demo Board for you.\n Use the numbers on the demo board as a reference for your turn\n";
    std::cout << "==============================================================================\n";
    makeBoard(demo);
}

bool validMove(char board[9], int slot) {
    if (slot < 1 or slot >9) {
        return false;
    } else if (board[slot-1] != ' ') {
        return false;
    } else {
        return true;
    }
}

bool setSlot(char board[9], int slot, char piece) {
    if (not validMove(board, slot)) {
        std::cout << "Trying to place " << piece << " in slot no." << slot;
        std::cout << "\nMake sure to pick an empty slot.\n";
        return false;
    } else if (validMove(board, slot)) {
        board[slot-1] = piece;
        std::cout << "Placed " << piece << " on " << slot << "\n";
        return true;
    } else if (piece != 'X' || piece != 'O') {
        return false;
    } else {
        return false;
    }
}

std::vector<int> availableMoves(char board[9]) {
    std::vector<int> list;
    for (int i = 1; i < 10; i++) {
        if (validMove(board, i)) {
            list.push_back(i);
        }
    }
    return list;
}

bool checkWin(char board[9], char piece) {
    if (board[0] == piece && board[1] == piece && board[2] == piece) {
        return true;
    } else if (board[3] == piece && board[4] == piece && board[5] == piece) {
        return true;
    } else if (board[6] == piece && board[7] == piece && board[8] == piece) {
        return true;
    } else if (board[0] == piece && board[3] == piece && board[6] == piece) {
        return true;
    } else if (board[1] == piece && board[4] == piece && board[7] == piece) {
        return true;
    } else if (board[2] == piece && board[5] == piece && board[8] == piece) {
        return true;
    } else if (board[2] == piece && board[4] == piece && board[6] == piece) {
        return true;
    } else if (board[0] == piece && board[4] == piece && board[8] == piece) {
        return true;
    } else {
        return false;
    }
}

bool gameOver(char board[9]) {
    return checkWin(board, 'X') || checkWin(board, 'O') || availableMoves(board).size() == 0;
}

void startGame() {
    
    demoBoard();
    char playBoard[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char turn = 'X';
    bool winner = false;
    while (not gameOver(playBoard)) {
        makeBoard(playBoard);
        int slot = 0;
        std::vector<int> avlMoves = availableMoves(playBoard);
        while (not std::count(avlMoves.begin(), avlMoves.end(), slot)) {
            std::cout << "It is " << turn << "'s turn. Please select a slot: ";
            std::cin >> slot;
        }
        setSlot(playBoard, slot, turn);
        if (checkWin(playBoard, turn)) {
            std::cout << turn << " has WON!\n";
            makeBoard(playBoard);
            winner = true;
            break;
        }
        if (turn == 'X') {
            turn = 'O';
        } else {
            turn = 'X';
        }
    }
    if (not winner) {
        std::cout << "It was a TIE!\n";
        makeBoard(playBoard);
    }
}