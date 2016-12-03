// https://www.hackerrank.com/contests/w26/challenges/hard-homework
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

int main()
{
	ll n;
	ip n;
	ll x,y,z;
	double highest = sin(1)+sin(1)+sin(n-2); //base case
	for (x = 1; x < n-1; ++x)
	{
		double sx= sin(x);
		if(sx < highest - 2 )
			continue;
		else
		{
			for (y = 1 , z = n-x-1; y < n-x, z>=1 ; ++y, --z)
			{
				double sy= sin(y);
				if(sy+sx < highest - 1)
					continue;
				//	op x<<" "<<y<<" "<<z;nl
				double val= sx+sy+sin(z);
				if(val>highest)
				{
					highest=val;
				}
			}
		}	
	}
	op fixed<<setprecision(9)<<highest;
	return 0;
}