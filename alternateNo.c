#include<stdio.h>

int main() {
    int odd=1, even=2, n=5;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(i%2==1) {
                printf("%d ", odd);
                odd+=2;
            } else {
                printf("%d ", even);
                even+=2;
            }
        }
        printf("\n");
    }
}