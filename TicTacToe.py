# FUNCTION TO PRINT THE BOARD WHEN CALLED
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

  
# FUNCTION TO CHECK IF THE MOVE IS VALID OR NOT
def validMove(board, slot):
  
  if slot<0 or slot>8:  #if slot doesnt exist
    return False
  for i in range(0,9):
    if board[slot] != ' ':  #if slot is not empty
      return False
  return True


# PLACES THE PIECE AT THE SELECTED SLOT
def selectSlot(board, slot, player):
  
  if not validMove(board, slot-1):  #checks if its a valid move
    print("Invalid Move")
    return False
  
  if board[slot-1] == ' ':  #places the symbol if its an empty slot
    board[slot-1] = player
    print(f"Placed {player} on {slot}")
    return True
  
  return False


# GIVES A LIST OF AVAILABLE MOVES
def availableMoves(board):
  
  moves = []
  
  for i in range(1,10):
    if validMove(board, i-1): # checks if the move is valid and appends it to the list
      moves.append(i)
      
  return moves

# CHECKS IF THE PLAYER HAS WON
def checkWin(board, symbol):
  
  if board[0] == board[4] == board[8] == symbol:  # checks for \ diagonal
    return True
  
  if board[2] == board[4] == board[6] == symbol:  # checks for / diagonal
    return True
  
  for i in range(3):
    if board[i] == board[i+3] == board[i+6] == symbol:  # checks for vertical rows
      return True
    
  for i in range(6):
    if board[i] == board[i+1] == board[i+2] == symbol and (i+3)%3==0: # checks for horizontal rows
      return True
    
  return False

# CHECKS IF THE GAME IS FINSIHED
def gameOver(board):
  
  return checkWin(board, "X") or checkWin(board, "O") or len(availableMoves(board)) == 0 
      
# STARTS THE GAME
def startGame():
  
  playBoard=[' ',' ',' ',' ',' ',' ',' ',' ',' ']
  turn = 'X'
  winner = False
  
  # prints numbered slots board and playing board
  while (not gameOver(playBoard)):
    
    numbering = []
    for i in range(1,10):
      numbering.append(i)
    print("Keep in mind the Slot Numbering")
    printBoard(numbering) # prints numbered board
    
    printBoard(playBoard) # prints playing board
    move = 0
    available = availableMoves(playBoard)
    
    while (move not in available):  # keeps asking for a correct slot until entered one
      move = int(input(f"It is {turn}'s turn.\nPlease select a slot, your options are:\n {str(available)}  > "))
    selectSlot(playBoard, move, turn)
    
    if checkWin(playBoard, turn): # checks if the player won after the last move
      print(f"{turn} has WON!")
      printBoard(playBoard)
      winner = True
      break
    
    if turn == "X": #changes turns
      turn = "O"
    else:
      turn = "X"

  if not winner:  #prints tie message
    print("It was a TIE!")
    printBoard(playBoard)
    
# STARTS THE GAME!!!!
startGame()
