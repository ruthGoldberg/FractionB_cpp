#pragma once
#include <iostream>
namespace ariel{
    class Fraction{
    private:
        int numerator;
        int denominator;
        void reduction ();
        float toFloat()const;
    public:
        Fraction();
        Fraction(int numerator , int denominator);
        Fraction(float decimal);
        Fraction operator+ (const Fraction& other)const;
        Fraction operator+ (float number)const;
        friend Fraction operator+ (float number, const Fraction& other);

        Fraction operator- (const Fraction& other)const;
        Fraction operator- (float number)const;
        friend Fraction operator- (float number, const Fraction& other);

        Fraction operator/ (const Fraction& other)const;
        Fraction operator/ (float number)const;
        friend Fraction operator/ (float number, const Fraction& other);

        Fraction operator* (const Fraction& other)const;
        Fraction operator* (float number)const;
        friend Fraction operator * (float number, const Fraction& other);

        bool operator>= (const Fraction& other)const;
        bool operator>= (float number)const;
        friend bool operator>= (float number, const Fraction& other);

        bool operator> (const Fraction& other)const;
        bool operator> (float number)const;
        friend bool operator> (float number, const Fraction& other);

        bool operator<= (const Fraction& other)const;
        bool operator<=(float number)const;
        friend bool operator<= (float number, const Fraction& other);

        bool operator< (const Fraction& other)const;
        bool operator<(float number)const;
        friend bool operator< (float number, const Fraction& other);

        bool operator == (const Fraction& other)const;
        bool operator==(float number)const;
        friend bool operator== (float number, const Fraction& other);
      
        bool operator != (const Fraction& other)const;
        bool operator!=(float number)const;
        friend bool operator!= (float number, const Fraction& other);

        Fraction operator-- ();
        Fraction operator-- (int);
        Fraction operator++ ();
        Fraction operator++ (int);


        friend std::ostream& operator<< (std::ostream& output, const Fraction& fraction);
        int getNumerator()const{
            return numerator;
        }

        int getDenominator()const{
            return denominator;
        }

        friend std::istream& operator>>(std::istream& input, Fraction& fraction);
    };
}