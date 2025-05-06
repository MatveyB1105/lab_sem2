#pragma once

#include <iostream>
#include <cmath>

class complex {
    private:
        double real;
        double imagine;
    public:
        complex() { real = 0; imagine = 0; }
        complex(double r, double i) { real = r; imagine = i; }
        complex(const complex& other) { real = other.real; imagine = other.imagine; }

        complex& operator = (complex other) {
            this->real = other.real;
            this->imagine = other.imagine;
            return *this;
        }
        complex operator + (complex other) {
            complex result = complex(*this);
            result.real = this->real + other.real;
            result.imagine = this->imagine + other.imagine;
            return result;
        }
        complex operator - (complex other) {
            complex result = complex(*this);
            result.real = this->real - other.real;
            result.imagine = this->imagine - other.imagine;
            return result;
        }
        complex operator * (complex& other) {
            complex result = complex(*this);
            result.real = real * other.real - imagine * other.imagine;
            result.imagine = real * other.imagine + other.real * imagine;
            return result;
        }
        complex operator / (complex& other) {
            double k;
            complex result = complex(*this);
            k = real * real + other.imagine * other.imagine;
            result.real = (real * other.real + imagine * other.imagine) / k;
            result.imagine = (other.real * imagine - real * other.imagine) / k;
            return result;
        }
        complex& operator += (complex other) {
            real += other.real;
            imagine += other.imagine;
            return *this;
        }
        complex& operator -= (complex other) {
            real -= other.real;
            imagine -= other.imagine;
            return *this;
        }
        friend std::ostream& operator << (std::ostream& stream, const complex& other) {
            if (other.imaginary == 0)
                stream << other.real;
            else if (other.imaginary >= 0)
                stream << other.real << " + " << other.imaginary << 'i';
            else
                stream << other.real << " - " << -other.imaginary << 'i';
            return stream; 
        }

        bool operator == (complex& other) {
            if (this->real == other.real && this->imagine == other.imagine)
                return 1;
            else
                return 0;
        }
        bool operator != (complex& other) {
            if (this->real != other.real || this->imagine != other.imagine){
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator > (complex& other) {
            if(sqrt(real * real + imagine * imagine) > sqrt(other.real * other.real + other.imagine * other.imagine)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator >= (complex& other) {
            if(sqrt(real * real + imagine * imagine) >= sqrt(other.real * other.real + other.imagine * other.imagine)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator < (complex& other) {
            if(sqrt(real * real + imagine * imagine) < sqrt(other.real * other.real + other.imagine * other.imagine)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator <= (complex& other) {
            if(sqrt(real * real + imagine * imagine) <= sqrt(other.real * other.real + other.imagine * other.imagine)) {
                return 1;
            }
            else {
                return 0;
            }
        }
}