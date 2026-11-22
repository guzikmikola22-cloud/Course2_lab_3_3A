#pragma once              
#include "Point.h"        

class PointPrivate : private Point   
{
public:
    // --- Конструктори ---
    PointPrivate();                                // Конструктор за умовчанням (0, 0)
    PointPrivate(double xVal, double yVal);        // Конструктор ініціалізації
    PointPrivate(const PointPrivate& r);           // Конструктор копіювання
    ~PointPrivate();                               // Деструктор

    // --- Відкриваємо доступ до геттерів/сеттерів через using ---
    using Point::getX;                             // Відкриваємо базовий геттер для X
    using Point::getY;                             // Відкриваємо базовий геттер для Y
    using Point::setX;                             // Відкриваємо базовий сеттер для X
    using Point::setY;                             // Відкриваємо базовий сеттер для Y

    // --- Присвоєння та приведення до рядка ---
    PointPrivate& operator=(const PointPrivate& r); // Перевантаження оператора присвоєння
    operator string() const;                        // Перетворення об'єкта у літерний рядок

    // --- Інкремент і декремент ---
    PointPrivate& operator++();                    // Префіксний інкремент (++p): X + 1
    PointPrivate& operator--();                    // Префіксний декремент (--p): X - 1
    PointPrivate operator++(int);                  // Постфіксний інкремент (p++): Y + 1
    PointPrivate operator--(int);                  // Постфіксний декремент (p--): Y - 1

    // --- Методи за варіантом 15 ---
    double distanceToOrigin() const;               // Відстань до початку координат (0, 0)
    void toPolar(double& r, double& phi) const;    // Перетворення у полярні координати (r, phi)

    // --- Порівняння та ввід/вивід (дружні функції) ---
    friend bool operator==(const PointPrivate& l, const PointPrivate& r);     // Перевірка на рівність
    friend bool operator!=(const PointPrivate& l, const PointPrivate& r);     // Перевірка на нерівність
    friend ostream& operator<<(ostream& out, const PointPrivate& r);          // Вивід у потік (cout << obj)
    friend istream& operator>>(istream& in, PointPrivate& r);                 // Ввід із потоку (cin >> obj)
};