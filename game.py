
ps = [[' ', ' ', ' ', ' ', ' ', ' ', ' '],
[' ', ' ', ' ', ' ', ' ', ' ', ' '],
[' ', ' ', ' ', ' ', ' ', ' ', ' '],
[' ', ' ', ' ', ' ', ' ', ' ', ' '],
[' ', ' ', ' ', ' ', ' ', ' ', ' '],
[' ', ' ', ' ', ' ', ' ', ' ', ' ']] 


def openRowFinder(column):
  for i in range (0,6):
    if ps[5][column] == ' ':
      availableRow = 5
      return availableRow
      break
    if ps[0][column] != ' ':
      print('Invalid move: Column is Full')
      break
    if  column < 0 or column > 7:
      print("Invalid move: Column doesn't Exist")
      break
    if ps[i+1][column] != ' ':
      availableRow = i
      return availableRow
      break
    else:
      pass

    
def dropPiece(piece, column):
  row = openRowFinder(column)
  global ps
  ps[row][column] = piece
  board = f'''
  1   2   3   4   5   6   7
+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |
| {ps[0][0]} | {ps[0][1]} | {ps[0][2]} | {ps[0][3]} | {ps[0][4]} | {ps[0][5]} | {ps[0][6]} |   6
|   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |
| {ps[1][0]} | {ps[1][1]} | {ps[1][2]} | {ps[1][3]} | {ps[1][4]} | {ps[1][5]} | {ps[1][6]} |   5
|   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |
| {ps[2][0]} | {ps[2][1]} | {ps[2][2]} | {ps[2][3]} | {ps[2][4]} | {ps[2][5]} | {ps[2][6]} |   4
|   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |
| {ps[3][0]} | {ps[3][1]} | {ps[3][2]} | {ps[3][3]} | {ps[3][4]} | {ps[3][5]} | {ps[3][6]} |   3
|   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |
| {ps[4][0]} | {ps[4][1]} | {ps[4][2]} | {ps[4][3]} | {ps[4][4]} | {ps[4][5]} | {ps[4][6]} |   2
|   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |
| {ps[5][0]} | {ps[5][1]} | {ps[5][2]} | {ps[5][3]} | {ps[5][4]} | {ps[5][5]} | {ps[5][6]} |   1
|   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+
'''
  print(board)
  
  
def winCondition():
  for i in range(0,6):
    for j in range(0,7):
      if (j<4) and (ps[i][j] == ps[i][j+1] == ps[i][j+2] == ps[i][j+3] == 'X' or ps[i][j] == ps[i][j+1] == ps[i][j+2] == ps[i][j+3] == 'O'):
        return True
        break
      elif (i<3) and (ps[i][j] == ps[i+1][j] == ps [i+2][j] == ps[i+3][j] == 'X' or ps[i][j] == ps[i+1][j] == ps [i+2][j] == ps[i+3][j] == 'O'):
        return True
        break
      elif (i<3 and j<4) and (ps[i][j] == ps[i+1][j+1] == ps[i+2][j+2] == ps[i+3][j+3] == 'X' or ps[i][j] == ps[i+1][j+1] == ps[i+2][j+2] == ps[i+3][j+3] == 'O'):
        return True
        break
      elif (j-3>=0 and i<3) and (ps[i][j] == ps[i+1][j-1] == ps[i+2][j-2] == ps[i+3][j-3] == 'X' or ps[i][j] == ps[i+1][j-1] == ps[i+2][j-2] == ps[i+3][j-3] == 'O'):
        return True
        break
        
        
def playGame():
  while True:
    if winCondition() == True:
      print("WON")
      break
    pieceMove = input("Select your Piece [O or X]: ")
    move = int(input("Select Column to drop your piece: "))
    dropPiece(pieceMove, move-1)
playGame()
