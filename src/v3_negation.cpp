#include "include/matcalc/matcalc.h"

int main (void)
{
    Vector3 a(14, 18, 24),
	    b = -a;

    if (a == -b)
	return 0;

    bzouzerr << "error :" << endl
	     << "   " << a << endl
	     << " + " << b << endl
	     << " = " << a+b << endl;
    return 1;
}
