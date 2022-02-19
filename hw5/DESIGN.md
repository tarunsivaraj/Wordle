This is the Design Doc for Assignment 5. In this assignment, we are recreating the newly popular game wordle.

In this assignment, we need to finish 4 different fucntions and we also need to keep track of how we are allocating memory since we can't have memory leaks and we need to free it at the end. To check whether or not we have memory leaks, we would use valgrind.

bool score_guess(char *secret, char *guess, char *result) <-- this is the first function

Returns true if the guess is an exact match with the secret word. We also read the guesses and we add letter to the slot depending on the word.
 x if the letter is not there, y is the letter is in the word, and g if the letter is in the same spot

 bool valid_guess(char *guess, char **vocabulary, size_t num_words) <-- second function

 Returns true if the specified guess is one of the strings in the vocabulary. We would do a simple linear search in th txt file. Not sure how the psuedocode is suppose to be so I will add it in when I figure out how to do it. 

 char **load_vocabulary(char *filename, size_t *num_words) <-- third function

 Returns an array of strings (so, char **), where each string contains a word from the specified file. The file is assumed to contain 5-letter words, one per line. This fucntion loads the vocab txt file to be open and read so that we can check if the user inputs are real words and not a bunch of random letter to try to find out the letter.

 void free_vocabulary(char **vocabulary, size_t num_words) <-- fourth function

 This function is responsible for freeing everything so that we have no memory leaks.

 I am not sure how to approach this yet, so that is why I don't have psuedocode yet. I will add that onto this doc as soon ad I watch some of the section recording and get an idea on how to implement each one of these fucntions.