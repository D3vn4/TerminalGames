# creating 7x6 column for the game using a 2D list
playSpace =[[' ',' ',' ',' ',' ',' ',' '],
            [' ',' ',' ',' ',' ',' ',' '],
            [' ',' ',' ',' ',' ',' ',' '],
            [' ',' ',' ',' ',' ',' ',' '],
            [' ',' ',' ',' ',' ',' ',' '],
            [' ',' ',' ',' ',' ',' ',' ']]

#printing top of the board to indicate the column number
columnIndicator = ' '
for n in range(1, len(playSpace)+1):
  columnIndicator += ' ' + str(n) + '  '
print(columnIndicator)
print("+---"*len(playSpace) + "+")

#printing rows and columns of the board
for row in range(len(playSpace[0])):
    print('|   ' * (len(playSpace) +1))
    row_with_items = ''
    for col in range(len(playSpace)):
        row_with_items += ('| '+str(playSpace[col][row])) + ' '
    print(row_with_items + '|')
    print('|   ' * (len(playSpace) +1))
    print('+---' * (len(playSpace)) + '+')
