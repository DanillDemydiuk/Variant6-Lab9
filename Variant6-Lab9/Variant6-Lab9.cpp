#include <iostream>
#include <stdlib.h>
using namespace std;

const int n = 5, m = 5;

bool Proste(int num) { // Проверка на простое число
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0) return false;
    return true;
}

bool Doskonale(int num) { // Проверка на совершенное число
    if (num == 1) return false;
    int s = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            s += i;
            if (i != num / i) s += num / i;
        }
    }
    return s == num;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int a[n][m], maxV = -1, maxX = 0, maxY = 0, pCnt = 0;
    int prodP = 1;
    bool fPerf = false; // Чи знайдено досконале число

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = rand() % 93;
            cout << a[i][j] << "\t";
            if (a[i][j] > maxV) {
                maxV = a[i][j];
                maxX = i;
                maxY = j;
            }
            if (Proste(a[i][j])) {
                pCnt++; //  счетчик простых чисел
            }
            if (Doskonale(a[i][j])) {
                prodP *= a[i][j];
                fPerf = true;
            }
        }
        cout << "\n";
    }

    if ((maxX + maxY) % 2 == 0) {
        cout << "Кількість простих чисел: " << pCnt << "\n";
    }
    else if (fPerf) {
        cout << "Добуток досконалих чисел: " << prodP << "\n";
    }
    else {
        cout << "Досконалих чисел не знайдено.\n";
    }

    return 0;
}
