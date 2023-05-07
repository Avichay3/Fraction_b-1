#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
using namespace ariel;
using namespace std;
#define MAX_NUM 1000000

Fraction::Fraction(int numerator, int denominator) : mone(numerator), mechane(denominator){ //main constructor
    if(denominator == 0){
        throw invalid_argument("Fraction can't be divided by zero");
    }
}

Fraction::Fraction(float num) {
    // Convert float to fraction
    int sign = (num < 0) ? -1 : 1;
    int whole = static_cast<int>(num);
    num -= whole;
    // find the denominator by multiplying by powers of 10
    int denominator = 1;
    while (std::abs(num * denominator - static_cast<int>(num * denominator)) > 1e-6) {
        denominator *= 10;
    }
    // set the numerator and denominator
    int numerator = static_cast<int>(num * denominator);
    mone = sign * (whole * denominator + numerator);
    mechane = denominator;
}

//getters and setters
int Fraction::getMone() const{
    return this->mone;
}

int Fraction::getMechane() const{
    return this->mechane;
}

void Fraction::setMone(int _mone) {
    this->mone = _mone;
}

void Fraction::setMechane(int _mechane) {
    this->mechane = _mechane;
}

// binary operators
Fraction Fraction::operator+ (Fraction& other) const{
    return Fraction(0,1);
}

Fraction Fraction::operator- (Fraction& other) const{
        return Fraction(0,1);

}

Fraction Fraction::operator* (Fraction& other) const{
        return Fraction(0,1);

}

Fraction Fraction::operator/ (Fraction& other) const{
        return Fraction(0,1);

}

// comparison operators
bool Fraction::operator> (Fraction& other) const{
    return false;
}

bool Fraction::operator< (Fraction& other) const{
    return false;
}

bool Fraction::operator>= (Fraction& other) const{
    return false;
}

bool Fraction::operator<= (Fraction& other) const{
    return false;
}

// increment and decrement operators
Fraction& Fraction::operator++(){
    mone += mechane;
    return *this;
}

const Fraction Fraction::operator++(int){
    return *this;
}

Fraction& Fraction::operator--(){
    mone -= mechane;
    return *this;
}

const Fraction Fraction::operator--(int){
    return *this;
}

// friend global comparison operators
bool ariel::operator> (float f1, const Fraction& f2){
    return false;
}

bool ariel::operator< (float f1, const Fraction& f2){
    return false;
}

bool ariel::operator>= (float f1, const Fraction& f2){
    return false;
}

bool ariel::operator<= (float f1, const Fraction& f2){
    return false;
}

bool ariel::operator> (const Fraction& f2, float f1){
    return false;
}

bool ariel::operator< (const Fraction& f2, float f1){
    return false;
}

bool ariel::operator>= (const Fraction& f2, float f1){
     return false;

}

bool ariel::operator<= (const Fraction& f2, float f1){
    return false;

}

// friend global binary operators
bool ariel::operator== (const Fraction& f1, const Fraction& f2){
    return false;
}

Fraction ariel::operator+ (float f1, const Fraction& f2){
    return Fraction(0,1);
}

Fraction ariel::operator- (float f1, const Fraction& f2){
    return Fraction(0,1);
}

Fraction ariel::operator* (float f1, const Fraction& f2){
    return Fraction(0,1);
}
Fraction ariel::operator/ (float f1, const Fraction& f2){
    return Fraction(0,1);
}

Fraction ariel::operator+ (const Fraction& f2, float f1){
    return Fraction(0,1);
}

Fraction ariel::operator- (const Fraction& f2, float f1){
    return Fraction(0,1);
}

Fraction ariel::operator* (const Fraction& f2, float f1){
    return Fraction(0,1);
}

Fraction ariel::operator/ (const Fraction& f2, float f1){
    return Fraction(0,1);
}

//input output operators
std::ostream& ariel::operator<< (std::ostream& output, const Fraction& a){
    // Output the fraction to the output stream
    output << a.getMone() << "/" << a.getMechane();
    return output;
}

std::istream& ariel::operator>> (std::istream& input, const Fraction& f){
    // read the fraction from the input stream
    return input;
}


float ariel::FractionToFloat(const Fraction& a) {
    float fraction_float = static_cast<float>(a.getMone()) / static_cast<float>(a.getMechane());
    float rounded_float = static_cast<float>(static_cast<int>(fraction_float * 1000)) / 1000;
    return rounded_float;
}