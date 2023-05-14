 The purpose of this program is to implement a simple version of the dice game Pass the Pigs.

 First, I prompt the user to put in the amount of players.
The command to do this is provided in the homework.
Also, I need to make sure that the input is between 2 and 10 inclusive.
To do this it would be a condition that if the input is between 2 and 10 then continue the program otherwise print the
error given in the homework.

 Next I need to get a seed from the user in order to randomize the numbers.
I can do this by using the given function within the homework.
Also, make sure there isn't a negative seed as an answer.

 Then, intilize the player points variables all to 0. 
I will keep track of the player's points in an array and update it whenever a player gets points.

 Start the game at player 0 who I know will be a name in names.h in an array and this array also contains the names of
all players in the game as well.
In order to print out their names I will write a print function that indexes until it gets all the names from the array.At the start of each round the program will print out the current player's name.

 All the dice functions will have similar code, where we use the provided names to find out the die rolls. So to
implement this I will have to have each die roll follow the proper chances. For instance for side has a 2/7th chance of rolling. Then I assign point values to each of the rolls and keep track of the points in an array. Also, for side the
point count will not change. In order to end a player's turn they must roll a side so it will yield no points and end a player's turn. Then the turn will continue on to the next player until it comes back full circle or somebody wins the
game. To simulate the die it will find a random number and then modulo 7 to find the correct pig roll.  

 The entire round system will be in a while loop where it will continue until one person has 100 or more points where 
then a stdout message will print with a congratulatory message. 

