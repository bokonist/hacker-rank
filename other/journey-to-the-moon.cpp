//https://www.hackerrank.com/challenges/journey-to-the-moon
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
int *source;
bool *visited;
int countNumberOfNodes(int src , int n)
{
	queue<int> q;
	q.push(src);
	int i,count=0;
	while(!q.empty())	
	{
		count++;
		i=q.front();
		q.pop();
		visited[i]=true;
		for (int j = 0; j < n; ++j)
		{
			if(source[j]==i && !visited[j])
				q.push(j);
		}
	}
	return count;
}
int main()
{
	int n,n_i,a,b;
	ip n;
	ip n_i;
	source = new int[n];
	visited = new bool[n];
	//memset(&visited,false,sizeof(n));
	for (int i = 0; i < n; ++i)
	{
		source[i]=-1;
		visited[i]=false;
	}
	until(n_i,0)
	{
		ip a>>b;
		source[b]=a;
	}
	int numberOfWays=1;
	for (int i = 0; i < n; ++i)
	{
		if(source[i]==-1) //root of some graph in the forest
			numberOfWays *=countNumberOfNodes(i,n);
	}
	op numberOfWays;
	return 0;
}