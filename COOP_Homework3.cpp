#include <iostream>
#include <string> 
#include <cmath>

using namespace std;

#pragma region Task1

class Figure {
    virtual double area() = 0;
};

class Parallelogram : public Figure {
protected:
    double a;
    double b;
public:    
    Parallelogram(double A=0, double B=0) : a(A), b(B) {

    }
    double area() {
        return a * b * sin(a);
    }
};
class Circle : public Figure {
    const double pi = 3.14;
    double r;
public:
    Circle(double Radius) : r(Radius) {

    }
    double area() {
        return pow(r, 2)*pi;
    }
};
class Rectangle : public Parallelogram {
public:
    double area() {
        return a * b;
    }
};
class Square : public Parallelogram {
    double a;
public:
    Square(double A) : a(A) {

    }
    double area() {
        return a * a;
    }
};
class Rhombus : public Parallelogram {
    double a;
public:
    Rhombus(double A) : a(A) {

    }
    double area() {
        return pow(a, 2) * sin(a);
    }
};

#pragma endregion

#pragma region Task2
class Car {
protected:
    string company;
    string model;
public:
    Car(string Comp, string Mod) {
        company = Comp;
        model = Mod;
        cout << " Car " << company << " " << model << " is created;" << endl;
    }
};
class PassengerCar : public Car {
public:
    PassengerCar(string Comp, string Mod) : Car(Comp, Mod){
        cout << " PassengerCar " << company << " " << model << " is created;" << endl;
    }
};
class Bus : public Car {
public:
    Bus(string Comp, string Mod) : Car(Comp, Mod) {
        cout << " Bus " << company << " " << model << " is created;" << endl;
    }
};
class Minivan : public Bus {
public:
    Minivan(string Comp, string Mod) : Bus(Comp, Mod) {
        cout << " Minivan " << Comp << " " << Mod << " is created;" << endl;
    }
};

#pragma endregion

#pragma region Task3
class Fraction {
public:
    double numerator;
    double denominator;
    Fraction(double num, double denum) : numerator(num), denominator(denum) {
        numerator = num;
        if (denum != 0) {
            denominator = denum;
        }
        else {
            denominator = 1;
            cout << "incorrect denominator" << endl;
        }
    }
    Fraction operator +(Fraction f2) {
        Fraction sum(numerator+f2.numerator, denominator+f2.denominator);
        return sum;
    }
    Fraction operator -(Fraction f2) {
        Fraction sum(numerator - f2.numerator, denominator - f2.denominator);
        return sum;
    }
    Fraction operator *(Fraction f2) {
        Fraction sum(numerator * f2.numerator, denominator * f2.denominator);
        return sum;
    }
    Fraction operator /(Fraction f2) {
        Fraction sum(numerator / f2.numerator, denominator / f2.denominator);
        return sum;
    }
};
#pragma endregion
int main()
{
    //#Task1#=======================================================================
    cout << endl << "#Task1#==========================================================" << endl;
    Circle c1(3);
    Square s1(9);
    Rhombus r1(5.7);
    cout << "Circle radius: 3, Circle area: " << to_string(c1.area()) << endl;
    cout << "Square radius: 9, Square area: " << to_string(s1.area()) << endl;
    cout << "Rhombus radius: 5.7, Rhombus area: " << to_string(r1.area()) << endl;
    //#Task2#=======================================================================
    cout << endl << "#Task2#==========================================================" << endl;
    Car car1("Tesla", "Roadster");
    PassengerCar pcar1("LADA", "2102");
    Bus bus1("PAZ", "4234");
    Minivan mini1("Honda", "Odyssey");
    //#Task3#=======================================================================
    cout << endl << "#Task3#==========================================================" << endl;
}

