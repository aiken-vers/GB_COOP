#include <iostream>
#include <string>
using namespace std;

/* Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести
сообщение об ошибке и предложить ввести число еще раз.
*/
#pragma region Task1

void Task1() 
{
    cout << "Enter int: ";
    int aka;

    while (!(cin >> aka)) {
        cerr << "Incorrect input!" << endl;
        cin.clear();
        cin.ignore(40, '\n');
        cout << "Enter int: ";
    }
    cout << "aka = " << aka << endl;
}
#pragma endregion

#pragma region Task2

inline ostream& endll(ostream& out)
{
    out << "\n\n";
    out.flush();
    return out;
}
#pragma endregion

#pragma region BlackjackLegacy
#include <vector>
class Data {
public:
    static const enum suits {
        CLUBS='♧',
        DIAMONDS='♢',
        HEARTS='♡',
        SPADES='♤'
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
    bool cardIsUp = false;
public:
    Card(Data::suits Suit, Data::ranks Rank) : suit(Suit), rank(Rank)
    {}

    bool cardUp() const {
        return cardIsUp;
    }
    void Flip() {
        cardIsUp = !cardIsUp;
    }
    bool isAce() const {
        if (getValue() == 1)
            return true;

        return false;
    }
    int getValue() const // возврат цены карты
    {
        return rank;
    }
    friend ostream& operator<< (ostream& out, const Card& card);
};

class Hand {
protected:
    vector<Card> cards;
public:
    void Add(Card new_card) {
        cards.push_back(new_card);
    }
    void Clear() {
        cards.clear();
    }
    int GetValue() const{
        int value = 0;
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
#pragma endregion

#pragma region Task3-5
class GenericPlayer : public Hand {
protected:
    static int count;
    string name;
public:
    GenericPlayer() : name("Player"+count)
    {
        ++count;
    }
    virtual bool isHitting() const
    {}
    bool isBoosted() {
        if (GetValue() > 21)
            return true;
        return false;
    }
    void Bust() {
        cout << "Player " << name << " is boosted";
    }
    friend ostream& operator<< (ostream& out, const GenericPlayer& player);
};

class Player : public GenericPlayer {
private:
    int balance = 0;
public:
    virtual bool IsHitting() const {        
        char answr;
        while (!cin.get(answr) && answr != 'y' && answr != 'n') {
            cout << name << ", need another card? [y/n]" << endl;            
        }
        return(answr == 'y');
    }
    void Win() const {
        cout << name << " Won!" << endl;
    }
    void Lose() const {
        cout << name << " Lost!" << endl;
    }
    void Push() const {
        cout << name << " played to a draw!" << endl;
    }    
};

class House : public GenericPlayer {
    virtual bool IsHitting() const {
        if (GetValue() < 17)
            return true;
        return false;
    }
    void FlipFirstCard() {
        cards[0].Flip();
    }
};

/*Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим), вывести ХХ, 
если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку оператора вывода, 
который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
*/
ostream& operator<< (ostream& out, const Card& card) {
    if (card.cardUp()) {
        out << (char)card.suit << card.rank;
    }
    else {
        out << "XX";
    }
    return out;
}
ostream& operator<< (ostream& out, const GenericPlayer& player) {
    out << player.name << " Score: " << player.GetValue()<< "\n";
    out << player.name << " cards: ";
    for (Card c : player.cards) {
        out << c << " ";
    }
    out << "\n";
    return out;
}

#pragma endregion

int GenericPlayer::count = 0;

int main()
{    
    //Task1==========================================================
    cout << "Task1===================================================" << endl;
    Task1();
    //Task2==========================================================
    cout << "Task2===================================================" << endl;
    cout << "Random text 1" << endll;
    cout << "Random text 2" << endll;
    //Task5==========================================================
    cout << "Task5===================================================" << endl;
    Card c2(Data::suits::SPADES, Data::ranks::JACK);
    c2.Flip();
    cout << c2 << endl;

}


