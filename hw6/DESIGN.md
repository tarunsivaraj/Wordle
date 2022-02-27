Assignment 6

In this assignment we have to implement 5 functions in search_util.c

int score_letter(char letter, char **vocabulary, size_t num_words)

What this function is suppose to return the number of times a letter appears in a word. Since the max number of letters in the word is 5, the number can not be more than five. We would compare char to each letter in each word and compare to see if it is equal to each other. If then, we would keep a counter and increment it if it is equal to each other.

int score_word(char *word, int *letter_scores)

this function will calculate a score for each word. Im not really sure how this function works, but ill add more as I learn more how to to it.

size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words)

What this function would do is remove the words that don't have the specific letter in it. So if a word has the letter a in it, this function would remove all the words that don't have the letter a in it. The pool of words will get a lot smaller and it will be easier to guess the word from that. This would be at any position. since it is gray, it would filter the words out that result in an x. For yellow, you would filter the words out that don't have that specific letter. For green, you would filter out the words that don't have the specific letter in a specific position


