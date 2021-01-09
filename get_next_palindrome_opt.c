#include<stdio.h>
#include<string.h>

int getDigitCount(long int number) {
    int count=0;
    while(number!=0) {
        count++;
        number/=10;
    }
    return count;
}

void incrementMiddleMembers(short int numberArr[], int n) {
    if(n%2==0 || numberArr[n/2]==9) {
        int i=1;
        while(numberArr[n/2 - i] == 9) {
            numberArr[n/2 - i]=0;
            i++;
        }
        numberArr[n/2 - i]++;
    } 

    int i=0;
    while(numberArr[n/2 +i] == 9) {
        numberArr[n/2 +i] = 0;
        i++;
    }
    numberArr[n/2 + i]++;
}

long int joinNumberArr(short int numberArr[], int digitCount) {
    long int number=0;
    for(int i=0; i<digitCount; i++) {
        number = number*10 + numberArr[i];
    }
    return number;
}

void formPalindrome(short int numberArr[], int n) {
    for(int i=0; i<n/2; i++){
        numberArr[n-i-1] = numberArr[i];
    }
}

long int getNextPalindrome(long int number) {

    long int temp = number;
    int digitCount=getDigitCount(number);
    short int numberArr[digitCount];

    for(int i=digitCount-1; i>=0 && temp!=0; i--) {
        numberArr[i] = temp%10;
        temp/=10;
    }

    formPalindrome(numberArr, digitCount);

    long int palindromeNo = joinNumberArr(numberArr, digitCount);

    if(palindromeNo < number) {
        incrementMiddleMembers(numberArr, digitCount);
        palindromeNo = joinNumberArr(numberArr, digitCount); 
    }

    return palindromeNo;
}

int main() {
    long int number;
    printf("Enter a number: ");
    scanf("%ld", &number);
    printf("Next Palindrome number = %ld\n\n", getNextPalindrome(number));
}
