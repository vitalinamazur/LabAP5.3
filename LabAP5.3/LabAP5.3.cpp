#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(const double x);
int main()
{
	double yp, yk, z;
	int n;
	cout << "yp = "; cin >> yp;
	cout << "yk = "; cin >> yk;
	cout << "n = "; cin >> n;
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(7) << "y" << " |"
		<< setw(7) << "f" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;
	double yg = (yk - yp) / n;
	double y = yp;
	while (y <= yk)
	{
		z = f(1 + y * y) + pow((f(1) + pow(f(y * y), 2)), 2);
		cout << "|" << setw(7) << setprecision(5) << y << " |"
			<< setw(7) << setprecision(5) << z << " |"
			<< endl;
		//cout << z << " " << z << endl;
		y += yg;
	}
	return 0;
}
double f(const double x)
{
	if (abs(x) >= 1)
		return cos(x/2) / (1 + pow(sin(x), 2));
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++; 
			int factorial = 0;
			for (int j = 0; j <= (2 * i); j++) {
				if (factorial == 0)
					factorial = j;
				else factorial *= j;

			}
			double R = pow(x, 3 * i) / factorial;
			a *= R;
			S += a;
		} while (i < 6);
		return S;
	}

}
