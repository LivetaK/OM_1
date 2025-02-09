#include "Header.h"


double ySk(double x) {
	double y;
	y = pow((pow(x, 2) - 8), 2) / 8;
	return y;
}
// a = 8;
// b = 0   --     2+3+1+3+9+8 = 26   --   2+6 = 8; 
