#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator;   
    int denominator; 
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero." << "\n";
            exit(1);
        }
        simplify(); 
    }
    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;

        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero." << "\n";
            exit(1);
        }
        simplify();
    }
    void display() const {
        cout << numerator << "/" << denominator;
    }
    Fraction add(const Fraction& other) const {
        int resultNum = numerator * other.denominator + other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Fraction(resultNum, resultDenom);
    }
    Fraction subtract(const Fraction& other) const {
        int resultNum = numerator * other.denominator - other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Fraction(resultNum, resultDenom);
    }
    Fraction multiply(const Fraction& other) const {
        int resultNum = numerator * other.numerator;
        int resultDenom = denominator * other.denominator;
        return Fraction(resultNum, resultDenom);
    }
    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Error: Division by zero." << "\n";
            exit(1);
        }
        int resultNum = numerator * other.denominator;
        int resultDenom = denominator * other.numerator;
        return Fraction(resultNum, resultDenom);
    }
private:
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }
};
int main()
{
    Fraction fraction1, fraction2;
    cout << "Enter details for fraction 1:" << "\n";
    fraction1.input();
    cout << "\nEnter details for fraction 2:" << "\n";
    fraction2.input();
    cout << "\nFraction 1: ";
    fraction1.display();
    cout << "\nFraction 2: ";
    fraction2.display();
    Fraction sum = fraction1.add(fraction2);
    Fraction difference = fraction1.subtract(fraction2);
    Fraction product = fraction1.multiply(fraction2);
    Fraction quotient = fraction1.divide(fraction2);
    cout << "\n\nSum: ";
    sum.display();
    cout << "\nDifference: ";
    difference.display();
    cout << "\nProduct: ";
    product.display();
    cout << "\nQuotient: ";
    quotient.display();
    return 0;
}