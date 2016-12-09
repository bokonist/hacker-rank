// https://www.hackerrank.com/challenges/even-odd-query
/* author: github.com/bokonist */
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
int *a;
bool evaluatesToZero(int lb, int ub, int sz)
{
	if(lb>ub)
		return false;
	if(a[lb] == 0)
		return true;
	else if(evaluatesToZero(lb+1,ub, sz))
		return false;
	return false;
}
void OddOrEven(int lb, int ub, int sz)
{
	bool flag= evaluatesToZero(lb+1,ub,sz);
	if(flag)
		op "Odd\n";
	else if(a[lb]%2==0)
		op "Even\n";
	else
		op "Odd\n";
}
int main()
{
	int n,q,x,y,temp;
	ip n;
	a = new int[n];
	repeat(n)
	{
		ip temp;
		temp%=10;
		a[i]=temp;
	}
	ip q;
	while(q--)
	{
		ip x>>y;
		x--; y--;
		OddOrEven(x,y,n);
	}
	return 0;
}