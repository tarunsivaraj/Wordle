# CSE 13s, Winter 2022 -- Midterm Exam

  * name: Tarun Sivaraj
  * email: sammyslug@ucsc.edu  (tsivaraj@ucsc.edu)

*I understand that getting help from a classmate or an external source would
be a violation of academic integrity. So I did all of this work myself.*
signed: Tarun Sivaraj


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

YOUR PLAN & EXPLANATION HERE (code goes in midterm.c)

So I plan to do tis iteratively since I understood that was a lot more in the 
lecture. The first step you do is allocating memory in terms of a long long 
to make space for the array. After, I added in the base case of 1 and started
the sequence from there. Then I used inspiration from the demos to do my forloop
and keeping track of the currect, previous, and previousprevious. Then in the main, 
you would have to set n equal to some number and iterate through the array to print
out the statements.

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

YOUR PLAN & EXPLANATION HERE (code goes in midterm.c)

Here, I would implement the base bubble sort code and then change it and include
the pointers etc. You would sort it in terms of shoe size, but you would swap the whole customers
since you want everything in there to get swaped. Pointer math would be used when swaping, 
kind of like indexing values.

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

YOUR PLAN & EXPLANATION HERE (code goes in midterm.c)

This took a little more time. First you would need a while loop to traverse
the linked list. Then the special function would be added and then you would make a new linked
list and add them onto there. You would have to keep track of te previous one since
you would have to link them. The last node will not have a link after that since
the next is NULL. You would keep track of the head node since that is how you access the 
linked list.


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

YOUR PLAN & EXPLANATION HERE (code goes in midterm.c)

Here, I used inspiration from the most recent lecture. What AND does is it
returns 1 only if both of the values in the operation is 1. Here, if we AND all the schedules,
the 1's would be where everyone of available. In the end, you would get the number in the position 
in binary where everyone would be available.

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

YOUR ANSWER HERE

We went to the memory address of the second value on the array of floats. The value of p would be
`0xC0FF37`. The value of p + 5 would be `0xC0FF43`.

## problem 6 (short answer)
In math, how many real numbers are there? Comparatively, in a computer, how many
floating point numbers (C type `float`) are there? How could you find out how
many floating point numbers there are, for sure?

YOUR ANSWER HERE

In math, there are an infinite amout of real number, since there is no end
and numbers keep getting bigger and bigger. In a computer, there is a set amount of memory,
that means it can not be infinite. First 2^24 are the posible numbers that can be represented, 
which is 16777216. The total number of combination would be 2^24*127 whihc is 2130706432.
2^24 * 127