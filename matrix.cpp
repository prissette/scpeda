#include <iostream>
#include "matrix.h"
using namespace std;


int main(void)
{
matrix<int> M,M2;

M.resize(3,4);



for (int l=0;l<3;l++)
	for (int c=0;c<4;c++)
		M[l][c]=l*10+c;	

M2=M;
for (int l=0;l<3;l++)
	{
	for (int c=0;c<4;c++)
		cout << M2[l][c]<< " ";
	cout << endl;	
	}
}
