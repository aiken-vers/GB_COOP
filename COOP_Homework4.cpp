#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#pragma region Task1
class ArrayInt {
    int m_length;
    int* m_data;
public:
    ArrayInt() : m_length(0), m_data(nullptr) {

    }
    ArrayInt(int length, int* data=nullptr) : m_length(length), m_data(data) {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    ~ArrayInt() {
        delete[] m_data;
    }
    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() {
        return m_length;
    }
    int& operator[](int index) {
        assert(index>=0 && index<m_length);
        return m_data[index];
    }
    int& operator=(int* array) {
        delete[] m_data;
        m_data = array;
    }
    void resize(int newLength) {
        if (m_length == newLength)
            return;
        if (newLength <= 0) {
            erase();
            return;
        }

        int* data = new int[newLength];
        if (m_length > 0) {
            int elementsToCopy = newLength > m_length ? m_length : newLength;
            for (int index = 0; index < elementsToCopy; index++) 
            {
                data[index] = m_data[index];
            }
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }
    void InsertBefore(int value, int index) {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length + 1];
        for (int i = 0; i < index; i++)
        {
            data[i] = m_data[i];
        }
        data[index] = value;
        for (int i = index+1; i < m_length; ++i) {
            data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
        m_length++;
    }
    void push_back(int value) {
        InsertBefore(value, m_length);
    }

    void pop_at(int index) {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length-1];
        int sub_i = 0;
        for (int i = 0; i < m_length; i++)
        {
            if (i == index)
                continue;
            data[sub_i] = m_data[i];
            sub_i++;
        }        
        delete[] m_data;
        m_data = data;
        m_length--;
    }
    void pop_back() {        
        pop_at(m_length-1);
    }
    void pop_front() {
        pop_at(0);
    }
    void shift(int index1, int index2) {
        int temp = 0;
        temp = m_data[index1];
        m_data[index1] = m_data[index2];
        m_data[index2] = temp;
    }
    void sort() {
        int shift_count;
        int sort_length = m_length;
        do {
            shift_count = 0;
            for (int i = 0; i < m_length-1; i++) {
                if (m_data[i] > m_data[i + 1]) {
                    shift(i, i + 1);
                    shift_count++;
                }
                sort_length--;
            }
        } while (shift_count > 0);
    }
    void print() {
        cout << " { ";
        for (int i = 0; i < m_length;i++) {
            cout << m_data[i] << " ";
        }
        cout << "}" << endl;
    }
};

#pragma endregion

#pragma region Task2
void print(vector<int> vec) {
    cout << " { ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "}" << endl;
}

void FindVar(vector<int> v1) {
    vector<int> v2;
    for (int i = 0; i < v1.size(); i++) {
        bool var = true;
        for (int value : v2) {
            if (v1[i] == value)
                var = false;
        }
        if (var)
            v2.push_back(v1[i]);
    }
    cout << "Found different elements: " << v2.size() << endl;
    print(v2);   
}

#pragma endregion

#pragma region Task3
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
        T2=2,
        T3=3,
        T4=4,
        T5=5,
        T6=6,
        T7=7,
        T8=8,
        T9=9,
        T10=10,
        JACK=10,
        QUEEN=10,
        KING=10,
        ACE=1
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
    int getValue() // возврат цены карты
    {    
        return rank;
    }
};

class Hand {
private:
    vector<Card> cards;
    int value;
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
            if (c.getValue() == 1) {
                aces++;
                continue;
            }
            value += c.getValue();
        }
        if (value > 10 || aces > 1)
            value += aces;
        else
            value += 11;
        
        return value;
    }
};
#pragma endregion


int main()
{
    //#Task1#=========================================================================
    cout << endl << "#Task1#==========================================================" << endl;    
    ArrayInt arr;
    arr.push_back(5); arr.push_back(2); arr.push_back(1); arr.push_back(3); arr.push_back(9);
    arr.push_back(0); arr.push_back(4); arr.push_back(6); arr.push_back(8); arr.push_back(7);
    cout << arr.getLength() << endl;
    arr.print();
    arr.sort();
    arr.print();
    arr.pop_back();
    arr.pop_front();
    cout << arr.getLength() << endl;
    arr.print();
    //#Task2#=========================================================================
    cout << endl << "#Task2#==========================================================" << endl;
    vector<int> arr2 = { 5, 5, 1, 9, 1, 5, 5, 1, 9, 9, 1, 1 };
    print(arr2);
    FindVar(arr2);   

}
