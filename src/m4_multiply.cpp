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
    
    if (0) {
	Vector3 v(5,7,11);
	v /= v.norm();
	Matrix4 r1(v, 1);
	Matrix4 r2(v, -1);

	Matrix4 r = r1 * r2;  // with rotations on the same axis, the multiplication is commutative
	//Matrix4 r = r2 * r1;
	d = dist(r, Matrix4(Matrix4::IDENT));
    }

    if (0) {
	Vector3 v(5,7,11);
	v /= v.norm();
	Matrix4 r1(v, 1);

	//Matrix4 r = r1 * (~r1);//	with rotations, the transposed matrix equals the invert
	d = dist(~r1, !r1);
    }

    if (0) {
	Matrix4 rx (Vector3(1,0,0), M_PI_2),
		ry (Vector3(0,1,0), M_PI_2),
		rz (Vector3(0,0,1), M_PI_2);

	Matrix4 r (Matrix4::IDENT);

	r = (rz * (ry * (rx * r)));
	r = (rz * (ry * (rx * r)));
	r = (rz * (ry * (rx * r)));
	r = (rz * (ry * (rx * r)));
	
	d = dist(r, Matrix4(Matrix4::IDENT));
    }

    if (1) {
	Matrix4 rx (Vector3(1,0,0), M_PI_2),
		ry (Vector3(0,1,0), M_PI_2),
		rz (Vector3(0,0,1), M_PI_2);

	Matrix4 r (Matrix4::IDENT);

	r = (~ry) * (rz * (ry * rx));
	r = (((~ry) * rz) * ry) * rx;
    
	d = dist(r, Matrix4(Matrix4::IDENT));
    }


    if (0) {
	Matrix4 rx (Vector3(1,0.3,0.5), 1),
		ry (Vector3(2,0.9,0), 1.2),
		rz (Vector3(0,0.5,1), 4.2);

	Matrix4 r (Matrix4::IDENT);

	d = dist((rz * (ry * rx)) , ((rz * ry) * rx));	// seems to be associative, though not commutative
	// d = dist((rz * (rx * ry)) , (rz * (ry * rx)));	// yes, not commutative
    }
    

    if (d > 6.0e-7) {
	bzouzerr << "error : d(r, I) = " << d << endl ;
	return 1;
    } else {
	cout << "d(r, I) = " << d << endl ;
	return 0;
    }

}
