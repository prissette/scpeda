// lexicographical_compare example
#include <iostream>
#include <vector>
using namespace std;

class matrix
{
	public :
			vector< vector<int> >M;
			vector<int>& operator[](int x) {return M[x];}
			void resize(int l,int c);
};


void matrix::resize(int l, int c)
{
	M.resize(l);
	
	for(int i=0;i<l;i++)
		M[i].resize(c);
}

int main(void)
{
matrix M;

M.resize(3,4);

for (int l=0;l<3;l++)
	for (int c=0;c<4;c++)
		M[l][c]=l*10+c;	

for (int l=0;l<3;l++)
	{
	for (int c=0;c<4;c++)
		cout << M[l][c]<< " ";
	cout << endl;	
	}
}
