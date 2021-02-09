#include<stdio.h>

int main() {
    int k=1, inc=1, n=4;
    for(int i=1; i<=n; i++) {
        if(i%2==0) {
            for(int j=1; j<=n; j++) {
                printf("%d ", k);
                k+=(-1);
            }
            k+=(n+1);
        } else {
            for(int j=1; j<=n; j++) {
                printf("%d ", k);
                k+=(1);
            }
            k+=(n-1);
        }
        printf("\n");
    }
}