// Формування елементів масиву за допомогою генератора випадкових чисел 
// Діапазон значень елементів масиву – від Low до High включно, визначається відповідними параметрами функції. 
// Рекурсивний спосіб

#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create_r(int* c, const int size, const int Low, const int High, int i) {
    if (i == size) {
        return;
    }
    c[i] = Low + rand() % (High - Low + 1);
    Create_r(c, size, Low, High, i + 1);
}

void Print_r(int* c, const int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << c[i];
    Print_r(c, size, i + 1);
}

int Count_r(int* c, const int size, int i) {
    if (i == size) {
        return 0;
    }
    if (!(c[i] % 2 == 0 || i % 13 == 0)) {
        return Count_r(c, size, i + 1) + 1;
    }
    return Count_r(c, size, i + 1);
}

void Zero_r(int* c, const int size, int i) {
    if (i == size) {
        return;
    }
    if (!(c[i] % 2 == 0 || i % 13 == 0)) {
        c[i] = 0;
    }
    Zero_r(c, size, i + 1);
}

int Sum_r(int* c, const int size, int i) {
    if (i == size) {
        return 0;
    }
    if (!(c[i] % 2 == 0 || i % 13 == 0)) {
        return Sum_r(c, size, i + 1) + c[i];
    }
    return Sum_r(c, size, i + 1);
}

int main() {
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел  
    const int n = 21;
    int c[n];

    int Low = 15;
    int High = 85;

    Create_r(c, n, Low, High, 0);
    Print_r(c, n, 0);
    cout << "Sum = " << Sum_r(c, n, 0) << endl;
    cout << "Count = " << Count_r(c, n, 0) << endl;
    Zero_r(c, n, 0);
    Print_r(c, n, 0);

    return 0;
}