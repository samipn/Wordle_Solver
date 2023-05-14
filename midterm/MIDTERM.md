# CSE 13s, Winter 2022 -- Midterm Exam

  * name: Samip Niraula
  * email: saniraul@ucsc.edu  (put yours here)

*I understand that getting help from a classmate or an external source would
be a violation of academic integrity. So I did all of this work myself.*
signed: Samip Niraula


**HOWTO do this midterm** -- this is a take-home exam, to be done by just you,
with your notes, with the reading materials, and with your ability to read man
pages and search the web. Do not consult with other students, and do not ask
people other than the course staff for help!

The midterm is due in 24 hours (+ accommodations), and turned in the same way
that we turn in homeworks. You must check in your materials into your
course git repository *and* upload the relevant commit ID on Canvas by then.
For most students, this is due at *1:20pm on Thursday 10 February 2022*. 

So make sure you check in *at least* these files into a directory called
`midterm` in your git repository:
  * your completed `MIDTERM.md` (ie, this file, filled out)
  * your completed `midterm.c`
  * your `Makefile` for compiling the code -- make sure to turn on the strict
    compiler flags before turning in.

For short answer questions, write your response in this file. For the
programming problems, write a short explanation of what your code does (and *why
it does it!*) in this file, and complete the program in `midterm.c`.

## problem 1

Write a function that returns the first *n* Fibonacci numbers, in a dynamically
allocated array of type `long long`. Recall that the sequence goes 1, 1, 2, 3,
5, 8...

Should this be done iteratively or recursively?

The Fibonacci numbers are a set of numbers where each number in the sequenece is the sum of the last two numbers.

I will implement this recursively. 

To implement this I will start by setting the starting variables to 1 and 1 as they are the first numbers in the sequence.

Then I will make a for loop that will keep going until it reaches the length set by the user which is stored in n.

The length must be within bounds so there will be error checking to implement. 

Then inside the loop it will add the two last sums and store it.
In the end it will return the answer.

## problem 2

[Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) is a simple (but
relatively inefficient) sorting algorithm that works by comparing elements in an
array and swapping them if they are in the incorrect order.

The pseudocode looks like:

* keep doing this...
  * for every element x of my input array
    * for every *other* element y of my input array
      * if x should go before y but does not, swap x and y's position in the
        array
* stop if I did not perform any swaps

Imagine that we are working at an online shoe retailer, and we want to sort our
customers by their shoe size.

Implement a function for bubble sorting procedure that sorts customers by shoe
size, ascending. Smallest shoe sizes should go first, larger shoe sizes later.

Make a swap function to help when swapping numbers.

Following psuedocode I can use a do while loop with a boolean that only becomes true once I have sorted the array.

Then I start it at false and loop through the n_customers using a for loop.

Then I do the same for every other element in the same array.

Inside those loops I make an if statement that will only switch the shoe sizes if the first one is larger than the next.

Then it swaps them using the function and sets the bool to true.

After that we -1 to n_customers everytime.

## problem 3

Recall in homework 2, we wrote a function `reduce`, which took a collection of
numbers and reduced it down to a single number, essentially a summary of that
collection.

Here we will write a version of the companion function to *reduce*, which is
called [*map*](https://en.wikipedia.org/wiki/Map_(higher-order_function)). Map
takes a function and applies that function to each element in the collection,
and returns a collection of the same shape.

In this version, we will take in a linked list of floating point numbers (see
`LLfloat` in the code) and return a *new* linked list of floating point numbers,
of the same length, where each element of the new list is the result of calling
the specified function on the corresponding number in the input list.

For example, if your input list consisted of:
`[0, 1, 2, 3]`

And your specified function computed the square of the input number, then your
function would return a new linked list (you'll have to allocate it with
`malloc` or `calloc` !) containing:
`[0, 1, 4, 9]`

For this one, I will first check if the linked list is null and print that it is empty. 

Next, I will loop through the length of the list and then apply the function to the values in the linked list.

Afterwords, I make a new linked list whose values are the ones that I changed. I need to allocate memory for the list as well.

Next I make the next node point to the linked list itself.

Finally, I have to make sure I dont forget to free the memory.


## problem 4

Imagine that we are building a calendar system, and we want to find out when a
group of different users are available for a meeting. Here we will represent a
user's availability with a bit vector in the form of an `unsigned long` -- we
get 64 different appointment slots during a week, and a user can be either
*available* (the bit is set to 1) or *unavailable* (the bit is set to 0) for
that appointment slot.

Write a function that takes an array (ie, a pointer to an array) of these
bit-vector calendars, a number of users (ie, the size of the array) and returns
a single `unsigned long` where each bit in the unsigned long is set to 1 if *all
users* are available at that time.

I have to loop through the entire calenders array using the num_users as the length.

Then I check if every bit is 0 or 1.

If its 0 then I return 0.

If its 1 then I return the unsigned long with every bit at 1.

## problem 5 (short answer)

Consider the following code snippet:

```
float f[10];
float *p;
p = f;
p++;
```

Say that you found out that the array `f` was at memory address `0xC0FF33`. In
your own words, what did we do on the line `p++`, and what is the value of `p`
after this code runs? What is the value of `p + 5`? (give these as hexidecimal
numbers)

Every element in the f[10] array takes up 4 bytes. When we do p++ it means we are adding 1 to p which in turn adds four bytes to the memory address, so now p = 0xC0FF37. 

Then that means that p + 5 = 0xC0FF53.

## problem 6 (short answer)
In math, how many real numbers are there? Comparatively, in a computer, how many
floating point numbers (C type `float`) are there? How could you find out how
many floating point numbers there are, for sure?

There are infinite real numbers in math. In a computer, there are 32 bits of space for a float which means it can hold any number between 1.2E-38 to 3.4E+38. 

To find out how many there are for sure you would need to add the binary of a 32 bit number when all of the bits are set to 1.
