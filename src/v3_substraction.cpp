#include "include/matcalc/matcalc.h"

int main (void)
{
    Vector3
	    a(14, 18, 24),
	    b(3,   5,  7),
	    r(11, 13, 17);

    if ((a - b) == r)
	return 0;

    bzouzerr << "error :" << endl
	     << "   " << a << endl
	     << " r " << b << endl
	     << " = " << r << endl
	     << "difference : " << endl
	     << "   " << ((a-b)-r) << endl;
    return 1;
}
