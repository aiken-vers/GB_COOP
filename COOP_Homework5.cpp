#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------------------------
#pragma region Task1
template <class T>
class Pair1
{
    T a, b;
public:
    Pair1(T A, T B) : a(A), b(B) {

    }
    T first() const {
        return a;
    }
    T second() const {
        return b;
    }
};
#pragma endregion
//-------------------------------------------------------------------
#pragma region Task2
template <class T1, class T2>
class Pair
{
    T1 a;
    T2 b;
public:
    Pair(T1 A, T2 B) : a(A), b(B) {

    }
    T1 first() const {
        return a;
    }
    T2 second() const {
        return b;
    }
};
#pragma endregion
//-------------------------------------------------------------------
#pragma region Task3
template <class T>
class StringValuePair : public Pair<string, T> {
public:
    StringValuePair(string A, T B) : Pair<string, T>(A, B) { }
};
#pragma endregion

int main()
{
    //Task1==========================================================
    cout << "Task1===================================================" << endl;
    Pair1<int> p1(6, 9);
    cout << "Pair1: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair2: " << p2.first() << ' ' << p2.second() << '\n';
    //Task2==========================================================
    cout << "Task2===================================================" << endl;
    Pair<int, double> p3(6, 7.8);
    cout << "Pair3: " << p3.first() << ' ' << p3.second() << '\n';
    const Pair<double, int> p4(3.4, 5);
    cout << "Pair4: " << p4.first() << ' ' << p4.second() << '\n';
    //Task3==========================================================
    cout << "Task3===================================================" << endl;
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

}

//Task4======================================================================================
#pragma region Task4_BlackJack
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
        T2 = 2,
        T3 = 3,
        T4 = 4,
        T5 = 5,
        T6 = 6,
        T7 = 7,
        T8 = 8,
        T9 = 9,
        T10 = 10,
        JACK = 10,
        QUEEN = 10,
        KING = 10,
        ACE = 1
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
    bool isAce() {
        if (getValue() == 1)
            return true;

        return false;
    }
    int getValue() // возврат цены карты
    {
        return rank;
    }
};

class Hand {
private:
    list<Card> cards;
    int value=0;
public:
    void Add(Card new_card) {
        cards.push_back(new_card);        
    }
    void Clear() {
        cards.clear();
    }
    int GetValue() {
        int aces = 0;
        for (Card c : cards) {
            if (c.isAce()) {
                aces++;
                continue;
            }
            value += c.getValue();
        }
        value += aces;
        
        if (value <= 11)
            value += 10;
                
        return value;
    }
};

class GenericPlayer : public Hand {
private:
    string name;
public:
    virtual bool isHitting() {
        if (GetValue() < 17)
            return true;
        return false;
    }

    bool isBoosted() {
        if (GetValue() > 21)
            return true;
        return false;
    }
    void Bust() {
        cout << "Player " << name << " is boosted";
    }
};
#pragma endregion