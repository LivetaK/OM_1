#include <iostream>
#include <iomanip>
#include "header.h"

using std::cout;
using std::setw;
using std::endl;
using std::left;

int main() {

	cout << "X" << setw(10) << "Y" << endl;
	cout << endl;
	double x = -10.0;
	for (int i = 0; i < 40; i++) {
		double y = ySk(x);
		cout << left << setw(10) << x << setw(10) << y << endl;
		x += 0.5;
	}
}