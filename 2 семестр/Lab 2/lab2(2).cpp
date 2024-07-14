//Representation of a prime fraction

#include <iostream>

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
	//The constructor without parameters
	Fraction() : numerator(0), denominator(1) {}
	//The constructor with 2 parameters
	Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}
	void reduceFraction() {
		int gcd_n_d = gcd(abs(numerator), abs(denominator));
		numerator /= gcd_n_d;
		denominator /= gcd_n_d;
		if (denominator < 0 && numerator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}
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
		out << int_part_fraction << " integer part of fraction";
		if (remainder != 0) {
			out << " and " << remainder << "/" << abs(fraction.denominator);
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
	Fraction result;
	result.numerator = fraction1.numerator * fraction2.denominator;
	result.denominator = fraction1.denominator * fraction2.numerator;
	result.reduceFraction();
	return result;
}
bool operator<(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator*fraction2.denominator < fraction2.numerator * fraction1.denominator;
}
bool operator<=(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator * fraction2.denominator <= fraction2.numerator* fraction1.denominator;
}
bool operator>(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator * fraction2.denominator > fraction2.numerator* fraction1.denominator;;
}
bool operator>=(Fraction& fraction1, Fraction& fraction2) {
	return fraction1.numerator * fraction2.denominator >= fraction2.numerator * fraction1.denominator;
}

int main()
{
	Fraction fraction1, fraction2;
	std::cout << "Enter 2 fractions(instead of the '/', press a space):\n";
	std::cout << "1 fraction: ";
	std::cin >> fraction1;
	if (!fraction1.checkFractionValidity()) {
		std::cerr << "Error: division by zero\n";
		return 0;
	}

	std::cout << "2 fraction: ";
	std::cin >> fraction2;
	if (!fraction2.checkFractionValidity()) {
		std::cerr << "Error: division by zero\n";
		return 0;
	}
	std::cout << "\n";
	//Reducing fractions
	fraction1.reduceFraction();
	fraction2.reduceFraction();
	std::cout << "Reduced 1 fraction: " << fraction1 << "\n";
	std::cout << "Reduced 2 fraction: " << fraction2 << "\n";
	std::cout << "\n";

	std::cout << "Sum of fractions: " << fraction1 + fraction2 << "\n";
	std::cout << "Difference of fractions: " << fraction1 - fraction2 << "\n";
	std::cout << "Product of fractions: " << fraction1 * fraction2 << "\n";
	std::cout << "Division of fraction 1 by fraction 2: " << fraction1 / fraction2 << "\n";
	std::cout << "\n";
	if (fraction1 > fraction2) {
		std::cout << "Fraction 1 is bigger than fraction 2" << "\n";
	}
	else if (fraction1 < fraction2) {
		std::cout << "Fraction 2 is bigger than fraction 1" << "\n";
	}
	if (fraction1 >= fraction2) {
		std::cout << "Fraction 1 is bigger than or equal to fraction 2" << "\n";
	}
	if (fraction2 >= fraction1) {
		std::cout << "Fraction 2 is bigger than or equal to fraction 1" << "\n";
	}
	
	return 0;
}

