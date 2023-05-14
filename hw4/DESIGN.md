# Hw4 Design Doc
## Pathing and Breadth-First Search
For both of these functions I can use code provided from the demos and the psuedocode provided by Dr. Rudnick

## Depth First Search
Need to create a stackt that can use path behavior in order to make depth first search

To do this I will have to make the function loop through all the paths using the stack

Then it will need to go back to the starting path and repeat this process until it goes through all the paths

After, I will need it to return the longest path by comparing all the paths and then only accept the longest one

Also, I have to remember to free the memory that I allocate and I can use valgrind to make sure there are no memory leaks
