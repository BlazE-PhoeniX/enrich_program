#include<stdio.h>

int main() {
    int k=1, inc=1, n=5;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ", k);
            k+=inc;
        }
        printf("\n");
        inc*=-1;
        k+=n+inc;
    }
}