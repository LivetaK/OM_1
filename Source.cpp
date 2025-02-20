#include "Header.h"


// a = 8;
// b = 0   --     2+3+1+3+9+8 = 26   --   2+6 = 8; 

double ySk(double x) {
	double y;
	return pow((x * x - 8), 2) / 7;
}

double dxFun(double x) {
	return 4 / 7 * x * x * x - 32 / 7 * x;
}

double dxxFun(double x) {
	return 12 / 7 * x * x - 32 / 7;
}

void intervaloDalijimasPusiau(double &xm, double &x1, double &x2, double &r, double &l, double &L, double &ym) {

	double y1 = ySk(x1);
	double y2 = ySk(x2);

	if (y1 < ym) {
		r = xm;
		xm = x1;
		ym = y1;
	}
	else if (y2 < ym) {
		l = xm;
		xm = x2;
		ym = y2;
	}
	else {
		l = x1;
		r = x2;
	}
	x1 = (xm + l) / 2;
	x2 = (r + xm) / 2;
	

	L = r - l;

}




void auksinisPjuvis(double &L, double& x1, double& x2, double& y1, double& y2, double &l, double &r, const double ap) {
	if (y2 < y1) {
		l = x1;
		L = r - l;
		x1 = x2;
		x2 = l + ap * L;
		y1 = y2;
		y2 = ySk(x2);
	}
	else {
		r = x2;
		L = r - l;
		x2 = x1;
		x1 = r - ap * L;
		y2 = y1;
		y1 = ySk(x1);
	}
 }


double niutonoMetodas(int& iteracijos, int& funkcijosKvietimas) {
	double xi = 5;
	double xj = 5;
	double dx = 0;
	double dxx = 0;
	do {
		xi = xj;
		dx = dxFun(xi);
		dxx = dxxFun(xi);
		xj = xi - dx / dxx;
		iteracijos += 1;
		funkcijosKvietimas += 2;
		cout << "xj: " << xj << endl;
		cout << dx << endl;
		cout << dxx << endl;
	} while (abs(xj - xi) > 0.0001);
	return xj;
}


