#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <vector>
using namespace std;

/*
 * Class Matrix
 * 
 */

template <class X>
class matrix
{
	protected :
			vector< vector<X> >M;
	public :
			matrix();
			matrix(int,int);
			matrix(const matrix<X>&);
			matrix<X>& operator=(const matrix<X>&);
			virtual ~matrix();
			
			vector<X>& operator[](int);
			void resize(int, int);
};


//-------------------------------------------------------
/*
 * Constructors & destructor
 */
template <class X>
matrix<X>::matrix()
{
}

template <class X>
matrix<X>::matrix(int l, int c)
{
	resize(l,c);
}

template <class X>
matrix<X>::matrix(const matrix<X>& m)
{
	M=m.M;
}

template <class X>
matrix<X>::~matrix()
{
}

/*
 * Overloaded operators
 */
template <class X>
matrix<X>& matrix<X>::operator=(const matrix<X>& m)
{
	if (&m == this)
		return *this;
	
	M=m.M;
	return *this;
}

template <class X>
vector<X>& matrix<X>::operator[](int x) 
{
	return M[x];
}

/*
 * other methods
 */
template <class X>
void matrix<X>::resize(int l, int c)
{
	M.resize(l);
	for(int i=0;i<l;i++)
		M[i].resize(c);
}


#endif
