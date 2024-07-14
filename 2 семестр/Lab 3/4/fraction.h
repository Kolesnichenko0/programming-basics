#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdlib.h>
#include <exception>

using std::exception;

//Class for presenting a fraction
class Fraction
{
	//Input operator function
	friend std::istream& operator>>(std::istream& in, Fraction& fraction);
	//Output operator function
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
	//Overloading operations + , -, *, / , <, <= , >, >=
	friend Fraction operator+(Fraction& fraction1, Fraction& fraction2);
	friend Fraction operator-(Fraction& fraction1, Fraction& fraction2);
	friend Fraction operator*(Fraction& fraction1, Fraction& fraction2);
	friend Fraction operator/(Fraction& fraction1, Fraction& fraction2);
	friend bool operator<(Fraction& fraction1, Fraction& fraction2);
	friend bool operator<=(Fraction& fraction1, Fraction& fraction2);
	friend bool operator>(Fraction& fraction1, Fraction& fraction2);
	friend bool operator>=(Fraction& fraction1, Fraction& fraction2);
private:
	int numerator, denominator;
	//Finding the greatest common divisor
	int gcd(int numerator, int denominator) {
		return (denominator == 0) ? numerator : gcd(denominator, numerator % denominator);
	}

public:
	//Exception class for error: devision by zero
	class DevisionByZero : public exception {
	public:
		virtual const char* what() const noexcept { //the function cannot throw exceptions
			return "Devision by zero";
		}
	};

	//The constructor without parameters
	Fraction() : numerator(0), denominator(1) {}
	//The constructor with 2 parameters
	Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
		if (denominator == 0) {
			throw DevisionByZero();
		}
	}
	void reduceFraction() {
		int gcd_n_d = gcd(abs(numerator), abs(denominator));
		numerator /= gcd_n_d;
		denominator /= gcd_n_d;
		if (denominator < 0 && numerator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}

	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }

	//Checking for the existence of a fraction
	bool checkFractionValidity() const {
		return (denominator == 0) ? 0 : 1;
	}
};

std::istream& operator>>(std::istream& in, Fraction& fraction) {
	return in >> fraction.numerator >> fraction.denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
	if (fraction.numerator == 0) {
		return out << 0;
	}
	else if (fraction.denominator == 1) {
		return out << fraction.numerator;
	}
	//If the fraction is incorrect
	else if (abs(fraction.numerator) > abs(fraction.denominator)) {
		int int_part_fraction = fraction.numerator / fraction.denominator;
		int remainder = abs(fraction.numerator) % abs(fraction.denominator);
		out << int_part_fraction;
		if (remainder != 0) {
			out << "integer part of fraction and " << remainder << "/" << abs(fraction.denominator);
		}
		return out;
	}
	//If the fraction is correct
	else {
		if (fraction.denominator < 0) {
			return out << -fraction.numerator << "/" << -fraction.denominator;
		}
		else {
			return out << fraction.numerator << "/" << fraction.denominator;
		}
	}
}

Fraction operator+(Fraction& fraction1, Fraction& fraction2) {
	Fraction result;
	result.numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
	result.denominator = fraction1.denominator * fraction2.denominator;
	result.reduceFraction();
	return result;
}
Fraction operator-(Fraction& fraction1, Fraction& fraction2) {
	Fraction result;
	result.numerator = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
	result.denominator = fraction1.denominator * fraction2.denominator;
	result.reduceFraction();
	return result;
}
Fraction operator*(Fraction& fraction1, Fraction& fraction2) {
	Fraction result;
	result.numerator = fraction1.numerator * fraction2.numerator;
	result.denominator = fraction1.denominator * fraction2.denominator;
	result.reduceFraction();
	return result;
}
Fraction operator/(Fraction& fraction1, Fraction& fraction2) {
	if (fraction2.numerator == 0) {
		throw Fraction::DevisionByZero();
	}
	Fraction result;
	result.numerator = fraction1.numerator * fraction2.denominator;
	result.denominator = fraction1.denominator * fraction2.numerator;
	result.reduceFraction();
	return result;
}
bool operator<(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator * fraction2.denominator < fraction2.numerator* fraction1.denominator;
}
bool operator<=(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator * fraction2.denominator <= fraction2.numerator * fraction1.denominator;
}
bool operator>(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator * fraction2.denominator > fraction2.numerator * fraction1.denominator;;
}
bool operator>=(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator * fraction2.denominator >= fraction2.numerator * fraction1.denominator;
}

#endif
