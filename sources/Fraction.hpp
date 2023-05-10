#pragma once

#include <iostream>

namespace ariel{
    class Fraction{

        private:
        int mone;
        int mechane;

        public:
        // initializer constructor
        Fraction(int numerator, int denominator);

        // Constructor for convert float to fraction
        Fraction(float num);

        //default constructor
        Fraction(); 

        /* getters and setters to the members */
        int getMone() const;
        int getMechane() const;
        void setMone(int) ;
        void setMechane(int) ;

        
        friend float FractionToFloat(const Fraction& a);
        // binary operators
        Fraction operator+ (const Fraction &other) const;
        Fraction operator- (const Fraction &other) const;
        Fraction operator* (const Fraction &other) const;
        Fraction operator/ (const Fraction &other) const;
        bool operator> (const Fraction &other) const;
        bool operator< (const Fraction &other) const;
        bool operator>= (const Fraction &other) const;
        bool operator<= (const Fraction &other) const;
        Fraction& operator++();
        const Fraction operator++(int);
        Fraction& operator--();
        const Fraction operator--(int);

        /* friend functions */
        friend bool operator== (const Fraction& frac1, const Fraction& frac2);
        friend Fraction operator+ (float frac1, const Fraction& frac2);
        friend Fraction operator- (float frac1, const Fraction& frac2);
        friend Fraction operator* (float frac1, const Fraction& frac2);
        friend Fraction operator/ (float frac1, const Fraction& frac2);
        friend Fraction operator+ (const Fraction& frac2, float frac1);
        friend Fraction operator- (const Fraction& frac2, float frac1);
        friend Fraction operator* (const Fraction& frac2, float frac1);
        friend Fraction operator/ (const Fraction& frac2, float frac1);
        friend bool operator> (float frac1, const Fraction& frac2);
        friend bool operator< (float frac1, const Fraction& frac2);
        friend bool operator>= (float frac1, const Fraction& frac2);
        friend bool operator<= (float frac1, const Fraction& frac2);
        friend bool operator> (const Fraction& frac2, float frac1);
        friend bool operator< (const Fraction& frac2, float frac1);
        friend bool operator>= (const Fraction& frac2, float frac1);
        friend bool operator<= (const Fraction& frac2, float frac1);
        
        // friend global IO operators
        friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);
        friend std::istream& operator>> (std::istream& input,Fraction& frac);
    }; // end of Fraction class
}
