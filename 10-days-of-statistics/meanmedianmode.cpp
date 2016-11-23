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
	ll n,sum=0,temp;
	vector<int> v;
	cin>>n;
	repeat(n)
	{
		ip temp;
		v.push_back(temp);
		sum+= temp;
	}
	//op "sum is"<<sum; nl
	float mean, median;
	int mode;
	mean= (float)sum/(float)n;
	sort(v.begin(),v.end());
	if(n&1)// odd elements
	{	

		median = *(v.begin() + n/2);
	}
	else
		median= (float)(*(v.begin()+ n/2) + *(v.begin()+ n/2 -1))/(float)2;
	int freqCount=0,highest=-1;
	mode = v[0];
	for (vector<int>::iterator it=v.begin(); it != v.end()-1; ++it)
	{
		if(*it == *(it+1))
			freqCount++;
		else //new element range
		{
			if(freqCount>highest)
			{
				highest=freqCount;
				mode= *it;
			}
            freqCount=0;
		}

	}
	op fixed<<setprecision(1)<<mean; nl
	op fixed<<setprecision(1)<<median; nl
	op mode; nl
	

	return 0;
}