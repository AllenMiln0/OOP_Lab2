/* Вагон, содержит поле - количество мест (целое число) и цена билета по данному маршруту (вещественная). 
Реализовать метод, вычисляющий общую ожидаемую сумму от продаж билетов в вагоне. 
Основным классом является поезд, содержащий три поля типа вагонов и процент заполнения каждого вагона(три целых поля). 
Реализовать метод, вычисляющий реальный доход от данного маршрута и вагон с наименьшей ожидаемой суммой продаж. */

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <cstring>
#include <string>
#include <conio.h>
#include <windows.h>


using namespace std;

class carriage {
private:
	int count_seat;
	float price;
public:
	
	float profit() {
		float pro;
		pro = price * count_seat;
		return (pro);
	}

	void init() {
		count_seat = 30;
		price = 3000;
	}

	void display() {
		cout << "Количество мест в вагоне: " << count_seat << endl;
		cout << "Цена билета: " << price << endl;
	}

	void read() {
		cout << "Введите кол-во мест в вагоне: " << endl;
		cin >> count_seat;
		cout << "Введите цену по этому маршруту: " << endl;
		cin >> price;
	}
};

class train {
private:
	carriage *one;
	int percent[3];

	char mas[100];
public:
	train() {
		one = new carriage[3];
	}

	~train() {
		delete[] one;
	}

	void display() {
		cout << "Наименование маршрута: " << mas << endl;
		for (int i = 0; i < 3; i++) {
			one[i].display();
			cout << "Заполненность вагона в процентах: " << percent[i] << endl;
		}
	}

	void real_profit(){
		float rp_one[3];
		float sum_one[3], sum;
		sum = 0;
		for (int i = 0; i < 3; i++) {
			rp_one[i] = one[i].profit();
			sum_one[i] = (rp_one[i] * percent[i]) / 100.;
			sum += sum_one[i];
		}
		
		cout << "Реальная сумма прибыли со всех вагонов " << sum << endl << endl << endl;
	}

	// второй метод
	void min_profit() {
		float c1[3], c_end;
		for (int i = 0; i < 3; i++) {
			c1[i] = one[i].profit();
		}

		c_end = c1[0];
		for (int i = 0; i < 3; i++) {
			if (c1[i] < c_end) c_end = c1[i];
		}
		int t;
		for (int i = 0; i < 3; i++) {
			if (c1[i] == c_end) t = i;
		}


		cout << "Наименьшая ожидаемая сумма продаж: " << (t+1) << " вагон." << endl << endl << endl;
	}

	void profit() {
		float one_p[3];
		for (int i = 0; i < 3; i++) {
			one_p[i] = one[i].profit();
			cout << "Ожидаемая сумма прибыли " << (i+1) << " поезда: " << one_p[i] << endl;
		}
	}

	void read_train() {
		cout << "Введите название маршрута" << endl;
		fflush(stdin);
		cin >> mas;
		// cout << mas;

		for (int i = 0; i < 3; i++) {
			one[i].read();
			cout << "Введите процент заполнения " << (i+1) << " вагона (0..100):" << endl;
			cin >> percent[i];
		}
	}
};

void menu() {
	cout << "***************** Меню ***************" << endl;
	cout << "* 1. Ввод мест, стоимости билета и \n*\tзаполненность вагонов в процентах *" << endl;
	cout << "* 2. Вывести на экран данные о трех вагонах *" << endl;
	cout << "* 3. Рассчитать ожидаемую сумму дохода каждого вагона *" << endl;
	cout << "* 4. Рассчитать реальную сумму дохода всех вагонов *" << endl;
	cout << "* 5. Определить наименьший по ожидаемой сумме вагон *" << endl;
	cout << "* 6. Выход *" << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	do {
		menu();
		train moscow;
		cin >> choice;
		switch (choice) {
		case 1:	moscow.read_train();
			break;
		case 2: moscow.display();
			break;
		case 3: moscow.profit();
			break;
		case 4:	moscow.real_profit();
			break;
		case 5:	moscow.min_profit();
			break;
		case 6: return 3;
			break;
		default: cout << "Такого пункта меню нет. " << endl;
			break;
		}
	} while (choice != 6);
}

