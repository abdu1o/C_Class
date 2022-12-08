#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	void set(int num1, int num2)
	{
		numerator = num1;
		denominator = num2;
	}

	void show()
	{
		cout << "Your fraction: " << numerator << '/' << denominator << "\n\n";
	}

	void plus(double num)
	{
		double solution = (numerator / denominator) + num;
		cout << numerator << '/' << denominator << " + " << num << " = " << solution << endl;
	}
	void minus(double num)
	{
		double solution = (numerator / denominator) - num;
		cout << numerator << '/' << denominator << " - " << num << " = " << solution << endl;
	}
	void division(double num)
	{
		double solution = numerator / (denominator * num);
		cout << numerator << '/' << denominator << " : " << num << " = " << solution << endl;
	}
	void multiplication(double num)
	{
		double solution = (numerator * num) / denominator;
		cout << numerator << '/' << denominator << " * " << num << " = " << solution << endl;
	}
};



int main()
{
	int numerator, denominator;
	int num;

	cout << "Enter numerator: ";
	cin >> numerator;

	cout << "Enter denominator: ";
	cin >> denominator;

	if (denominator == 0)
	{
		while (denominator == 0)
		{
			cout << "Enter NORMAL denominator: ";
			cin >> denominator;
		}
	}

	cout << "Enter number: ";
	cin >> num;

	Fraction object;

	object.set(numerator, denominator);

	system("cls");
	object.show();

	object.plus(num);
	object.minus(num);
	object.multiplication(num);
	object.division(num);
}

