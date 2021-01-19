#include<stdio.h>
#include<string.h>

void addStrings(char result[], char num1[], char num2[]) {
    int num1Index=strlen(num1)-1, num2Index=strlen(num2)-1;
    int index = num1Index > num2Index ? num1Index: num2Index;

    result[index+1] = '\0';

    while(num1Index>=0 && num2Index>=0) {
        result[index--] = num1[num1Index--] + num2[num2Index--] - 48;
    }

    while(num1Index>=0) {
        result[index--] = num1[num1Index--];
    }

    while(num2Index>=0) {
        result[index--] = num2[num2Index--];
    }
}

int main() {
    char num1[20], num2[20];
    char result[20];

    printf("Enter string 1: ");
    scanf("%s", num1);

    getchar();

    printf("Enter string 2: ");
    scanf("%s", num2);

    addStrings(result, num1, num2);

    printf("Result string: %s\n\n", result);

    return 1;

}