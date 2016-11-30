// https://www.hackerrank.com/challenges/2s-complement
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
ll closestPowerOfTwo(ll n)
{
	if(!n&(n-1))
		return n;
	n|=n>>1;
	n|=n>>2;
	n|=n>>4;
	n|=n>>8;
	n|=n>>16;
	return (n+1)>>1;
}
int noOfSetBits(int n)
{
	int count =0;
	while(n)
	{
		count++;
		n=n&(n-1);
	}
	return count;
}
ll whichPowerOfTwo(ll n)
{
	if(n==0)
		return 0;
	int i=0;
	while(! (n& 1<<i))
		i++;
	return i;
}
ll onesTill(ll n)
{
	ll y= closestPowerOfTwo(n);
	y=whichPowerOfTwo(y)+1; //get the number of columns to count ones
	ll count=0;
	ll a=1,b=2;
	for (ll i = 0; i < y; ++i)
	{
		count+= a*(n/b);
		if(n%b >= b/2)
			count+= (n%b - b/2 + 1);
		a*=2;
		b*=2;
	}
	return count;
}
bool isPowerOfTwo(int n)
{
	if(!n&(n-1))
		return true;
	return false;
}
ll onesNeg(ll b)
{
	if(b==0)
		return 0;
	ll count=0;
	count+= (32*(-b) - onesTill(-b-1));
	if(!isPowerOfTwo(-b+1))
		count;
	else if(isPowerOfTwo(-b+1))
		count+=((-b)-1);
	/*ll count=0;
	for (ll i = b; i < 0; ++i)
	{
		count+=noOfSetBits(i);
	}*/
	return count;
}
ll onesInRange(ll a,ll b)
{
	//int count=0;
	if(a>=0)
	{
		//op "all pos";nl
		return onesTill(b) - onesTill(a) + noOfSetBits(a);
	}
	else
	{
		if(b>=0) //pos and negative
		{
			//op "pos and neg";nl
			return onesNeg(a) + onesTill(b);

		} //both are negative
		else
		{
			//op"all neg";nl
			return onesNeg(a) - onesNeg(b) + noOfSetBits(b);
		}
	}
}
int main()
{
	int t;
	ip t;
	while(t--)
	{
		ll a,b;
		ll count=0;
		ip a>>b;
		op onesInRange(a,b); nl
	}
	/*
	op bitset<32>(-1);nl
	op bitset<32>(-2);nl
	op bitset<32>(-3);nl
	op bitset<32>(-4);nl
	op bitset<32>(-5);nl
	op bitset<32>(-6);nl
	op bitset<32>(-7);nl
	op bitset<32>(-8);nl
	op bitset<32>(-9);nl
	op bitset<32>(-10);nl
	op bitset<32>(-11);nl
	op onesNeg(-1);nl
	op onesNeg(-2);nl
	op onesNeg(-3);nl
	op onesNeg(-4);nl
	op onesNeg(-5);nl
	op onesNeg(-6);nl
	op onesNeg(-7);nl
	op onesNeg(-8);nl
	op onesNeg(-9);nl
	op onesNeg(-10);nl
	op onesTill(15); nl
	op onesNeg(-3);nl
	op onesInRange(-3,15);nl
	//op INT_MIN;nl
	op onesTill(15)<<' '<<onesTill(16)<<' '<<onesTill(17)<<' '<<onesTill(18)<<' '<<onesTill(19)<<' '<<onesTill(20)<<' ';
	//op closestPowerOfTwo(18);*/
	return 0;
}