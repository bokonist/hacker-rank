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
map<int, vector<int> > neighbours; //adjacency list for the graph
bool *visited;
int n;
int countNumberOfNodes(int src)
{
	visited[src]=true;
	vector<int> v = neighbours[src];
	int count = 0;
	for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
	{
		if(visited[ *it ] == false)
			count += countNumberOfNodes( *it );
		visited[ *it ]=true;
	}
	return count+1;
}
int main()
{
	int n,a,b;
	int n_i;
	ip n;
	ip n_i;
	visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i]=false;
	}
	until(n_i,0)
	{
		ip a>>b;
		neighbours[a].push_back(b);
		neighbours[b].push_back(a);
	}
	vector<int> population;
	int temp = n - neighbours.size();
	for (int i = 0; i < temp; ++i)
	{
		population.push_back(1);
	}
	ll numberOfWays=0;
	for (map<int, vector<int> >::iterator it = neighbours.begin(); it!= neighbours.end(); ++it)
	{
		if(!visited[it->first])
		{
			population.push_back(countNumberOfNodes(it->first));
		}
	}
	int n_trees= population.size();
	int suffixsum[n_trees] ,k=1;
	suffixsum[n_trees-1]=population.back();
	for (int k = 2; k <= n_trees; ++k)
	{
		suffixsum[n_trees-k]= suffixsum[n_trees-k+1]+population[n_trees-k];
	}
	numberOfWays=0;
	for (int i = 0; i+1 < n_trees; ++i)
	{
		numberOfWays += population[i]*suffixsum[i+1];
	}
	op numberOfWays;
	return 0;
}