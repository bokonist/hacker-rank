// https://www.hackerrank.com/contests/101hack44/challenges/picking-numbers
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
int countabs(multiset<int> v, int key)
{
	int mx=0;
	int x= v.count(key-1);
	int y= v.count(key+1);
	int z= v.count(key);
	MAX(x+z,y+z,mx);
	return mx;
}
int main()
{
	int n,temp;
	ip n;
	multiset<int> a;
	for (int i = 0; i < n; ++i)
	{
		ip temp;
		a.insert(temp);
	}
	int highest=INT_MIN;
	for (auto it: a)
	{
		temp= countabs(a,it);
		if(temp>highest)
			highest=temp;
	}
	op highest;
	return 0;
}