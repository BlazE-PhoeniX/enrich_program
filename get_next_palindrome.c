#include<stdio.h>
#include<string.h>

long int reverseNo(long int number) {
    long int reverse=0;
    while(number!=0) {
        reverse = reverse*10 + (number%10);
        number/=10;
    }
    return reverse;
}

int checkPalindrome(long int number) {
    return number==reverseNo(number);
}


long int getNextPalindrome(long int number) {
    while(!checkPalindrome(number)) {
        number++;
    }
    return number;
}

int main() {
    long int number, palindromeNo;
    
    printf("Enter a number: ");
    scanf("%ld", &number);
    
    palindromeNo=getNextPalindrome(number);
    printf("Next Palindrome number = %ld\n\n", palindromeNo);
}
