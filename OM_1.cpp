#include <iostream>
#include "Header.h"
using std::cout;
using std::setw;
using std::endl;
using std::left;
using std::round;


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
		yFunkcijosKvietimas += 2;
		iteracijos += 1;
	}

	double Ymin = ySk(xm);
	cout << "INTERVALO DALIJIMAS PUSIAU" << endl;
	cout << endl;
	cout << "Minimumo taskas:\n" << "( " << xm << " ; " << Ymin << " )" << endl;
	cout << "Y funkcija buvo kviesta: " << yFunkcijosKvietimas << endl;
	cout << "Iteraciju skaicius:" << iteracijos << endl;
	cout << endl;

	// AUKSO PJUVIS

	const double ap = (sqrt(5) - 1) / 2;


	r = 10;
	l = 0;

	L = r - l;
	x1 = r - ap * L;
	x2 = l + ap * L;

	double y1 = ySk(x1);
	double y2 = ySk(x2);


	yFunkcijosKvietimas = 2;
	iteracijos = 0;

	while (L > 0.0001) {
		auksinisPjuvis(L, x1, x2, y1, y2, l, r, ap);

		yFunkcijosKvietimas += 1;
		iteracijos += 1;
	}

	double Xmin = (x1 + x2) / 2;
	Ymin = ySk(Xmin);

	cout << "AUKSO PJUVIS" << endl;
	cout << endl;
	cout << "Minimumo taskas:\n" << "( " << Xmin << " ; " << Ymin << " )" << endl;
	cout << "Y funkcija buvo kviesta: " << yFunkcijosKvietimas << endl;
	cout << "Iteraciju skaicius:" << iteracijos << endl;
	cout << endl;


	// NIUTONO METODAS 

	iteracijos = 0;
	int funkcijosKvietimas = 0;
	Xmin = niutonoMetodas(iteracijos, funkcijosKvietimas);
	Ymin = ySk(Xmin);

	cout << "NIUTONO METODAS" << endl;
	cout << endl;
	cout << "Minimumo taskas:\n" << "( " << Xmin << " ; " << Ymin << " )" << endl;
	cout << "Funkcija buvo kviesta: " << funkcijosKvietimas << endl;
	cout << "Iteraciju skaicius:" << iteracijos << endl;
	cout << endl;





}