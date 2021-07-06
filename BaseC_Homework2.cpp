#include <iostream>

using namespace std;

//#1//////////////
void task1() 
{
    short s_temp = 17'003;
    int int_temp = 1'000'000;
    float f_temp = 1.334f;
    double d_temp = 0.3333333333333333;
    long long l_temp = 111'222'333'444'555'666;
    bool b_temp = true;
    char c_temp = 'A';
    cout << c_temp << f_temp << b_temp;
}

//#2-3//////////////
void task2_3()
{
    enum T3_chars
    {
        CHAR_NONE,
        CHAR_O,
        CHAR_X,
    };
    T3_chars temp_chars[] = { CHAR_NONE, CHAR_O, CHAR_X };

    // Вывод массива значений перечисления
    for (int i = 0; i < 3; i++)
    {
        if (temp_chars[i] == CHAR_NONE)
            cout << '\0';
        else if (temp_chars[i] == 1)
            cout << 'O';
        else if (temp_chars[i] == T3_chars(2))
            cout << 'X';
    }
}

//#4//////////////
void task4()
{
    struct T3_player
    {
        string name;
        char mark;
    };
    struct T3_game
    {
        char board[3][3];
        T3_player playerA, playerB;
        bool game_on;
        bool game_off = true;
        bool A_turn, B_turn;
        enum Game_results {A_WIN, B_WIN, DRAW};        
    };

    T3_player Vasya, Petya;
    Vasya.name = "Vasya";
    Vasya.mark = 'X';
    Petya.name = "Petya";
    Petya.mark = 'O';

    T3_game test;
    test.playerA = Vasya;
    test.playerB = Petya;
    cout << "Preparing for battle: " << test.playerA.name << " vs. " << test.playerB.name << endl;
}

//MAIN//////////////
int main()
{
    cout << "Task 1: ";
    task1();
    cout << endl;

    cout << "Task 2-3: ";
    task2_3();
    cout << endl;
    
    cout << "Task 4: ";
    task4();
    
    return 0;
}
