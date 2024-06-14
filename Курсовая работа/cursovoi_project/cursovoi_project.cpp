#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

const int MAX_USERS = 100;
const int MAX_ATTRACTIONS = 100;
const int MAX_TOURS = 100;
const int MAX_REVIEWS = 100;
const int MAX_BOOKINGS = 100;

class AttractionType {
private:
    string typeName;
public:
    AttractionType() : typeName("") {}

    AttractionType(const string& typeName) : typeName(typeName) {}

    string getTypeName() const {
        return typeName;
    }

    void viewAttractionType() const {
        cout << "Тип достопримечательности: " << typeName << endl;
    }

    void setTypeName(const string& name) {
        typeName = name;
    }
};

class Attraction {
private:
    string name;
    string location;
    string description;
    AttractionType type;
public:
    Attraction() : name(""), location(""), description(""), type("") {}

    Attraction(const string& name, const string& location, const string& description, const AttractionType& type)
        : name(name), location(location), description(description), type(type) {}

    void viewAttraction() const {
        cout << "Достопримечательность - Название: " << name << ", Местоположение: " << location
            << ", Описание: " << description << ", Тип: " << type.getTypeName() << endl;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setLocation(const string& location) {
        this->location = location;
    }

    void setDescription(const string& description) {
        this->description = description;
    }

    void setType(const AttractionType& type) {
        this->type = type;
    }

    string getName() const {
        return name;
    }

    string getLocation() const {
        return location;
    }

    string getDescription() const {
        return description;
    }

    AttractionType getType() const {
        return type;
    }
};

class User {
protected:
    int id;
    string name;
    string email;
    string password;
    bool isAdmin;
    static int userCount;
public:
    User() : id(-1) {
        ++userCount;
    }

    User(int id, const string& name, const string& email, const string& password, const bool& a)
        : id(id), name(name), email(email), password(password), isAdmin(a) {
        ++userCount;
    }

    void registerUser() {
    }

    void login() {
        cout << "\nВы успешно вошли в систему: " << name << endl << endl;
    }

    virtual void viewProfile() const {
        cout << "Профиль пользователя - Имя: " << name << ", Электронная почта: " << email << endl;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPassword() const { return password; }
    bool getIsAdmin() const { return isAdmin; }

    void setId(int id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    void setEmail(const string& email) { this->email = email; }
    void setPassword(const string& password) { this->password = password; }
    void setIsAdmin(const bool& a) { this->isAdmin = a; }

    ~User() {
        --userCount;
    }
};


class Customer : public User {
public:
    Customer() : User() {}

    Customer(int id, const string& name, const string& email, const string& password, const bool& a)
        : User(id, name, email, password, a) {}

    void viewProfile() const override {
        cout << "Профиль клиента - Имя: " << name << ", Электронная почта: " << email << endl;
    }
};

class Admin : public User {
public:
    Admin() : User() {}

    Admin(int id, const string& name, const string& email, const string& password, const bool& a)
        : User(id, name, email, password, a) {}

    void viewProfile() const override {
        cout << "Профиль администратора - Имя: " << name << ", Электронная почта: " << email << endl;
    }
};

class UserManager {
private:
    User users[MAX_USERS];
    int userCount;
    int nextId;

    void saveUsersToFile() {
        ofstream file("users.txt");
        if (file.is_open()) {
            for (int i = 0; i < userCount; ++i) {
                file << users[i].getId() << "|"
                    << users[i].getName() << "|"
                    << users[i].getEmail() << "|"
                    << users[i].getPassword() << "|"
                    << users[i].getIsAdmin() << endl;
            }
            file.close();
        }
    }

    void loadUsersFromFile() {
        ifstream file("users.txt");
        if (file.is_open()) {
            userCount = 0;
            string line;
            while (getline(file, line)) {
                int id;
                string name, email, password;
                bool isAdmin;

                size_t pos = 0;
                string token;
                vector<string> tokens;

                while ((pos = line.find('|')) != string::npos) {
                    token = line.substr(0, pos);
                    tokens.push_back(token);
                    line.erase(0, pos + 1);
                }
                tokens.push_back(line);

                if (tokens.size() == 5) {
                    id = stoi(tokens[0]);
                    name = tokens[1];
                    email = tokens[2];
                    password = tokens[3];
                    isAdmin = (tokens[4] == "1");

                    users[userCount].setId(id);
                    users[userCount].setName(name);
                    users[userCount].setEmail(email);
                    users[userCount].setPassword(password);
                    users[userCount].setIsAdmin(isAdmin);
                    userCount++;
                    nextId = id + 1;
                }
            }
            file.close();
        }
    }

public:
    UserManager() : userCount(0), nextId(1) {
        loadUsersFromFile();
    }

    template <typename T, typename Func>
    int findElementIndex(const T* array, int count, Func criterion) {
        for (int i = 0; i < count; ++i) {
            if (criterion(array[i])) {
                return i;
            }
        }
        return -1;
    }

    bool registerUser(const string& name, const string& email, const string& password, bool isAdmin) {
        if (userCount >= MAX_USERS) {
            cout << "Достигнуто максимальное количество пользователей." << endl;
            return false;
        }

        for (int i = 0; i < userCount; ++i) {
            if (users[i].getEmail() == email) {
                cout << "Пользователь с таким email уже существует." << endl;
                return false;
            }
        }

        int newId = nextId++;
        if (isAdmin) {
            Admin admin(newId, name, email, password, isAdmin);
            admin.registerUser();
            users[userCount++] = admin;
        }
        else {
            Customer customer(newId, name, email, password, isAdmin);
            customer.registerUser();
            users[userCount++] = customer;
        }

        saveUsersToFile();
        return true;
    }

    void registerUserFromInput() {
        string name, email, password;
        bool isAdmin;

        cout << "Введите имя пользователя: ";
        cin >> name;

        cout << "Введите адрес электронной почты: ";
        cin >> email;

        cout << "Введите пароль: ";
        cin >> password;

        cout << "Является ли пользователь администратором? (1/0): ";
        cin >> isAdmin;
        cin.ignore();

        registerUser(name, email, password, isAdmin);
        cout << "\nРегистрация прошла успешно!!!\n";
        cout << endl;
    }

    bool loginUser(const string& email, const string& password) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].getEmail() == email && users[i].getPassword() == password) {
                users[i].login();
                return true;
            }
        }
        return false;
    }

    int checkAdmin(const string& email, const string& password) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].getEmail() == email && users[i].getPassword() == password) {
                return users[i].getIsAdmin();
            }
        }
    }

    void viewAllUsers() const {
        for (int i = 0; i < userCount; ++i) {
            users[i].viewProfile();
        }
    }
};

class Tour {
private:
    string name;
    string destination;
    string description;
    float price;
    vector<Attraction> attractions;
public:
    Tour() : name(""), destination(""), description(""), price(0.0) {}

    Tour(const string& name, const string& destination, const string& description, float price, const vector<Attraction>& attractions = {})
        : name(name), destination(destination), description(description), price(price), attractions(attractions) {}

    void viewTour() const {
        cout << "Тур - Название: " << name << ", Место: " << destination
            << ", Описание: " << description << ", Цена: " << price << " рублей" << endl;
        cout << "Достопримечательности:\n";
        for (const auto& attraction : attractions) {
            attraction.viewAttraction();
        }
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setDestination(const string& destination) {
        this->destination = destination;
    }

    void setDescription(const string& description) {
        this->description = description;
    }

    void setPrice(float price) {
        this->price = price;
    }

    void setAttractions(const vector<Attraction>& attractions) {
        this->attractions = attractions;
    }

    string getName() const {
        return name;
    }

    string getDestination() const {
        return destination;
    }

    string getDescription() const {
        return description;
    }

    float getPrice() const {
        return price;
    }

    vector<Attraction> getAttractions() const {
        return attractions;
    }
};

class TourManager {
private:
    Tour tours[MAX_TOURS];
    int tourCount;

    void saveToursToFile() {
        ofstream file("tours.txt");
        if (file.is_open()) {
            for (int i = 0; i < tourCount; ++i) {
                file << tours[i].getName() << "|"
                    << tours[i].getDestination() << "|"
                    << tours[i].getDescription() << "|"
                    << tours[i].getPrice() << endl;
            }
            file.close();
        }
    }

    void loadToursFromFile() {
        ifstream file("tours.txt");
        if (file.is_open()) {
            tourCount = 0;
            string line;
            while (getline(file, line)) {
                string name, destination, description;
                float price;

                size_t pos = 0;
                string token;
                vector<string> tokens;

                while ((pos = line.find('|')) != string::npos) {
                    token = line.substr(0, pos);
                    tokens.push_back(token);
                    line.erase(0, pos + 1);
                }
                tokens.push_back(line);

                if (tokens.size() == 4) {
                    name = tokens[0];
                    destination = tokens[1];
                    description = tokens[2];
                    price = stof(tokens[3]);

                    tours[tourCount].setName(name);
                    tours[tourCount].setDestination(destination);
                    tours[tourCount].setDescription(description);
                    tours[tourCount].setPrice(price);
                    tourCount++;
                }
            }
            file.close();
        }
    }

public:
    TourManager() : tourCount(0) {
        loadToursFromFile();
    }

    bool addTour(const string& name, const string& destination, const string& description, float price, const vector<Attraction>& attractions) {
        if (tourCount >= MAX_TOURS) {
            cout << "Достигнуто максимальное количество туров." << endl;
            return false;
        }

        tours[tourCount++] = Tour(name, destination, description, price, attractions);
        saveToursToFile();
        return true;
    }

    void addTourFromInput(const vector<Attraction>& availableAttractions) {
        string name, destination, description;
        float price;
        int attractionCount;

        cout << "Введите название тура: ";
        cin >> name;

        cout << "Введите место назначения тура: ";
        cin >> destination;

        cout << "Введите описание тура: ";
        cin >> description;

        cout << "Введите цену тура: ";
        cin >> price;

        cout << "Введите количество достопримечательностей для тура: ";
        cin >> attractionCount;

        vector<Attraction> selectedAttractions;
        for (int i = 0; i < attractionCount; ++i) {
            int index;
            cout << "Введите номер достопримечательности (1-" << availableAttractions.size() << "): ";
            cin >> index;
            if (index > 0 && index <= availableAttractions.size()) {
                selectedAttractions.push_back(availableAttractions[index - 1]);
            }
            else {
                cout << "Некорректный номер достопримечательности." << endl;
            }
        }

        addTour(name, destination, description, price, selectedAttractions);
        cout << "\nТур успешно добавлен!\n";
    }

    void viewAllTours() const {
        for (int i = 0; i < tourCount; ++i) {
            tours[i].viewTour();
        }
    }

    bool deleteTour(int index) {
        if (index < 0 || index >= tourCount) {
            cout << "Некорректный индекс тура." << endl;
            return false;
        }

        for (int i = index; i < tourCount - 1; ++i) {
            tours[i] = tours[i + 1];
        }

        tourCount--;
        saveToursToFile();
        cout << "Тур успешно удален." << endl;
        return true;
    }

    void searchTour(const string& query) const {
        bool found = false;
        for (int i = 0; i < tourCount; ++i) {
            if (tours[i].getName().find(query) != string::npos ||
                tours[i].getDestination().find(query) != string::npos ||
                tours[i].getDescription().find(query) != string::npos) {
                tours[i].viewTour();
                found = true;
            }
            else {
                for (const auto& attraction : tours[i].getAttractions()) {
                    if (attraction.getName().find(query) != string::npos ||
                        attraction.getDescription().find(query) != string::npos) {
                        tours[i].viewTour();
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found) {
            cout << "Туры не найдены.\n";
        }
    }

};

class MaxAttractionsException : public std::runtime_error {
public:
    MaxAttractionsException() : std::runtime_error("Достигнуто максимальное количество достопримечательностей.") {}
};

class AttractionManager {
private:
    Attraction attractions[MAX_ATTRACTIONS];
    int attractionCount;

    void saveAttractionsToFile() {
        ofstream file("attractions.txt");
        if (file.is_open()) {
            for (int i = 0; i < attractionCount; ++i) {
                file << attractions[i].getName() << "|"
                    << attractions[i].getLocation() << "|"
                    << attractions[i].getDescription() << "|"
                    << attractions[i].getType().getTypeName() << endl;
            }
            file.close();
        }
    }

    void loadAttractionsFromFile() {
        ifstream file("attractions.txt");
        if (file.is_open()) {
            attractionCount = 0;
            string line;
            while (getline(file, line)) {
                string name, location, description, typeName;

                size_t pos = 0;
                string token;
                vector<string> tokens;

                while ((pos = line.find('|')) != string::npos) {
                    token = line.substr(0, pos);
                    tokens.push_back(token);
                    line.erase(0, pos + 1);
                }
                tokens.push_back(line);

                if (tokens.size() == 4) {
                    name = tokens[0];
                    location = tokens[1];
                    description = tokens[2];
                    typeName = tokens[3];

                    attractions[attractionCount].setName(name);
                    attractions[attractionCount].setLocation(location);
                    attractions[attractionCount].setDescription(description);
                    attractions[attractionCount].setType(AttractionType(typeName));
                    attractionCount++;
                }
            }
            file.close();
        }
    }

public:
    AttractionManager() : attractionCount(0) {
        loadAttractionsFromFile();
    }

    bool addAttraction(const std::string& name, const std::string& location, const std::string& description, const AttractionType& type) {
        if (attractionCount >= MAX_ATTRACTIONS) {
            throw MaxAttractionsException();
        }

        attractions[attractionCount++] = Attraction(name, location, description, type);
        saveAttractionsToFile();
        return true;
    }

    void addAttractionFromInput() {
        string name, location, description, typeName;

        cout << "Введите название достопримечательности: ";
        cin >> name;

        cout << "Введите местоположение достопримечательности: ";
        cin >> location;

        cout << "Введите описание достопримечательности: ";
        cin >> description;

        cout << "Введите тип достопримечательности: ";
        cin >> typeName;

        addAttraction(name, location, description, AttractionType(typeName));
        cout << "\nДостопримечательность успешно добавлена!\n";
    }

    void viewAllAttractions() const {
        for (int i = 0; i < attractionCount; ++i) {
            attractions[i].viewAttraction();
        }
    }

    vector<Attraction> getAllAttractions() const {
        return vector<Attraction>(attractions, attractions + attractionCount);
    }
 
    void searchAttraction(const string& query) const {
        bool found = false;
        for (int i = 0; i < attractionCount; ++i) {
            if (attractions[i].getName() == query ||
                attractions[i].getLocation() == query ||
                attractions[i].getDescription() == query ||
                attractions[i].getType().getTypeName() == query) {
                attractions[i].viewAttraction();
                found = true;
            }
        }
        if (!found) {
            cout << "Достопримечательность не найдена.\n" << endl;
        }
    }

    void deleteAttraction(int index) {
        if (index < 0 || index >= attractionCount) {
            cout << "\nНеверный индекс достопримечательности!!!\n" << endl;
            return;
        }
        for (int i = index; i < attractionCount - 1; ++i) {
            attractions[i] = attractions[i + 1];
        }
        attractionCount--;
        cout << "\nДостопримечательность успешно удалена!!!\n" << endl;
        saveAttractionsToFile();
    }

    void deleteAttraction(const string& name) {
        int index = -1;
        for (int i = 0; i < attractionCount; ++i) {
            if (attractions[i].getName() == name) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            std::cout << "\nДостопримечательность с указанным названием не найдена!!!\n" << std::endl;
            return;
        }

        deleteAttraction(index);
    }

    void editAttraction() {
        viewAllAttractions();
        int index;
        cout << "Введите индекс достопримечательности для редактирования: ";
        cin >> index;
        index = index - 1;

        if (index < 0 || index >= attractionCount) {
            cout << "Неверный индекс достопримечательности.\n";
            return;
        }

        cout << "\t 1. Редактировать название\n\t 2. Редактировать местоположение\n\t 3. Редактировать описание\n\t 4. Редактировать тип\n";
        cout << "Что вы хотите редактировать: ";
        short l;
        cin >> l;

        string name, location, description;
        int typeIndex;
        AttractionType selectedType;

        switch (l) {
        case 1:
            cout << "Введите новое название достопримечательности: ";
            cin.ignore();
            getline(cin, name);
            attractions[index].setName(name);
            break;
        case 2:
            cout << "Введите новое местоположение достопримечательности: ";
            cin.ignore();
            getline(cin, location);
            attractions[index].setLocation(location);
            break;
        case 3:
            cout << "Введите новое описание достопримечательности: ";
            cin.ignore();
            getline(cin, description);
            attractions[index].setDescription(description);
            break;
        case 4:
            cout << "Выберите новый тип достопримечательности:\n";
            cout << "1) Historical\n2) Cultural\n3) Natural\n4) Entertainment\n5) Religious\n6) Architectural\n7) Museum\n";
            cout << "Введите номер типа: ";
            cin >> typeIndex;

            switch (typeIndex) {
            case 1:
                selectedType = AttractionType("Historical");
                break;
            case 2:
                selectedType = AttractionType("Cultural");
                break;
            case 3:
                selectedType = AttractionType("Natural");
                break;
            case 4:
                selectedType = AttractionType("Entertainment");
                break;
            case 5:
                selectedType = AttractionType("Religious");
                break;
            case 6:
                selectedType = AttractionType("Architectural");
                break;
            case 7:
                selectedType = AttractionType("Museum");
                break;
            default:
                cout << "Неверный тип. Используется тип по умолчанию.\n";
                selectedType = AttractionType("Неизвестный");
                break;
            }

            attractions[index].setType(selectedType);
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }

        cout << "Достопримечательность успешно обновлена.\n";
        saveAttractionsToFile();
    }
};

class Review {
private:
    int rating;
    string comment;
    string customerEmail;
public:
    Review() : rating(0), comment(""), customerEmail("") {}

    Review(int rating, const string& comment, const string& customerEmail)
        : rating(rating), comment(comment), customerEmail(customerEmail) {}

    void viewReview() const {
        cout << "Отзыв - Оценка: " << rating << ", Комментарий: " << comment << ", Электронная почта клиента: " << customerEmail << endl;
    }

    void setRating(int rating) {
        this->rating = rating;
    }

    void setComment(const string& comment) {
        this->comment = comment;
    }

    void setCustomerEmail(const string& customerEmail) {
        this->customerEmail = customerEmail;
    }

    int getRating() const {
        return rating;
    }

    string getComment() const {
        return comment;
    }

    string getCustomerEmail() const {
        return customerEmail;
    }
};

class ReviewManager {
private:
    Review reviews[MAX_REVIEWS];
    int reviewCount;

    void saveReviewsToFile() {
        ofstream file("reviews.txt");
        if (file.is_open()) {
            for (int i = 0; i < reviewCount; ++i) {
                file << reviews[i].getRating() << " | "
                    << reviews[i].getComment() << " | "
                    << reviews[i].getCustomerEmail() << endl;
            }
            file.close();
        }
    }

    void loadReviewsFromFile() {
        ifstream file("reviews.txt");
        if (file.is_open()) {
            reviewCount = 0;
            string line;
            while (getline(file, line)) {
                int rating;
                string comment, customerEmail;

                size_t pos = 0;
                string token;
                vector<string> tokens;

                while ((pos = line.find('|')) != string::npos) {
                    token = line.substr(0, pos);
                    tokens.push_back(token);
                    line.erase(0, pos + 1);
                }
                tokens.push_back(line);

                if (tokens.size() == 3) {
                    rating = stoi(tokens[0]);
                    comment = tokens[1];
                    customerEmail = tokens[2];

                    reviews[reviewCount].setRating(rating);
                    reviews[reviewCount].setComment(comment);
                    reviews[reviewCount].setCustomerEmail(customerEmail);
                    reviewCount++;
                }
            }
            file.close();
        }
    }

public:
    ReviewManager() : reviewCount(0) {
        loadReviewsFromFile();
    }

    bool addReview(int rating, const string& comment, const string& customerEmail) {
        if (reviewCount >= MAX_REVIEWS) {
            cout << "Достигнуто максимальное количество отзывов." << endl;
            return false;
        }

        reviews[reviewCount++] = Review(rating, comment, customerEmail);
        saveReviewsToFile();
        return true;
    }

    void addReviewFromInput() {
        int rating;
        string comment, customerEmail;

        cout << "Введите рейтинг (от 1 до 5): ";
        cin >> rating;

        cout << "Введите комментарий: ";
        cin >> comment;

        cout << "Введите электронную почту клиента: ";
        cin >> customerEmail;

        addReview(rating, comment, customerEmail);
        cout << "\nОтзыв успешно добавлен!\n";
    }

    void viewAllReviews() const {
        for (int i = 0; i < reviewCount; ++i) {
            reviews[i].viewReview();
        }
    }
};

class Booking {
private:
    string tourName;
    string customerEmail;
public:
    Booking() : tourName(""), customerEmail("") {}

    Booking(const string& tourName, const string& customerEmail)
        : tourName(tourName), customerEmail(customerEmail) {}

    void viewBooking() const {
        cout << "Бронирование - Название тура: " << tourName << ", Электронная почта клиента: " << customerEmail << endl;
    }

    void setTourName(const string& tourName) {
        this->tourName = tourName;
    }

    void setCustomerEmail(const string& customerEmail) {
        this->customerEmail = customerEmail;
    }

    string getTourName() const {
        return tourName;
    }

    string getCustomerEmail() const {
        return customerEmail;
    }
};

class BookingManager {
private:
    Booking bookings[MAX_BOOKINGS];
    int bookingCount;

    void saveBookingsToFile() {
        ofstream file("bookings.txt");
        if (file.is_open()) {
            for (int i = 0; i < bookingCount; ++i) {
                file << bookings[i].getTourName() << "|"
                    << bookings[i].getCustomerEmail() << endl;
            }
            file.close();
        }
    }

    void loadBookingsFromFile() {
        ifstream file("bookings.txt");
        if (file.is_open()) {
            bookingCount = 0;
            string line;
            while (getline(file, line)) {
                string tourName, customerEmail;

                size_t pos = 0;
                string token;
                vector<string> tokens;

                while ((pos = line.find('|')) != string::npos) {
                    token = line.substr(0, pos);
                    tokens.push_back(token);
                    line.erase(0, pos + 1);
                }
                tokens.push_back(line);

                if (tokens.size() == 2) {
                    tourName = tokens[0];
                    customerEmail = tokens[1];

                    bookings[bookingCount].setTourName(tourName);
                    bookings[bookingCount].setCustomerEmail(customerEmail);
                    bookingCount++;
                }
            }
            file.close();
        }
    }

public:
    BookingManager() : bookingCount(0) {
        loadBookingsFromFile();
    }

    bool addBooking(const string& tourName, const string& customerEmail) {
        if (bookingCount >= MAX_BOOKINGS) {
            cout << "Достигнуто максимальное количество бронирований." << endl;
            return false;
        }

        bookings[bookingCount++] = Booking(tourName, customerEmail);
        saveBookingsToFile();
        return true;
    }

    void addBookingFromInput() {
        string tourName, customerEmail;

        cout << "Введите название тура: ";
        cin >> tourName;

        cout << "Введите электронную почту клиента: ";
        cin >> customerEmail;

        addBooking(tourName, customerEmail);
        cout << "\nБронирование успешно добавлено!\n";
    }

    void viewAllBookings() const {
        for (int i = 0; i < bookingCount; ++i) {
            bookings[i].viewBooking();
        }
    }
};

int User::userCount = 0;

int main() {
    setlocale(LC_ALL, "rus");
    UserManager userManager;
    TourManager tourManager;
    BookingManager bookingManager;
    ReviewManager reviewManager;
    AttractionManager attractionManager;
    vector<Attraction> attractions;

    string email, password;
    string name, destination, description;
    float price;
    int numAttractions;
    int index2;
    string a;

    int n;
    do {
        cout << "Добро пожаловать в TravelExplore!!!\nЧтобы войти в систему пожалуйста авторизуйтесь!!!"<<endl<<endl;
        cout << "Операции:\n\t1) Регистрация \n\t2) Авторизация\n";
        cout << "\nВведите номер операции: ";
        cin >> n;

        switch (n) {
        case 1:
            system("cls");
            cout << "\nВы выбрали операцию 1 (регистрация)\n" << endl;
            userManager.registerUserFromInput();
            break;
        case 2:
            system("cls");
            cout << "\nВы выбрали операцию 2 (авторизация)\n" << endl;
            cout << "Введите адрес электронной почты: ";
            cin >> email;
            cout << "Введите пароль: ";
            cin >> password;
            if (userManager.loginUser(email, password)) {
                if (userManager.checkAdmin(email, password) == 1) {
                    int t;
                    cout << "Операции которые доступны для вас (Администратор):\n\t1) Добавление достопримечательности \n\t2) Удаление достопримечательности \n\t3) Редактирование достопримечательности \n\t4) Вывод всех достопримечательностей\n";
                    cout << "\t5) Просмотр всех пользователей \n\t6) Добавление тура \n\t7) Удаление тура\n\t8) Просмотр всех туров\n\t9) Бронирование тура" << endl;
                    cout << "\t11) Оставить отзыв\n\t12) Просмотр отзывов\n\t13) Поиск достопримечательности по произвольному шаблону" << endl;
                    cout << "\t14) Поиск туров по произвольному шаблону\n\t15) Выход"<<endl;
                    cout << endl;

                    do {
                        cout << "Введите номер операции: ";
                        cin >> t;

                        string name, location, description;
                        int typeIndex;
                        AttractionType selectedType;

                        AttractionType historical("Historical");
                        AttractionType cultural("Cultural");
                        AttractionType natural("Natural");
                        AttractionType entertainment("Entertainment");
                        AttractionType religious("Religious");
                        AttractionType architectural("Architectural");
                        AttractionType museum("Museum");

                        switch (t) {
                        case 1:
                            system("cls");
                            cout << "\nВы выбрали операцию 1 (добавление достопримечательности)\n" << endl;
                            try {
                                cout << "Введите название достопримечательности: ";
                                cin >> name;
                                cout << "Введите местоположение достопримечательности: ";
                                cin >> location;
                                cout << "Введите описание достопримечательности: ";
                                cin >> description;

                                cout << "Выберите тип достопримечательности:\n";
                                cout << "1) Историческая\n2) Культурная\n3) Природная\n4) Развлекательная\n5) Религиозная\n6) Архитектурная\n7) Музей\n";
                                cout << "Введите номер типа: ";
                                cin >> typeIndex;

                                switch (typeIndex) {
                                case 1:
                                    selectedType = historical;
                                    break;
                                case 2:
                                    selectedType = cultural;
                                    break;
                                case 3:
                                    selectedType = natural;
                                    break;
                                case 4:
                                    selectedType = entertainment;
                                    break;
                                case 5:
                                    selectedType = religious;
                                    break;
                                case 6:
                                    selectedType = architectural;
                                    break;
                                case 7:
                                    selectedType = museum;
                                    break;
                                default:
                                    cout << "Неверный тип. Используется тип по умолчанию.\n";
                                    selectedType = AttractionType("Неизвестный");
                                    break;
                                }

                                attractionManager.addAttraction(name, location, description, selectedType);
                                cout << "\nДостопримечательность успешно добавлена!!!" << endl;
                            }
                            catch (const MaxAttractionsException& e) {
                                std::cout << e.what() << std::endl;
                            }
                            break;
                        case 2:
                            system("cls");
                            cout << "\nВы выбрали операцию 2 (удаление достопримечательности)\n" << endl;
                            attractionManager.viewAllAttractions();
                            int index;
                            cout << "Введите индекс достопримечательности для удаления: ";
                            cin >> index;
                            index = index - 1;
                            attractionManager.deleteAttraction(index);
                            break;
                        case 3:
                            system("cls");
                            cout << "\nВы выбрали операцию 3 (обновление достопримечательности)\n" << endl;
                            attractionManager.editAttraction();
                            break;
                        case 4:
                            system("cls");
                            cout << "\nВы выбрали операцию 4 (просмотр всех достопримечательностей)\n" << endl;
                            attractionManager.viewAllAttractions();
                            cout << endl;
                            break;
                        case 5:
                            system("cls");
                            cout << "\nВы выбрали операцию 5 (просмотр всех пользователей)\n" << endl;
                            userManager.viewAllUsers();
                            cout << endl;
                            break;
                        case 6:
                            system("cls");
                            cout << "\nВы выбрали операцию 6 (добавление тура)\n" << endl;
                            cout << "Введите название тура: ";
                            cin >> name;
                            cout << "Введите пункт назначения: ";
                            cin >> destination;
                            cout << "Введите описание тура: ";
                            cin >> description;
                            cout << "Введите цену тура: ";
                            cin >> price;

                            cout << "Введите количество достопримечательностей: ";
                            cin >> numAttractions;
           
                            for (int i = 0; i < numAttractions; ++i) {
                                string attractionName, attractionLocation, attractionDescription, attractionType;
                                cout << "Введите название достопримечательности: ";
                                cin >> attractionName;
                                cout << "Введите местоположение достопримечательности: ";
                                cin >> attractionLocation;
                                cout << "Введите описание достопримечательности: ";
                                cin >> attractionDescription;
                                cout << "Введите тип достопримечательности: ";
                                cin >> attractionType;

                                attractions.emplace_back(attractionName, attractionLocation, attractionDescription, attractionType);
                            }

                            if (tourManager.addTour(name, destination, description, price, attractions)) {
                                cout << "Тур успешно добавлен." << endl;
                            }
                            else {
                                cout << "Не удалось добавить тур." << endl;
                            }
                            break;
                        case 7:
                            system("cls");
                            cout << "\nВы выбрали операцию 7 (удаление тура)\n" << endl;
                            tourManager.viewAllTours();
                            cout << endl;
                            cout << "Введите индекс тура для удаления: ";
                            cin >> index2;
                            tourManager.deleteTour(index2);
                            break;
                        case 8:
                            system("cls");
                            cout << "\nВы выбрали операцию 8 (просмотр всех туров)\n" << endl;
                            tourManager.viewAllTours();
                            cout << endl;
                            break;
                        case 9:
                            system("cls");
                            cout << "\nВы выбрали операцию 9 (бронирование тура)\n" << endl;
                            bookingManager.addBookingFromInput();
                            cout << endl;
                            break;
                        case 10:
                            system("cls");
                            cout << "\nВы выбрали операцию 10 (вывод всех забронированных туров)\n" << endl; 
                            bookingManager.viewAllBookings();
                            cout << endl;
                            break;
                        case 11:
                            system("cls");
                            cout << "\nВы выбрали операцию 11 (оставить отзыв)\n" << endl;
                            reviewManager.addReviewFromInput();
                            cout << endl;
                            break;
                        case 12:
                            system("cls");
                            cout << "\nВы выбрали операцию 12 (просмотр отзывов)\n" << endl;
                            reviewManager.viewAllReviews();
                            cout << endl;
                            break;
                        case 15:
                            system("cls");
                            cout << "\nВы выбрали операцию 13 (выход)\n" << endl;
                            cout << "Вы вышли из системы!!!" << endl;
                            t = 0;
                            break;
                        case 13:
                            system("cls");
                            cout << "\nВы выбрали операцию 13 (поиск достопримечательности по произвольному шаблону)\n" << endl;
                            cout << endl;
                            cout << "Введите произвольный шаблон для поиска:";
                            cin >> a;
                            attractionManager.searchAttraction(a);
                            break;
                        case 14:
                            system("cls");
                            cout << "\nВы выбрали операцию 14 (поиск туров по произвольному шаблону)\n" << endl;
                            cout << endl;
                            cout << "Введите произвольный шаблон для поиска:";
                            cin >> a;
                            tourManager.searchTour(a);
                            break;
                        default:
                            system("cls");
                            cout << "Такой операции нет!";
                            break;
                        }

                        if (t != 0) {
                            cout << "Операции которые доступны для вас (Администратор):\n\t1) Добавление достопримечательности \n\t2) Удаление достопримечательности \n\t3) Редактирование достопримечательности \n\t4) Вывод всех достопримечательностей\n";
                            cout << "\t5) Просмотр всех пользователей \n\t6) Добавление тура \n\t7) Удаление тура\n\t8) Просмотр всех туров\n\t9) Бронирование тура" << endl;
                            cout << "\t11) Оставить отзыв\n\t12) Просмотр отзывов\n\t13) Поиск достопримечательности по произвольному шаблону" << endl;
                            cout << "\t14) Поиск туров по произвольному шаблону\n\t15) Выход"<<endl;
                            cout << endl;
                        }
                        
                    } while (t != 0);
                }
                else {
                    int k;
                    cout << "Операции которые доступны для вас(Пользователь):\n\t1) Добавление достопримечательности \n\t2) Вывод всех достопримечательностей\n";
                    cout << "\t3) Просмотр всех туров\n\t4) Бронирование тура\n\t5) Оставить отзыв\n\t6) Просмотр отзывов" << endl;
                    cout << "\t7) Поиск достопримечательности по произвольному шаблону\n\t8) Поиск туров по произвольному шаблону\n\t9) Выход\n";
                    cout << endl;

                    do {
                        cout << "Введите номер операции: ";
                        cin >> k;

                        string name, location, description;
                        int typeIndex;
                        AttractionType selectedType;

                        AttractionType historical("Historical");
                        AttractionType cultural("Cultural");
                        AttractionType natural("Natural");
                        AttractionType entertainment("Entertainment");
                        AttractionType religious("Religious");
                        AttractionType architectural("Architectural");
                        AttractionType museum("Museum");

                        switch (k) {
                        case 1:
                            system("cls");
                            cout << "\nВы выбрали операцию 1 (добавление достопримечательности)\n" << endl;
                            cout << "Введите название достопримечательности: ";
                            cin >> name;
                            cout << "Введите местоположение достопримечательности: ";
                            cin >> location;
                            cout << "Введите описание достопримечательности: ";
                            cin >> description;

                            cout << "Выберите тип достопримечательности:\n";
                            cout << "1) Историческая\n2) Культурная\n3) Природная\n4) Развлекательная\n5) Религиозная\n6) Архитектурная\n7) Музей\n";
                            cout << "Введите номер типа: ";
                            cin >> typeIndex;

                            switch (typeIndex) {
                            case 1:
                                selectedType = historical;
                                break;
                            case 2:
                                selectedType = cultural;
                                break;
                            case 3:
                                selectedType = natural;
                                break;
                            case 4:
                                selectedType = entertainment;
                                break;
                            case 5:
                                selectedType = religious;
                                break;
                            case 6:
                                selectedType = architectural;
                                break;
                            case 7:
                                selectedType = museum;
                                break;
                            default:
                                cout << "Неверный тип. Используется тип по умолчанию.\n";
                                selectedType = AttractionType("Неизвестный");
                                break;
                            }

                            attractionManager.addAttraction(name, location, description, selectedType);
                            break;
                        case 2:
                            system("cls");
                            cout << "\nВы выбрали операцию 2 (просмотр всех достопримечательностей)\n" << endl;
                            attractionManager.viewAllAttractions();
                            cout << endl;
                            break;
                        case 3:
                            system("cls");
                            cout << "\nВы выбрали операцию 3 (просмотр всех туров)\n" << endl; \
                                tourManager.viewAllTours();
                            cout << endl;
                            break;
                        case 4:
                            system("cls");
                            cout << "\nВы выбрали операцию 4 (бронирование тура)\n" << endl; \
                            bookingManager.addBookingFromInput();
                            cout << endl;
                            break;
                        case 9:
                            system("cls");
                            cout << "\nВы выбрали операцию 9 (выход)\n" << endl;

                            cout << "Вы вышли из системы!!!" << endl;
                            k = 0;
                            break;
                        case 5:
                            system("cls");
                            cout << "\nВы выбрали операцию 5 (оставление отзыва)\n" << endl;
                            reviewManager.addReviewFromInput();
                            cout << endl;
                            break;
                        case 6:
                            system("cls");
                            cout << "\nВы выбрали операцию 6 (просмотр отзывов)\n" << endl;
                            reviewManager.viewAllReviews();
                            cout << endl;
                            break;
                        case 7:
                            system("cls");
                            cout << "\nВы выбрали операцию 7 (поиск достопримечательности по произвольному шаблону)\n" << endl;
                            cout << endl;
                            cout << "Введите произвольный шаблон для поиска:";
                            cin >> a;
                            attractionManager.searchAttraction(a);
                            break;
                        case 8:
                            system("cls");
                            cout << "\nВы выбрали операцию 8 (поиск туров по произвольному шаблону)\n" << endl;
                            cout << endl;
                            cout << "Введите произвольный шаблон для поиска:";
                            cin >> a;
                            tourManager.searchTour(a);
                            break;
                        default:
                            system("cls");
                            cout << "Такой операции нет!!!";
                            break;
                        }

                        if (k != 0) {
                            cout << "Операции которые доступны для вас(Пользователь):\n\t1) Добавление достопримечательности \n\t2) Вывод всех достопримечательностей\n";
                            cout << "\t3) Просмотр всех туров\n\t4) Бронирование тура\n\t5) Оставить отзыв\n\t6) Просмотр отзывов" << endl;
                            cout << "\t7) Поиск достопримечательности по произвольному шаблону\n\t8) Поиск туров по произвольному шаблону\n\t9) Выход\n";
                            cout << endl;
                        }
                    } while (k != 0);
                }
            }
            else {
                do {
                    cout << "\nНеверный email или пароль!" << endl;
                    cout << "Введите данные заново." << endl;
                    cout << "\nВведите адрес электронной почты: ";
                    cin >> email;
                    cout << "Введите пароль: ";
                    cin >> password;
                } while (userManager.loginUser(email, password) != true);
            }
            break;
        default:
            system("cls");
            cout << "Программа завершена!";
            break;
        }
    } while (n != 0);

    return 0;
}
