#include<stdio.h>
#include<stdlib.h>

void splitArray(int array[], int n, int odd[], int *oddCount, int even[], int *evenCount) {
    *evenCount = *oddCount = 0;
    for(int i=0; i<n; i++) {
        if(array[i]%2==0) {
            odd[*oddCount] = array[i];
            (*oddCount)++;
        } else {
            even[*evenCount] = array[i];
            (*evenCount)++;
        }
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

    int array[n], odd[n], even[n];
    int oddCount, evenCount;

    printf("Enter the number of elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }

    splitArray(array, n, odd, &oddCount, even, &evenCount);

    printf("Even numbers: \n");
    printArray(even, evenCount);

    printf("Odd numbers: \n");
    printArray(odd, oddCount);

    return 0;
}