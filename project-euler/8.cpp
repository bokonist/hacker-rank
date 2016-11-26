//https://projecteuler.net/problem=8
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
int ctoi(char ch)
{
	return ch-48;
}
inline unsigned long long prodK(string number, int start, int end)
{
    unsigned long long product=1;
    for (int j=start;j<end;j++){
        product*=ctoi(number[j]);
    }
    return product;
}

int main() 
{
    int T,N,K;
    string number;
    unsigned long long product,max;
    ip T;
    until(T,0)
    {
        ip N>>K;
        ip number;
        product=1;
        product=prodK(number,0,K);
        max=product;
        for (int l=K;l<N;l++)
        {
            if (ctoi(number[l-K])!=0)
            {
                product/=ctoi(number[l-K]);
                product*=ctoi(number[l]);
            }
            else
            {
                product=prodK(number,l-K+1,l+1);
            }
            max=(product>max)?product:max;
        }
        op max; nl
    }
    return 0;
}