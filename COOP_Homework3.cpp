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
    void print() {
        cout << to_string(numerator)<<"/"<<denominator<<endl;
    }

    friend Fraction operator +(Fraction f1, Fraction f2);
    friend Fraction operator -(Fraction f1, Fraction f2);
    friend Fraction operator *(Fraction f1, Fraction f2);
    friend Fraction operator /(Fraction f1, Fraction f2);
    friend Fraction operator -(Fraction f1);
    friend bool operator ==(Fraction f1, Fraction f2);
    friend bool operator !=(Fraction f1, Fraction f2);
    friend bool operator >(Fraction f1, Fraction f2);
    friend bool operator <(Fraction f1, Fraction f2);
    friend bool operator >=(Fraction f1, Fraction f2);
    friend bool operator <=(Fraction f1, Fraction f2);
};

Fraction operator +(Fraction f1, Fraction f2)  {
    return Fraction(f1.numerator + f2.numerator, f1.denominator);
}
Fraction operator -(Fraction f1, Fraction f2) {
    return Fraction(f1.numerator - f2.numerator, f1.denominator);
}
Fraction operator *(Fraction f1, Fraction f2) {
    return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
}
Fraction operator /(Fraction f1, Fraction f2) {
    return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
}
Fraction operator -(Fraction f1) {
    return Fraction(-f1.numerator, f1.denominator);
}
bool operator ==(Fraction f1, Fraction f2) {
    if (f1.numerator == f2.numerator && f1.denominator == f2.denominator) {
        return true;
    }
    return false;
}
bool operator !=(Fraction f1, Fraction f2) {
    if (f1.numerator == f2.numerator && f1.denominator == f2.denominator) {
        return false;
    }
    return true;
}
bool operator >(Fraction f1, Fraction f2) {
    if (f1.numerator > f2.numerator) {
        return true;
    }
    return false;
}
bool operator <(Fraction f1, Fraction f2) {
    if (f1.numerator < f2.numerator) {
        return true;
    }
    return false;
}
bool operator >=(Fraction f1, Fraction f2) {
    if (f1 < f2) {
        return false;
    }
    return true;
}
bool operator <=(Fraction f1, Fraction f2) {
    if (f1 > f2) {
        return false;
    }
    return true;
}


#pragma endregion

#pragma region Task4
#include <list>
class Data {
public:
    static const enum suits {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    static const enum ranks {
        T2,
        T3,
        T4,
        T5,
        T6,
        T7,
        T8,
        T9,
        T10,
        JACK,
        QUEEN,
        KING,
        ACE
    };
};

class Card {
private:
    Data::suits suit;
    Data::ranks rank;
    bool cardUp = false;
public:
    Card(Data::suits Suit, Data::ranks Rank) : suit(Suit), rank(Rank)
    {}

    void Flip() {
        cardUp = !cardUp;
    }

    bool isAce() //проверка, является ли карта тузом
    {}
    int getValue() // возврат цены карты
    {
        if (rank > 8 && rank != 12) {
            return 10;
        }
        if (rank == 12) {
            return 1;
        }

        return rank+2;
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
    Fraction f1(7, 9);
    Fraction f2(2, 9);
    (f1 - f2).print();
    //#Task4#=======================================================================
    cout << endl << "#Task4#==========================================================" << endl;
    Card Spades9(Data::SPADES, Data::T9);
    cout << "Spades 9 value = " << Spades9.getValue() << endl;
}