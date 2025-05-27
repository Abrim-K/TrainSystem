#include "Train.h"

void LoadFromFile(vector <Train> &trains) {
    string file, number, station, month, day, hour, minute;
    cout << "Введите имя файла: ";
    cin >> file;
    ifstream in(file);
    if (in.is_open()) {
        while (in >> number >> station >> month >> day >> hour >> minute) {
            Train train(number, station, month, day, hour, minute);
            trains.push_back(train);
        }
        cout << "Данные получены успешно" << endl;
    }
    else {
        cout << "Ошибка" << endl;
    }
}


int main() {
    system("chcp 1251");
    vector <Train> trains;
    int choice;
    do {
        divide();
        cout << "Меню:\n"
            << "1. Ввод данных о поездах\n"
            << "2. Вывод сведений по всем поездам\n"
            << "3. Вывод сведений по поезду с запрошенным номером\n"
            << "4. Вывод сведений по поездам до запрошенной станции назначения\n"
            << "5. Ввод данных из файла\n"
            << "6. Выход\n"
            << "Выберите действие: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1: {
            divide();
            int n;
            cout << "Введите количество поездов: ";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                divide();
                InputTrain(trains);
            }
            break;
        }
        case 2:
            divide();
            OutputAllTrains(trains);
            break;
        case 3: {
            divide();
            SearchByNumber(trains);
            break;
        }
        case 4: {
            divide();
            SearchByStation(trains);
            break;
        }
        case 5: {
            divide();
            LoadFromFile(trains);;
            break;
        }
        case 6:
            cout << "Выход из программы." << std::endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 6);
}
