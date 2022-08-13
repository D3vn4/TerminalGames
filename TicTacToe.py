def printBoard(board):
  print(f"""
     |   |   
   {board[0]} | {board[1]} | {board[2]} 
     |   |   
  ---+---+---
     |   |
   {board[3]} | {board[4]} | {board[5]} 
     |   |   
  ---+---+---
     |   |   
   {board[6]} | {board[7]} | {board[8]} 
     |   |   """)

def validMove(board, slot):
  if slot<0 or slot>8:
    return False
  for i in range(0,9):
    if board[slot] != ' ':
      return False
  return True

def selectSlot(board, slot, player):
  if not validMove(board, slot-1):
    print("Invalid Move")
    return False
  if board[slot-1] == ' ':
    board[slot-1] = player
    print(f"Placed {player} on {slot}")
    return True
  return False

def availableMoves(board):
  moves = []
  for i in range(1,10):
    if validMove(board, i-1):
      moves.append(i)
  return moves

def checkWin(board, symbol):
  if board[0] == board[4] == board[8] == symbol:
    return True
  if board[2] == board[4] == board[6] == symbol:
    return True
  for i in range(3):
    if board[i] == board[i+3] == board[i+6] == symbol:
      return True
  for i in range(6):
    if board[i] == board[i+1] == board[i+2] == symbol and (i+3)%3==0:
      return True
  return False

def gameOver(board):
  return checkWin(board, "X") or checkWin(board, "O") or len(availableMoves(board)) == 0 
      

def startGame():
  playBoard=[' ',' ',' ',' ',' ',' ',' ',' ',' ']
  turn = 'X'
  winner = False
  

  while (not gameOver(playBoard)):
    numbering = []
    for i in range(1,10):
      numbering.append(i)
    print("Keep in mind the Slot Numbering")
    printBoard(numbering)
    printBoard(playBoard)
    move = 0
    available = availableMoves(playBoard)
    while (move not in available):
      move = int(input(f"It is {turn}'s turn.\nPlease select a slot, your options are:\n {str(available)}  > "))
    selectSlot(playBoard, move, turn)
      
    if checkWin(playBoard, turn):
      print(f"{turn} has WON!")
      printBoard(playBoard)
      winner = True
      break

    if turn == "X":
      turn = "O"
    else:
      turn = "X"

  if not winner:
    print("It was a TIE!")
    printBoard(playBoard)
    
startGame()
