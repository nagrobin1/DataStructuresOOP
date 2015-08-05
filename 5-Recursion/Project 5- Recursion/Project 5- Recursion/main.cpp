//  main.cpp
//  Project 5- Recursion
//  Robin Nag
//
//  unsigned factorial(unsigned n);
//      Postcondion: Returns the factorial value of the nth term
//
//  unsigned long fibonacci(unsigned long n);
//      Postcondion: Returns the fibonacci value of the nth term
//
//  void powerOf2sum(unsigned long n);
//      Postcondion: Outputs the sum of a number in terms of 2^n +...2^0
//
//  void PrimeFactors(unsigned long n);
//      Postcondion: Outputs the prime factorization of a number


#include <iostream>
#include <cmath> // pow
using namespace std;

// PROTOTYPES OF THE 4 FUNCTIONS
unsigned long factorial(unsigned long n);
unsigned long fibonacci(unsigned long n);
void powerOf2sum(unsigned long n);
void PrimeFactors(unsigned long n);


int main() {
    
    //Part 1
    cout << "           ------------------------------------------------------     " << endl;
    cout << "       ****       Part 1 Demonstration: Factorial                ****" << endl << endl;
    
    cout << "The factorial of 5 is " << factorial(5) << endl;
    cout << "The factorial of 8 is " << factorial(8) << endl;
    cout << "The factorial of 10 is " << factorial(10) << endl;
    cout << "The factorial of 13 is " << factorial(13) << endl;
    cout << "The factorial of 15 is " << factorial(15) << endl << endl;
    
    
    //Part 2
    cout << "           ------------------------------------------------------     " << endl;
    cout << "       ****       Part 2 Demonstration: Fibonacci Sequence       ****" << endl << endl;
    
    cout << "The Fibonacci of 0th term is " << fibonacci(0) << endl;
    cout << "The Fibonacci of 1st term is " << fibonacci(1) << endl;
    cout << "The Fibonacci of 2nd term is " << fibonacci(2) << endl;
    cout << "The Fibonacci of 3rd term is " << fibonacci(3) << endl;
    cout << "The Fibonacci of 7th term is " << fibonacci(7) << endl;
    cout << "The Fibonacci of 9th term is " << fibonacci(9) << endl << endl;
    
    
    //Part 3
    cout << "           ------------------------------------------------------     " << endl;
    cout << "       ****       Part 3 Demonstration: Sum of Power Twos        ****" << endl << endl;
    
    cout << "Print Sum of 16 is "; powerOf2sum(16); cout << endl;
    cout << "Print Sum of 17 is "; powerOf2sum(17); cout << endl;
    cout << "Print Sum of 77 is "; powerOf2sum(77); cout << endl;
    cout << "Print Sum of 275 is "; powerOf2sum(275); cout << endl << endl;
    
    //Part 4
    cout << "           ------------------------------------------------------     " << endl;
    cout << "       ****       Part 4 Demonstration: Prime Factors            ****" << endl << endl;
    
    cout << "The Prime Factorization of 17 is  " ; PrimeFactors(17); cout << endl;
    cout << "The Prime Factorization of 48 is  " ; PrimeFactors(48); cout << endl;
    cout << "The Prime Factorization of 147 is  " ; PrimeFactors(147); cout << endl;
    cout << "The Prime Factorization of 150 is  " ; PrimeFactors(150); cout << endl;
    cout << "The Prime Factorization of 330 is  " ; PrimeFactors(330); cout << endl;
    
    return 0;
}

unsigned long factorial(unsigned long n){
    
    //  Base Case
    if(n == 0){
        return 1;}
    
    //  Recursion Step
    else
        return (n * factorial(n-1));
}

unsigned long fibonacci(unsigned long n){
    
    //  Base Case
    if (n == 0) {
        return 0;}
    if (n == 1) {
        return 1;}
    
    //  Recursion Step
    return ( fibonacci(n-1) + fibonacci(n-2) );
}

void powerOf2sum(unsigned long n){
    
    //  Base Case
    if (n == 0) {
        return;
    }
    unsigned long orginal_n = n;
    unsigned long exponent = 0;
    
    while (n%2 == 0) {
        exponent++;
        n = n/2;
    }
    cout << "2^" << exponent << " + ";
    
    //  Recursion Step
    return powerOf2sum(orginal_n - pow(2, exponent));
}

void PrimeFactors(unsigned long n) {
    
    //  Base Case
    if (n == 1) {
        return;}
    
    //  Recursion Step
    int i = 2;
    while (n%i != 0) {
            i++;
        }
    cout << i << " x ";
    return PrimeFactors(n/i);
}



