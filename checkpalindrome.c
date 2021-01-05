#include<stdio.h>
#include<string.h>

int reverseNo(int number) {
    int reverse=0;
    while(number!=0) {
        reverse = reverse*10 + (number%10);
        number/=10;
    }
    return reverse;
}

int checkPalindrome(int number) {
    return number==reverseNo(number);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(checkPalindrome(number)) {
        printf("%d is palindrome\n\n", number);
    } else {
        printf("%d is not palindrome\n\n", number);
    }
}
