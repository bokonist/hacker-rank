// https://www.hackerrank.com/contests/w26/challenges/taste-of-win
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
static const long long mod = 1000000007;
/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

set<ll> chosen;
ll cnt=0;
void checkxor()
{

	ll x=0;
	//op "checking set ";
	for(auto a: chosen)
	{
	//	op a<<' ';
		x=x^a;
	}
	//nl
	if(x!=0)
	{
		for(auto a: chosen)
		{
			op a<<' ';
		}
		cnt =(cnt+1)%mod;
	}
}
void perm(ll n, ll m)
{
	int temp=0;
	if(chosen.size()==n)
		checkxor();
	else
		for(int i=1;i<pow(2,m);i++)
		{
			if(chosen.count(i)==0)
			{
				chosen.insert(i);
				perm(n,m);
				chosen.erase(i);
			}
		}
}
int main()
{
	ll n,m;
	ip n>>m;
	perm(n,m);
	op cnt;
	return 0;
}