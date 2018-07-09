#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct deadline {
	string task;
	int day;
	int month;
	int year;
};
int main()
{
	int action = 0;
	string task;

	string buff;

	struct deadline d[5];
	struct deadline sort[5];
	int date[5];

	ofstream fout;
	for (int i = 0; action != 2; i++) {
		system("cls");
		cout << "If you want to add a task, click 1! " << endl << "If you want to view your tasks, click 2 ";
		cin >> action;
		if (action == 1) {


			ofstream fout("tasks.txt", ios_base::app);
			cout << "Enter your task: ";
			cin >> d[i].task;

			cout << "Please enter the deadline for task : " << i << endl << "day: ";

			cin >> d[i].day;

			cout << "month: ";

			cin >> d[i].month;

			cout << "year: ";
			cin >> d[i].year;
			fout << d[i].day << "." << d[i].month << "." << d[i].year << d[i].task << endl;
			fout.close();

		}

	}


	if (action == 2) {
		ifstream fin("tasks.txt");
		int counter = 0;
		string line[50];
		string year[50];
		string month[50];
		string day[50];
		for (int i = 0; !fin.eof(); i++) {
			fin >> buff;
			line[i] = buff;
			year[i] = line[i].substr(6, 9);
			month[i] = line[i].substr(3, 4);
			day[i] = line[i].substr(0, 1);

			counter++;
		}
		string temp;


		for (int i = 0; i < counter - 1; i++) {
			for (int j = 0; j < counter - i - 1; j++) {
				if (year[i] > year[j]) {
					temp = line[i];
					line[i] = line[j];
					line[j] = temp;
				}
			}
		}
		fin.close();
		for (int i = 0; i < counter - 1; i++) {
			cout << line[i] << endl;
		}


	}



}

