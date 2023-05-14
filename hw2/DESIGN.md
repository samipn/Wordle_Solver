To find the maximum of an array I have to loop through the array and find the largest number and return it.
In order to do this I set a variable that is the first element of the array.
Then, I check if through all the numbers of the array to see if they are bigger than that variable.
Next I sete the variable to that number if it is true, and return that varaible.

For the find positives and sum them all up array, I will use another for loop.
This time it checks if the number is greater than zero and if so it will add up the numbers.

For reduce we use what we have for the previous two functions. 
Using the map function provided to us, I can use the cumulative value to go thorugh the array.
Making sure to check for NULL along the way.
Then it updates the value of the counter.

For using reduce in maximum elements I will need a helper function that finds the max of the two values.
Then it will return the maximum using reduce and its counter.

Summing all the positive numbers with reduce can be done by calling reduce and using the code for the positive function earlier.
The same can be done for the negative numbers except it will be if the number is less than 0, do the check.
