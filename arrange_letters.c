#include<stdio.h>
#include<string.h>

void arrangeStrings(char resultStr[], char str1[], char str2[]) {
    int index=0, str1Index=0, str2Index=0;

    for(; str1[str1Index] && str2[str2Index]; index++) {
        if(str1[str1Index]<=str2[str2Index]) {
            resultStr[index]=str1[str1Index];
            str1Index++;
        } else {
            resultStr[index]=str2[str2Index];
            str2Index++;
        }
    }

    while(str1[str1Index]) {
        resultStr[index]=str1[str1Index];
        index++;
        str1Index++;
    }
    
    while(str2[str2Index]) {
        resultStr[index]=str2[str2Index];
        index++;
        str2Index++;
    }

    resultStr[index] = '\0';

}

int main() {
    char str1[20], str2[20];
    char resultStr[40];

    printf("Enter string 1: ");
    scanf("%s", str1);

    getchar();

    printf("Enter string 2: ");
    scanf("%s", str2);

    arrangeStrings(resultStr, str1, str2);

    printf("Result string: %s\n\n", resultStr);

}