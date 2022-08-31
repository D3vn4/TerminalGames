#include <iostream>
#include <vector>



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

bool validMove(int slot, char board[9]) {
    if (not 1<=slot<=9) {
        std::cout << "Not a valid slot, please enter a number between 1 and 9";
        return false;
    }
    if (board[slot-1] != ' ') {
        std::cout << "Slot already occupied, Please select different slot.";
        return false;
    }
}

bool setPiece(int slot, char piece, char board[9]) {
    if (not validMove(slot, board)) {
        std::cout << "Error: ";
        return false;
    }
    if (board[slot-1] == ' ') {
        board[slot-1] = piece;
        return true;
    }
    return false;
}

bool checkWin(char board[9], char piece) {

    // Check for Horizontal pieces
    if (board[0] == board[1] == board[2] == piece) {
        return true;
    } else if (board[3] == board[4] == board[5] == piece) {
        return true;
    } else if (board[6] == board[7] == board[8] == piece) {
        return true;
    }

    // Check for Vertical pieces
    if (board[0] == board[3] == board[6] == piece) {
        return true;
    } else if (board[1] == board[4] == board[7] == piece) {
        return true;
    } else if (board[2] == board[5] == board[8] == piece) {
        return true;
    }

    // Check for '/' Diagonal
    if (board[2] == board[4] == board[6] == piece) {
        return true;
    }

    // Check for '\' Diagonal
    if(board[0] == board[4] == board[8] == piece) {
        return true;
    }

    return false;
}

bool checkDraw(char board[9]) {
    std::vector<char> avlMoves = {};
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            avlMoves.push_back(i);
        }
    }
    if (avlMoves.empty()) {
        return true;
    }
    return false;
}

bool gameIsOver(char board[9]) {
    return checkWin(board, 'X') || checkWin(board, 'O') || checkDraw(board);
}

void startGame() {
    demoBoard();
}