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
bool isBeatiful(ll a[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		if(a[i]==a[i-1])
			return false;
	}
	return true;
}
void perm(ll A[], int k, int n)
{
	int temp=0;
	ll count=0;
	if(k==n)
		if (isBeatiful(A,n))
		{
			count++;
		}
	else
		for(int i=k;i<n;i++)
		{
			temp=A[k]; A[k]=A[i]; A[i]=temp;
			perm(A,k+1,n);
			temp=A[k]; A[k]=A[i]; A[i]=temp;
		}
	op count;
}
int main()
{
	ll q;
	ip q;
	while(q--)
	{
		ll n;
		ip n;
		ll A[n];
		repeat(n)
		{
			ip A[i];
		}
		perm(A,0,n);
	}
	return 0;
}