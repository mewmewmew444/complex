#pragma once
#include <iostream>

class complex_number {

private:
    double re;
    double im;

public:
    friend std::ostream& operator <<(std::ostream&, const complex_number&);
    complex_number(double re, double im);
    double get_real() const;
    double get_im() const;
    void set_real(const double value);
    void set_im(const double value);
    complex_number operator +(const complex_number& other);
    complex_number operator -(const complex_number& other);
    complex_number operator *(const complex_number& other);
    complex_number operator /(const complex_number& other);
    complex_number& operator +=(const complex_number& other);
    complex_number& operator -=(const complex_number& other);
    complex_number& operator *=(const complex_number& other);
    complex_number& operator /=(const complex_number& other);
    bool operator == (const complex_number& other);
    bool operator == (const double& other);
    double Abs() const;
    complex_number Pow(int degree) const;
};

std::ostream& operator << (std::ostream& out, const complex_number& num);