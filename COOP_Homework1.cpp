#include <iostream>
#include <cstdint>
using namespace std;

class Power;
class RGBA;

/// <summary>
/// Возведение числа в степень
/// </summary>
class Power
{
private:
    float a = 1;
    float b = 1;
public:
    /// <summary>
    /// Возведение числа 'A' в степень 'B'
    /// </summary>
    /// <param name="A">число 'A'</param>
    /// <param name="B">число 'B'</param>
    Power(float A, float B) : a(A), b(B) {     }

    void set(float A, float B)
    {
        a = A;
        b = B;
    }

    float calculate()
    {
        return pow(a, b);
    }
};

/// <summary>
/// Класс RGBA
/// </summary>
class RGBA 
{
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    /// <summary>
    /// Объект RGBA
    /// </summary>
    /// <param name="red">красный</param>
    /// <param name="green">зеленый</param>
    /// <param name="blue">синий</param>
    /// <param name="alpha">непрозрачность</param>
    RGBA(uint8_t red=0, uint8_t green=0, uint8_t blue=0, uint8_t alpha=255)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {}  

    void print() 
    {
        cout << "R:" << (uint16_t)m_red << " G:" << (uint16_t)m_green << " B:" << (uint16_t)m_blue << " a:" << (uint16_t)m_alpha<<endl;
    }
};

/// <summary>
/// Класс стэка
/// </summary>
class Stack
{
private:
    int stack[10] = {};
    const int max = 10;
    int count = 0;
public:
    /// <summary>
    /// Очистить стэк
    /// </summary>
    void reset() 
    {
        for (int p : stack) 
        {
            p = 0;
        }
        count = 0;
    }
    /// <summary>
    /// Положить элемент в стэк
    /// </summary>
    /// <param name="p">новый элемент</param>
    /// <returns>true/false - незаполнен/заполнен</returns>
    bool push(int p) 
    {
        if (count < max) {
            stack[count] = p;
            count++;
            return true;
        }
        return false;
    }
    /// <summary>
    /// Достать элемент из стэка
    /// </summary>
    /// <returns></returns>
    int pop() 
    {
        if (count > 0) 
        {
            count--;
            return stack[count];
        }
        cout << "Stack is empty!";
        return 0;
    }
    void print() 
    {
        cout << " ( ";
        for (int i = 0; i < count; i++)
        {
            cout << stack[i] << " ";
        }
        cout << ")" << endl;        
    }

};

int main()
{    
    //#1---------------------------
    cout << "#1---------------------------" << endl;
    Power p(3.0f, 5.0f);
    p.set(2.0f, 9.643f);
    cout << p.calculate() << endl;
    //#2---------------------------
    cout << "#2---------------------------" << endl;
    RGBA butter (249, 238, 182);
    butter.print();
    //#3---------------------------
    cout << "#3---------------------------" << endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
}