#include "include/matcalc/matcalc.h"

int precision_test (void)
{
    int i=1;

    Vector3 a(1,1,1), b;
    GLfloat d = 1;

    do {
	d /= 2;
	b = a + Vector3 (d,d,d);
	i ++;
    } while ((a != b) && (i<100));
    if (d > 6.0e-08) {
	bzouzerr << "warning : max precision is only around : 1 / " << d << endl ;
	return 1;
    } else {
	cerr << "max precision is around : 1 / " << d << endl ;
	return 0;
    }
}

int main (void)
{
    Vector3
	    a(14,	18,    24),
	    b(14.0,   18.0,  24.0),
	    c(14.0,   18.0,  24.1);

    if ((a == b) && (a != c)) {
	return precision_test ();
    }

    if (!(a == b))
	bzouzerr << "error :" << endl
		 << "   " << a << endl
		 << "   " << b << endl
		 << "seem to differ !" << endl
		 << "difference : " << endl
		 << "   " << (a-b) << endl;
    if (!(a != c))
	bzouzerr << "error :" << endl
		 << "   " << a << endl
		 << "   " << c << endl
		 << "seem to be equal !" << endl
		 << "difference : " << endl
		 << "   " << (a-b) << endl;
    return 1;
}
