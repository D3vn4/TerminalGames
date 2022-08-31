#include <vector>
void greet();
void makeBoard(char game[9]);
void demoBoard();
void setPiece(int slot, char piece, char board[9]);
bool validPiece(int slot, char piece, char board[9]);
bool checkWin(char board[9], char piece);
bool checkDraw(char board[9]);
bool gameIsOver(char board[9]);
void startGame();


char playGame[9] = {' ', ' ', ' ', ' ', ' ', ' ' ,' ', ' ', ' '};
std::vector<char> avlMoves;