#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Standard multiplication (for comparison)
long long standardMultiply(long long a, long long b) {
    return a * b;
}

// Karatsuba algorithm for fast multiplication
// Works well for large integers
long long karatsubaMultiply(long long a, long long b) {
    // Base case for recursion
    if (a < 10 || b < 10) {
        return a * b;
    }

    // Calculate the size of the numbers
    long long n = max(to_string(a).size(), to_string(b).size());
    long long half = n / 2;
    
    // Powers of 10
    long long power = pow(10, half);
    
    // Split the numbers
    long long a_high = a / power;
    long long a_low = a % power;
    long long b_high = b / power;
    long long b_low = b % power;
    
    // Recursive calls
    long long z0 = karatsubaMultiply(a_low, b_low);
    long long z1 = karatsubaMultiply((a_low + a_high), (b_low + b_high));
    long long z2 = karatsubaMultiply(a_high, b_high);
    
    // Calculate the final result using the Karatsuba formula
    return (z2 * pow(10, 2 * half)) + ((z1 - z2 - z0) * pow(10, half)) + z0;
}

// Russian Peasant (Ancient Egyptian) multiplication
// Works for any integers and is simple to implement
long long russianPeasantMultiply(long long a, long long b) {
    long long result = 0;
    
    // While second number doesn't become 0
    while (b > 0) {
        // If second number is odd, add the first number to result
        if (b & 1) {
            result += a;
        }
        
        // Double the first number
        a <<= 1;
        
        // Halve the second number
        b >>= 1;
    }
    
    return result;
}

// Fast multiplication using bit shifting for powers of 2
long long bitShiftMultiply(long long a, int power) {
    // Multiplies a by 2^power
    return a << power;
}

// Binary multiplication (similar to Russian Peasant but using binary operations)
long long binaryMultiply(long long a, long long b) {
    long long result = 0;
    
    while (b > 0) {
        if (b & 1) {  // If least significant bit of b is 1
            result += a;
        }
        a <<= 1;      // Left shift a by 1 (multiply by 2)
        b >>= 1;      // Right shift b by 1 (divide by 2)
    }
    
    return result;
}

// Vedic Mathematics - Urdhva Tiryakbhyam (for numbers up to 999)
long long vedicMultiply(int a, int b) {
    int a_hundreds = a / 100;
    int a_tens = (a / 10) % 10;
    int a_ones = a % 10;
    
    int b_hundreds = b / 100;
    int b_tens = (b / 10) % 10;
    int b_ones = b % 10;
    
    // Step 1: Multiply ones digits
    int step1 = a_ones * b_ones;
    
    // Step 2: Cross multiply ones of first with tens of second and vice versa, then add
    int step2 = a_ones * b_tens + a_tens * b_ones;
    
    // Step 3: Multiply tens digits and add cross product of ones and hundreds
    int step3 = a_tens * b_tens + a_ones * b_hundreds + a_hundreds * b_ones;
    
    // Step 4: Cross multiply tens of first with hundreds of second and vice versa, then add
    int step4 = a_tens * b_hundreds + a_hundreds * b_tens;
    
    // Step 5: Multiply hundreds digits
    int step5 = a_hundreds * b_hundreds;
    
    // Combine all steps to get final result
    return step5 * 10000 + step4 * 1000 + step3 * 100 + step2 * 10 + step1 % 10;
}

// Divide and conquer for squaring numbers close to powers of 10
long long squareNumberCloseToBase10(long long n, int base) {
    // For numbers like 95, 995, 9995 (close to 100, 1000, 10000)
    long long power = pow(10, base);
    long long deviation = power - n;
    
    return (power - deviation) * power - deviation * power + deviation * deviation;
    // e.g., for 95 = (100-5) -> 95 * 100 - 5 * 100 + 5 * 5 = 9025
}

int main() {
    long long a = 123;
    long long b = 456;
    
    cout << "Fast Multiplication Techniques\n";
    cout << "===========================\n\n";
    
    cout << "Numbers to multiply: " << a << " * " << b << "\n\n";
    
    cout << "1. Standard multiplication:\n";
    cout << "   " << a << " * " << b << " = " << standardMultiply(a, b) << "\n\n";
    
    cout << "2. Karatsuba algorithm (efficient for large numbers):\n";
    cout << "   " << a << " * " << b << " = " << karatsubaMultiply(a, b) << "\n\n";
    
    cout << "3. Russian Peasant algorithm:\n";
    cout << "   " << a << " * " << b << " = " << russianPeasantMultiply(a, b) << "\n\n";
    
    int power = 3; // 2^3 = 8
    cout << "4. Bit shifting for powers of 2:\n";
    cout << "   " << a << " * 2^" << power << " = " << bitShiftMultiply(a, power) << "\n\n";
    
    cout << "5. Binary multiplication:\n";
    cout << "   " << a << " * " << b << " = " << binaryMultiply(a, b) << "\n\n";
    
    int smallA = 97;
    int smallB = 96;
    cout << "6. Vedic multiplication (Urdhva Tiryakbhyam):\n";
    cout << "   " << smallA << " * " << smallB << " = " << vedicMultiply(smallA, smallB) << "\n\n";
    
    int base = 2; // 10^2 = 100
    int close_num = 95;
    cout << "7. Squaring numbers close to powers of 10:\n";
    cout << "   " << close_num << "^2 = " << squareNumberCloseToBase10(close_num, base) << "\n";
    
    return 0;
}