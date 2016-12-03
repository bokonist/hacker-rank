// https://www.hackerrank.com/contests/hourrank-15/challenges/an-interesting-game-1
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
bool desc (ll i,ll j) { return (i>j); }
int main()
{
	ll g;
	ip g;
	while(g--)
	{
		vector<ll> arr, sarr;
		ll n,temp;
		ip n;
		repeat(n)
		{
			ip temp;
			arr.push_back(temp);
		}
		ll moves=0;
		while(!arr.empty())
		{
			sarr=arr;
			sort(sarr.begin(),sarr.end(),desc);
			ll greatest=*sarr.begin(),count=0;
			//op greatest;nl
			for(vector<ll>::iterator it= arr.begin(); it!=arr.end(); ++it)
			{
				count++;
				if(*it == greatest)
				{
					arr.erase(it, arr.end());
					/*if(!arr.empty())
						for(auto a: arr)
						{
							op a<<' ';
						}
					nl*/
					moves++;
					break;
				}
			}
		}
		if(moves%2==0)
			op "ANDY";
		else
			op "BOB";
		nl
	}
	return 0;
}