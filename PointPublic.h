#pragma once             
#include "Point.h"        

class PointPublic : public Point   
{
public:
    // --- Конструктори та деструктор ---
    PointPublic();                                 // Конструктор за умовчанням (0, 0)
    PointPublic(double xVal, double yVal);         // Конструктор ініціалізації
    PointPublic(const PointPublic& r);             // Конструктор копіювання
    ~PointPublic();                                // Деструктор

    // --- Присвоєння та приведення до рядка ---
    PointPublic& operator=(const PointPublic& r);  // Перевантаження оператора присвоєння
    operator string() const;                       // Перетворення об'єкта у літерний рядок

    // --- Інкремент і декремент (префіксні змінюють X, постфіксні — Y) ---
    PointPublic& operator++();                     // Префіксний інкремент (++p): збільшує X на 1
    PointPublic& operator--();                     // Префіксний декремент (--p): зменшує X на 1
    PointPublic operator++(int);                   // Постфіксний інкремент (p++): збільшує Y на 1
    PointPublic operator--(int);                   // Постфіксний декремент (p--): зменшує Y на 1

    // --- Методи за варіантом 15 ---
    double distanceToOrigin() const;               // Визначення відстані до початку координат (0, 0)
    void toPolar(double& r, double& phi) const;    // Перетворення у полярні координати (r — радіус, phi — кут)

    // --- Порівняння на рівність та нерівність (зовнішні дружні функції) ---
    friend bool operator==(const PointPublic& l, const PointPublic& r); // Перевірка на рівність (==)
    friend bool operator!=(const PointPublic& l, const PointPublic& r); // Перевірка на нерівність (!=)
};