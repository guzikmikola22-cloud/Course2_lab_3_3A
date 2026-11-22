#include "PointPublic.h"   
#include <cmath>           
#include <sstream>         

// --- Конструктор за умовчанням ---
PointPublic::PointPublic() : Point(0.0, 0.0)             // Викликаємо базовий конструктор із нулями
{}

// --- Конструктор ініціалізації ---
PointPublic::PointPublic(double xVal, double yVal) : Point(xVal, yVal) // Передаємо координати в базовий клас Point
{}

// --- Конструктор копіювання ---
PointPublic::PointPublic(const PointPublic& r) : Point(r) // Копіюємо базову частину з об'єкта r
{}

// --- Деструктор ---
PointPublic::~PointPublic()
{}                                                       // Базовий деструктор викличеться автоматично

// --- Перевантаження оператора присвоєння (=) ---
PointPublic& PointPublic::operator=(const PointPublic& r)
{
    if (this != &r)                                      // Захист від самоприсвоєння (a = a)
    {
        setX(r.getX());                                  // Копіюємо координату X через сеттер
        setY(r.getY());                                  // Копіюємо координату Y через сеттер
    }
    return *this;                                        // Повертаємо посилання на поточний об'єкт
}

// --- Операція приведення типу до string ---
PointPublic::operator string() const
{
    stringstream ss;                                     // Створюємо рядковий потік
    ss << "PointPublic(" << getX() << ", " << getY() << ")"; // Форматуємо рядок із координатами
    return ss.str();                                     // Повертаємо готовий рядок
}

// --- Префіксний інкремент (++p): збільшує X на 1 ---
PointPublic& PointPublic::operator++()
{
    setX(getX() + 1.0);                                  // Додаємо 1 до X
    return *this;                                        // Повертаємо вже змінений об'єкт
}

// --- Префіксний декремент (--p): зменшує X на 1 ---
PointPublic& PointPublic::operator--()
{
    setX(getX() - 1.0);                                  // Віднімаємо 1 від X
    return *this;                                        // Повертаємо вже змінений об'єкт
}

// --- Постфіксний інкремент (p++): збільшує Y на 1 ---
PointPublic PointPublic::operator++(int)
{
    PointPublic temp(*this);                             // Зберігаємо копію старого стану
    setY(getY() + 1.0);                                  // Додаємо 1 до Y
    return temp;                                         // Повертаємо стару копію
}

// --- Постфіксний декремент (p--): зменшує Y на 1 ---
PointPublic PointPublic::operator--(int)
{
    PointPublic temp(*this);                             // Зберігаємо копію старого стану
    setY(getY() - 1.0);                                  // Віднімаємо 1 від Y
    return temp;                                         // Повертаємо стару копію
}

// --- Відстань до початку координат: sqrt(x^2 + y^2) ---
double PointPublic::distanceToOrigin() const
{
    return sqrt(getX() * getX() + getY() * getY());      // Формула відстані до (0, 0)
}

// --- Перетворення у полярні координати: r — радіус, phi — кут у радіанах ---
void PointPublic::toPolar(double& r, double& phi) const
{
    r = distanceToOrigin();                              // Полярний радіус r = √(x² + y²)
    phi = atan2(getY(), getX());                         // Полярний кут phi у радіанах
}

// --- Порівняння на рівність (==) ---
bool operator==(const PointPublic& l, const PointPublic& r)
{
    return (l.getX() == r.getX()) && (l.getY() == r.getY()); // Точки рівні, якщо рівні їхні X та Y
}

// --- Порівняння на нерівність (!=) ---
bool operator!=(const PointPublic& l, const PointPublic& r)
{
    return !(l == r);                                    // Заперечення результату оператора ==
}