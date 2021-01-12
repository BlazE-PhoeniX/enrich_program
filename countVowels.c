#include<stdio.h>
#include<stdlib.h>

int checkVowel(char c) {
    switch(c) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return 1;

        default:
            return 0;
    }
}

int countVowels(char *word) {
    int noOfVowels = 0;
    while(*word!='\n' || *word!='\0') {
        if(checkVowel(*word)) {
            noOfVowels++;
        }
        word++;
    }

    return noOfVowels;
}

int main() {
    char word[20];

    printf("Enter the word or sentence: \n");
    fgets(word, 100, stdin);

    countVowels(word);
}
