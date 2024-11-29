#include <stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

struct WordWithHint {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};
void displayword(const char secretword[],const bool guessedletter[]);
void drawhangman(int tries);

int main() {
    srand(time(NULL));
    struct WordWithHint wordList[] = {
        {"geeksforgeeks", "Computer programming language"},
        {"leetcode", "A popular coding platform"},
        {"google", "Search engine developed by Google"},
        {"microsoft", "A multinational technology company"},
        {"apple", "A multinational technology company"}
    };
    int wordIndex = rand() % 5;
    const char* secretWord = wordList[wordIndex].word;
    const char* hint = wordList[wordIndex].hint;
    int wordlength=strlen(secretWord);
    bool guessedletters[26] = {false};
    printf("Welcome to Hangman Game\n");
    printf("Hint: %s\n", hint);
    int tries = 0;
    while (tries<MAX_TRIES)
    {
        /* code */
        printf("\n");
        displayword(secretWord,guessedletters);
        drawhangman(tries);
        char guess;
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess=tolower(guess);
        if(guessedletters[guess-'a'])
        {
            printf("You have already guessed this letter.\n");
            continue;
        }
        guessedletters[guess-'a'] = true;
        bool found = false;
        for (int i = 0; i < wordlength; i++) {
            if (secretWord[i] == guess) {
                found = true;
            }
        }
        if(found){
            printf("Correct guess!\n");
        }else{
            printf("Incorrect guess. You have %d tries left.\n", MAX_TRIES-tries-1);
            tries++;
        }
        bool complete = true;
        for (int i = 0; i < wordlength; i++) {
            if (!guessedletters[secretWord[i] - 'a']) {
                complete = false;
                break;
            }

        }
         if(complete){
                printf("\nCongratulations! You've guessed the word: %s\n", secretWord);
                break;
            }
        if(tries==MAX_TRIES){
            printf("\nGame Over! The word was: %s\n", secretWord);
        }


    }
    return 0;
}

void displayword(const char secretword[], const bool guessedletters[]) {
    printf("Word : ");
    for (int i = 0; secretword[i]!= '\0'; i++) {
        if (guessedletters[secretword[i] - 'a']) {
            printf("%c ", secretword[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void drawhangman(int tries) {
    const char* hangmanParts[] = {
        " _________",
        " |       |",
        " |       O",
        " |      /|\\",
        " |      / \\",
        " |"
    };
    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangmanParts[i]);
    }
}
