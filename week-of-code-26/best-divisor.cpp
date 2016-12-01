// https://www.hackerrank.com/contests/w26/challenges/best-divisor
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
int digitsum(int n)
{
	int sum=0;
	while(n>0)
	{
		sum+= n%10;
		n/=10;
	}
	return sum;
}
int main()
{	
	int n;
	ip n;
	std::vector<int> divisors;
	divisors.push_back(1);
	divisors.push_back(n);
	for (int i = 2; i <= n/2; ++i)
	{
		if(n%i==0)
		{
			op i;nl
			divisors.push_back(i);
		}
	}
	int highest=INT_MIN,x=INT_MAX,temp;
	for(auto a: divisors)
	{
		temp=digitsum(a);
		if(temp>=highest)
		{
			if(temp==highest)
			{
				if(a<x)
				{
					x=a;
				}
			}
			else
			{
				//op "sdasd "<<temp;nl
				highest= temp;
				x=a;
			}
		}
	}
	//op digitsum(12345);
	op x;
	return 0;
}