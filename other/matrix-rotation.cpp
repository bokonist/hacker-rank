// https://www.hackerrank.com/challenges/matrix-rotation-algo
#include "bits/stdc++.h"
using namespace std;
/* useful utility macros */
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
#define printWholeArray(a) for(int(i)=0;(i)<int((sizeof(a)/sizeof(a[0])));i++) { cout<<(a[i])<<' ';}
#define repeat(n) for(int (i)=0;(i)<(int)(n);++(i)) //repeat n times
#define repeatBounds(l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i)) //repeat lower to upperbound
#define until(x,val) for(int(i) = int(x); int(x)!=int(val); (i<val)?x++:x--) //until x becomes val through increment or decrement

/*some constants*/
static const long double PI = 3.142857143;

/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline
void rotQueue(queue<int> &q , ll nr =0)
{
	nr= nr%q.size();
	int temp=0;
	while(nr--)
	{
		temp=q.front();
		q.pop();
		q.push(temp);
	}
}
int main()
{
	int m,n ,mt,nt;
	ll r;
	ip m>>n;
	mt=m; nt=n;
	ip r;
	int a;
//	op INT_MAX;
	(m>n)?a=n/2:a=m/2;
	int matrix[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ip matrix[i][j];
		}
	}
	queue<int> layers[150];
	int k=0,l=0,i,index=0;
    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
            layers[index].push(matrix[k][i]);
        }
        k++;
        for (i = k; i < m; ++i)
        {
            layers[index].push(matrix[i][n-1]);
        }
        n--;
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                layers[index].push(matrix[m-1][i]);
            }
            m--;
        }
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                layers[index].push(matrix[i][l]);
            }
            l++;    
        }
        index++;        
    }
    for (int i = 0; i < index; ++i)
    {
    	rotQueue(layers[i],r);
    }
    m=mt; n=nt;
    int finalMatrix[m][n];
    k=0; l=0; i; index=0;
    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
            finalMatrix[k][i]=layers[index].front();
            layers[index].pop();
        }
        k++;
        for (i = k; i < m; ++i)
        {
            finalMatrix[i][n-1] = layers[index].front();
            layers[index].pop();
        }
        n--;
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                finalMatrix[m-1][i] = layers[index].front();
            	layers[index].pop();
            }
            m--;
        }
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                finalMatrix[i][l] = layers[index].front();
            	layers[index].pop();
            }
            l++;    
        }
        index++;        
    }
	for (int i = 0; i < mt; ++i)
	{
		for (int j = 0; j < nt; ++j)
		{
			op finalMatrix[i][j]<<' ';
		}
		nl
	}
	return 0;
}