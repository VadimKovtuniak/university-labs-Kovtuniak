#include <iostream>
#include <cmath>

using namespace std;
struct point {

	double first;
	double second;

	void Display() {
		cout << "X= " << first << endl;
		cout << "Y= " << second << endl;
	}
	
	void Read() {
		cout << "Введіть кординату Х = ";
		cin >> first;

		cout << "Введіть кординату Y = ";
		cin >> second;

	}

	void Init(double f, double s) {

		first = f;
		second = s;
	}

	double distance() {
		return sqrt(first * first + second * second);

	}
};

	


int main() {
	system("chcp 65001");

	point po;

	po.Read();
	po.Display();

	cout << "відстань до початку координат = " << po.distance() << endl;


	return 0;
		
}



	
