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
    GLfloat d = 1000.0 ;
    
    Matrix4 m;
    m.m[0][0] = 1.1; m.m[0][1] =  0.1; m.m[0][2] = -0.1;
    m.m[1][0] = 0.2; m.m[1][1] =  1.0; m.m[1][2] = -0.2;
    m.m[2][0] = 0.1; m.m[2][1] = -0.1; m.m[2][2] =  1.0;

    d = m.det();

    cout << "initital det = " << d << endl;

    m.reorth();

    d = m.det() - 1.0;


    
    if (d > 6.0e-8) {
	bzouzerr << "error : det(m.reorth()) = " << d << endl ;
	return 1;
    } else {
	cout << "det(m.reorth()) - 1 = " << d << endl ;
	return 0;
    }

}
