The focus on this assignment is to teach us how to use reduce.

The first 2 functions are the easiest functions.

For the first function, we need to find the biggest number in an array. For that we need to iterate through each number in an array.

for(int x = o; x < len; x++) 

This would go through each of the numbers. Now we have to compare every number to the number that was the largest at that moment.

int temp
if arr[x] > temp
    temp = arr[x]

if there is a number bigger than temp it will become temp annd then at the end of the for loop, we would return temp which would be the biggest number in the array.

For the second function, we would use the same forloop except we would add the positive numbers

int sum
if arr[x] > 0
    sum += arr[x]

Then at the end we would return sum which would be the dum of all the positive numbers

Reduce is the hardest part

reduce take 2 ints and returns a single int. It is like a helper function that we would use in the last three functions

We would interate throught the array with:

for(int i = 0; i < len; i++)

and then set the initial value to f(int, int) and then we would return initial.

Now for the last three functions, we would use reduce and put in the parameters. Like this:

reduce(parameters)

We also need helper functions to to each of the specific functions and that would be the end of this assignment