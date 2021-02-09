#include<stdio.h>

int main() {
    int n=5;
    for(int i=1; i<=n; i++) {
        int inc = -1;
        for(int j=n; j>=1 && j<=n; j+=inc) {
            if(j<=i) {
                printf("%d ", j);
            } else {
                printf("  ");
            }

            if(j==1) {
                inc = 1;
            }
        }
        printf("\n");
    }
}