#include<stdio.h>

int main() {
    int odd=1, even=2, n=5;
    for(int i=1; i<=n; i++) {

        int *var = (i%2==1) ? &odd : &even;

        for(int j=1; j<=i; j++) {
                printf("%d ", *var);
                (*var)+=2;
        }
        printf("\n");
    }
}