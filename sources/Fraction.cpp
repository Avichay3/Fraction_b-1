#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
using namespace ariel;
using namespace std;
#define MAX_NUM 1000000

Fraction::Fraction(int numerator, int denominator){
    if(denominator == 0){
        throw invalid_argument("Fraction can't be divided by zero");
    }
    int gcd = abs(__gcd(getMone,getMechane));
    if(((this->mone < 0 && this->mechane > 0)) || (this.mone > 0 && this.mechane < 0)){
        this->setMone (-this->getMone / gcd);
        this->setMechane (-this->getMechane / gcd);
    }
    else{
        this->setMone (numerator / gcd);
        this->setMechane(denominator / gcd); 

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
Fraction Fraction::operator+ (const Fraction &other) const{
    int lcm = std::lcm (mechane, other.mechane);
    int new_mone = (mone * lcm / mechane) +other.mone
}

Fraction Fraction::operator- (Fraction& other) const{ // the subtruction of two fractions a/b - c/d defined as (ad - bc)/bd
        int new_numarator = (this->getMone * other.getMechane  -  this->mechane * other.getMone);
        int new_denominator = this->getMechane * other.getMechane;
        Fraction f1 (new_numarator, new_denominator);
        return f1;
}

Fraction Fraction::operator* (Fraction& other) const{
        if(this->getMechane == 0 || other.getMechane == 0){
            return runtime_error("cannot be divided by 0");
        }
        int new_numartor = this->getMone * other.getMone;
        int new_denominator = this->getMechane * other.getMechane;
        Fraction f1(new_numartor,new_denominator);
        return f1;

}

/*the result of (a/b) / (b/c) is ad/bc  */
Fraction Fraction::operator/ (Fraction& other) const{ 
        if(this->getMechane == 0 || other.getMone == 0){
            return runtime_error("cannot be divided by 0");
        }
        int new_numartor = this->getMone * other.getMechane;
        int new_denominator = this->getMechane * other.getMone;
        Fraction f1(new_numartor, new_denominator);
        return f1;
}

// comparison operators
/*we need to convert the fractions to double and after that compare them*/
bool Fraction::operator> (Fraction &other) const{
    if(this->getMechane == 0 || other.getMechane == 0){
        throw ("it is illegal to divide by 0");
        return;
    }
    double d1 = double(this->getMone) / double(other.getMone);
    double d2 = double(this->getMechane) / double(other.getMechane);
    return d1 > d2;
}

/*we need to convert the fractions to double and after that compare them*/
bool Fraction::operator< (Fraction &other) const{
    if(this->getMechane == 0 || other.getMechane == 0){
        throw ("it is illegal to divide by 0");
        return;
    }
    double d1 = double(this->getMone) / double(this->getMechane);
    double d2 = double(other.getMone) / double(other.getMechane);
    return d1 < d2;
}

/*we need to convert the fractions to double and after that compare them*/
bool Fraction::operator>= (Fraction &other) const{
    if(this->getMechane == 0 || other.getMechane == 0){
        throw ("it is illegal to divide by 0");
        return;
    }
    double d1 = double(this->getMone) / double(this->getMechane);
    double d2 = double(other.getMone) / double(other.getMechane);
    return d1 >= d2; 
}

/*we need to convert the fractions to double and after that compare them*/
bool Fraction::operator<= (Fraction &other) const{
    if(this->getMechane == 0 || other.getMechane == 0){
        throw ("it is illegal to divide by 0");
        retturn;
    }
    double d1 = double(this->getMone) / double(this->getMechane);
    double d2 = double(other.getMone) / double(other.getMechane);
    return d1 <= d2; 
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
        if(f3 != f4){
            return false;
        }
        else{
            return true;
        }

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
    if(f2.getMone == 0){ 
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
    output << a.getMone() << "/" << a.getMechane();
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
                f.mone = numerator;
                f.mechane = denominator;
            }
            else{
                throw runtime_error("Denominator cannot be zero");
            }
        }
        else
        {
            f.mone = numerator;
            f.mechane = 1;
            input.clear();
            input.putback(slash);
        }
    }
    return input;
}



float ariel::FractionToFloat(const Fraction &a) {
    float fraction_float = static_cast<float>(a.getMone()) / static_cast<float>(a.getMechane());
    float rounded_float = static_cast<float>(static_cast<int>(fraction_float * 1000)) / 1000;
    return rounded_float;
}