#include "include/matcalc/matcalc.h"

int main (void)
{
    Vector3 a(3,   5,  7),
	    b(11, 13, 17),
	    r(14, 18, 24);

    if ((a + b) == r)
	return 0;

    bzouzerr << "error :" << endl
	     << "   " << a << endl
	     << " + " << b << endl
	     << " = " << r << endl
	     << "difference : " << endl
	     << "   " << ((a+b)-r) << endl;
    return 1;
}
