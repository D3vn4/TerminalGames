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
