#include<stdio.h>
#include<stdlib.h>

void generateArithmeticProgression(int progress[], int startValue, int diff, int length) {
    int temp = startValue;
    for(int index=0; index<length; index++, temp+=diff) {
        progress[index] = temp;
    }
}

void printArray(int array[], int n ) {
    for(int index=0; index<n; index++) {
        printf("%d  ", array[index]);
    }
    printf("\n");
}

int main() {
    int startValue, diff, length;

    printf("Enter the start value: ");
    scanf("%d", &startValue);

    printf("Enter the difference value: ");
    scanf("%d", &diff);

    printf("Enter the no of elements: ");
    scanf("%d", &length);

    int progress[length];

    generateArithmeticProgression(progress, startValue, diff, length);

    printf("Elements of progression: \n");
    printArray(progress, length);

    return 0;
}