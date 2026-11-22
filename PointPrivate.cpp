#include "PointPrivate.h"  
#include <cmath>          
#include <sstream>         

// --- Конструктор за умовчанням ---
PointPrivate::PointPrivate() : Point(0.0, 0.0)             // Викликаємо базовий конструктор із нулями
{}

// --- Конструктор ініціалізації ---
PointPrivate::PointPrivate(double xVal, double yVal) : Point(xVal, yVal) // Передаємо координати в базовий клас Point
{}

// --- Конструктор копіювання ---
PointPrivate::PointPrivate(const PointPrivate& r) : Point(r) // Копіюємо базову частину з об'єкта r
{}

// --- Деструктор ---
PointPrivate::~PointPrivate()
{}                                                         // Базовий деструктор викличеться автоматично

// --- Перевантаження оператора присвоєння (=) ---
PointPrivate& PointPrivate::operator=(const PointPrivate& r)
{
    if (this != &r)                                        // Захист від самоприсвоєння (a = a)
    {
        setX(r.getX());                                    // Копіюємо координату X через сеттер
        setY(r.getY());                                    // Копіюємо координату Y через сеттер
    }
    return *this;                                          // Повертаємо посилання на поточний об'єкт
}

// --- Операція приведення типу до string ---
PointPrivate::operator string() const
{
    stringstream ss;                                       // Створюємо рядковий потік
    ss << "PointPrivate(" << getX() << ", " << getY() << ")"; // Форматуємо рядок із координатами
    return ss.str();                                       // Повертаємо готовий рядок
}

// --- Префіксний інкремент (++p): збільшує X на 1 ---
PointPrivate& PointPrivate::operator++()
{
    setX(getX() + 1.0);                                    // Додаємо 1 до X
    return *this;                                          // Повертаємо вже змінений об'єкт
}

// --- Префіксний декремент (--p): зменшує X на 1 ---
PointPrivate& PointPrivate::operator--()
{
    setX(getX() - 1.0);                                    // Віднімаємо 1 від X
    return *this;                                          // Повертаємо вже змінений об'єкт
}

// --- Постфіксний інкремент (p++): збільшує Y на 1 ---
PointPrivate PointPrivate::operator++(int)
{
    PointPrivate temp(*this);                              // Зберігаємо копію старого стану
    setY(getY() + 1.0);                                    // Додаємо 1 до Y
    return temp;                                           // Повертаємо стару копію
}

// --- Постфіксний декремент (p--): зменшує Y на 1 ---
PointPrivate PointPrivate::operator--(int)
{
    PointPrivate temp(*this);                              // Зберігаємо копію старого стану
    setY(getY() - 1.0);                                    // Віднімаємо 1 від Y
    return temp;                                           // Повертаємо стару копію
}

// --- Визначення відстані до початку координат (0, 0) ---
double PointPrivate::distanceToOrigin() const
{
    return sqrt(getX() * getX() + getY() * getY());        // Формула: √(x² + y²)
}

// --- Перетворення у полярні координати (r, phi) ---
void PointPrivate::toPolar(double& r, double& phi) const
{
    r = distanceToOrigin();                                // Полярний радіус r = √(x² + y²)
    phi = atan2(getY(), getX());                           // Полярний кут phi у радіанах
}

// --- Порівняння на рівність (==) ---
bool operator==(const PointPrivate& l, const PointPrivate& r)
{
    return (l.getX() == r.getX()) && (l.getY() == r.getY()); // Точки рівні, якщо рівні їхні X та Y
}

// --- Порівняння на нерівність (!=) ---
bool operator!=(const PointPrivate& l, const PointPrivate& r)
{
    return !(l == r);                                      // Заперечення результату оператора ==
}

// --- Операція виводу в потік (cout << obj) ---
ostream& operator<<(ostream& out, const PointPrivate& r)
{
    return out << string(r);                               // Перетворюємо об'єкт у string і виводимо
}

// --- Операція вводу з потоку (cin >> obj) ---
istream& operator>>(istream& in, PointPrivate& r)
{
    double xVal, yVal;                                     // Тимчасові змінні для зчитування
    cout << "x = "; in >> xVal;                            // Запит і ввід X
    cout << "y = "; in >> yVal;                            // Запит і ввід Y
    r.setX(xVal);                                          // Запис X із перевіркою
    r.setY(yVal);                                          // Запис Y із перевіркою
    return in;                                             // Повертаємо потік для ланцюжкового вводу
}