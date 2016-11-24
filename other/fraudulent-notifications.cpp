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

float median(vector<int> v, vector<int>::iterator begin, vector<int>::iterator end)
{
	vector<int> vec(begin,end);
	sort(vec.begin(), vec.end());
	/*for (auto it : vec)
	{
		op it<<' ';
	}
	nl*/
	int sz= vec.size();
	if(sz==1)
	{
		return *(vec.begin());
	}
	if(sz % 2 == 0)
	{
		return (float)(vec.at(sz/2) + vec.at(sz/2 -1))/(float)2;
	}
	else
	{
		return (vec.at(sz/2));
	}
}

int main()
{
	int n;
	ip n;
	int d,temp;
	ip d;
	vector<int> expend;
	float *medians =  new float[n];
	repeat(n)
	{
		ip temp;
		expend.push_back(temp);
		if(i>=d)
		{
			medians[i]=median(expend, expend.end()-d, expend.end());
		}
		else
		{
			medians[i]=median(expend, expend.begin(), expend.end());
		}
		//op medians[i]<<" | ";
	}
//	nl
	int notifications=0;
	for (int i = d; i < n; ++i)
	{
		if(expend[i] >= 2* medians[i-1])
			notifications++;
	}
	op notifications;
	return 0;
}