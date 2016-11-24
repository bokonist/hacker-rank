//https://www.hackerrank.com/challenges/circle-summation
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
static const long modval = 1000000007; 

/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

int RIGHT(int i, int sz)
{
	if(i== sz-1)
		 return 0; 
	else
		return i+1;
}
int LEFT(int i, int sz)
{
	if(i==0)
		return (sz-1);
	else
		return (i-1);
}
void restore(int* src, int* dest, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		dest[i]=src[i];
	}
}
int main()
{
	int t,n,m, *a,*arr,temp ;
	ip t;
	until(t,0)
	{
		ip n;
		a = new int[n];
		arr= new int[n];
		ip m;
		repeat(n)
		{
			ip a[i];
			arr[i]=a[i];
		}
		for (int starter = 0; starter < n; ++starter)
		{
			int lp=0;
			for (int i = starter; lp < m; ++i ,++lp)
			{
				i=i%n;
				arr[i] = (arr[i]+arr[LEFT(i,n)]+arr[RIGHT(i,n)])%modval; 
			}
			printArray(arr,0,n); nl
			restore(a,arr,n);
		}
		//delete a;
		//delete arr;
		if(t!=1)
			nl
	}
	return 0;
}