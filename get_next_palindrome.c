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


int getNextPalindrome(int number) {
    while(!checkPalindrome(number)) {
        number++;
    }
    return number;
}

int main() {
    int number, palindromeNo;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    palindromeNo=getNextPalindrome(number);
    printf("Next Palindrome number = %d\n\n", palindromeNo);
}
