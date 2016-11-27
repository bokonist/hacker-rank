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
int xorinrange(string s,int lb, int ub)
{
	int sum=0;
	for (int i = lb; i <= ub; ++i)
	{
		sum+=s[i];
	}
	return sum%2;
}
int ctoi(char ch)
{
	return ch-48;
}
int main()
{
	int n,k;
	ip n>>k;
	string s;
	ip s;
	string ans;
	ans+=s[0];
	int ch, prevxor ,i ,j ,p,sum=0;
	prevxor= ctoi(s[0]);
	/*ans[0]=s[0];
	ans[1]=s[0]^s[1];
	ans[2]=s[0]^s[1]^s[2];*/
	for ( i = 1; i < k; ++i)
	{
		ch = ctoi(s[i]);
		ans += (prevxor ^ ch)+48;
		prevxor^= ctoi(ans[i]);
	}
	/*prevxor ^= ctoi(s[0]);
	int decryptbit=ctoi(ans[0]);
	ans+= (prevxor ^ ctoi(s[i]))+48; i++;*/
	for ( j=i ; j < (n-k)+i; ++j)
	{
		//op j<<"th index's bit is "<<j-k+1<<" to "<<j-1<<"xord ^ "<<s[j];nl
		/*ch = ctoi(s[j]);
		prevxor ^= ch;
		prevxor ^= decryptbit;

		ans+= (prevxor)+48;
		decryptbit = ctoi(ans[j-k]);*/
		ans+= ((xorinrange(ans,j-k+1,j-1)^ctoi(s[j])) +48 );
	}
	op ans;
	return 0;
}