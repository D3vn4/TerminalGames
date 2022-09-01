#include <vector>

void greet();
void makeBoard(char game[9]);
void demoBoard();
void startGame();
bool validMove(char board[9], int slot);
bool setSlot(char board[9], int slot, char piece);
std::vector<int> availableMoves(char board[9]);
bool checkWin(char board[9], char piece);
bool gameOver(char board[9]);
void startGame();
