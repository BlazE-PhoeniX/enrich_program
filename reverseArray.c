#include<stdio.h>
#include<stdlib.h>

void reverseCopy(int array[], int n) {
    for(int i=0; i<n/2; i++) {
        int temp =array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp;
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

    int array[n];

    printf("Enter the number of elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }

    reverseCopy(array, n);

    printf("Elements after reversing array: \n");
    printArray(array, n);

    return 0;
}