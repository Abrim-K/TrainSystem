#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Time
{
protected:
	string month;
	string day;
	string hour;
	string minute;
public:
	Time(string p_month = "1", string p_day = "1", string p_hour = "00", string p_minute = "00") {
		month = p_month;
		day = p_day;
		hour = p_hour;
		minute = p_minute;
	}
	void print_time() {
		cout << "Дата отправления (ММ.ДД): " << month << '.' << day << "\nВремя: " << hour << ':' << minute << endl;
	}
	string get_time() {
		return month + '.' + day + ' ' + hour + ':' + minute;
	}
	//~Time();
};


class Train : public Time
{
private:
	string number;
	string station;
public:
	Train(string p_number = "0", string p_station = "Unknown", string p_month = "1", string p_day = "1", string p_hour = "0", string p_minute = "0") :
		Time(p_month, p_day, p_hour, p_minute)
	{
		number = p_number;
		station = p_station;
	}
	string get_number() {
		return number;
	}
	string get_station() {
		return station;
	}
	void print_train() {
		cout << "Поезд номер " << number << "\nСтанция назначения: " << station << endl;
		cout << "Дата отправления (ММ.ДД): " << month << '.' << day << "\nВремя: " << hour << ':' << minute << endl;
	}
	//~Train();
};


string rework(string p_time);


void InputTrain(vector <Train>& p_trains);


void OutputAllTrains(vector <Train> p_trains);


void SearchByNumber(vector <Train> p_trains);


void SearchByStation(vector <Train> p_trains);


void divide();