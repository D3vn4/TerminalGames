#include <iostream>
#include <vector>
#include <algorithm>


// Greets with the game message
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

// makes the board for a given list
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

// demo board list for reference
void demoBoard() {
    char demo[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::cout << "==============================================================================\n";
    std::cout << "Here's a Demo Board for you.\n Use the numbers on the demo board as a reference for your turn\n";
    std::cout << "==============================================================================\n";
    makeBoard(demo);
}

// checks if the move is valid
bool validMove(char board[9], int slot) {
    if (slot < 1 or slot >9) {      // checks if the slot number is in range
        return false;
    } else if (board[slot-1] != ' ') {      // checks if the slot is empty
        return false;
    } else {
        return true;
    }
}

// if the move is valid, this functions places the piece in the given slot
bool setSlot(char board[9], int slot, char piece) {
    if (not validMove(board, slot)) {       // if move is not valid, it asks for a valid move
        std::cout << "Trying to place " << piece << " in slot no." << slot;
        std::cout << "\nMake sure to pick an empty slot.\n";
        return false;
    } else if (validMove(board, slot)) {        // if move is valid, it places the piece in the given slot
        board[slot-1] = piece;
        std::cout << "Placed " << piece << " on " << slot << "\n";
        return true;
    } else if (piece != 'X' || piece != 'O') {
        return false;
    } else {
        return false;
    }
}

// checks and returns the current available moves
std::vector<int> availableMoves(char board[9]) {
    std::vector<int> list;
    for (int i = 1; i < 10; i++) {
        if (validMove(board, i)) {
            list.push_back(i);      // appends the available / valid moves to list which is then returned by the function
        }
    }
    return list;
}

//checks if the piece has won the game 
bool checkWin(char board[9], char piece) {
    if (board[0] == piece && board[1] == piece && board[2] == piece) {      // checks top horizontal row
        return true;
    } else if (board[3] == piece && board[4] == piece && board[5] == piece) {       // checks middle horizontal row 
        return true;
    } else if (board[6] == piece && board[7] == piece && board[8] == piece) {       // checks bottom horizontal row
        return true;
    } else if (board[0] == piece && board[3] == piece && board[6] == piece) {       // checks left vertical row
        return true;
    } else if (board[1] == piece && board[4] == piece && board[7] == piece) {       // checks middle vertical row
        return true;
    } else if (board[2] == piece && board[5] == piece && board[8] == piece) {       // checks right vertical row    
        return true;
    } else if (board[2] == piece && board[4] == piece && board[6] == piece) {       // checks '\' row
        return true;
    } else if (board[0] == piece && board[4] == piece && board[8] == piece) {       // '/' row
        return true;
    } else {
        return false;
    }
}

// checks if the game is over i.e. either X or O has won or there are no available moves left
bool gameOver(char board[9]) {
    return checkWin(board, 'X') || checkWin(board, 'O') || availableMoves(board).size() == 0;
}

//starts the game
void startGame() {
    
    demoBoard();        // creates demo board
    char playBoard[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};      // defines play space list 
    char turn = 'X';        // first turn = X
    bool winner = false;
    while (not gameOver(playBoard)) {       // if game is not over
        makeBoard(playBoard);       // prints the current playing board
        int slot = 0;
        std::vector<int> avlMoves = availableMoves(playBoard);     
        while (not std::count(avlMoves.begin(), avlMoves.end(), slot)) {        // checks if move is a valid / available move or not
            std::cout << "It is " << turn << "'s turn. Please select a slot: ";
            std::cin >> slot;
        }
        setSlot(playBoard, slot, turn);     // if it is a legit move, the piece is set in the slot

        if (checkWin(playBoard, turn)) {        // checks if the last move created a winning condition
            std::cout << turn << " has WON!\n";
            makeBoard(playBoard);
            winner = true;
            break;
        }
        if (turn == 'X') {      // if the game is not over, the turn is changed.
            turn = 'O';
        } else {
            turn = 'X';
        }
    }
    if (not winner) {       // if theres no winner and no available moves left, it is a tie
        std::cout << "It was a TIE!\n";
        makeBoard(playBoard);
    }
}