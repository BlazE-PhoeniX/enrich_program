#include<stdio.h>

int main() {
    int k, n=5;
    for(int i=1; i<=n; i++) {
        k = i%2;
        for(int j=1; j<=n; j++) {
            printf("%d ", k);
            k = !k;
        }
        printf("\n");
    }
}