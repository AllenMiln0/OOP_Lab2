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
	/*carriage() {
		count_seat = 0;
		price = 0;
	}

	~carriage() {

	}*/
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
	carriage one;
	carriage two;
	carriage three;

	int percent_one;
	int percent_two;
	int percent_three;

	char mas[100];
public:

	/*train(){
	/*	one = carriage();
		two = carriage();
		three = carriage(); 
		percent_one = 0;
		percent_two = 0;
		percent_three = 0;
	}

	~train() {

	}*/
	void display() {
		cout << "Наименование маршрута: " << mas << endl;
		one.display();
		cout << "Заполненность первого вагона в процентах: " << percent_one << endl;
		two.display();
		cout << "Заполненность второго вагона в процентах: " << percent_two << endl;
		three.display();
		cout << "Заполненность третьего вагона в процентах: " << percent_two << endl << endl << endl;
	}

	void real_profit() {
		float rp_one, rp_two, rp_three;
		float sum_one, sum_two, sum_three;
		rp_one = one.profit();
		rp_two = two.profit();
		rp_three = three.profit();
		sum_one = (rp_one * percent_one)/100.;
		sum_two = (rp_two * percent_two)/100.;
		sum_three = (rp_three * percent_three)/100.;

		float sum = sum_one + sum_two + sum_three;
		cout << "Реальная сумма прибыли со всех вагонов " << sum << endl << endl << endl;
	}

	// второй метод
	void min_profit() {
		float c1, c2, c3;
		int c_end;
		c1 = one.profit();
		c2 = two.profit();
		c3 = three.profit();
		if (c1 < c2) {
			if (c3 < c1) c_end = 3;
			else c_end = 1;
		}
		else {
			if (c3 > c2) c_end = 2;
			else c_end = 3;
		}

		if (c_end == 1) cout << "Наименьшая ожидаемая сумма продаж: первый вагон." << endl << endl << endl;
		else {
			if (c_end == 2) cout << "Наименьшая ожидаемая сумма продаж: второй вагон." << endl << endl << endl;
			else cout << "Наименьшая ожидаемая сумма продаж: третий вагон." << endl << endl << endl;
		}
	}

	void profit() {
		float one_p, two_p, three_p;
		one_p = one.profit();
		two_p = two.profit();
		three_p = three.profit();

		cout << "Ожидаемая сумма прибыли первого поезда: " << one_p << endl;
		cout << "Ожидаемая сумма прибыли второго поезда: " << two_p << endl;
		cout << "Ожидаемая сумма прибыли третьего поезда: " << three_p << endl << endl << endl;
	}

	void read_train() {
		cout << "Введите название маршрута" << endl;
		fflush(stdin);
		fflush(stdin);
		fflush(stdin);
		cin >> mas;
		// cout << mas;
		one.read();
		two.read();
		three.read();

		cout << "Введите процент заполнения первого вагона (0..100):" << endl;
		cin >> percent_one;
		cout << "Введите процент заполнения второго вагона (0..100):" << endl;
		cin >> percent_two;
		cout << "Введите процент заполнения третьего вагона (0..100):" << endl;
		cin >> percent_three;
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

