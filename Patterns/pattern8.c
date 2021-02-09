#include<stdio.h>

int main() {
    int k, n=5;
    for(int i=n; i>=1; i--) {
        k=n;
        for(int j=1; j<=n; j++) {
            printf("%d ", k);
            if(k>i) {
                k--;
            }
        }
        printf("\n");
    }
}