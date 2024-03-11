//Задание 1

//#include <iostream>
//
//using namespace std;
//
//class Employee {
//protected:
//    string name;
//    string position;
//    double salary;
//
//public:
//    Employee() {
//        this->name = "";
//        this->position = "";
//        this->salary = 0;
//    }
//
//    Employee(const string& name, const string& position, double salary) {
//        this->name = name;
//        this->position = position;
//        this->salary = salary;
//    }
//
//    double calculateAnnualSalary() {
//        return salary * 12;
//    }
//
//    void displayEmployee() {
//        cout << "Имя: " << name << endl;
//        cout << "Позиция: " << position << endl;
//        cout << "Зарплата: " << salary << endl;
//    }
//};
//
//class Manager : public Employee {
//private:
//    double annual_bonus;
//    string company_car;
//    int stock_options;
//
//public:
//    Manager() : Employee(){
//        this->annual_bonus = 0;
//        this->company_car = "";
//        this->stock_options = 0;
//    }
//
//    Manager(const string& name, const string& position, double salary,
//        double annual_bonus, const string& company_car, int stock_options)
//        : Employee(name, position, salary) {
//        this->annual_bonus = annual_bonus;
//        this->company_car = company_car;
//        this->stock_options = stock_options;
//    }
//
//
//    void displayManager() {
//        displayEmployee();
//        cout << "Ежегодный бонус: " << annual_bonus << endl;
//        cout << "Машина компании: " << company_car << endl;
//        cout << "Опционные акции: " << stock_options << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    Employee emp1("Кудайбердиев Эрлан", "java разработчик", 6000);
//    cout << "Информация о сотруднике:" << endl;
//    emp1.displayEmployee();
//    cout << "Ежегодный бонус: " << emp1.calculateAnnualSalary() << endl;
//
//    cout << endl;
//
//    Manager mgr1("Камиев Абулхаир", "Проект менеджер", 17000, 2000, "BMV x5", 100);
//    cout << "Информация о менеджеров:" << endl;
//    mgr1.displayManager();
//    cout << "Ежегодный бонус: " << mgr1.calculateAnnualSalary() << endl;
//
//    return 0;
//}


//Задание 2

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Display {
//protected:
//    string type;
//    long colors;
//    int x_resolution;
//    int y_resolution;
//
//public:
//    Display(const string& t, long c, int x_res, int y_res) : type(t), colors(c), x_resolution(x_res), y_resolution(y_res) {}
//
//    void ShowInfo() {
//        cout << "Тип дисплея: " << type << endl;
//        cout << "Количество цветов: " << colors << endl;
//        cout << "Разрешение: " << x_resolution << "x" << y_resolution << endl;
//    }
//};
//
//class MotherBoard {
//protected:
//    int processor;
//    int speed;
//    int RAM;
//
//public:
//    MotherBoard(int proc, int spd, int ram) : processor(proc), speed(spd), RAM(ram) {}
//
//    void ShowInfo() {
//        cout << "Тип процессора: " << processor << endl;
//        cout << "Скорость процессора: " << speed << " МГц" << endl;
//        cout << "Объем оперативной памяти: " << RAM << " ГБ" << endl;
//    }
//};
//
//class Computer : public Display, public MotherBoard {
//protected:
//    string name;
//    int hard_disk;
//
//public:
//    Computer(const string& n, int hd, const string& display_type, long display_colors, int display_x_res, int display_y_res, int mb_processor, int mb_speed, int mb_ram)
//        : Display(display_type, display_colors, display_x_res, display_y_res), MotherBoard(mb_processor, mb_speed, mb_ram), name(n), hard_disk(hd) {}
//
//    void Show() {
//        cout << "Название компьютера: " << name << endl;
//        MotherBoard::ShowInfo();
//        Display::ShowInfo();
//        cout << "Жесткий диск: " << hard_disk << " ГБ" << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL,"rus");
//    Computer myComputer("Erlan's laptop", 500, "IPS", 16777216, 1920, 1080, 8, 3600, 16);
//    myComputer.Show();
//    return 0;
//}


//Задание 3

#include <iostream>

using namespace std;

class Employee {
public:
    string name;

private:
    string position;

protected:
    double salary;

public:
    Employee() {
        this->name = "";
        this->position = "";
        this->salary = 0;
    }

    Employee(const string& name, const string& position, double salary) {
        this->name = name;
        this->position = position;
        this->salary = salary;
    }

    double calculateAnnualSalary() {
        return salary * 12;
    }

    void displayEmployee() {
        cout << "Имя: " << name << endl;
        cout << "Позиция: " << position << endl;
        cout << "Зарплата: " << salary << endl;
    }
};

class Manager : private Employee {
private:
    double annual_bonus;
    string company_car;
    int stock_options;

public:
    Employee::displayEmployee;
    Employee::calculateAnnualSalary;


public:
    Manager() : Employee(){
        this->annual_bonus = 0;
        this->company_car = "";
        this->stock_options = 0;
    }

    Manager(const string& name, const string& position, double salary,
        double annual_bonus, const string& company_car, int stock_options)
        : Employee(name, position, salary) {
        this->annual_bonus = annual_bonus;
        this->company_car = company_car;
        this->stock_options = stock_options;
    }


    void displayManager() {
        displayEmployee();
        cout << "Ежегодный бонус: " << annual_bonus << endl;
        cout << "Машина компании: " << company_car << endl;
        cout << "Опционные акции: " << stock_options << endl;
    }
};


int main() {
    setlocale(LC_ALL, "rus");
    Employee emp1("Кудайбердиев Эрлан", "java разработчик", 6000);
    cout << "Информация о сотруднике:" << endl;
    emp1.displayEmployee();
    cout << "Ежегодный бонус: " << emp1.calculateAnnualSalary() << endl;

    cout << endl;

    Manager mgr1("Камиев Абулхаир", "Проект менеджер", 17000, 2000, "BMV x5", 100);
    cout << "Информация о менеджеров:" << endl;
    mgr1.displayManager();
    cout << "Ежегодный бонус: " << mgr1.calculateAnnualSalary() << endl;

    return 0;
}


