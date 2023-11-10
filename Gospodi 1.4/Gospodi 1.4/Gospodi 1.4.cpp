﻿// Gospodi 1.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

int main() {
    setlocale(LC_ALL, "");
    // Инициализация переменной для хранения результата
    long long result = 1;

    // Внешний цикл для умножения (1+2)(1+2+3)...(1+2+...+10)
    for (int i = 2; i <= 10; ++i) {
        // Внутренний цикл для вычисления суммы (1+2+...+i)
        int sum = 0;
        for (int j = 1; j <= i; ++j) {
            sum += j;
        }

        // Умножение текущего результата на текущую сумму
        result *= sum;
    }

    // Вывод результата
    std::cout << "Результат вычислений: " << result << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.