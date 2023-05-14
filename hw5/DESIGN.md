# Hw5 Design Doc

## score_guess
Return true if guessed word equals the word of the day

Else print x if the letter doesnt appear in the word at all

Else print y if the letter is in the word but in the wrong location

Else print g if the letter is in the right location

Make sure to allocate meomory that is at least 6 bytes long and then free the memory at the end

## valid_guess

Return true if guess is a word in vocabulary file
and false otherwise

Scan through the file and all the words making sure that the array is a big enough size

## load_vocabulary

Return array of strings where each string has a word from the file

One 5 letter word per each line of text in the file

Set starting array size and dynamically allocate using realloc for more and more words

Fopen the file and use strdup to make copies of the words then close the file

Contents of the array are the letters and then it ends with NULL

## free_vocabulary 

Iterate through all the strings in the array and free each one of them

Also free the pointer vocabulary
