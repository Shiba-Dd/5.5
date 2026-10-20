#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

int current_depth = 0;
int max_depth = 0;
long long total_calls = 0;

int A(int m, int n) {
    total_calls++;
    current_depth++;

    if (current_depth > max_depth) {
        max_depth = current_depth;
    }

    cout << "Виклик #" << total_calls << " | РІВЕНЬ: " << current_depth
        << " | ЗНАЧЕННЯ: A(" << m << ", " << n << ")\n";

    int result;

    if (m == 0) {
        result = n + 1;
    }
    else if (m > 0 && n == 0) {
        result = A(m - 1, 1);
    }
    else {
        result = A(m - 1, A(m, n - 1));
    }

    current_depth--;
    return result;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int m, n;
    cout << "Введіть m: ";
    cin >> m;
    cout << "Введіть n: ";
    cin >> n;

    if (m < 0 || n < 0) {
        cout << "Помилка: m та n мають бути невід'ємними числами.\n";
        return 1;
    }

    current_depth = 0;
    max_depth = 0;
    total_calls = 0;

    int result = A(m, n);

    cout << "\nРезультат\n";
    cout << "Значення A(" << m << ", " << n << ") = " << result << "\n";
    cout << "Максимальна глибина рекурсії: " << max_depth << "\n";
    cout << "Загальна кількість викликів: " << total_calls << "\n";

    return 0;
}