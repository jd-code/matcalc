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
    Matrix4 r1(Vector3 (1, 0, 0), M_PI);

    Matrix4 tr1 = ~r1;

    GLfloat d = dist(r1, tr1);

    if (d > 5.0e-7) {
	bzouzerr << "error : d(r1, tr1) = " << dist(r1, tr1) << endl ;
	return 1;
    } else {
	cout << "d(r1, tr1) = " << dist(r1, tr1) << endl ;
	return 0;
    }

}
