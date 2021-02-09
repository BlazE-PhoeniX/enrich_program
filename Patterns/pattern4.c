#include<stdio.h>

int main() {
    int k=1, n=5;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }
}