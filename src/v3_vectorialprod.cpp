#include "include/matcalc/matcalc.h"

int main (void)
{
    Vector3 a(1, 0, 0),
	    b(0, 1, 0),
	    r(0, 0, 1);

    if ((a ^ b) == r)
	return 0;

    bzouzerr << "error :" << endl
	     << "   " << a << endl
	     << " ^ " << b << endl
	     << " = " << r << endl
	     << "difference : " << endl
	     << "   " << ((a+b)-r) << endl;
    return 1;
}
