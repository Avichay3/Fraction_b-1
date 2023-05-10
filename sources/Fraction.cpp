#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>   
#include <limits>
#include <stdexcept> 
using namespace ariel;
using namespace std;
#define MAX_NUM 1000000

Fraction::Fraction(int mone, int mechane){
    if (mechane == 0){
        throw invalid_argument("Fraction cannot be divided by zero");
    }
    int gcd = abs(__gcd(mone, mechane));
    if ((mone < 0 && mechane < 0) || (mone > 0 && mechane < 0)){
        this->mone = -mone / gcd;
        this->mechane = -mechane / gcd;
    }
    else{
        this->mone = mone / gcd;
        this->mechane = mechane / gcd;
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

Fraction::Fraction(){
    this->setMone(1);
    this->setMechane(1);
}

//getters and setters
int Fraction::getNumerator() const{
    return this->mone;
}

int Fraction::getDenominator() const{
    return this->mechane;
}

void Fraction::setMone(int _mone) {
    this->mone = _mone;
}

void Fraction::setMechane(int _mechane) {
    this->mechane = _mechane;
}

// binary operators
Fraction Fraction::operator+(const Fraction &other) const{
    int new_mone = this->getNumerator() * other.getDenominator() + other.getNumerator() * this->getNumerator();
    int new_mechane = this->getDenominator() * other.getDenominator();
    int gcd = std::gcd(new_mone, new_mechane);
    new_mone /= gcd;
    new_mechane /= gcd;
    return Fraction{ new_mone, new_mechane };
}



Fraction Fraction::operator- (const Fraction &other) const{ // the subtruction of two fractions a/b - c/d defined as (ad - bc)/bd
        int new_numarator = (this->getNumerator() * other.getDenominator()  -  this->mechane * other.getNumerator());
        int new_denominator = this->getDenominator() * other.getDenominator();
        Fraction f1 (new_numarator, new_denominator);
        return f1;
}


Fraction Fraction::operator* (const Fraction& other) const{
        if(this->getDenominator() == 0 || other.getDenominator() == 0){
            throw runtime_error("cannot be divided by 0");
        }
        int new_numartor = this->getNumerator() * other.getNumerator();
        int new_denominator = this->getDenominator() * other.getDenominator();
        Fraction f1(new_numartor,new_denominator);
        return f1;

}





/*the result of (a/b) / (c/d) is ad/bc  */
Fraction Fraction::operator/ (const Fraction& other) const{ 
        if(other.getNumerator() == 0){
            throw runtime_error("cannot be divided by 0");
        }
        Fraction ans(other.getDenominator(), other.getNumerator());
        return *this * ans;
}

// comparison operators
bool Fraction::operator>(const Fraction &other) const{
    return other < *this;
}

bool Fraction::operator<(const Fraction &other) const{
    int divide = abs(this->getDenominator() * other.getDenominator());
    int first_fraction = (divide * this->getNumerator()) / this->getDenominator();
    int second_fraction = (divide * other.getNumerator()) / other.getDenominator();
    return first_fraction < second_fraction;
}


 bool Fraction::operator>=(const Fraction &other) const{
    return ((mone * other.mechane) >= (other.mone * mechane));
}

bool Fraction::operator<=(const Fraction &other) const{
    return other >= *this;
}


// increment and decrement operators
Fraction& Fraction::operator++(){
    mone += mechane;
    return *this;
}

const Fraction Fraction::operator++(int){
    Fraction fraction(*this);
    this->setMone(this->getNumerator() + this->getDenominator());
    return fraction;
}

Fraction& Fraction::operator--(){
    mone -= mechane;
    return *this;
}

const Fraction Fraction::operator--(int){
    Fraction fraction(*this);
    this->setMone(this->getNumerator() - this->getDenominator());
    return fraction;
}





// friend global comparison operators
bool ariel::operator> (float f1, const Fraction &f2){
    float f3 = FractionToFloat(f2);
    return f1 > f3;
}

bool ariel::operator< (float f1, const Fraction &f2){
    float f3 = FractionToFloat(f2);
    return f1 < f3;
}

bool ariel::operator>= (float f1, const Fraction &f2){
    float f3 = FractionToFloat(f2);
    return f1 >= f3;
}

bool ariel::operator<= (float f1, const Fraction &f2){
    float f3 = FractionToFloat(f2);
    return f1 <= f3;
}

bool ariel::operator> (const Fraction& f2, float f1){
    float f3 = FractionToFloat(f2);
    return f1 > f3;
}

bool ariel::operator< (const Fraction &f2, float f1){
    float f3 = FractionToFloat(f2);
    return f1 < f3;
}

bool ariel::operator>= (const Fraction &f2, float f1){
     float f3 = FractionToFloat(f2);
    return f1 <= f3;

}

bool ariel::operator<= (const Fraction &f2, float f1){
    float f3 = FractionToFloat(f2);
    return f1 <= f3;
}

// friend global binary operators
bool ariel::operator== (const Fraction& f1, const Fraction &f2){
        float f3 = FractionToFloat(f1);  
        float f4 = FractionToFloat(f2);  
        return f3 == f4;

    }


Fraction ariel::operator+ (float f1, const Fraction &f2){
    Fraction fraction(f1);
    Fraction ans (fraction + f2);
    return ans;

}

Fraction ariel::operator- (float f1, const Fraction &f2){
    Fraction fraction (f1);
    Fraction ans (fraction - f2);
    return ans;
}

Fraction ariel::operator* (float f1, const Fraction &f2){
    Fraction fraction (f1);
    Fraction ans = fraction * f2;
    return ans;
}
Fraction ariel::operator/ (float f1, const Fraction &f2){
    if(f2.getNumerator() == 0){ 
        throw runtime_error ("fraction cannot be divided by 0"); //beacause if the numerator of f2 is 0 the all number is 0
    }
    Fraction fraction (f1);
    Fraction ans = fraction / f2;
    return ans;


}

Fraction ariel::operator+ (const Fraction &f2, float f1){
    Fraction fraction (f1);
    Fraction ans = fraction + f2;
    return ans;
}

Fraction ariel::operator- (const Fraction &f2, float f1){
    Fraction fraction (f1);
    Fraction ans = f2 - fraction;
    return ans;
}

Fraction ariel::operator* (const Fraction &f2, float f1){
    Fraction fraction(f1);
    Fraction ans = fraction * f2;
    return ans;
}

Fraction ariel::operator/ (const Fraction &f2, float f1){
    Fraction fraction (f1);
    Fraction ans(f2 / fraction);
    return ans;
}

//input output operators
std::ostream& ariel::operator<< (std::ostream &output, const Fraction &a){
    // Output the fraction to the output stream
    output << a.getNumerator() << "/" << a.getDenominator();
    return output;
}

std::istream& ariel::operator>>(istream &input, Fraction &f){
    int numerator = 0;
    int denominator = 1;
    char slash = '/';

    input >> numerator;
    if (!input.fail()){
        input >> slash;
        if (slash == '/'){
            input >> denominator;
            if (denominator != 0){
                f.setMone(numerator);
                f.setMechane(denominator);
            }
            else{
                throw runtime_error("Denominator cannot be zero");
            }
        }
        else{
            f.setMone(numerator);
            f.setMechane(1);
            input.clear();
            input.putback(slash);
        }
    }
    return input;
}



float ariel::FractionToFloat(const Fraction &a) {
    float fraction_float = static_cast<float>(a.getNumerator()) / static_cast<float>(a.getDenominator());
    float rounded_float = static_cast<float>(static_cast<int>(fraction_float * 1000)) / 1000;
    return rounded_float;
}

