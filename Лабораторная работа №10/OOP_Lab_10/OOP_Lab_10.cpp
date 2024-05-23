// OOP_Lab_10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



//Задание 1

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Gun {
private:
    static double p;
public:
    static int shoot(int n) {
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < n; ++i) {
            if ((double)rand() / RAND_MAX < p) {
                return 1;
            }
        }
        return 0;
    }

    static double estimateProbability(int n) {
        return 1 - pow((1 - p), n);
    }

    static void setProbability(double probability) {
        p = probability;
    }
};

double Gun::p = 0.0;

int main() {
    setlocale(LC_ALL, "rus");

    Gun::setProbability(0.5);

    int n;
    cout << "Введите количество выстрелов: ";
    cin >> n;

    int result = Gun::shoot(n);
    cout << "Результат стрельбы: " << (result == 1 ? "Цель уничтожена" : "Цель не поражена") << endl;

    double estimatedProbability = Gun::estimateProbability(n);
    cout << "Оценочное значение вероятности поражения цели: " << estimatedProbability << endl;

    return 0;
}




//#include <iostream>
//
//class Parent {
//public:
//    static int staticField;
//};
//
//// Инициализация статического поля класса Parent
//int Parent::staticField = 10;
//
//class Child : public Parent {
//public:
//    void displayStaticField() {
//        std::cout << "Value of staticField in Child: " << staticField << std::endl;
//    }
//};
//
//int main() {
//    // Вывод значения статического поля из родительского класса
//    std::cout << "Value of staticField in Parent: " << Parent::staticField << std::endl;
//
//    // Создание объекта подкласса
//    Child childObj;
//
//    // Вызов метода подкласса для вывода значения статического поля
//    childObj.displayStaticField();
//
//    // Изменение значения статического поля в родительском классе
//    Parent::staticField = 20;
//
//    // Вывод нового значения статического поля из подкласса
//    childObj.displayStaticField();
//
//    return 0;
//}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
