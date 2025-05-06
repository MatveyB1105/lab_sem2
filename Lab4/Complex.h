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

        friend complex sqrt(complex complex1) {
            complex result;
            double value = complex1.real * complex1.real + complex1.imagine * complex1.imagine;
            result.real = std::sqrt((std::sqrt(value) + complex1.real) / 2);
            result.imagine = complex1.imagine / std::abs(complex1.imagine) * std::sqrt((std::sqrt(value) - complex1.real) / 2);
            return result;
        }
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
            if (other.imagine == 0)
                stream << other.real;
            else if (other.imagine >= 0)
                stream << other.real << " + " << other.imagine << 'i';
            else
                stream << other.real << " - " << -other.imagine << 'i';
            return stream; 
        }

        bool operator == (const complex& other) {
            if (this->real == other.real && this->imagine == other.imagine)
                return 1;
            else
                return 0;
        }
        bool operator != (const complex& other) {
            if (this->real != other.real || this->imagine != other.imagine){
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator > (const complex& other) {
        if(std::sqrt(real * real + imagine * imagine) > std::sqrt(other.real * other.real + other.imagine * other.imagine)) {
            return 1;
        }
        else {
            return 0;
        }
    }
        bool operator >= (const complex& other) {
            if(std::sqrt(real * real + imagine * imagine) >= std::sqrt(other.real * other.real + other.imagine * other.imagine)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator < (const complex& other) {
            if(std::sqrt(real * real + imagine * imagine) < std::sqrt(other.real * other.real + other.imagine * other.imagine)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator <= (const complex& other) {
            if(std::sqrt(real * real + imagine * imagine) <= std::sqrt(other.real * other.real + other.imagine * other.imagine)) {
                return 1;
            }
            else {
                return 0;
            }
        }
};