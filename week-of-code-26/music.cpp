// https://www.hackerrank.com/contests/w26/challenges/street-parade-1
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
	int n;
	ip n;
	ll a[n];
	vector<ll> distances;
	repeat(n)
	{
		ip a[i];
	}
	ll m,hmin,hmax,distsofar=0;
	ip m>>hmin>>hmax;
	ll startpoint=a[0] ,startindex=0,endindex=LONG_MAX;
	for (int i = 1; i < n; ++i)
	{
		ll diff=a[i]-a[i-1];
		if(diff < hmin  || diff > hmax)
		{
			startpoint=a[i];
			startindex=i;
			distsofar=0;
		}
		else if(distsofar < m)
		{
			distsofar+=diff;
			endindex=i;
		}
		if(distsofar==m)
			break;
	}
	if(distsofar<m)
	{
		ll disleft=m-distsofar; //always <= hmin+hmax
		if(startindex==0) //place the hmax block in infinity
		{
			startpoint-= (hmax<disleft)?hmax:disleft;
			disleft-=(hmax<disleft)?hmax:disleft;
			distsofar+=(disleft);
		}
		else if(endindex==n-1) //place the hmin block before the start. the hmax block can fuck off to infinity
		{
			startpoint-=(hmin<disleft)?hmin:disleft;
			distsofar+=disleft;
		}
		else //place it in either side
		{
			ll prev= a[startindex-1];
			ll next= a[endindex+1];

			if(prev < startpoint-((hmax<disleft)?hmax:disleft)) //hmax can be placed to the left
			{
				startpoint-=(hmax<disleft)?hmax:disleft; //place hmax before it
				disleft-=(hmax<disleft)?hmax:disleft;
				//after this, place hmin to the right. but we dont need to
			}
			else if(prev < startpoint-((hmin<disleft)?hmin:disleft)) //hmin can be placed to the left
			{
				startpoint-=(hmin<disleft)?hmin:disleft; //place hmin before it
				disleft-=(hmin<disleft)?hmin:disleft;
			}

		}

	}
	op startpoint;
	return 0;
}