#include <iostream>
#include <vector>
#include <clocale>

using namespace std;

/*
Для двух заданных матриц A (NxN) и B (NxN) проверить,
можно ли получить вторую из первой применением конечного
числа (не более четырёх) операций транспонирования
относительно главной и побочной диагоналей.
*/

// Читает элементы матрицы размера n*n в одномерный массив
bool read_matrix(vector<int>& m, int n) {
    for (int i = 0; i < n * n; ++i) {
        if (!(cin >> m[i])) return false;
    }
    return true;
}

// Проверяет, равны ли матрицы A и B поэлементно
bool is_identity(const vector<int>& A, const vector<int>& B, int n) {
    for (int i = 0; i < n * n; ++i) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

// Проверяет транспонирование по главной диагонали
bool is_main_transpose(const vector<int>& A, const vector<int>& B, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (B[i * n + j] != A[j * n + i]) return false;
        }
    }
    return true;
}

// Проверяет транспонирование по побочной диагонали
bool is_secondary_transpose(const vector<int>& A, const vector<int>& B, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int ai = n - 1 - j;
            int aj = n - 1 - i;
            if (B[i * n + j] != A[ai * n + aj]) return false;
        }
    }
    return true;
}

// Проверяет поворот матрицы на 180 градусов
bool is_rotation_180(const vector<int>& A, const vector<int>& B, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int ai = n - 1 - i;
            int aj = n - 1 - j;
            if (B[i * n + j] != A[ai * n + aj]) return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "");

    int n;

    cout << "Введите размер матрицы N: ";
    if (!(cin >> n)) {
        cout << "Ошибка: ожидается целое число N\n";
        return 0;
    }

    if (n <= 0) {
        cout << "Ошибка: N должно быть положительным\n";
        return 0;
    }

    vector<int> A(n * n);
    vector<int> B(n * n);

    cout << "Введите " << n * n << " элементов матрицы A:\n";
    if (!read_matrix(A, n)) {
        cout << "Ошибка ввода матрицы A\n";
        return 1;
    }

    cout << "Введите " << n * n << " элементов матрицы B:\n";
    if (!read_matrix(B, n)) {
        cout << "Ошибка ввода матрицы B\n";
        return 1;
    }

    bool result =
        is_identity(A, B, n) ||
        is_main_transpose(A, B, n) ||
        is_secondary_transpose(A, B, n) ||
        is_rotation_180(A, B, n);

    cout << (result ? "YES\n" : "NO\n");

    return 0;
}
