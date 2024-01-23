// OOP_lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Задания 1 

//#include <iostream>
//using namespace std;
//
//double power(double n, int p);
//
//void main()
//{
//	setlocale(LC_ALL,("rus"));
//	double n, result, chek = 0;
//	int p = 2;
//	cout << "Введите основание числа: ";
//	cin >> n;
//	cout << "\nБудете ли вводить степень числа?. \nЕсли да введите число 1, в противном случае введи число 0: ";
//	cin >> chek;
//	if (chek == 1) {
//		cout << "\nВведите степень числа (больше 2): ";
//		cin >> p;
//		if (p < 2) {
//			cout << "\nВы ввели степень числа меньшее 2!!! \nПоэтому степень числа по умалчанию стало равно 2.";
//			p = 2;
//		}
//	}
//	result = power(n, p);
//	cout << "\nРезультат: " << result << endl;
//}
//
//double power(double n, int p) {
//	double result = 0;
//	result = 1.0;
//	for (int i = 0; i < p; ++i) {
//		result *= n;
//	}
//	return result;
//}


//Задание 2

//#include <iostream>
//using namespace std;
//
//double power(char n, int p) {
//    double result = 1.0;
//    for (int i = 0; i < p; ++i) {
//        result *= static_cast<double>(n);
//    }
//    return result;
//}
//
//double power(short int n, int p) {
//    double result = 1.0;
//    for (int i = 0; i < p; ++i) {
//        result *= static_cast<double>(n);
//    }
//    return result;
//}
//
//double power(long int n, int p) {
//    double result = 1.0;
//    for (int i = 0; i < p; ++i) {
//        result *= static_cast<double>(n);
//    }
//    return result;
//}
//
//double power(float n, int p) {
//    double result = 1.0;
//    for (int i = 0; i < p; ++i) {
//        result *= static_cast<double>(n);
//    }
//    return result;
//}
//
//void main() {
//    setlocale(LC_ALL, ("rus"));
//    cout << "Пример 1: power('G', 3) = " << power('G', 3) << endl;
//    cout << "Пример 2: power(8, 11) =  " << power(static_cast<float>(8), 11) << endl;
//    cout << "Пример 3: power(7521L, 2) = " << power(7521L, 2) << endl;
//    cout << "Пример 4: power(65.38f, 7) = " << power(65.38f, 7) << endl;
//}

//Задание 3

//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct Worker {
//    string lastName;
//    int age;
//    string specialty;
//    double averageSalary;
//};
//
//void processFactories(vector<vector<Worker>>& factories, int& totalLocksmiths, int& totalTurners) {
//    int numFactories;
//    cout << "Введите количество заводов: ";
//    cin >> numFactories;
//    totalLocksmiths = 0;
//    totalTurners = 0;
//
//    for (int i = 0; i < numFactories; ++i) {
//        int numWorkers;
//
//        cout << "Введите количество работников на заводе " << i + 1 << ": ";
//        cin >> numWorkers;
//
//        vector<Worker> workers;
//
//        for (int j = 0; j < numWorkers; ++j) {
//            Worker worker;
//
//            cout << "Введите фамилию работника " << j + 1 << ": ";
//            cin >> worker.lastName;
//
//            cout << "Введите возраст работника " << j + 1 << ": ";
//            cin >> worker.age;
//
//            cout << "Введите специальность работника " << j + 1 << ": ";
//            cin >> worker.specialty;
//
//            cout << "Введите средний оклад работника " << j + 1 << ": ";
//            cin >> worker.averageSalary;
//
//            if (worker.specialty == "слесарь") {
//                totalLocksmiths++;
//            }
//            else if (worker.specialty == "токарь") {
//                totalTurners++;
//            }
//
//            workers.push_back(worker);
//        }
//        factories.push_back(workers);
//    }
//}
//
//void main() {
//    setlocale(LC_ALL, "rus");
//    vector<vector<Worker>> factories;
//    int totalLocksmiths, totalTurners;
//    processFactories(factories, totalLocksmiths, totalTurners);
//    cout << "Общее количество слесарей: " << totalLocksmiths << endl;
//    cout << "Общее количество токарей: " << totalTurners << endl;
//
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
