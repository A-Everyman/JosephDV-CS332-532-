#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Check if a number is prime runs through all test cases 
int isPrime(int n) {
    if (n <= 1)
        return 0; //Not prime
    if (n == 2)
        return 1; //Prime
    if (n % 2 == 0)
        return 0; //Even numbers greater than 2 are not prime
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0; //Divisible by a number other than 1 and itself
    }
    return 1; //Prime
}

//Calculate factorial of a number using unsigned long long for longer factorials in stack
unsigned long long factorial(int n) 
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

//Checking if n is prime or return the factorial
const char* primeOrFactorial(int n) {
    if (n <= 1) {
        return "Invalid Input";
    }

    if (isPrime(n)) {
        return "Prime Number";
    } else {
        static char buffer[50]; //Buffer to store the factorial result as a string
        unsigned long long fact = factorial(n);
        snprintf(buffer, sizeof(buffer), "%llu", fact);
        return buffer;
    }
}

//Function to calculate the sum of elements equal to their indices
int UABIndexSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == i) {
            sum += arr[i];
        }
    }
    return sum;
}

//Function to replace even numbers with 0
int* replaceEvenWithZero(int arr[], int size) {
    //Allocate memory for the array
    int* newArr = (int*)malloc(size * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            newArr[i] = 0; //Replace even number with 0
        } else {
            newArr[i] = arr[i]; //Keep the odd number unchanged
        }
    }
    return newArr;
}

//Function to check if a number is an even square
int evenSquare(int n) {
    if (n < 0) {
        return 0; //Negative numbers are not even squares
    }

    int sqrt_n = (int)sqrt(n); //Calculate the integer square root of n
    if (sqrt_n * sqrt_n == n && sqrt_n % 2 == 0) {
        return 1; //n is a square number and its square root is even
    }
    return 0; //n is not an even square
}

//Function to count the number of vowels in a string, ignoring case, using c.type library 
int countVowels(const char* s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = tolower(s[i]); //Convert character to lowercase
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    //primeOrFactorial
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%s\n", primeOrFactorial(n));

    //UABIndexSum
    int arr[] = {0, 1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = UABIndexSum(arr, size);
    printf("Sum of elements equal to their indices: %d\n", sum);

    //replaceEvenWithZero
    int* newArr = replaceEvenWithZero(arr, size);
    printf("Array after replacing even numbers with 0: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");

    //evenSquare
    printf("Enter a number to check if it's an even square: ");
    scanf("%d", &n);
    if (evenSquare(n)) {
        printf("%d is an even square.\n", n);
    } else {
        printf("%d is not an even square.\n", n);
    }

    //countVowels
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str); //Reading a string with spaces
    int vowels = countVowels(str);
    printf("Number of vowels in the string: %d\n", vowels);

    // Free the allocated memory for the new array
    free(newArr);

    return 0;
}
