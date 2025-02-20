#include <iostream>
#include <iomanip>
#include "header.h"
using std::cout;
using std::setw;
using std::endl;
using std::left;
using namespace std;

int ipow(int base, int exp)
{
	int result = 1;
	while (true)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		if (exp == 0)
			break;
		base *= base;
	}

	return result;
}

double round_prec(double n, int prec)
{
	return std::round(n * ipow(10, prec)) / ipow(10, prec);
}


int main() {

	//cout << "X" << setw(10) << "Y" << endl;
	//cout << endl;
	//double x = -40.0;
	//for (int i = 0; i < 500; i++) {
	//	double y = ySk(x);
	//	cout << left << setw(10) << x << setw(10) << y << endl;

	//	//cout << x << endl;

	//	//cout << y << endl;
	//	x += 0.5;
	//}

	double r = 10.0;
	double l = 0.0;

	double xm = (r + l) / 2;
	double x1 = (xm + l) / 2;
	double x2 = (r + xm) / 2;
	double ym = ySk(xm);

	double L = 10;
	int yFunkcijosKvietimas = 1;
	int iteracijos = 0;

	while (L > 0.0001) {
		intervaloDalijimasPusiau(xm, x1, x2, r, l, L, ym);
		cout << "X Y :" << xm << " " << round(ym) << endl;
		yFunkcijosKvietimas += 2;
		iteracijos += 1;
	}

	double Ymin = ySk(xm);

	cout << "Minimumo taskas:\n" << "( " << xm << " ; " << round_prec(Ymin, 8) << " )" << endl;
	cout << "Y funkcija buvo kviesta: " << yFunkcijosKvietimas << endl;
	cout << "Iteraciju skaicius:" << iteracijos << endl;

	// AUKSO PJUVIS

	const double ap = (sqrt(5) - 1) / 2;


	r = 10;
	l = 0;

	L = r - l;
	cout << L << endl;
	x1 = r - ap * L;
	x2 = l + ap * L;
	cout << "x1: " << x1 << endl;
	cout << "x2: " << x2 << endl;
	double y1 = ySk(x1);
	double y2 = ySk(x2);

	cout << "y1: " << y1 << endl;
	cout << "y2: " << y2 << endl;
	cout << "reziai: " << l << "   " << r << "L = " << L << endl;

	yFunkcijosKvietimas = 2;
	iteracijos = 0;

	while (L > 0.0001) {
		auksinisPjuvis(L, x1, x2, y1, y2, l, r, ap);
		//cout << L << " " << x1 << " " << x2 << " " << y1 << " " << y2 << " " << l << " "  << r << endl;
		cout << "x1: " << x1 << endl;
		cout << "x2: " << x2 << endl;
		cout << L << endl;
		cout << "y1: " << y1 << endl;
		cout << "y2: " << y2 << endl;
		yFunkcijosKvietimas += 2;

		iteracijos += 1;
	}

	double Xmin = (x1 + x2) / 2;
	Ymin = ySk(Xmin);

	cout << "Minimumo taskas:\n" << "( " << Xmin << " ; " << Ymin << " )" << endl;
	cout << "Y funkcija buvo kviesta: " << yFunkcijosKvietimas << endl;
	cout << "Iteraciju skaicius:" << iteracijos << endl;







}