#include <iostream>
#include <windows.h>
#include "PointPublic.h"
#include "PointPrivate.h"

using namespace std;

// Допоміжна структура для перевірки розміру в режимі #pragma pack(1)
#pragma pack(push, 1)
class PointPacked : public PointPublic {};
#pragma pack(pop)

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== 1. Розмір класів (без pack(1) та з #pragma pack(1)) ===" << endl;
    cout << "sizeof(PointPublic) без pack(1): " << sizeof(PointPublic) << " байт" << endl;
    cout << "sizeof(PointPublic) з #pragma pack(1): " << sizeof(PointPacked) << " байт" << endl;
    cout << "sizeof(PointPrivate) без pack(1): " << sizeof(PointPrivate) << " байт" << endl;

    cout << "\n=== 2. Робота з відкритим нащадком PointPublic ===" << endl;
    PointPublic p1(3.0, 4.0);
    PointPublic p2;
    p2 = p1;                                     // Оператор присвоєння

    cout << "p1 (через базовий <<): " << p1 << endl;
    cout << "p2 (string): " << string(p2) << endl;
    cout << "p1 == p2: " << (p1 == p2 ? "так" : "ні") << endl;

    ++p1;                                        // X + 1 -> (4, 4)
    p1++;                                        // Y + 1 -> (4, 5)
    cout << "p1 після ++p1 та p1++: " << p1 << endl;
    cout << "p1 != p2: " << (p1 != p2 ? "так" : "ні") << endl;

    double r, phi;
    p2.toPolar(r, phi);
    cout << "Відстань p2(3, 4) до (0, 0): " << p2.distanceToOrigin() << endl;
    cout << "Полярні координати p2: r = " << r << ", phi = " << phi << " рад" << endl;

    cout << "\n=== 3. Робота із закритим нащадком PointPrivate ===" << endl;
    PointPrivate pr1;
    cout << "Введіть координати для pr1:" << endl;
    cin >> pr1;
    cout << "pr1 = " << pr1 << endl;

    --pr1;
    pr1--;
    cout << "pr1 після --pr1 та pr1--: " << pr1 << endl;
    cout << "Відстань pr1 до (0, 0): " << pr1.distanceToOrigin() << endl;

    cout << "\n=== 4. Масив об'єктів ===" << endl;
    PointPublic arr[2] = { PointPublic(1.0, 0.0), PointPublic(0.0, 2.0) };
    for (int i = 0; i < 2; i++)
    {
        cout << "arr[" << i << "] = " << arr[i]
            << ", відстань = " << arr[i].distanceToOrigin() << endl;
    }

    return 0;
}