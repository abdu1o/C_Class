#include <iostream>
#include <stdexcept>
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
        if (num2 == 0)
        {
            throw invalid_argument("Denominator can`t be zero!");
        }
        denominator = num2;
    }

    void division(double num)
    {
        if (num == 0)
        {
            throw logic_error("Numerator can`t be zero");
        }
        double solution = numerator / (denominator * num);
        cout << numerator << '/' << denominator << " : " << num << " = " << solution << endl;
    }

    void show()
    {
        cout << "Your fraction: " << numerator << '/' << denominator << "\n\n";
    }

    void plus(double num)
    {
        double solution = (numerator / static_cast<double>(denominator)) + num;
        cout << numerator << '/' << denominator << " + " << num << " = " << solution << endl;
    }

    void minus(double num)
    {
        double solution = (numerator / static_cast<double>(denominator)) - num;
        cout << numerator << '/' << denominator << " - " << num << " = " << solution << endl;
    }

    void multiplication(double num)
    {
        double solution = (numerator * num) / static_cast<double>(denominator);
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

    try
    {
        Fraction object;
        object.set(numerator, denominator);

        cout << "Enter number: ";
        cin >> num;

        cout << "\n\n";

        object.show();
        object.plus(num);
        object.minus(num);
        object.multiplication(num);
        object.division(num);
        object.division(0);
    }
    catch (const invalid_argument& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const logic_error& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}
