#include "Train.h"

string rework(string p_time) {
	if (p_time.size() == 1) {
		return '0' + p_time;
	}
	else {
		return p_time;
	}
}


void InputTrain(vector <Train>& p_trains) {
	string number, station, month, day, hour, minute;
	cout << "Введите номер поезда: ";
	cin >> number;
	cout << "Введите станцию назначения: ";
	cin >> station;
	cout << "Введите время отправления (месяц число час минута):" << endl;
	cin >> month >> day >> hour >> minute;
	Train train(number, station, rework(month), rework(day), rework(hour), rework(minute));
	p_trains.push_back(train);
	cout << "Поезд добавлен" << endl;
}


void OutputAllTrains(vector <Train> p_trains) {
	for (Train train : p_trains) {
		train.print_train();
		cout << endl;
	}
}


void SearchByNumber(vector <Train> p_trains) {
	string p_number;
	cout << "Введите номер поезда: ";
	cin >> p_number;
	int found = 0;
	for (Train train : p_trains) {
		if (train.get_number() == p_number) {
			train.print_train();
			cout << endl;
			found++;
		}
	}
	if (found == 0) {
		cout << "Подходящих поездов нет" << endl;
	}
}


void SearchByStation(vector <Train> p_trains) {
	string p_station;
	cout << "Введите станцию назначения: ";
	cin >> p_station;
	int found = 0;
	for (Train train : p_trains) {
		if (train.get_station() == p_station) {
			train.print_train();
			cout << endl;
			found++;
		}
	}
	if (found == 0) {
		cout << "Подходящих поездов нет" << endl;
	}
}


void LoadFromFile(vector <Train>& trains) {
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


void divide() {
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}
