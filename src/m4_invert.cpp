#include <math.h>
#include "include/matcalc/matcalc.h"

GLfloat dist (const Matrix4 &a, const Matrix4 &b)
{
    int i, j;
    GLfloat d = 0;
    for (i=0 ; i<3 ; i++)
	for (j=0 ; j<3 ; j++)
	    d += fabs (a.m[i][j] - b.m[i][j]);

    return d;
}

int main (void)
{
    Vector3 v(5,7,11);
    v /= v.norm();
    Matrix4 r1(v, 1);
    Matrix4 r2(v, -1);

    Matrix4 ir1 = !r1;

    GLfloat d = dist(ir1, r2);

    if (d > 5.0e-7) {
	bzouzerr << "error : d(ir1, r2) = " << d << endl ;
	return 1;
    } else {
	cout << "d(ir1, r2) = " << d << endl ;
	return 0;
    }

}
