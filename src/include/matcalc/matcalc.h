/*
 *  $Id$
 *
 */

#ifndef MATCALC_H_INC
#define MATCALC_H_INC

#include <iostream>
#include <iomanip>

#include <GL/gl.h>

#ifndef bzouzerr    
#define bzouzerr cerr << __FILE__  << ':'  << __LINE__ << ':' << __FUNCTION__ << ':'
#endif              


#ifndef M_PI
# define M_E            2.7182818284590452354   /* e */
# define M_LOG2E        1.4426950408889634074   /* log_2 e */
# define M_LOG10E       0.43429448190325182765  /* log_10 e */
# define M_LN2          0.69314718055994530942  /* log_e 2 */
# define M_LN10         2.30258509299404568402  /* log_e 10 */
# define M_PI           3.14159265358979323846  /* pi */
# define M_PI_2         1.57079632679489661923  /* pi/2 */
# define M_PI_4         0.78539816339744830962  /* pi/4 */
# define M_1_PI         0.31830988618379067154  /* 1/pi */
# define M_2_PI         0.63661977236758134308  /* 2/pi */
# define M_2_SQRTPI     1.12837916709551257390  /* 2/sqrt(pi) */
# define M_SQRT2        1.41421356237309504880  /* sqrt(2) */
#endif //M_PI

// --------------------------------------------------------------------------

using namespace std;

class Vector3;
class Vector4;

// --------------- Vector3 --------------------------------------------------
//
//! a three-GLfloat(s)/double(s)-in-a-column vector with facilities

class Vector3
{
    friend class Vector4;

    public:

	GLfloat x,  //! TD's abscissa
		y,  //! TD's orderly
		z;  //! TD's elevation


	//! the regular constructor from three numbers
	inline Vector3 (GLfloat x, GLfloat y, GLfloat z)
	    {	Vector3::x=x, Vector3::y=y, Vector3::z=z ;
	    }

	//! the algebric 0 constructor
	inline Vector3 (void)
	    { x=0.0, y=0.0, z=0.0 ;
	    }

	//! the regular self-addition operator
	inline Vector3 & operator += (const Vector3 &u)
	    {	x += u.x;
		y += u.y;
		z += u.z;
		return *this;
	    }

	//! the regular self-substraction operator
	inline Vector3 & operator -= (const Vector3 &u)
	    {   x -= u.x;
		y -= u.y;
		z -= u.z;
		return *this;
	    }

	//! self-multiplication by a scalar
	inline Vector3 & operator *= (GLfloat a)
	    {	x *= a, y *= a, z *= a;
		return *this;
	    }

	//! multiplication by a scalar
	inline Vector3 operator * (GLfloat a) const
	    {	return Vector3 (a*x, a*y, a*z);
	    }

	//! self-division by a scalar (be careful : no 0-division test !)
	inline Vector3 & operator /= (GLfloat a)
	    {	x /= a, y /= a, z /= a;
		return *this;
	    }

	//! addition of two vectors
	inline Vector3 operator + (const Vector3 &u) const
	    {   return Vector3 (x+u.x, y+u.y, z+u.z) ;
	    }

	//! substraction of two vectors
	inline Vector3 operator - (const Vector3 &u) const
	    {   return Vector3 (x-u.x, y-u.y, z-u.z) ;
	    }

	//! scalar product of two vectors
	inline GLfloat operator * (const Vector3 &u) const
	    {   return  x * u.x  +  y * u.y  +  z * u.z  ;
	    }

	//! the norm of the vector
	inline GLfloat norm (void) const
	    {   return sqrt (x*x + y*y + z*z) ;
	    }

	//! the squared norm of the vector
	inline GLfloat norm2 (void) const
	    {   return x*x + y*y + z*z ;
	    }
};

//! multiplication of a vector by a scalar
inline Vector3 operator * (GLfloat a, Vector3 v)
{   return Vector3 (a*v.x, a*v.y, a*v.z);
}

//! stream output of a Vector3 (WARNING ! with const precision of 4 digits only)
inline ostream& operator<<(ostream& out, const Vector3 &v)
{
    out << setprecision (4)
	<< "( " << setw (10) << v.x
	<< "  " << setw (10) << v.y
	<< "  " << setw (10) << v.z
	<< " )" ;
    return out;
}


// --------------- Matrix4 --------------------------------------------------
//
//! a 4x4 GLfloat(s)/double(s)-in-a-column matrix with facilities

class Matrix4
{   
    public:
	typedef enum {ZERO, IDENT, ROT} Build;

	//! the set of values in a 4x4 table
	GLfloat m[4][4] ;

	//! sets the matrix to the identity
	inline void setident (void)
	    {   int i, j;
		for (i=0 ; i<4 ; i++)
		for (j=0 ; j<4 ; j++)
		    m[i][j] = (i == j) ? 1.0 : 0.0 ;
	    }

	//! sets the matrix to the alebric 0
	inline void setnull (void)
	    {   int i, j;
		for (i=0 ; i<4 ; i++)
		for (j=0 ; j<4 ; j++)
		    m[i][j] = 0.0;
	    }

	//! the 0 constructor
	inline Matrix4 (void)
	    {	setnull ();
	    }

	//! the multimethod constructor : builds a 0 (Matrix4::ZERO) or identity (Matrix4::IDENT) matrix
	inline Matrix4 (Build b)
	    {   switch (b) {
		    default:
			bzouzerr << " unaproriate construction method " << (int) b << endl ;
		    case ZERO:
			setnull ();
			break;
		    case IDENT:
			setident ();
			break;
		}
	    }

	//! the rotation-matrix constructor, along a non-zero vector "v" and with and angle "vang"
	inline Matrix4 (Vector3 const & v, GLfloat vang)
	    {
		// JDJDJDJD later-on a "Build" flag set to ROT should be used to discriminate
		// different method that use the same initial datas

		GLfloat s = sin (vang);
		GLfloat c = cos (vang);

		const GLfloat &vrx = v.x,
			      &vry = v.y,
			      &vrz = v.z;
		
		m[0][0] = vrx*vrx*(1.0-c)+c    ;  m[0][1] = vrx*vry*(1.0-c)-vrz*s;  m[0][2] = vrx*vrz*(1.0-c)+vry*s;  m[0][3] = 0.0;
		m[1][0] = vry*vrx*(1.0-c)+vrz*s;  m[1][1] = vry*vry*(1.0-c)+c    ;  m[1][2] = vry*vrz*(1.0-c)-vrx*s;  m[1][3] = 0.0;
		m[2][0] = vrx*vrz*(1.0-c)-vry*s;  m[2][1] = vry*vrz*(1.0-c)+vrx*s;  m[2][2] = vrz*vrz*(1.0-c)+c    ;  m[2][3] = 0.0;
		m[3][0] = 0.0                  ;  m[3][1] = 0.0                  ;  m[3][2] = 0.0                  ;  m[3][3] = 1.0;
	    }

	//! multiplication of matrices ( beware ! non-commutative ! )
	inline Matrix4 operator * (Matrix4 const & b) const
	    {
		Matrix4 r;
		int i, j, k;
		for (i=0 ; i<4 ; i++)
		for (j=0 ; j<4 ; j++)
		for (k=0 ; k<4 ; k++)
		    r.m[i][j] += m[i][k] * b.m[k][j] ;
		return r;
	    }
};

//! multiplication of matrices ( beware ! non-commutative ! )
// inline Matrix4 operator * (Matrix4 const & a, Matrix4 const & b)
// {
//     Matrix4 r;
//     int i, j, k;
//     for (i=0 ; i<4 ; i++)
//     for (j=0 ; j<4 ; j++)
//     for (k=0 ; k<4 ; k++)
// 	r.m[i][j] += a.m[i][k] * b.m[k][j] ;
//     return r;
// }

//! multiplication of a matrix and a vector
inline Vector3 operator * (Matrix4 const & a, Vector3 const &v)
{
    return Vector3 (a.m[0][0] * v.x  +  a.m[0][1] * v.y  +  a.m[0][2] * v.z ,
		    a.m[1][0] * v.x  +  a.m[1][1] * v.y  +  a.m[1][2] * v.z ,
		    a.m[2][0] * v.x  +  a.m[2][1] * v.y  +  a.m[2][2] * v.z 
	    );
}

//! stream output of a matrix (WARNING ! with const precision of 4 digits only)
inline ostream& operator<<(ostream& out, const Matrix4 &c)
{
    int i, j;
    out << setprecision (4);
    for (i=0 ; i<4 ; i++) {
	out << "| " ;
	for (j=0 ; j<4 ; j++)
	    out << setw (10) << c.m[i][j] << "  ";  // JDJDJDJD some formating (width?) should be performed here
	out << " |" << endl ;
    }
    return out ;
}

// --------------- Vector4 --------------------------------------------------
//
//! a four-GLfloat(s)/double(s)-in-a-column vector with facilities

class Vector4
{
	GLfloat v[4];
    public:
	inline Vector4 (void) {
	    v[0]=0.0, v[1]=0.0, v[2]=0.0, v[3]=0.0 ;
	}
	inline Vector4 (GLfloat x, GLfloat y, GLfloat z, GLfloat t) {
	    v[0]=x, v[1]=y, v[2]=z, v[3]=t ;
	}
	inline Vector4 (Vector3 const &u) {
	    v[0]=u.x, v[1]=u.y, v[2]=u.z, v[3]=0.0 ;
	}
	inline const GLfloat * getGLfloatP (void) { return &v[0]; }

	// JDJDJDJD this is a test in order to fluently convert to GLfloat *
	inline operator GLfloat * () {
	    return &v[0];
	}

	friend ostream& operator<<(ostream& out, const Vector4 &v);
};

//! stream output of a Vector4 (WARNING ! with const precision of 4 digits only)
inline ostream& operator<<(ostream& out, const Vector4 &v)
{
    out << setprecision (4)
	<< "( " << setw (10) << v.v[0]
	<< "  " << setw (10) << v.v[1]
	<< "  " << setw (10) << v.v[2]
	<< "  " << setw (10) << v.v[3]
	<< " )" ;
    return out;
}


#endif // MATCALC_H_INC

/*
 *  $Log: matcalc.h,v $
 *  Revision 1.2  2004/03/27 15:42:40  jd
 *  added M_PI and co... definitions
 *
 *  Revision 1.1.1.1  2004/02/28 15:28:24  jd
 *  Imported sources
 *
 *  Revision 1.4  2003/04/02 14:16:25  jd
 *  small typos
 *
 *  Revision 1.3  2002/12/07 20:59:11  jd
 *  added Matrix4 first operators and constructors
 *
 *  Revision 1.2  2002/12/05 00:47:39  jd
 *  added Vector3 and its florilege of operators
 *
 *  Revision 1.1  2002/12/02 18:51:12  jd
 *  additions for raw modularisation before merging with sounds
 *
 */