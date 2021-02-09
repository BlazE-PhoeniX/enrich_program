#include<stdio.h>

int main() {
    int k=0, inc=1, n=4;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            k+=inc;
            printf("%d ", k);
        }
        printf("\n");
        k+=n+inc;
        inc*=-1;
    }
}