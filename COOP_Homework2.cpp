#include <iostream>
#include <string> 
using namespace std;

#pragma region Task1

class Person {
protected:
	string name;
	int age;
	char sex;
	int weight;
public:
	Person(string Name, int Age, char Sex, int Weight) :
		name(Name), age(Age), sex(Sex), weight(Weight)
	{}

	string getName() const {
		return name;
	}
	void setName(string Name) {
		name = Name;
	}
	int getAge() const {
		return age;
	}
	void setAge(int Age) {
		age = Age;
	}
	char getSex() const {
		return sex;
	}
	void setSex(char Sex) {
		sex = Sex;
	}
	int getWeight() const {
		return weight;
	}
	void setWeight(int Weight) {
		weight = Weight;
	}

	string print() const {
		string printed = "Person "+name;
		printed += " {age: " + to_string(age) + ", sex: " + sex + ", weight: "+to_string(weight)+"}";
		return printed;
	}
};

class Student : public Person {
protected:
	int year;
	static int students;
public:
	Student(string Name, int Age, char Sex, int Weight, int Year) :
		year(Year), Person(Name, Age, Sex, Weight)
	{
		students++;
	}

	int getYear() const{
		return year;
	}
	void setYear(int Year) {
		year = Year;
	}
	void addYear() {
		year++;
	}
	static int getCount(){
		return students;
	}

	string print() const {
		string printed = "Student "+name;
		printed += " {age: " + to_string(age) + ", sex: " + sex + ", weight: " + to_string(weight)+"}";
		return printed;
	}
};


#pragma endregion


#pragma region Task2
class Froot {
protected:
	string name;
	string color;
	Froot(string Name, string Color) : name(Name), color(Color)	
	{}
public:
	string getName() const {
		return name;
	}
	string getColor() const {
		return color;
	}
};

class Apple : public Froot {
public:
	Apple(string Color, string name="apple") : Froot(name, Color)
	{}
};

class Banana : public Froot {
public:
	Banana() : Froot("banana", "yellow")
	{}
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple("green", "Granny Smith apple")
	{}
};

#pragma endregion


int Student::students = 0;
int main()
{
	//#Task1#=======================================================================
	cout <<endl<< "#Task1#==========================================================" << endl;
	Person Steve("Steve", 32, 'M', 70);
	cout<<Steve.print()<<endl;
	Student Robert("Robert", 21, 'M', 65, 2021);
	cout << Robert.print() << endl;
	cout << "count " << Robert.getCount() << endl;

	Student Robert2("Robert2", 22, 'F', 63, 2022);
	Student Robert3("Robert3", 23, 'M', 66, 2023);
	cout << Robert2.print() << endl;
	cout << Robert3.print() << endl;
	cout << "count " << Student::getCount() << endl;
	//#Task2#=========================================================================
	cout << endl << "#Task2#==========================================================" << endl;
	Apple a("red");
	Banana b;
	GrannySmith c;

	cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

#pragma region Task3
#include <list>

class Card {
private:
	string suit;
	string rank;
public:	
	Card(string Suit, string Rank) : suit(Suit), rank(Rank) 
	{}

	bool isAce() //проверка, является ли карта тузом
	{}
	int getValue() // возврат цены карты
	{}
};
class Deck {
	list<Card> cards;
	int value = 0;

	void AddCard(Card c) {
		cards.push_back(c);
		if (!c.isAce()) {
			// динамически выбрать размер туза в зависимости от значения value
			// если value>10
			// value++
			// иначе
			// value+=11
		}
		else {
			value += c.getValue();
		}
	}
	int getValue() 
	{}
};

class Player {
private:
	Deck pdeck;
	int cash;
public:
	int bet;
	string name;

	 static enum action {
		HIT,
		STAND,
		DOUBLE_DOWN,
		SPLIT,
		SURRENDER,
		INSURANCE
	};
};

class Game {
	list<Player> players;
	int total_bet;
	Player dealer;
	Deck dealer_deck;
	Deck Table;

	void Serve(Player p, Player::action act) {

	}
};

#pragma endregion

