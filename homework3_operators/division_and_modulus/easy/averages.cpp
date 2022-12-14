/*
● Write a program that reads 5 numbers and print the following:
○ A) Their average
○ B) The sum of the first 3 numbers divided by the sum of the last 2 numbers
○ C) The average of the first 3 numbers divided by the average of the last 2 numbers.
○ What is the math relation between B and C?
● Input 1 2 3 4 5 ○3
○ 0.666666667 ○ 0.444444444
*/

#include <iostream>
using namespace std;

int main()
{
    double num1, num2, num3, num4, num5 = 0.0;
    // Prompt user for input
    cout << "Enter 5 numbers: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    cout << "\nTheir Average: " << (num1 + num2 + num3 + num4 + num5) / 5 << "\n";
    cout << "The sum of the first 3 numbers divided by the sum of the last 2 numbers: "
    << (num1 + num2 + num3) / (num4 + num5) << "\n";
    cout << "The average of the first 3 numbers divided by the average of the last 2 numbers" 
    << ((num1 + num2 + num3) / 3) / ((num4 + num5) / 2) << "\n";

    return 0;
}