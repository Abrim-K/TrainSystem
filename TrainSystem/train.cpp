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
	cout << "������� ����� ������: ";
	cin >> number;
	cout << "������� ������� ����������: ";
	cin >> station;
	cout << "������� ����� ����������� (����� ����� ��� ������):" << endl;
	cin >> month >> day >> hour >> minute;
	Train train(number, station, rework(month), rework(day), rework(hour), rework(minute));
	p_trains.push_back(train);
	cout << "����� ��������" << endl;
}


void OutputAllTrains(vector <Train> p_trains) {
	for (Train train : p_trains) {
		train.print_train();
		cout << endl;
	}
}


void SearchByNumber(vector <Train> p_trains) {
	string p_number;
	cout << "������� ����� ������: ";
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
		cout << "���������� ������� ���" << endl;
	}
}


void SearchByStation(vector <Train> p_trains) {
	string p_station;
	cout << "������� ������� ����������: ";
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
		cout << "���������� ������� ���" << endl;
	}
}


void LoadFromFile(vector <Train>& trains) {
	string file, number, station, month, day, hour, minute;
	cout << "������� ��� �����: ";
	cin >> file;
	ifstream in(file);
	if (in.is_open()) {
		while (in >> number >> station >> month >> day >> hour >> minute) {
			Train train(number, station, month, day, hour, minute);
			trains.push_back(train);
		}
		cout << "������ �������� �������" << endl;
	}
	else {
		cout << "������" << endl;
	}
}


void divide() {
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}
