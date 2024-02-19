// Copyright 2023 VasenkovAA

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
private:
    int numerator;
    int denominator;
    char sign; 

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (numerator * denominator >= 0) {
            sign = '+'; 
        }
        else {
            sign = '-'; 
        }
        int common = gcd(abs(numerator), abs(denominator));
        numerator = abs(numerator) / common; 
        denominator = abs(denominator) / common; 
    }
    Fraction(char sign_, int n, int d) : numerator(abs(n)), denominator(abs(d)) {
        if ((n < 0 && d > 0) || (n > 0 && d < 0)) {
            sign = '-';
        }
        else {
            sign = '+';
        }
        if (sign_ == '-') {
            sign = (sign == '+') ? '-' : '+';
        }
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }
    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator), sign(other.sign) {}

    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }
    Fraction operator+(const Fraction& f) {
        int new_numerator = (sign == f.sign) ? (numerator * f.denominator + f.numerator * denominator) : (numerator * f.denominator - f.numerator * denominator);
        int new_denominator = (sign == f.sign) ? (denominator * f.denominator) : (denominator * f.denominator);
        char new_sign;

        if (sign == f.sign) {
            new_sign = sign;
        }
        else {
            if (numerator * f.denominator < f.numerator * denominator) {
                new_sign = (sign == '+') ? f.sign : sign;
            }
            else {
                new_sign = sign;
            }
        }

        return Fraction(new_sign, abs(new_numerator), abs(new_denominator));
    }
    Fraction operator-(const Fraction& f) {
        int new_numerator = (sign == f.sign) ? (numerator * f.denominator - f.numerator * denominator) : (numerator * f.denominator + f.numerator * denominator);
        int new_denominator = (sign == f.sign) ? (denominator * f.denominator) : (denominator * f.denominator);
        char new_sign;

        if (sign == f.sign) {
            new_sign = sign;
        }
        else {
            if (numerator * f.denominator < f.numerator * denominator) {
                new_sign = (sign == '+') ? f.sign : sign;
            }
            else {
                new_sign = sign;
            }
        }

        return Fraction(new_sign, abs(new_numerator), abs(new_denominator));
    }
    Fraction operator-(const Fraction& f)const {
        int new_numerator = (sign == f.sign) ? (numerator * f.denominator - f.numerator * denominator) : (numerator * f.denominator + f.numerator * denominator);
        int new_denominator = (sign == f.sign) ? (denominator * f.denominator) : (denominator * f.denominator);
        char new_sign;

        if (sign == f.sign) {
            new_sign = sign;
        }
        else {
            if (numerator * f.denominator < f.numerator * denominator) {
                new_sign = (sign == '+') ? f.sign : sign;
            }
            else {
                new_sign = sign;
            }
        }

        return Fraction(new_sign, abs(new_numerator), abs(new_denominator));
    }
    Fraction operator*(const Fraction& f) {
        int new_numerator = numerator * f.numerator;
        int new_denominator = denominator * f.denominator;
        char new_sign;
        if (sign == f.sign) {
            new_sign = '+';
        }
        else {
            new_sign = '-';
        }
        return Fraction(new_sign, new_numerator, new_denominator);
    }

    Fraction operator/(const Fraction& f) {
        int new_numerator = numerator * f.denominator;
        int new_denominator = denominator * f.numerator;
        char new_sign;
        if (sign == f.sign) {
            new_sign = '+';
        }
        else {
            new_sign = '-';
        }
        return Fraction(new_sign, new_numerator, new_denominator);
    }

    bool operator==(const Fraction& f) const {
        return (numerator == f.numerator) && (denominator == f.denominator) && (sign == f.sign);
    }

    bool operator!=(const Fraction& f) const {
        return !(*this == f);
    }

    bool operator<(const Fraction& f) {
        if (sign == f.sign) {
            return (numerator * f.denominator) < (f.numerator * denominator);
        }
        else if (sign == '+') {
            return false; 
        }
        else {
            return true; 
        }
    }
    bool operator<(const Fraction& f) const {
        if (sign == f.sign) {
            return (numerator * f.denominator) < (f.numerator * denominator);
        }
        else if (sign == '+') {
            return false;
        }
        else {
            return true;
        }
    }
    bool operator>(const Fraction& f)const  {
        if (sign == f.sign) {
            return (numerator * f.denominator) > (f.numerator * denominator);
        }
        else if (sign == '+') {
            return true; 
        }
        else {
            return false; 
        }
    }

    bool operator<=(const Fraction& f) {
        return (*this < f) || (*this == f);
    }

    bool operator>=(const Fraction& f) {
        return (*this > f) || (*this == f);
    }

    Fraction& operator=(const Fraction& f) {
        if (this == &f) { throw logic_error("co-appropriation"); }
        numerator = f.numerator;
        denominator = f.denominator;
        sign = f.sign;
        return *this;
    }

    Fraction flip() {
        return Fraction(sign, denominator, numerator);
    }

    Fraction& swap(Fraction& f) {
        int temp_num = numerator;
        int temp_den = denominator;

        char temp_sign = sign;
        numerator = f.numerator;
        denominator = f.denominator;
        sign = f.sign;
        f.sign = temp_sign;
        f.numerator = temp_num;
        f.denominator = temp_den;
        return f;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.sign == '-') {
            os << '-';
        }
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int d) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        denominator = d;
    }

    char getSign() { return sign; }

    float run() const {
        return static_cast<float>(numerator) / static_cast<float>(denominator);
    }
    std::string to_string() const {
        std::string result;
        if (sign == '-') {
            result += '-';
        }
        result += std::to_string(numerator);
        result += "/";
        result += std::to_string(denominator);
        return result;
    }
};



#endif //FRACTION_H_