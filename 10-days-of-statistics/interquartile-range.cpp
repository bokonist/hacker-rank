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
float quartilePoint(vector<int> &v, int l_bound=0, int u_bound=0)
{
	int size= u_bound - l_bound +1;
	if(!(size&1)) //even elements
	{
		return (float)(v.at(l_bound + size/2) + v.at( l_bound + size/2 -1))/(float)2;
	}
	else
	{
		return v.at(l_bound+ size/2);
	}

}
int main()
{
	int n,temp;
	ip n;
	vector<int> v,f,dataset;
	repeat(n)
	{
		ip temp;
		v.push_back(temp);
	}
	repeat(n)
	{
		ip temp;
		f.push_back(temp);
	}
	int n_dataset=0;
	repeat(n)
	{
		for (int j = 0; j < f[i]; ++j)
		{
			dataset.push_back(v[i]);
			n_dataset++;
		}
	}
	sort(dataset.begin(),dataset.end());
	if(n_dataset&1) //odd elements
	{
		op fixed<<setprecision(1)<<quartilePoint(dataset,n_dataset/2 +1 ,n_dataset-1) - quartilePoint(dataset,0,n_dataset/2 -1); 
	}
	else //even elements
	{
		op fixed<<setprecision(1)<<quartilePoint(dataset,n_dataset/2	,n_dataset-1) - quartilePoint(dataset,0,n_dataset/2 -1);
	}
	return 0;
}