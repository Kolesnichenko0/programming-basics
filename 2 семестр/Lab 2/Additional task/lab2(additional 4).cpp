//Quadratic equation
#include <iostream>

class Quadratic_equation {
    friend void solving_equation(const Quadratic_equation& equation);
private:
    double a, b, c;
public:
	//The constructor without parameters
    Quadratic_equation() : a(0), b(0), c(0) {}
	//The constructor with 3 parameters
    Quadratic_equation(double a, double b, double c) : a(a), b(b), c(c) {}
	//Methods for setting and getting the values of equation coefficients
	double getValueA() const { return a; }
	double getValueB() const { return b; }
	double getValueC() const { return c; }
	void setValueA(double a) { this->a = a; }
	void setValueB(double b) { this->b = b; }
	void setValueC(double c) { this->c = c; }
};

//Function for finding the roots of an equation
void solving_equation(const Quadratic_equation& equation) {
	double x1, x2;
	int count; //Counter for the number of roots
	if (equation.a == 0) {
		(equation.b != 0) ? (x1 = -equation.c / equation.b, count = 1) : ((equation.c == 0) ? (count = -1) : (count = 0));
	}
	else {
		double discriminant = equation.b * equation.b - 4 * equation.a * equation.c;
		if (discriminant < 0) {
			count = 0;
		}
		else {
			x1 = (-equation.b + sqrt(discriminant)) / (2 * equation.a);
			x2 = (-equation.b - sqrt(discriminant)) / (2 * equation.a);
			(x1 == x2) ? (x1 == x2, count = 1) : (count = 2);
		}
	}
	//Printing of the solution
	switch (count)
	{
	case -1:
		std::cout << "The equation has many roots" << std::endl;
		break;
	case 0:
		std::cout << "The equation has no roots" << std::endl;
		break;
	case 1:
		std::cout << "The equation has 1 root : " << std::endl;
		std::cout << "x = " << x1 << std::endl;
		break;
	case 2:
		std::cout << "The equation has 2 roots : " << std::endl;
		std::cout << "x1 = " << x1 << std::endl << "x2 = " << x2 << std::endl;
		break;
	}
}

//Function for printing the coefficients of the equation
void printABC(const Quadratic_equation& equation) {
	std::cout << "a = " << equation.getValueA() << std::endl;
	std::cout << "b = " << equation.getValueB() << std::endl;
	std::cout << "c = " << equation.getValueC() << std::endl;
}

int main()
{
	Quadratic_equation equation1(1.0, 0, -4.0);
	std::cout << "Quadratic_equation 1: ax^2+bx+c=0" << std::endl;
	printABC(equation1);
	std::cout << "Solving equation..." << std::endl;
	solving_equation(equation1);
	std::cout << std::endl;

	Quadratic_equation equation2;
	std::cout << "Quadratic_equation 2: ax^2+bx+c=0" << std::endl;
	printABC(equation2);
	std::cout << "Solving equation..." << std::endl;
	solving_equation(equation2);
	std::cout << std::endl;

	std::cout << "Changing a, b, c of equation 2..." << std::endl;
	equation2.setValueA(1.0);
	equation2.setValueB(6.0);
	equation2.setValueC(9.0);
	printABC(equation2);
	std::cout << "Solving equation..." << std::endl;
	solving_equation(equation2);
	std::cout << std::endl;

	return 0;
}
