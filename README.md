# Wordle_Solver Design Doc

## score_letter

Search through the vocabulary array and then find the number of words that have the given letter
Should be within the size of num_words

## score_word

Use score_letter to get all the letter's values in the word 

Then add them up to get the score of the word

Use a as the first index in the array by subtracting it in the index of letter_scores

For each unqiue letter in the word

set word[i] to letter

then letter_scores[letter - a]

finally add up all the letters to get letter sum

## filter_vocabulary

Set any word in vocab to NULL if it doesn't have the letter in the right position for green

For yellow set any word that doesn't contain the letter or has the letter at the yellow postion to NULL

For gray set any word in vocab to NULL if it has the letter

Make sure to free the words that are set to NULL

So if vocab[i] is not NULL then strchr it with a
