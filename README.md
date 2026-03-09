======================

====Monoploy Board====

======================

This Monooly board is constructed by utilizing a circular linked list made up of 40 nodes and no more, which all have their own names, colors, values, and rent.

The game can be played by running the program and upon running 2 dice will be rolled determining your move, add up both dice and that number is how many spaces you can move foward. As the player moves foward and reaches the end of the board because a circular linked list is being used the player will start at the headNode after the tailNode. 



addSpace() - adds a space to the board

addMany() - adds all 40 spaces to the board 

movePLayer() - moves the player depending on what they recieved from dice roll

printFromPlayer() - prints all spaces(property name, color, value, and rent) all spaces infront of  player starting from the one they are on 

findByColor() - finds all properties that have matching colors

removeByName() - removes a specific property from the board by name

mirrorBoard() - reverses the board and the pointer of nodes

countSpaces() -counts all nodes in list as they are added

clear() - deletes all nodes in list
