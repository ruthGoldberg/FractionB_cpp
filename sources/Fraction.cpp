#include "Fraction.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <climits>
using namespace ariel;
using namespace std;
int gcd(int num1, int num2) {
    if(num1 < 0)
        num1 *= (-1);
    if(num2 < 0)
        num2 *= (-1);
    if (num2 == 0) {
        return num1;
    } else {
        return gcd(num2, num1 % num2);
    }
}

Fraction::Fraction():numerator(0),denominator(1){}

Fraction::Fraction(int numerator, int denominator):numerator(numerator),denominator(denominator) {
    if (denominator == 0) {
        throw invalid_argument("Error: denominator can not be zero");
    }
    reduction();
}
Fraction::Fraction(float decimal):numerator(decimal*1000),denominator(1000) {
    reduction();
}
void Fraction :: reduction(){
    int gcdResult = gcd(this->numerator, this->denominator);
    if(this->denominator<0){
        this->denominator = this->denominator * (-1) / gcdResult;
        this->numerator = this->numerator * (-1) / gcdResult;
    }else{
        this->numerator = this->numerator / gcdResult;
        this->denominator = this->denominator / gcdResult;
    }
}
void check_overflow(long num1 , long num2){
    if(num1 > INT_MAX || num2 > INT_MAX){
        throw overflow_error("There is a number larger than integer");
    }
    if(num1 < INT_MIN || num2 < INT_MIN){
        throw overflow_error("There is a number smallest than integer");
    }
} 

float Fraction:: toFloat()const{
        float num = (float)(this->numerator) / (this->denominator);
        return round(num*1000)/1000;
}


Fraction Fraction:: operator+(const Fraction &other) const {
    long newNumerator = static_cast<long>(this->numerator) * other.getDenominator() + this->denominator * other.getNumerator();
    long newDenominator = static_cast<long>(this->denominator) * other.getDenominator();
    check_overflow(newNumerator , newDenominator);
    return Fraction(newNumerator , newDenominator);
}

Fraction Fraction::operator+(const float number) const {
    float decimal = toFloat();
    Fraction frac(decimal +number);
    check_overflow(frac.getNumerator() , frac.getDenominator());
    return frac;
}

Fraction ariel::operator+(float number, const Fraction &other) {
    return other + number;
}
Fraction Fraction:: operator- (const Fraction& other)const{
    long newNumerator = static_cast<long>( this->numerator ) * other.getDenominator() - this->denominator * other.getNumerator();
    long newDenominator = static_cast<long>(this->denominator) * other.getDenominator();
    check_overflow(newNumerator , newDenominator);
    return Fraction(newNumerator , newDenominator);
}
Fraction Fraction:: operator- (const float number)const{
    Fraction f(number);
    return *this - f;
}
Fraction ariel::operator-(float number, const Fraction &other) {
    return -1*(other - number);
}
Fraction Fraction:: operator/ (const Fraction& other)const{
    if(other.getNumerator() == 0)
        throw runtime_error("can not divide by 0");
    Fraction f(other.getDenominator() , other.getNumerator());
    return (*this) * f;
}
Fraction Fraction:: operator/ (const float number)const{
    if(number == 0)
        throw runtime_error("can not divide by 0");
    Fraction f (number);
    return (*this) / f;
}
Fraction ariel::operator/(float number, const Fraction &other) {
    Fraction f(other.getDenominator() , other.getNumerator());
    return f * number;
}
Fraction Fraction::operator* (const Fraction& other)const{
    long newNumerator = static_cast<long>(this->numerator) * other.getNumerator();
    long newDenominator = static_cast<long>(this->denominator) * other.getDenominator();
    check_overflow(newNumerator , newDenominator);
    return Fraction(newNumerator ,newDenominator);
}
Fraction Fraction::operator* (const float number)const{
    Fraction f(number);
    return (*this) * f;
}

Fraction ariel::operator*(float number, const Fraction &other) {
    return other * number;
}
bool Fraction::operator>= (const Fraction& other)const{
    float num1 = toFloat();
    float num2 = other.toFloat();
    return num1 >= num2;
}
bool Fraction::operator>= (float number)const{
    float num1 = toFloat();
    return num1 >= number;
}
bool ariel::operator>=(float number, const Fraction &other) {
    return other <= number;
}
bool Fraction::operator> (const Fraction& other)const{
    float num1 = toFloat();
    float num2 = other.toFloat();
    return num1 > num2;
}
bool Fraction::operator> (const float number)const{
    float num1 = toFloat();
    return num1 > number;
}
bool ariel::operator>(float number, const Fraction &other) {
    return other < number;
}

bool ariel::operator<=(float number, const Fraction &other) {
    return other >= number;
}
bool Fraction::operator<= (const Fraction& other)const{
    float num1 = toFloat();
    float num2 = other.toFloat();
    return num1 <= num2;
}
bool Fraction::operator<=(const float number)const{
    float num1 = toFloat();
    return num1 <= number;
}
bool Fraction::operator< (const Fraction& other)const{
    float num1 = toFloat();
    float num2 = other.toFloat();
    return num1 < num2;
}
bool Fraction::operator<(const float number)const{
    float num1 = toFloat();
    return num1 < number;
}
bool ariel::operator<(float number, const Fraction &other) {
    return other > number;
}
bool Fraction::operator == (const Fraction& other)const{
    float frac1 = toFloat();
    float frac2 = other.toFloat();
    return frac1 == frac2;
    
}
bool Fraction::operator==(const float number)const{
    float num = toFloat();
    return num == number;
}
bool ariel:: operator== (float number, const Fraction& other){
    return other == number;
}
bool Fraction::operator != (const Fraction& other)const{
    return !(*this == other);
    
}
bool Fraction::operator!=(const float number)const{
    return !(*this == number);
}
bool ariel:: operator!= (float number, const Fraction& other){
    return other != number;
}
Fraction Fraction::operator-- (){
    *this = *this - 1;
    return *this;
}
Fraction Fraction::operator-- (int){
    Fraction temp = *this;
    --(*this);
    return temp;

}
Fraction Fraction::operator++ (){
    *this = *this +1;
    return *this;
}
Fraction Fraction::operator++ (int){
    Fraction temp = *this;
    ++(*this) ;   
    return temp;
}

std::ostream &ariel::operator<<(std::ostream &output, const ariel::Fraction &fraction) {
    output << fraction.getNumerator() << "/" << fraction.getDenominator();
    return output;
}

std::istream& ariel::operator>>(std::istream& input, Fraction& fraction) {
    int numeratorIN, denominatorIN;
    input >> numeratorIN >> denominatorIN;
    if(denominatorIN == 0){
        throw runtime_error("Error: denominator can not be zero");
    }
    if (input.fail()) {
        throw runtime_error("Error: Input stream does not contain two integers.");
    } 
    fraction.numerator = numeratorIN;
    fraction.denominator = denominatorIN;
    fraction.reduction();
    return input;
}



