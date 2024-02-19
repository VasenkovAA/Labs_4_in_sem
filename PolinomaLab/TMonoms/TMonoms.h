// Copyright 2023 VasenkovAA
#ifndef MONOMS_H_
#define MONOMS_H_

#include <iostream>
#include <vector>
#include "../TFraction/TFroction.h"

template <typename T>
class TVarible
{
private:
    T variable;
    Fraction degree;
public:
    TVarible(T var, Fraction deg) : variable(var), degree(deg) {}
    TVarible(const TVarible& other) : variable(other.variable), degree(other.degree) {}
    void setVariable(T var) {
        variable = var;
    }
    void setDegree(Fraction deg) {
        degree = deg;
    }
    T getVariable() const {
        return variable;
    }
    Fraction getDegree() const {
        return degree;
    }

    bool operator!=(const TVarible& other) const {
        return !(*this == other);
    }
    bool operator<(const TVarible& other) const {
        return degree < other.degree || (degree == other.degree && variable < other.variable);
    }
    bool operator==(const TVarible& other) const {
        return variable == other.variable && degree == other.degree;
    }
    bool operator>(const TVarible& other) const {
        return ((degree > other.degree) || (degree == other.degree && variable > other.variable));
    }
    bool operator>=(const TVarible& other) const {
        return (*this > other) || (*this == other);
    }
    bool operator<=(const TVarible& other) const {
        return !(*this > other);
    }
    float run() const {
        return pow(variable, degree.run());
    }

    template<typename T>
    friend class TMonom;
    std::string to_string() const {
        std::string result;
        result += std::to_string(variable);
        if (degree != 1) {
            result += "^" + degree.to_string();
        }
        return result;
    }
};

template<typename T>
Fraction pow(const T& base, const Fraction& exponent) {
    double result = pow(static_cast<double>(base), static_cast<double>(exponent.run()));
    int new_numerator = static_cast<int>(result * exponent.getDenominator());
    int new_denominator = exponent.getDenominator();
    char new_sign = (result >= 0) ? '+' : '-';
    return Fraction(new_sign, abs(new_numerator), new_denominator);
}

template <typename T>
class TMonom {
public:
    std::vector<TVarible<T>> var;
    Fraction coef;

public:
    TMonom() : coef(1, 1) {}

    TMonom(const std::vector<TVarible<T>>& vars, const Fraction& coef)
        : var(vars), coef(coef) {}

    TMonom(const TMonom& other) : var(other.var), coef(other.coef) {}

    void addVar(const TVarible<T>& var) {
        this->var.push_back(var);
    }

    void setCoef(const Fraction& coef) {
        this->coef = coef;
    }

    Fraction getCoef() const {
        return coef;
    }

    std::string to_string() const {
        std::string result;
        if (coef == 0) {
            result = "0";
        }
        else {
            if (coef != 1 || var.empty()) {
                result += coef.to_string();
            }
            for (const auto& v : var) {
                result +="*"+ v.to_string();
            }
        }
        return result;
    }


    float run() {
        float result = 0;
        for (const auto& var : var) {
            result += var.run();
        }
        return result*coef;
    }
    TMonom operator+(const TMonom<T> rhs) {
        if (rhs.var.size() != var.size()) {
            throw std::invalid_argument("Monoms have different number of variables");
        }
        for (int i = 0; i < var.size(); i++) {
            if (var[i].degree != rhs.var[i].degree || fabs(var[i].variable) != fabs(rhs.var[i].variable)) {
                throw std::logic_error("Monoms have different variables");
            }
        }
        TMonom<T> result;
        result.var = var;
        result.coef = coef + rhs.coef;

        return result;
    }

    TMonom<T> operator-(const TMonom<T>& rhs)const {
        if (rhs.var.size() != var.size()) {
            throw std::invalid_argument("Monoms have different number of variables");
        }
        for (int i = 0; i < var.size(); i++) {
            if (var[i] != rhs.var[i]) {
                throw logic_error("Monoms have different varibels");
            }
        }

        TMonom<T> result;
        result.var = var;
        result.coef = coef - rhs.coef;

        return result;
    }
    /*
    TMonom<T> operator*( const TMonom<T>& rhs) {
        TMonom<T> result;
        if (var.size() >= rhs.var.size()) {
            result.var = var;
            result.coef = coef * rhs.coef;
            for (int i = 0; i < rhs.var.size(); i++) {
                result.var[i].degree = result.var[i].degree + rhs.var[i].degree;
            }
        }
        else {
            result.var = rhs.var;
            result.coef = coef * rhs.coef;
            for (int i = 0; i < var.size(); i++) {
                result.var[i].degree = result.var[i].degree - rhs.var[i].degree;
            }
        }
        return result;
    }
    */
};


#endif //MONOMS_H_