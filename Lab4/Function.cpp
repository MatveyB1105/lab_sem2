#include <iostream>
#include "Function.h"

int MultTwo(int value) {
    return (value * 2);
}

float MultTwo(float value) {
    return (value * 2);
}

complex MultTwo(complex value) {
    complex a(2,0);
    return (value * a);
}

bool BigZero(int value) {
    return value > 0;
}

bool BigZero(float value) {
    return value > 0;
}

bool EqTwo(complex value) {
    complex a(2,0);
    if(value == a) {
        return true;
    }
    return false;
}
