#include "Train.h"


int main() {
    system("chcp 1251");
    vector <Train> trains;
    int choice;
    do {
        divide();
        cout << "����:\n"
            << "1. ���� ������ � �������\n"
            << "2. ����� �������� �� ���� �������\n"
            << "3. ����� �������� �� ������ � ����������� �������\n"
            << "4. ����� �������� �� ������� �� ����������� ������� ����������\n"
            << "5. ���� ������ �� �����\n"
            << "6. �����\n"
            << "�������� ��������: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1: {
            divide();
            int n;
            cout << "������� ���������� �������: ";
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
            cout << "����� �� ���������." << std::endl;
            break;
        default:
            cout << "�������� �����. ���������� �����." << std::endl;
        }
    } while (choice != 6);
}
