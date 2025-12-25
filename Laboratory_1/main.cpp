#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float x;
	float y;
	cout << "Введите числовое значение x и y: ";
	cin >> x >> y;
	float R = sin(3.14 * x / 3);
	float S;
	if (y == 0) {
		cout << "Ошибка, подлогарифмические выражение не может равняться нулю" << endl;
		return 1;
	}
	else {
		S = x * log10(pow(abs(y), 1.0 / 3.0));
	}
	
	cout << "R = " << R << endl;
	cout << "S = " << S << endl;
	float C = fmax(R, S);
	cout << "C = " << C;
	system("pause");
	return 0;
}
