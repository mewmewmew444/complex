#include <iostream>
#include <cmath>
#include "complex.h"

complex_number::complex_number(double re, double im) : re(re), im(im) {}

double complex_number::get_real() const {
    return re;
}

double complex_number::get_im() const {
    return im;
}

void complex_number::set_real(const double value) {
    re = value;
}

void complex_number::set_im(const double value) {
    im = value;
}

complex_number complex_number::operator +(const complex_number& other) {
    double new_real = re + other.re;
    double new_imaginary = im + other.im;
    return complex_number(new_real, new_imaginary);
}

complex_number complex_number::operator -(const complex_number& other) {
    double new_re = re - other.re;
    double new_imaginary = im - other.im;
    return complex_number(new_re, new_imaginary);
}

complex_number complex_number::operator *(const complex_number& other) {
    double new_real = re * other.re - im * other.im;
    double new_imaginary = re * other.im + other.re * im;
    return complex_number(new_real, new_imaginary);
}

complex_number complex_number::operator /(const complex_number& other) {
    double denominator = other.re * other.re + other.im * other.im;
    double eps = 1e-5;
    if (std::fabs(denominator) < eps) {
        throw std::overflow_error("Divide by zero exception");
    }
    double new_real = (re * other.re + im * other.im) / denominator;
    double new_imaginary = (other.re * im - re * other.im) / denominator;
    return complex_number(new_real, new_imaginary);
}

complex_number& complex_number::operator +=(const complex_number& other) {
    re = (*this + other).re;
    im = (*this + other).im;
    return *this;
}

complex_number& complex_number::operator -=(const complex_number& other) {
    re = (*this - other).re;
    im = (*this - other).im;
    return *this;
}

complex_number& complex_number::operator *=(const complex_number& other) {
    double new_real = re * other.re - im * other.im;
    double new_imaginary = re * other.im + other.re * im;
    re = new_real;
    im = new_imaginary;
    return *this;
}

complex_number& complex_number::operator /=(const complex_number& other) {
    double denominator = other.re * other.re + other.im * other.im;
    double eps = 1e-5;
    if (std::fabs(denominator) < eps) {
        throw std::overflow_error("Divide by zero exception");
    }
    double new_real = (re * other.re + im * other.im) / denominator;
    double new_imaginary = (other.re * im - re * other.im) / denominator;
    re = new_real;
    im = new_imaginary;
    return *this;
}

bool complex_number::operator ==(const complex_number& other) {
    return (re == other.re && im == other.im);
}

bool complex_number::operator ==(const double& other) {
    double eps = 1e-5;
    return (re == other && std::fabs(im) < eps);
}

double complex_number::Abs() const {
    return std::sqrt(re * re + im * im);
}

complex_number complex_number::Pow(int degree) const {
    double rad = std::pow(this->Abs(), degree);
    double phi = std::atan2(im, re);
    double new_real = round(rad * std::cos(degree * phi));
    double new_imaginary = round(rad * std::sin(degree * phi));
    return {new_real, new_imaginary};
}

std::ostream& operator << (std::ostream& out, const complex_number& num)
{
    if (num.im < 0) {
        out << num.re << num.im << "i\n";
    }
    else {
        out << num.re << "+" << num.im << "i\n";
    }
    return out;
}