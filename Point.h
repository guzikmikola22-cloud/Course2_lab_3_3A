#pragma once               
#include <iostream>       
#include <string>          

using namespace std;       

class Point                // Оголошення базового класу Point (Точка на площині)
{
private:                   // Закрита секція (інкапсуляція — доступ лише всередині класу)
    double x;              // Декартова координата X
    double y;              // Декартова координата Y

public:                    // Відкрита секція (інтерфейс класу)
    // --- Конструктори та деструктор ---
    Point();                               // Конструктор без аргументів (за умовчанням)
    Point(double xVal, double yVal);       // Конструктор ініціалізації
    Point(const Point& r);                 // Конструктор копіювання
    ~Point();                              // Деструктор

    // --- Методи доступу (геттери та сеттери) ---
    double getX() const { return x; }      // Геттер: повертає значення X
    double getY() const { return y; }      // Геттер: повертає значення Y
    void setX(double value);               // Сеттер: встановлює X (із перевіркою коректності)
    void setY(double value);               // Сеттер: встановлює Y (із перевіркою коректності)

    // --- Операції вводу / виводу (дружні функції) ---
    friend ostream& operator<<(ostream& out, const Point& r); // Перевантаження виводу (cout << obj)
    friend istream& operator>>(istream& in, Point& r);        // Перевантаження вводу (cin >> obj)
};