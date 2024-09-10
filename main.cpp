/*
Объект- сотрудник (поля:
ФИО, дата приема на работу,
должность, базовый оклад)
Пользовательский ввод или файл
vector Сортировка по ФИО в порядке
возрастания
*/
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
struct employee { // Структура сотрудник
    std::string fio;
    std::string date;
    std::string position;
    int money;
};

bool ForSortString(const employee& ob1, const employee& ob2) // Функция для сортировки по ФИО
{
    return ob1.fio < ob2.fio;
}
void print(const std::vector<employee>& vec) // Функция для вывода вектора в консоль
{
    for (auto& pos : vec)
        std::cout << "fio=" << pos.fio << " date=" << pos.date <<" position = "<<pos.position<<" money = "<<pos.money<< std::endl;
}
int main(int argc, char* argv[]) // Режим считывания из файла
{
    setlocale(LC_ALL, "Russian"); // Русский язык в консоли
    int n;
    std::vector<employee> employee; // Вектор структуры
    if (argc == 2) { // Проверка количества введённых аргументов
        std::string file_name = argv[1]; // Название файла
        std::ifstream file(file_name); // Считываем файл
        if (!file) { // Ошибка, если файл не найден
            std::cerr << "Файл не найден :(\n";
            return -1;
        }
        std::cout << "Введите количество сотрудников: "; // Ввод количества сотрудников
        std::cin >> n;
        employee.resize(n); // Подгоняем размер вектора под сотрудников
        bool flag = true;
        for (auto& pos : employee) { // range based for считываем информацию о сотрудниках
            if (!flag) {
                file.ignore(1, '\n');
            }           
            std::getline(file, pos.fio);
            std::getline(file, pos.date);
            std::getline(file, pos.position);
            file >> pos.money;
            flag = false;
        }
        //print(employee);
        std::sort(employee.begin(), employee.end(), ForSortString); // Сортируем сотрудников по ФИО
        int num = 1;
        for (auto& pos : employee) { // Выводим отсортированный вектор в консоль
             std::cout << "Номер сотрудника: " << num << std::endl;
             std::cout << pos.fio << std::endl;
             std::cout << pos.date << std::endl;
             std::cout << pos.position << std::endl;
             std::cout << pos.money << std::endl;
             num++;
             std::cout << std::endl;
        }
        return 0;
    }
    else {
        std::cerr << "Введено некорректное количество аргументов :(\n";
        system("pause");
        return -1;
    }
}
/*
int main() // Режим ввода в консоль
{   
    setlocale(LC_ALL, "Russian"); // Русский язык в консоли
    int n;
    std::vector<employee> employee; // Вектор сотрудников
    std::cout << "Введите количество сотрудников: "; 
    std::cin >> n;
    employee.resize(n);
    for (size_t i = 0; i < employee.size();++i) { // Ввод информации о сотрудниках
        std::cout << "Номер сотрудника: " << (i + 1) << std::endl;
        std::cout << "Введите ФИО сотрудника на английском языке: ";
        std::cin.ignore();
        std::getline(std::cin, employee[i].fio);
        std::cout << "Введите дату приёма на работу в формате дд.мм.гг : ";
        std::getline(std::cin, employee[i].date);
        std::cout << "Введите должность сотрудника на английском языке: ";
        std::getline(std::cin, employee[i].position);
        std::cout << "Введите оклад сотрудника в рублях: ";
        std::cin >> employee[i].money;
    }
    //print(employee);
    sort(employee.begin(), employee.end(), ForSortString); // Сортировка вектора сотрудников по ФИО
    int num = 1;
    for (auto& pos : employee) { // Вывод отсортированного вектора в консоль
        std::cout << "Номер сотрудника: " << num << std::endl;
        std::cout << "ФИО сотрудника: " << pos.fio << std::endl;;
        std::cout << "Дата приема сотрудника на работу: " << pos.date << std::endl;
        std::cout << "Должность сотрудника: " << pos.position << std::endl;
        std::cout << "Оклад сотрудника: " << pos.money << std::endl;
        num++;
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}*/
