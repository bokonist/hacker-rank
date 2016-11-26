//https://projecteuler.net/problem=1
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
	ll t,n;
	ll totalSum=0;
	ip t;
	until(t,0)
	{
		ip n;
		ll n5=n/5; //number of terms in ap till 1000
		ll n3=n/3;
		if(n%5==0)
			n5--;
		else if(n%3==0)
			n3--;
		ll n15= n/15; //15 is the lcm of 3 and 5
		/*if(n%15==0)
			n15--;*/
		ll a_n5 = 5+ (n5-1)*5; //n'th term of AP
		ll a_n3 = 3+ (n3-1)*3;
		ll a_n15= 15+ (n15-1)*15;
		ll sum_n5 = n5*(5+a_n5)/2; //sum to n terms of AP
		ll sum_n3 = n3*(3+a_n3)/2;
		ll sum_n15 = n15*(15+a_n15)/2;
		totalSum = sum_n5 + sum_n3 - sum_n15; //total sum = sum of multiples of 3 and 5 - sum of common multiples
		op totalSum; nl
		totalSum=0;
	}
	return 0;
}	