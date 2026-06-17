#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double f(double x) {
    return 8 - 2 * x * x;
}
double simpson(double a, double b, int n) {
    if (n % 2 != 0) n++; 
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }
    return sum * h / 3.0;
}

int main() {
    double a = -2.0, b = 2.0;
    int n_values[] = { 2, 4, 10, 18, 100, 1000 };

    cout << fixed << setprecision(10);
    cout << "Число разбиений N\tПриближённое значение площади\n";
    for (int n : n_values) {
        double area = simpson(a, b, n);
        cout << n << "\t\t\t" << area << endl;
    }
    return 0;
}
