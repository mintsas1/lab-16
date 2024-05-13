
#include <iostream>
#include <string>

    using namespace std;


class Abiturient {
private:
    string surname;
    string name;
    string patronymic;
    string address;
    int* grades; 
    int numGrades; 

public:
   
    Abiturient(const string& surname, const string& name, const string& patronymic, const string& address, const int* grades, int numGrades)
        : surname(surname), name(name), patronymic(patronymic), address(address), numGrades(numGrades) {
        this->grades = new int[numGrades];
        for (int i = 0; i < numGrades; ++i) {
            this->grades[i] = grades[i];
        }
    }

    
    ~Abiturient() {
        delete[] grades;
    }

    
    int getSumOfGrades() const {
        int sum = 0;
        for (int i = 0; i < numGrades; ++i) {
            sum += grades[i];
        }
        return sum;
    }

   
    bool hasbadGrades() const {
        for (int i = 0; i < numGrades; ++i) {
            if (grades[i] < 60) {
                return true;
            }
        }
        return false;
    }

   
    void printInfo() const {
        cout << surname << " " << name << " " << patronymic << ", Адреса: " << address << ", Оцінки: ";
        for (int i = 0; i < numGrades; ++i) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr"); 

    const int maxAbiturients = 5;
    Abiturient* abiturients[maxAbiturients];

    
    abiturients[0] = new Abiturient("Мюлер", "Кожум'яка", "Олександрович", "м. Київ, вул. Федорова 10", new int[3] {46, 34, 70}, 3);
    abiturients[1] = new Abiturient("Чевапчик", "Лариса", "Григорович", "м. Харків, вул. Кирилівська 5", new int[3] {55, 60, 58}, 3);
    abiturients[2] = new Abiturient("Котицько", "Євгенія", "Ігоровівна", "м. Львів, вул. Острівна 8", new int[3] {82, 90, 78}, 3);
    abiturients[3] = new Abiturient("Гето", "Сугуру", "Годжовіч", "м. Київ, проспект. Науки 20", new int[3] {70, 75, 87}, 3);
    abiturients[4] = new Abiturient("Краснівець", "Руслана", "Андрійіївна", "м. Одеса, вул. Четверта 3", new int[3] {63, 70, 69}, 3);

   
    cout << "Список абітурієнтів з незадовільними оцінками:" << endl;
    for (int i = 0; i < maxAbiturients; ++i) {
        if (abiturients[i]->hasbadGrades()) {
            abiturients[i]->printInfo();
        }
    }
    cout << endl;

    
    for (int i = 0; i < maxAbiturients; ++ i)
    {
        delete abiturients[i];
    }

    return 0;
}