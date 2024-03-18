// OOP_Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Задание 1

//#include <iostream>
//using namespace std;
//
//const int MAX_SIZE = 100;
//
//class Array {
//public:
//    unsigned int elements[MAX_SIZE];
//    unsigned int size;
//
//public:
//    Array(unsigned int initialSize, unsigned int initValue = 0) : size(initialSize) {
//        for (unsigned int i = 0; i < size; ++i) {
//            elements[i] = initValue;
//        }
//    }
//
//    virtual void add(const Array& other) {
//        for (unsigned int i = 0; i < size && i < other.size; ++i) {
//            elements[i] += other.elements[i];
//        }
//    }
//
//    void display(unsigned int initialSize) {
//        for (unsigned int i = 0; i < 5; ++i) {
//            cout << elements[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//class ArrayA : public Array {
//public:
//    ArrayA(unsigned int initialSize, unsigned int initValue = 0) : Array(initialSize, initValue) {}
//
//    void add(const Array& other) override {
//        for (unsigned int i = 0; i < size && i < other.size; ++i) {
//            elements[i] -= other.elements[i];
//        }
//    }
//};
//
//class ArrayB : public Array {
//public:
//    ArrayB(unsigned int initialSize, unsigned int initValue = 0) : Array(initialSize, initValue) {}
//
//    void add(const Array& other) override {
//        for (unsigned int i = 0; i < size && i < other.size; ++i) {
//            elements[i] *= other.elements[i];
//        }
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    cout << "Объекты а и b класса Array:\n";
//
//    Array a(5, 2);
//    Array b(5, 3);
//
//    cout << " Элементы массива а:";
//    a.display(5);
//
//    cout << " Элементы массива b:";
//    b.display(5);
//
//    cout << " Элементы массива a после поэлементного сложения с массивом b:";
//    a.add(b);
//    a.display(5);
//
//    cout << "--------------------------------------------------------------------------------\n";
//
//    cout << "Объекты c и d класса ArrayA:\n";
//
//    ArrayA c(5, 2);
//    ArrayB d(5, 2);
//
//    cout << " Элементы массива c:";
//    c.display(5);
//
//    cout << " Элементы массива d:";
//    d.display(5);
//
//    cout << " Элементы массива a после поэлементного вычитания с массивом b:";
//    c.add(d);
//    c.display(5);
//
//    cout << "--------------------------------------------------------------------------------\n";
//
//    cout << "Объекты e и f класса ArrayB:\n";
//
//    ArrayB e(5, 2);
//    ArrayB f(5, 2);
//
//    cout << " Элементы массива e:";
//    e.display(5);
//
//    cout << " Элементы массива f:";
//    f.display(5);
//
//    cout << " Элементы массива e после поэлементного умножения c массивом f:";
//    e.add(f);
//    e.display(5);
//
//    return 0;
//}


//Задание 2

//#include <iostream>
//using namespace std;
//
//class Figure {
//public:
//    virtual double area() const = 0;
//    virtual double perimeter() const = 0;
//};
//
//class Rectangle : public Figure {
//private:
//    double width;
//    double height;
//
//public:
//    Rectangle(double w, double h) : width(w), height(h) {}
//
//    double area() const override {
//        return width * height;
//    }
//
//    double perimeter() const override {
//        return 2 * (width + height);
//    }
//};
//
//class Circle : public Figure {
//private:
//    double radius;
//
//public:
//    Circle(double r) : radius(r) {}
//
//    double area() const override {
//        return 3.14159265 * radius * radius;
//    }
//
//    double perimeter() const override {
//        return 2 * 3.14159265 * radius;
//    }
//};
//
//class Trapezium : public Figure {
//private:
//    double side_a;
//    double side_b;
//    double height;
//
//public:
//    Trapezium(double a, double b, double h) : side_a(a), side_b(b), height(h) {}
//
//    double area() const override {
//        return (side_a + side_b) * height / 2.0;
//    }
//
//    double perimeter() const override {
//        return side_a + side_b + 2 * (height / 2);
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    Rectangle rect(4, 5);
//    Circle circle(3);
//    Trapezium trap(2, 4, 3);
//
//    cout << "Площадь прямоугольника: " << rect.area() << ", Периметр: " << rect.perimeter() <<endl;
//    cout << "Площадь круга: " << circle.area() << ", Периметр: " << circle.perimeter() << endl;
//    cout << "Площадь трапеции: " << trap.area() << ", Периметр: " << trap.perimeter() << endl;
//
//    return 0;
//}

//Задание 3

//#include <iostream>
//using namespace std;
//
//class Currency {
//public:
//    virtual double toRubles(double amount) const = 0;
//    virtual void display(double amount) const = 0;
//};
//
//class Dollar : public Currency {
//public:
//    double toRubles(double amount) const override {
//        return amount * 75.0;
//    }
//
//    void display(double amount) const override {
//        cout << "Значение доллара в рублях после перевода : " << toRubles(amount) << endl;
//        cout << endl;
//    }
//};
//
//class Euro : public Currency {
//public:
//    double toRubles(double amount) const override {
//        return amount * 90.0;
//    }
//
//    void display(double amount) const override {
//        cout << "Значение евро в рублях после перевода : " << toRubles(amount) << endl;
//        cout << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL,"rus");
//
//    Dollar dollar;
//    Euro euro;
//
//    double amount;
//
//    cout << "Введите сумму в долларах: ";
//    cin >> amount;
//    dollar.display(amount);
//
//    cout << "Введите сумму в евро: ";
//    cin >> amount;
//    euro.display(amount);
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
