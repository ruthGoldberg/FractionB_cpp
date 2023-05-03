#include "Fraction.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Fraction::Fraction():numerator(0),denominator(1){}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Error: denominator can not be zero");
    }
    int gcdResult = gcd(numerator, denominator);
    this->numerator = numerator / gcdResult;
    this->denominator = denominator / gcdResult;
    if(this->denominator<0){
        this->denominator = this->denominator * (-1);
        this->numerator = this->numerator * (-1);
    }
}
Fraction::Fraction(float decimal):numerator(decimal*1000),denominator(1000) {
    int gcdResult = gcd(numerator, denominator);
    this->numerator = numerator / gcdResult;
    this->denominator = denominator / gcdResult;
}

int Fraction::gcd(int num1, int num2) {
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

Fraction Fraction::toFraction(const float decimal)const {
    int numerator = decimal*1000;
    return Fraction(numerator , 1000);
}

float ariel::toFloat(const Fraction& fraction){
    float num = (float)(fraction.getNumerator()) / fraction.getDenominator();
    return num;
}

Fraction Fraction:: operator+(const Fraction &other) const {
    if(denominator == other.getDenominator()){
        return Fraction(numerator+other.getNumerator() , denominator);
    }
    int newNumerator = this->numerator * other.getDenominator() + this->denominator * other.getNumerator();
    int newDenominator = this->denominator * other.getDenominator();
    return Fraction(newNumerator , newDenominator);
}

Fraction Fraction::operator+(const float number) const {
    Fraction f(number);
    return (*this) + f;
}

std::ostream &ariel::operator<<(std::ostream &output, const ariel::Fraction &fraction) {
    output << fraction.getNumerator() << "/" << fraction.getDenominator();
    return output;
}

Fraction ariel::operator+(float number, const Fraction &other) {
    return other + number;
}
Fraction Fraction:: operator- (const Fraction& other)const{
    if(denominator == other.getDenominator()){
        return Fraction(numerator-other.getNumerator() , denominator);
    }
    int newNumerator = this->numerator * other.getDenominator() - this->denominator * other.getNumerator();
    int newDenominator = this->denominator * other.getDenominator();
    return Fraction(newNumerator , newDenominator);
}
Fraction Fraction:: operator- (const float number)const{
    Fraction f(number);
    return (*this) - f;
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
    Fraction f = toFraction(number);
    return (*this) / f;
}
Fraction ariel::operator/(float number, const Fraction &other) {
    Fraction f(other.getDenominator() , other.getNumerator());
    return f * number;
}
Fraction Fraction::operator* (const Fraction& other)const{
    return Fraction(this->numerator * other.getNumerator() ,this->denominator * other.getDenominator() );
}
Fraction Fraction::operator* (const float number)const{
    Fraction f = toFraction(number);
    return (*this) * f;
}

Fraction ariel::operator*(float number, const Fraction &other) {
    return other * number;
}
bool Fraction::operator>= (const Fraction& other)const{
    float num1 = toFloat(*this);
    float num2 = toFloat(other);
    return num1 >= num2;
}
bool Fraction::operator>= (float number)const{
    float num1 = toFloat(*this);
    return num1 >= number;
}
bool ariel::operator>=(float number, const Fraction &other) {
    return other <= number;
}
bool Fraction::operator> (const Fraction& other)const{
    float num1 = toFloat(*this);
    float num2 = toFloat(other);
    return num1 > num2;
}
bool Fraction::operator> (const float number)const{
    float num1 = toFloat(*this);
    return num1 > number;
}
bool ariel::operator>(float number, const Fraction &other) {
    return other < number;
}

bool ariel::operator<=(float number, const Fraction &other) {
    return other >= number;
}
bool Fraction::operator<= (const Fraction& other)const{
    float num1 = toFloat(*this);
    float num2 = toFloat(other);
    return num1 <= num2;
}
bool Fraction::operator<=(const float number)const{
    float num1 = toFloat(*this);
    return num1 <= number;
}
bool Fraction::operator< (const Fraction& other)const{
    float num1 = toFloat(*this);
    float num2 = toFloat(other);
    return num1 < num2;
}
bool Fraction::operator<(const float number)const{
    float num1 = toFloat(*this);
    return num1 < number;
}
bool ariel::operator<(float number, const Fraction &other) {
    return other > number;
}
bool Fraction::operator == (const Fraction& other)const{
    float frac1 = toFloat(*this);
    float frac2 = toFloat(other);
    return frac1 == frac2;
    
}
bool Fraction::operator==(const float number)const{
    float num = toFloat(*this);
    return num == number;
}
bool ariel:: operator== (float number, const Fraction& other){
    return other == number;
}

Fraction Fraction::operator-- (){
    *this = *this - 1;
    return *this;
}
Fraction Fraction::operator-- (int){
    Fraction temp = *this;
    *this = *this - 1;
    return temp;

    return *this;
}
Fraction Fraction::operator++ (){
    *this = *this +1;
    return *this;
}
Fraction Fraction::operator++ (int){
    Fraction temp = *this;
    *this = *this +1;
    return temp;
}

std::ostream& ariel:: operator<<(std::ostream& os, const bool b) {
    os << (b ? "true" : "false");
    return os;
}
std::istream& ariel::operator>>(std::istream& is, Fraction& fraction) {
    int numerator, denominator;
    is >> numerator >> denominator;
    if(denominator == 0){
        throw runtime_error("Error: denominator can not be zero");
    }
    if (is.fail()) {
        throw runtime_error("Error: Input stream does not contain two integers.");
    }
    fraction.numerator = numerator;
    fraction.denominator = denominator;
    return is;
}


