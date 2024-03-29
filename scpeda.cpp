#include <iostream>
#include "matrix.h"
using namespace std;
#include <algorithm>
#include <stdlib.h>

// 20 warehouses, 15 customers
matrix<int> A(20,15);

// cost for opening each warehouse
vector<int> O(20);



// sum of costs of the opened warehouses, and a penality for each missing customer equals to the max cost for opening a warehouse
int fitness(matrix<int> A, vector<int>O, vector<int> X)
{
	
// calculate the penality only for the first call of the fitness function
static int penality=0;
if (penality==0)
	penality=*max_element(O.begin(),O.end());
//cout << "#penality" << penality << endl;

// sum of costs of the opened warehouses
int cost=0;

for (int i=0; i<O.size(); i++)
	cost+=O[i]*X[i];
//cout << "#cost" << cost << endl;

// number of missing customers
int missing=0;
for (int c=0; c<A.size_lines(); c++)
	{
	int missed=1;
	for (int w=0; w<A.size_rows(); w++)
		if (A[c][w]*X[w]) missed=0;

	if (missed)
		missing++;
	}
//cout << "#missing" << missing << endl;

// penalities for missing customers
	cost+=missing*penality;
//cout << "#cost" << cost << endl;

return cost;
}

int cmp_fitness(vector<int> V1, vector<int> V2)
{
	return fitness(A,O,V1)<fitness(A,O,V2);
}

//---------------------------------------------------------------------------------------------------
int main(void)
{
srand(time(NULL));	
	
// 20 warehouses, 15 customers
//matrix<int> A(20,15);
for (int i=0; i<20; i++)
	for (int j=0; j<15; j++)
		A[i][j]=rand()%2;
// trick : each customer must be linkable to at least 1 warehouse.
for (int j=0; j<15; j++)
		A[rand()%20][j]=1;


// cost for opening each warehouse
//vector<int> O(20);
for (int i=0; i<20; i++)
	O[i]=rand()%20+1;

// probability of opening each warehouse
vector<double> P(20);
for (int i=0; i<20; i++)
	P[i]=0.5;

/* ***********************
 *      THE BIG LOOP     *
 * ***********************/
for(;;)
{{
//--------------------------------------------------------
vector<int> X[1000];


for (int i=0; i<1000; i++)
	{
	X[i].resize(20);
	for (int j=0;j<20;j++)
		{
		X[i][j]=(rand()%1000000<P[j]*1000000)?1:0;
		cout << X[i][j];
		}
	cout << " " << fitness(A,O,X[i]) << endl;		
	}

// partial sort, keep the 10 best vectors
partial_sort(X,X+10,X+1000,cmp_fitness);
cout <<"-------------------------------------------"<<endl;

for (int i=0; i<10; i++)
	{
	for (int j=0;j<20;j++)
		{
		cout << X[i][j];
		}
	cout << " " << fitness(A,O,X[i]) << endl;		
	}


vector<double> P2(20);

for (int i=0; i<20; i++)
	{
	P2[i]=0;
	for(int j=0;j<10;j++)
		P2[i]+=X[j][i];
	P2[i]/=10;
	
	cout << P2[i] << " ";
	}

for (int i=0; i<20; i++)
	P[i]=0.9*P[i]+0.1*P2[i];
}}
	
}
