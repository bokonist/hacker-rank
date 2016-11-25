//https://www.hackerrank.com/challenges/even-tree
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
int numberOfChanges=0;
int numberOfCuts=0;
queue<int> rootlist;
int countNumberOfChildren(int node , int src)
{
	//visited[src]=true;
	vector<int> v = neighbours[node];
	vector<int>::iterator it = find(v.begin(), v.end(), src);
	if(it != v.end())
		v.erase( it);
	if(v.empty())
		return 0;
	int count = 1;
	for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
	{
			count += countNumberOfChildren( *it , node);
	}
	return count;
}
void removeEdge(int src, int des)
{
	vector<int>::iterator it = find(neighbours[src].begin(), neighbours[src].end(), des);
	if(it != neighbours[src].end())
				neighbours[src].erase(it);
	it = find(neighbours[des].begin(), neighbours[des].end(), src);
	if(it != neighbours[des].end())
				neighbours[des].erase(it);
}
void cutEvenChildren(int node, int src)
{
	vector<int> v = neighbours[node];
	vector<int>::iterator it1 = find(v.begin(), v.end(), src);
	if(it1 != v.end())
		v.erase( it1);
	int temp;
	for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
	{
		temp = *it;
		if(countNumberOfChildren(temp, node)%2==0)
		{

			removeEdge(temp,node);
			numberOfCuts++;
			rootlist.push(temp);
		}
	}
}
int main()
{
	int n,e,a,b;
	int n_i;
	ip n;
	ip e;
	visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i]=false;
	}
	until(e,0)
	{
		ip a>>b;
		neighbours[a].push_back(b);
		neighbours[b].push_back(a);
	}
	int x;
	rootlist.push(1);
	while(!rootlist.empty())
	{
		x= rootlist.front();
		rootlist.pop();
		cutEvenChildren(x,-1);
	}
	op numberOfCuts;
	return 0;
}