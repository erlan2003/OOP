// OOP_Lab_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Задание 1

//#include <iostream>
//#include <cstdlib> 
//
//using namespace std;
//
//const int LIMIT = 5;
//
//class ArrayIndexOutOfBoundsException {
//public:
//    ArrayIndexOutOfBoundsException() {}
//    const char* what() const {
//        return "Индекс выходит за пределы массива!";
//    }
//};
//
//class safearray {
//private:
//    int arr[LIMIT];
//public:
//    void putel(int n, int elvalue) {
//        if (n < 0 || n >= LIMIT)
//            throw ArrayIndexOutOfBoundsException();
//        arr[n] = elvalue;
//    }
//    int getel(int n) const {
//        if (n < 0 || n >= LIMIT)
//            throw ArrayIndexOutOfBoundsException();
//        return arr[n];
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    safearray sal;
//
//    for (int j = 0; j < LIMIT; j++)
//        sal.putel(j, j * 10);
//
//
//    for (int j = 0; j < LIMIT; j++) {
//        try {
//            int temp = sal.getel(j);
//            cout << "Элемент " << j << " равен " << temp << endl;
//        }
//        catch (const ArrayIndexOutOfBoundsException& e) {
//            cout << e.what() << endl;
//            return 1;
//        }
//    }
//    return 0;
//}


//Задание 2

#include <iostream>
#include <stdexcept>

using namespace std;

class Kamaz {
private:
    int speed;
    string name;
    static constexpr int MAX_SPEED = 120;

public:
    Kamaz(int spd, string n) : speed(spd), name(n) {}

    int getSpeed() const {
        return speed;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << "Камаз '" << name << "': скорость " << speed << " км/ч" << endl;
    }

    void checkSpeed() const {
        if (speed > MAX_SPEED) {
            throw exception();
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    try {
        Kamaz kamaz1(130, "КамАЗ-4326-9 (VK) ");
        kamaz1.checkSpeed();
        kamaz1.display();
    }
    catch (const exception& e) {
        cerr << "Ошибка: Превышено лимит скорости!!!" << endl;
        return 1;
    }

    return 0;
}



//#include <iostream>
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    try {
//        int a = 10;
//        int b = 0;
//        if (b == 0) {
//            throw "Деление на ноль!";
//        }
//        int result = a / b;
//        cout << "Результат: " << result << endl;
//    }
//    catch (const char* error) {
//        cout << "Поймано исключение: " << error << endl;
//    }
//    return 0;
//}


//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//class Gun {
//private:
//    static double p; // Вероятность попадания
//public:
//    static int shoot(int n) {
//        srand(static_cast<unsigned int>(time(0)));
//        for (int i = 0; i < n; ++i) {
//            if ((double)rand() / RAND_MAX < p) {
//                return 1; // Самолет сбит
//            }
//        }
//        return 0; // Самолет не сбит
//    }
//
//    static double estimateProbability(int n) {
//        return 1 - pow((1 - p), n);
//    }
//
//    static void setProbability(double probability) {
//        p = probability;
//    }
//};
//
//double Gun::p = 0.0; // Инициализация статического поля
//
//int main() {
//    Gun::setProbability(0.3); // Устанавливаем вероятность попадания
//
//    int n;
//    std::cout << "Введите количество выстрелов: ";
//    std::cin >> n;
//
//    int result = Gun::shoot(n);
//    std::cout << "Результат стрельбы: " << (result == 1 ? "Цель уничтожена" : "Цель не поражена") << std::endl;
//
//    double estimatedProbability = Gun::estimateProbability(n);
//    std::cout << "Оценочное значение вероятности поражения цели: " << estimatedProbability << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <stdexcept>
//
//class Base {
//public:
//    static int staticField;
//};
//
//int Base::staticField = 0;
//
//class Derived : public Base {
//public:
//    void useStaticField() {
//        if (staticField != 0) {
//            throw std::logic_error("Производный класс не может использовать статическое поле базового класса");
//        }
//        std::cout << "Использование статического поля базового класса в производном классе" << std::endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    Derived derivedObj;
//    derivedObj.staticField = 10;
//
//    try {
//        derivedObj.useStaticField();
//    }
//    catch (const std::logic_error& e) {
//        std::cerr << "Перехвачено исключение: " << e.what() << std::endl;
//    }
//
//    return 0;
//}



//#include <iostream>
//#include <stdexcept>
//
//class Parent {
//private:
//    static int staticField;
//
//public:
//    static int getStaticField() {
//        return staticField;
//    }
//};
//
//int Parent::staticField = 10;
//
//class Child : private Parent {
//public:
//    void displayStaticField() {
//        try {
//            // Trying to access the static field through the private method of the parent class
//            int fieldValue = Parent::getStaticField();
//            std::cout << "Значение staticField в родительском классе: " << fieldValue << std::endl;
//        }
//        catch (const std::logic_error& e) {
//            throw std::logic_error("Дочерний объект не может напрямую обратиться к статическому полю родительского класса");
//        }
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    Child childObj;
//
//    try {
//        childObj.displayStaticField();
//    }
//    catch (const std::logic_error& e) {
//        std::cerr << "Поймано исключение: " << e.what() << std::endl;
//    }
//
//    return 0;
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
