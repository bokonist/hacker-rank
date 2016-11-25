//https://www.hackerrank.com/challenges/coin-change
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
ll numberOfWaysToMakeChange(int coins[], int m , int dollars)
{

    ll numberOfWays[m+1][dollars+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=dollars;j++)
        {
            if(i==0) 
            	numberOfWays[i][j]=0;
            else if(j==0) 
            	numberOfWays[i][j]=1;
            else if(coins[i-1]>j)
                numberOfWays[i][j]=numberOfWays[i-1][j];           
            else
                numberOfWays[i][j]=numberOfWays[i-1][j]+numberOfWays[i][j-coins[i-1]];      
        }
    }
    return numberOfWays[m][dollars];
}
int main()
{
	int dollars,m;
    ip dollars>>m;
    int coins[m];
    for(int i=0;i<m;i++)
    {
        ip coins[i];
    }
    op numberOfWaysToMakeChange(coins,m,dollars);
    return 0;
}