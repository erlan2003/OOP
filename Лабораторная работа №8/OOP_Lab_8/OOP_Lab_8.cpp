// OOP_Lab_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Задание 1

//#include <iostream>
//using namespace std;
//
//template<typename T>
//T findMax(const T arr[], int size) {
//    T max = arr[0];
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//    return max;
//}
//
//template<typename T>
//void bubbleSort(T arr[], int size) {
//    cout << "\n";
//    cout << "Отсортированный массив:" << endl;
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                T temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//template<typename T>
//void display(const T arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    const int n = 10;
//    int Array1[n] = { 3, 1, 4, 1, 5, 9, 2, 6, 11, 2 };
//    display(Array1, n);
//    cout << "Максимальный элемент в Массиве Array1: " << findMax(Array1, n) << endl;
//    bubbleSort(Array1, n);
//    display(Array1, n);
//    
//    cout << "\n----------------------------------------------------------------------------------------------" << endl;
//
//    float Array2[] = { 3.14, 1.23, 4.56, 1.67, 5.89, 2.22, 6.66, 1,05, 5,98, 3,22 };
//    display(Array2, n);
//    cout << "Максимальный элемент в Массиве Array2: " << findMax(Array2, n) << endl;
//    bubbleSort(Array2, n);
//    display(Array2, n);
//    return 0;
//}



//Задание 2

//#include <iostream>
//#include <cstdlib> 
//#include <ctime>   
//using namespace std;
//
//template<typename T, int Size>
//class ArraySum {
//private:
//    T array1[Size];
//    T array2[Size];
//
//public:
//    ArraySum() {
//        srand(time(nullptr));
//
//        
//        for (int i = 0; i < Size; ++i) {
//            array1[i] = static_cast<T>(rand() % 100); 
//            array2[i] = static_cast<T>(rand() % 100);
//        }
//    }
//
//    T sum() {
//        T totalSum = 0;
//        for (int i = 0; i < Size; ++i) {
//            totalSum += array1[i] + array2[i];
//        }
//        return totalSum;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
// 
//    ArraySum<int, 5> intArraySum;
//    cout << "Сумма int: " << intArraySum.sum() << endl;
//
//    ArraySum<double, 3> doubleArraySum;
//    cout << "Сумма doubles: " << doubleArraySum.sum() << endl;
//
//    return 0;
//}

//Задание 3

//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//struct Employee {
//    string Name;
//    int age;
//    string specialty;
//    double averageSalary;
//};
//
//template <typename T>
//class Stack {
//private:
//    stack<T> data;
//public:
//    void push(const T& item) {
//        data.push(item);
//    }
//
//    template <typename U>
//    U maxElement(U arr[], int size) {
//        U max = arr[0];
//        for (int i = 1; i < size; ++i) {
//            if (arr[i] > max) {
//                max = arr[i];
//            }
//        }
//        return max;
//    }
//
//    T pop() {
//        T top = data.top();
//        data.pop();
//        return top;
//    }
//
//    bool isEmpty() const {
//        return data.empty();
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    Stack<Employee> workersStack;
//
//    workersStack.push({ "Смит", 35, "токарь", 2500 });
//    workersStack.push({ "Джонсон", 28, "токарь", 2200 });
//    workersStack.push({ "Уильямс", 40, "слесарь", 2800 });
//    workersStack.push({ "Браун", 32, "слесарь", 2600 });
//    workersStack.push({ "Эрлан", 35, "токарь", 2500 });
//
//   /* double doubleArr[] = { 3.5, 1.2, 6.7, 2.9, 8.1 };
//
//    cout << "Максимальный элемент массива doubleArr: " << workersStack.maxElement(doubleArr, 5) << endl;*/
//
//    int locksmithsCount = 0;
//    int turnersCount = 0;
//
//    Stack<Employee> tempStack;
//
//    while (!workersStack.isEmpty()) {
//        Employee worker = workersStack.pop();
//        tempStack.push(worker);
//
//        if (worker.specialty == "слесарь") {
//            locksmithsCount++;
//        }
//        else if (worker.specialty == "токарь") {
//            turnersCount++;
//        }
//    }
//
//    cout << "Количество слесарей: " << locksmithsCount << endl;
//    cout << "Количество токарей: " << turnersCount << endl;
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
