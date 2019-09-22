/* Вагон, содержит поле - количество мест (целое число) и цена билета по данному маршруту (вещественная). 
Реализовать метод, вычисляющий общую ожидаемую сумму от продаж билетов в вагоне. 
Основным классом является поезд, содержащий три поля типа вагонов и процент заполнения каждого вагона(три целых поля). 
Реализовать метод, вычисляющий реальный доход от данного маршрута и вагон с наименьшей ожидаемой суммой продаж. */

#include "pch.h"
#include <iostream>

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
};

class train {
private:
	carriage one;
	carriage two;
	carriage three;

	int percent_one;
	int percent_two;
	int percent_three;
public:
	float real_profit() {
		float rp_one, rp_two, rp_three;
		rp_one = one.profit();
		rp_two = two.profit();
		rp_three = three.profit();
		rp_one *= (percent_one/100);
		rp_two *= (percent_two/100);
		rp_three *= (percent_three/100);

		float sum = rp_one + rp_two + rp_three;
		return sum;
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

		if (c_end == 1) cout << "Наименьшая ожидаемая сумма продаж: первый вагон." << endl;
		else {
			if (c_end == 2) cout << "Наименьшая ожидаемая сумма продаж: второй вагон." << endl;
			else cout << "Наименьшая ожидаемая сумма продаж: третий вагон." << endl;
		}
	}
};



int main()
{
	setlocale(LC_ALL, "rus");
}

