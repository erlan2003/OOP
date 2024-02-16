// OOP_Lab_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Задание 1

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Kamaz {
//private:
//    string name;
//    double speed;
//
//public:
//    Kamaz(const string& n, double s){
//        name = n;
//        speed = s;
//    }
//
//    void display(){
//        cout << "Скорость камаза '" << name << "' равна " << speed << " км/час" << endl;
//    }
//
//    double getSpeed() const{
//        return speed;
//    }
//
//    string getName() const {
//        return name;
//    }
//
//};
//
//class Tatra {
//private:
//    string name;
//    double speed;
//
//public:
//    Tatra(const string& n, double s){
//        name = n;
//        speed = s;
//    }
//
//    void display() const {
//        cout << "Скорость татры '" << name << "' равна " << speed << " км/час" << endl;
//    }
//
//    double getSpeed() const {
//        return speed;
//    }
//
//    string getName() const {
//        return name;
//    }
//};
//
//int FrCreator(const Kamaz& kamaz, const Tatra& tatra) {
//    if (kamaz.getSpeed() > tatra.getSpeed()) {
//        return 1;
//    }
//    else if (kamaz.getSpeed() < tatra.getSpeed()) {
//        return -1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    Kamaz kamaz("камаз1", 80);
//    Tatra tatra("татра1", 90);
//
//    int result = FrCreator(kamaz, tatra);
//
//    if (result == 1) {
//        kamaz.display();
//        tatra.display();
//
//        cout << endl;
//
//        cout <<kamaz.getName() << " быстрее чем " <<tatra.getName() <<"!!!" << endl;
//    }
//    else if (result == -1) {
//        kamaz.display();
//        tatra.display();
//
//        cout << endl;
//
//        cout << tatra.getName() << " быстрее чем " << kamaz.getName() <<"!!!" << endl;
//    }
//    else {
//        kamaz.display();
//        tatra.display();
//
//        cout << endl;
//
//        cout << "Их скорости одинаковые!!!" << endl;
//    }
//
//    return 0;
//}

//Задание 2

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Tatra;
//
//class Kamaz {
//private:
//    string name;
//    double speed;
//
//public:
//    Kamaz(const string& n, double s) : name(n), speed(s) {}
//
//    void display() const {
//        cout << "Скорость камаза '" << name << "' равна " << speed << " км/час" << endl;
//    }
//
//    double getSpeed() const {
//        return speed;
//    }
//
//    string getName() const {
//        return name;
//    }
//
//    friend int FrCreator(const Kamaz& kamaz, const Tatra& tatra);
//};
//
//class Tatra {
//private:
//    string name;
//    double speed;
//
//public:
//    Tatra(const string& n, double s) : name(n), speed(s) {}
//
//    void display() const {
//        cout << "Скорость татры '" << name << "' равна " << speed << " км/час" << endl;
//    }
//
//    double getSpeed() const {
//        return speed;
//    }
//
//    string getName() const {
//        return name;
//    }
//
//    friend int FrCreator(const Kamaz& kamaz, const Tatra& tatra);
//};
//
//int FrCreator(const Kamaz& kamaz, const Tatra& tatra) {
//    if (kamaz.speed > tatra.speed) {
//        return 1;
//    }
//    else if (kamaz.speed < tatra.speed) {
//        return -1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    Kamaz kamaz("камаз1", 80);
//    Tatra tatra("татра1", 90);
//
//    int result = FrCreator(kamaz, tatra);
//
//    if (result == 1) {
//        kamaz.display();
//        tatra.display();
//
//        cout << endl;
//
//        cout << kamaz.getName() << " быстрее чем " << tatra.getName() << "!!!" << endl;
//    }
//    else if (result == -1) {
//        kamaz.display();
//        tatra.display();
//
//        cout << endl;
//
//        cout << tatra.getName() << " быстрее чем " << kamaz.getName() << "!!!" << endl;
//    }
//    else {
//        kamaz.display();
//        tatra.display();
//
//        cout << endl;
//
//        cout << "Их скорости одинаковые!!!" << endl;
//    }
//
//    return 0;
//}


//Задание 3

#include <iostream>
#include <string>

using namespace std;

class Tatra;

class Kamaz {
private:
    string name;
    double speed;

public:
    Kamaz(const string& n, double s) : name(n), speed(s) {}

    void display() const {
        cout << "Скорость камаза '" << name << "' равна " << speed << " км/час" << endl;
    }

    double getSpeed() const {
        return speed;
    }

    string getName() const {
        return name;
    }

    friend class Tatra;

    friend int FrCreator(const Kamaz& kamaz, const Tatra& tatra);

};

class Tatra {
private:
    string name;
    double speed;
    string j;

public:
    Tatra(const string& n, double s) : name(n), speed(s) {}

    void display() const {
        cout << "Скорость татры '" << name << "' равна " << speed << " км/час" << endl;
    }

    double getSpeed() const {
        return speed;
    }

    string getName() const {
        return name;
    }

    friend int FrCreator(const Kamaz& kamaz, const Tatra& tatra);

};

int FrCreator(const Kamaz& kamaz, const Tatra& tatra) {
    if (kamaz.speed > tatra.speed) {
        return 1;
    }
    else if (kamaz.speed < tatra.speed) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    Kamaz kamaz("камаз1", 80);
    Tatra tatra("татра1", 90);

    int result = FrCreator(kamaz, tatra);

    if (result == 1) {
        kamaz.display();
        tatra.display();

        cout << endl;

        cout << kamaz.getName() << " быстрее чем " << tatra.getName() << "!!!" << endl;
    }
    else if (result == -1) {
        kamaz.display();
        tatra.display();

        cout << endl;

        cout << tatra.getName() << " быстрее чем " << kamaz.getName() << "!!!" << endl;
    }
    else {
        kamaz.display();
        tatra.display();

        cout << endl;

        cout << "Их скорости одинаковые!!!" << endl;
    }

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
