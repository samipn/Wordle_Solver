# Hw3 Design Doc
## Stack Push
First implement the false return if the node = NULL

Then, implement adding a new node to the front of the stack

Allocate memory for the stack, then point the node to the data of the number or operator

After, set that node to the top node, then return True

## Stack Pop
Return false if the pointer is NULL

Then set a variable to the resulte and then delete when the data is the top of the stack

Next set it to the next node in the stack and free memory, then return true

## Stack Empty
Check if the stack is empty by indexing through the stack and if it equals NULL return True else return False

## Stack Delete
Loop through the entire stack and free every node that it contains

After set the stack pointer to NULL

## Stack Compute Step
Try to do the arithemetic in the stack if it returns an error return false otherwise return true
