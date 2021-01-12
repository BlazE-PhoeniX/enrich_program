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

int countVowels(char word[]) {
    int noOfVowels = 0;
    
    for(int index=0; word[index]!='\0'; index++) {
        if(checkVowel(word[index])) {
            noOfVowels++;
        }
    }

    return noOfVowels;
}

int main() {
    char word[100];
    int noOfVowels;

    printf("Enter the word or sentence: \n");
    fgets(word, 100, stdin);

    noOfVowels = countVowels(word);

    printf("\nNumber of vowels: %d\n", noOfVowels);
    return 0;
}
