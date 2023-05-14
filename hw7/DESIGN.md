# Hw7 Design Doc

## Struct for hash table

This struct will contain all essential information to store in the hash table.

The key will be the email. For the values, I will have the name, the shoe size, and a favorite food stored within. It will also contain a next node which will be used for traversing the linked list.

## Hash function

For the hash function, I need to have a hash number. Then I loop through all the strings in the customers.tsv file.

In the loop I will right shift 5 times and add the hash number that I stored previously to my int.
Then add 1 to the str and continue until it hits the null byte at the end of the string.

Finally, return that hashed number.

## Loading customers

To loop through all the strings in the file I know that each tab indicates a new data item, and so at every tab, I assign the values and when it hits a new line I know that indicates the next person to be added to the hash table. 

If the loop runs into NULL then I know it has hit the end of the customers.

Currently I plan to go line by line with the implementation.

## Add function

To add the data to the hash struct, I will need to make two functions to add the data to a list and then add the data to the hashtable. 

This function when used will prompt the user for a email, name, shoe size, and favortite food.

Next, I need to allocate memeory for a node, and then I can use strdup to assign all the values to the correct numbers that are inputted in the function. Also, I need to make the next node point to bucket, which is where the hashed value will go.

Then, return that node that I just created.

For the second function, I will set the buckets to size 10 and then use the hash of the email and modulo the number of buckets, this will allow me to add the data to the correct bucket.

Then in the array I use the previous function to add the values to the array.

Also, I need to have an if statement at the start of this function that check that if strcmp is equal to zero, meaning if the inputted email is the same as an email already in the hash table, I need to reassign all the values that are given for that email.

## Lookup function

Prompts the user for an email.

To search for a specific email I have to make sure I have the hash(email address) modulo number of buckets.

Then I create a node that is the array of buckets that contains the bucket I want.

Then while the node is NOT equal to NULL, if an email in the hash table matches the inputted email, which can be done using strcmp. Then the function has to set all the values of the node to the ones stored in the hash table. 

Then it sets itself to the next node, and ends by printing all the values in a nicely formatted way.

However, if the email addresses do not match, then just have an error message printing that the email couldn't be found.

## Delete function

For this function I will use the lookup function that I made before to find the email address that the user searches for and it will go into the hash table and have to delete from the linked list within the bucket.

The first check I have to do is I have to make sure the email inputted actually matches an email within the hash table, and if it doesn't I print a nice error message. To loop through the hash table I just do what I did for the previous function.

If there is an email that matches, then I will have to loop through the linked list inside each bucket, by using a nested loop that goes through the buckets if they have data in them and then it loop through the linked list inside the buckets to find the email address and then delete it from the hash table, and set the empty spot to NULL, which is somewhat similar to what I have had to do for previous assignments.

## List function

This function has to loop through the customers.tsv file which I have done for the add function already.
Then it will just print out everything within the loop and make it look like the actual file.

So each entry will be tab seperated and then there will be a newline when it prints the next user's information.

## Save function

To save the changes made I will have to use the write function in the I/O settings, using the information we went over in class. 

To write my structured data into the file I will have to go into the buckets and within the linked list in each bucket, I will need to get that data and overwrite the file itself. This may make the ordering different, but it will save all the changes made whether it be a deletion or addition.

## Quit function

For the quit function I will need to free the memory I have allocated within the entire program which is at the start in the add function.

This function will be similar to the other free functions I have made in the past for this class, as it will loop through all the nodes that need to be freed, and then free the struct itself. 

After freeing all the memory I have to make sure to fclose(customers.tsv) and then use exit() to terminate the program.

## Linked list of customers within each bucket

For the linked list, I will have to make a seperate struct like I have done before for previous assignments.

The linked list will have allocation of memory so I must make sure that I free it as well. Then it will contatin the values needed and the next node, like the hash table struct.
