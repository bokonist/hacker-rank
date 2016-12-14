// https://www.hackerrank.com/contests/101hack44/challenges/alice-and-bobs-silly-game
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
#define limit 100001
void removeMultiples(vector<bool> &isPrime, int n)
{
	int k=3,temp=n*2;
	while(temp<limit)
	{
		isPrime[temp]=false;
		temp = n*k;
		k++;
	}
}
int main()
{
	vector<bool> isPrime(limit,true);
	isPrime[0]= isPrime[1]=false;
	removeMultiples(isPrime,2);
	for (ll i = 3; i <= limit; i+=2)
	{
		if (isPrime[i])
		{
			removeMultiples(isPrime,i);
		}
	}
	int g;
	ip g;
	while(g--)
	{
		int n;
		ip n;
		int count=0;
		for (int i = 0; i <= n; ++i)
		{
			if(isPrime[i])
			{
			/*	op i;nl*/
				count++;
			}
		}
		if(count%2!=0)
			op "Alice\n";
		else
			op "Bob\n";
	}
	return 0;
}