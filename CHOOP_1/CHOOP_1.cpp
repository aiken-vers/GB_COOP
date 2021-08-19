#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> 
#include <algorithm>
#include <optional>
using namespace std;

//--------------------------------------------------------------------------------------
//STRUCT:Person
//--------------------------------------------------------------------------------------
struct Person
{
    string firstname;
    string lastname;
    string midname;
    Person(string F, string L, string M = "")
    {
        firstname = F;
        lastname = L;
        midname = M;
    }
    friend bool operator<(const Person& p1, const Person& p2);
    friend bool operator==(const Person& p1, const Person& p2);
    friend ostream& operator<<(ostream& out, const Person& p1);
};
//--------------------------------------------------------------------------------------
//STRUCT:PhoneNumber
//--------------------------------------------------------------------------------------
struct PhoneNumber {
    int country;
    int city;
    string number;
    optional<int> subnum;
    PhoneNumber() {}
    PhoneNumber(int c1, int c2, string n, optional<int> s = nullopt)
    {
        country = c1;
        city = c2;
        number = n;
        subnum = s;
    }
    friend bool operator<(const PhoneNumber& p1, const PhoneNumber& p2);
    friend bool operator==(const PhoneNumber& p1, const PhoneNumber& p2);
    friend ostream& operator<<(ostream& out, const PhoneNumber& pn);
};
//--------------------------------------------------------------------------------------
//CLASS:PhoneBook
//--------------------------------------------------------------------------------------
class PhoneBook { 
public:
    vector<pair<Person, PhoneNumber>> book;
    PhoneBook(ifstream& file)
    {
        string bigline;
        stringstream sline;
        string segment;
        vector<string> seglist;
        std::optional<int> oEmpty;
        //Person tempPerson;
        //PhoneNumber tempNumber;

        while (getline(file, bigline))
        {
            sline.str(bigline);
            while (getline(sline, segment, ';'))
            {
                seglist.push_back(segment);
            }
            Person tempPerson(seglist[0], seglist[1], seglist[2]);
            PhoneNumber tempNumber(
                stoi(seglist[3]), 
                stoi(seglist[4]), 
                seglist[5],
                (seglist.size() > 6) ? stoi(seglist[6]) : oEmpty);
            pair<Person, PhoneNumber> tempPair(tempPerson, tempNumber);
            Add(tempPair);
        }
    }
protected:
    bool compName(pair<Person, PhoneNumber> a, pair<Person, PhoneNumber> b)
    {
        return a.first < b.first;
    }
    bool compNumber(pair<Person, PhoneNumber> a, pair<Person, PhoneNumber> b)
    {
        return a.second < b.second;
    }
public:
    void Add(pair<Person, PhoneNumber> entry)
    {
        book.push_back(entry);
    }
    void SortByName()
    {
        sort(book.begin(), book.end(), compName);
    }
    void SortByPhone()
    {
        sort(book.begin(), book.end(), compNumber);
    }
    pair<string, PhoneNumber> GetPhoneNumber(string targetname)
    {
        string answer;
        PhoneNumber targetNumber;
        int counter = 0;

        for (auto entry : book)
        {
            if (entry.first.lastname == targetname)
            {
                ++counter;
                targetNumber = entry.second;
            }
        }

        if (counter == 0)
            answer = "not found";
        else if (counter > 1)
            answer = "found more than 1";

        pair<string, PhoneNumber>finder = make_pair(answer, targetNumber);
        return finder;
    }
    
    class NameMatch {
        pair<Person, PhoneNumber> test;
    public:
        NameMatch(pair<Person, PhoneNumber> t) :test(t) 
        {}
        bool operator()(Person comp)
        {
            return comp.lastname == test.first.lastname;
        }
    };
    
    void ChangePhoneNumber(Person a, PhoneNumber b)
    {        
        //std::vector<int>::iterator it = find_if(book.begin(), book.end(), NameMatch());
        auto entry = find_if(book.begin(), book.end(), NameMatch(a));
        
    }
    friend ostream& operator<<(ostream& out, const PhoneNumber& pb);
};
//--------------------------------------------------------------------------------------
//Re:OPs
//--------------------------------------------------------------------------------------
bool operator<(const Person& p1, const Person& p2)
{
    return tie(p1.lastname, p1.firstname, p1.midname) < tie(p2.lastname, p2.firstname, p2.midname);
}
bool operator==(const Person& p1, const Person& p2)
{
    return tie(p1.lastname, p1.firstname, p1.midname) == tie(p2.lastname, p2.firstname, p2.midname);
}
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2) 
{
    return tie(p1.country, p1.city, p1.number, p1.subnum) < tie(p2.country, p2.city, p2.number, p2.subnum);
}
bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.country, p1.city, p1.number, p1.subnum) == tie(p2.country, p2.city, p2.number, p2.subnum);
}
ostream& operator<<(ostream& out, const Person& p1)
{
    out << p1.lastname << " " << p1.firstname;
    if (p1.midname != "")
        out << " " << p1.midname;

    return out;
}
ostream& operator<<(ostream& out, const PhoneNumber& pn)
{
    out << "+" << pn.country << "(" << pn.city << ")" << pn.number;
    if (pn.subnum.has_value())
        out << " " << pn.subnum.value();

    return out;
}
ostream& operator<<(ostream& out, const PhoneBook& pb)
{
    for (auto entry : pb.book)
    {
        out << entry.first << " " << entry.second << endl;
    }
    return out;
}
//--------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------
// MAIN
//--------------------------------------------------------------------------------------
int main()
{
    ifstream file("ХХХ"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона этого человека, либо строку с ошибкой
        auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
        };
        // вызовы лямбды
        print_phone_number("Ivanov");
        print_phone_number("Petrov");
        cout << "----ChangePhoneNumber----" << endl;
        book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
            PhoneNumber{ 7, 123, "15344458", nullopt });
        book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
            PhoneNumber{ 16, 465, "9155448", 13 });
        cout << book;
}

