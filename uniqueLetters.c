#include<stdio.h>
#include<stdlib.h>

int checkIfAlphabet(char c) {
    if( (c>=65 && c<=90) || (c>=97 && c<=122) ) {
        return 1;
    }
    return 0;
}

int checkIfPresentInString(char string[], char charToCheck, int stringLength) {
    for(int index=0; index<stringLength; index++) {
        if(string[index] == charToCheck) {
            return 1;
        }
    }
    return 0;
}

void getUniqueChars(char word[], char uniqueChars[]) {
    int uniqueCharsCount = 0;
    
    for(int index=0; word[index]!='\0'; index++) {
        if(checkIfAlphabet(word[index]) && !checkIfPresentInString(uniqueChars, word[index], uniqueCharsCount)) {
            uniqueChars[uniqueCharsCount++]=word[index];
        }
    }
    uniqueChars[uniqueCharsCount] = '\0';
}

int main() {
    char word[100], uniqueChars[100];

    printf("Enter the word or sentence: \n");
    fgets(word, 100, stdin);

    getUniqueChars(word, uniqueChars);

    printf("\nUnique characters:\n%s\n", uniqueChars);
    return 0;
}
