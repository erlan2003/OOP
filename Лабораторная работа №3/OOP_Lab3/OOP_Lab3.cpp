// OOP_Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Задание 1

//#include <iostream>
//#include <ctime>
//#include <string>
//
//#define CLK_TCK CLOCKS_PER_SEC
//
//using namespace std;
//
//class Timer {
//public:
//    int seconds;
//
//public:
//    Timer(int sec) {
//        seconds = sec;
//    }
//
//    Timer(int min, int sec) {
//        seconds = min * 60 + sec;
//    }
//
//    Timer(string time) {
//        int delimiterPos = time.find(':');
//        int min = stoi(time.substr(0, delimiterPos));
//        int sec = stoi(time.substr(delimiterPos + 1));
//        seconds = min * 60 + sec;
//    }
//
//    void run() {
//        cout << "Начинается обратный отсчет таймера!" << endl;
//
//        while (seconds > 0) {
//            cout << seconds << " с" << endl;
//            seconds--;
//            clock_t start_time = clock();
//            while (clock() < start_time + CLK_TCK);
//        }
//
//        cout << "Время вышло!!!!!!!" << endl;
//    }
//};
//
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    int seconds, min;
//    string time;
//
//    short n;
//    cout << "Выберите действие: \n 1) Ввести начальное значения таймера в секундах \n 2) Ввести начальное значения таймера в минутах и секундах \n 3) Ввести начальное значения таймера в виде строки(0:20) ";
//    cout << "\nДействие: ";
//    cin >> n;
//    if (n == 1) {
//        cout << "\nВведите начальное значения таймера в секундах: ";
//        cin >> seconds;
//        Timer timer1(seconds);
//        timer1.run();
//    }
//    else if (n == 2) {
//        cout << "\nВведите начальное значения таймера в минутах и секундах: ";
//        cout << "\nВведите минуту: "; 
//        cin >> min;
//
//        cout << "\nВведите секунду: ";
//        cin >> seconds;
//        
//        Timer timer2(min, seconds);
//        timer2.run();
//    }
//    else if (n == 3) {
//        cout << "\nВведите начальное значения таймера в виде строки(0:20): ";
//        cin >> time;
//        Timer timer3(time);
//        timer3.run();
//    }
//    else { cout << "Такого действия нет!!!"; }
//    return 0;
//}


//Задание 2

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Nomenclature {
//private:
//    string itemName;
//    double wholesalePrice;
//    double retailMarkup;
//    int quantity;
//
//public:
//    Nomenclature(string name, double wholesale, double markup, int qty) :
//        itemName(name), wholesalePrice(wholesale), retailMarkup(markup), quantity(qty) {}
//
//    ~Nomenclature() {
//        cout << "\nТовар '" << itemName << "' был удален!!!" << endl;
//    }
//
//    double calculateProfit() {
//        return quantity * (retailMarkup * wholesalePrice);
//    }
//
//    void display() {
//        cout << "\nНазвания товара: " << itemName << endl;
//        cout << "Оптовая цена: " << wholesalePrice <<" сом" << endl;
//        cout << "Розничная наценка: " << (retailMarkup * 100) << "%" << endl;
//        cout << "Количество товаров на складе: " << quantity << endl;
//        cout << "Чистый доход: " << calculateProfit() << " сом" << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    Nomenclature item1("Холодильник", 800, 0.2, 10);
//    item1.display();
//
//    Nomenclature item2("Кровать", 489, 0.4, 7);
//    item2.display();
//
//    return 0;
//}
 
//Задание 3

//#include <iostream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
//class Soft {
//private:
//    string name;
//    string developer;
//    float size;
//    time_t licenseExpirationDate;
//
//public:
//    Soft(const string& name, const string& developer, float size, time_t expirationDate)
//        : name(name), developer(developer), size(size), licenseExpirationDate(expirationDate) {}
//
//    ~Soft() {
//        cout << "\nПрограммное обеспечение '" << name << "' был удален!!!" << endl;
//    }
//
//    int daysUntilExpiration() const {
//        time_t currentTime;
//        time(&currentTime);
//        double secondsLeft = difftime(licenseExpirationDate, currentTime);
//        return static_cast<int>(secondsLeft / (60 * 60 * 24));
//    }
//
//    void displayInfo() const {
//        cout << "Название программы: " << name << endl;
//        cout << "Разработчик: " << developer << endl;
//        cout << "Занимаемый объем: " << size << " МБ" << endl;
//        cout << "Дней до окончания лицензии: " << daysUntilExpiration() << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    time_t expirationDate = time(nullptr) + 30 * 24 * 60 * 60;
//    Soft software("Paint", "Эрлан", 10.5, expirationDate);
//
//    software.displayInfo();
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
