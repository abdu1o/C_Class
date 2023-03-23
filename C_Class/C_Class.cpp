#include <iostream>
#include <stdexcept>
#include <fstream>
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

    void save(ofstream& data) 
    {
        data << numerator << endl;
        data << denominator << endl;
    }

    void load(ifstream& data) 
    {
        data >> numerator;
        data >> denominator;
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
        Fraction obj;
        obj.set(numerator, denominator);

        cout << "Enter number: ";
        cin >> num;

        cout << "\n\n";

        ofstream file1("data.txt");
        obj.save(file1);
        file1.close();

        obj.show();
        obj.plus(num);
        obj.minus(num);
        obj.multiplication(num);
        obj.division(num);

        Fraction new_obj;
        ifstream file2("data.txt");
        new_obj.load(file2);
        file2.close();

        cout << "\nNew object data after load: ";
        new_obj.show();  
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
