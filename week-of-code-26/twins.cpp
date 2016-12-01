// https://www.hackerrank.com/contests/w26/challenges/twins
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

//#define limit 1000001
vector<ll> listOfPrimes;
void removeMultiples(int mode, bool* isPrime, ll n , ll limit, ll a=0, ll b=0)
{
	if(mode==1)
	{
		ll temp=n*2;
		while(temp<=limit)
		{
			
			isPrime[temp]=false;
			temp +=n;
		}
	}
	else
	{
		ll startFrom=0;
		if(n<a) //the prime to be removed is not in the range
		{   
			if((a + a%n)%n ==0)
				startFrom= a%n;
			else if((a + n-a%n)%n==0)
				startFrom= n-a%n;
			ll temp= n;
			isPrime[startFrom]=false;
			while(temp<=limit)
			{
				isPrime[startFrom+temp]=false;
				temp += n;
			}
		}
		else //the prime to be removed is in the range
		{
			ll temp=n*2;
			while(temp<=limit)
			{	
				isPrime[temp]=false;
				temp +=n;
			}
		}
	}
}
int main()
{
	ll a,b;
	ip a>>b;
	ll count=0;
	ll size= floor(sqrt(b))+1;
	bool isPrime[size];
	memset(&isPrime,true,size);
	removeMultiples(1,isPrime,2,size);
	for (ll i = 3; i*i <= b; i+=2) //get all primes till sqrt(b)
	{
		removeMultiples(1,isPrime,i,size);
	}
	for (ll i = 2; i < size; ++i)
	{
		if(isPrime[i])
			listOfPrimes.push_back(i);
	}
	size= b-a+1;
	bool isPrime2[size];
	memset(&isPrime2,true,size);

	ll i=0,start=0;
	for (vector<ll>::iterator it= listOfPrimes.begin(); it!=listOfPrimes.end();++it)
	{
		removeMultiples(2,isPrime2,(*it),size,a,b);
	}
	if(a<3)
		isPrime2[0]=isPrime2[1]=false;
	count=0;
	for (ll i = 0; i+2 < size; ++i)
	{
		if(isPrime2[i] && isPrime2[i+2])
		{
			op i+a<<" and "<<i+2+a; nl
			count++;
		}
	}
	op count;
	return 0;
}