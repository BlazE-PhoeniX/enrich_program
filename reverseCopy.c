#include<stdio.h>
#include<stdlib.h>

void reverseCopy(int reverse[], int array[], int n) {
    for(int i=0, j=n-1; i<n; i++, j--) {
        reverse[j] = array[i];
    }
}

void printArray(int array[], int n ) {
    for(int i=0; i<n; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int array[n], reverse[n];

    printf("Enter the number of elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }

    reverseCopy(reverse, array, n);

    printf("Elements of revered array: \n");
    printArray(reverse, n);

    return 0;
}