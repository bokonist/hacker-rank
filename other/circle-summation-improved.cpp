//https://www.hackerrank.com/challenges/circle-summation
#include "bits/stdc++.h"
using namespace std;
/* useful utility macros */
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define printArray(a,l,n) for(ll(i)=(l);(i)<ll(n);i++) { cout<<(a[i])<<' ';}
#define printWholeArray(a) for(ll(i)=0;(i)<ll((sizeof(a)/sizeof(a[0])));i++) { cout<<(a[i])<<' ';}
#define repeat(n) for(ll (i)=0;(i)<(ll)(n);++(i)) //repeat n times
#define repeatBounds(l,u) for(ll (i)=(ll)(l);(i)<(ll)(u);++(i)) //repeat lower to upperbound
#define until(x,val) for(ll(i) = ll(x); ll(x)!=ll(val); (i<val)?x++:x--) //until x becomes val through increment or decrement

/*some constants*/
static const long double PI = 3.142857143;
static const long mod = 1000000007; 

/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

ll RIGHT(ll i, ll sz)
{
	if(i== sz-1)
		 return 0; 
	else
		return i+1;
}
ll LEFT(ll i, ll sz)
{
	if(i==0)
		return (sz-1);
	else
		return (i-1);
}

class Matrix
{
	public:
		int n;
		Matrix(int n = 0)
		{
			this->n = n;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					data[i][j] = (int)(i == j);
		}
		Matrix (const Matrix& m)
		{
			n = m.n;
			memcpy(data, m.data, sizeof(data));
		}
		Matrix& operator = (const Matrix& m)
		{
			n = m.n;
			memcpy(data, m.data, sizeof(data));
			return *this;
		}
		Matrix operator * (const Matrix& m) const
		{
			Matrix ret(n);
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					ret.data[i][j] = 0;
					for (int k = 0; k < n; ++k)
					{
						ret.data[i][j] = (ret.data[i][j] + (long long)data[i][k] * m.data[k][j]) % mod;
					}
				}
			}
			return ret;
		}
		vector<int> operator * (const vector<int>& v) const
		{
			vector<int> ret(n, 0);
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					ret[i] = (ret[i] + (long long)v[j] * data[i][j]) % mod;
				}
			}
			return ret;
		}
		Matrix operator ^ (long long power) const
		{
			Matrix ret(n);
			Matrix cur(*this);
			while (power > 0)
			{
				if (power & 1)
					ret = ret * cur;
				power >>= 1;
				cur = cur * cur;
			}
			return ret;
		}

		void transform_for(int child_index)
		{
			memset(data, 0, sizeof(data));
			for (int i = 0; i < n; ++i)
			{
				if (i != child_index)
					data[i][i] = 1;
				else
					data[i][i] = data[i][(i - 1 + n) % n] = data[i][(i + 1) % n] = 1;
			}
		}
		int data[50][50];
};

void transform(vector<int> &v, int i)
{
	int n = v.size();
	v[i] = ((long long)v[i] + (long long)v[(i - 1 + n) % n] + v[(i + 1) %n]) % mod;
}
int main() 
{	
	int t;
	ip t;
	until(t,0)
	{
		int N, M;
		ip N>>M;

		vector<int> a(N);

		for (int i = 0; i < N; ++i)
			ip a[i];
		
		Matrix A(N);
		for (int i = 0; i < N; ++i)
		{
			Matrix B(N);
			B.transform_for(i);
			A = B * A;
		}
		int K = M - N - N;
		if (K >= N)
		{
			K /= N;
			A = A ^ K;
		}
		else
			K = 0;
		for (int first = 0; first < N; ++first)
		{
			vector<int> v = a;
			int curM = 0;
			for (int i = first; curM < M && i < N; ++i, ++curM)
				transform(v, i);
			if (curM + (K * N) <= M && K > 0)
			{
				v = A * v;
				curM += K * N;
			}
			for (int i = 0; curM < M; ++curM, ++i)
				transform(v, i % N);

			for (int i = 0; i < N; ++i)
			{
				printf("%d", v[i]);
				if (i < N - 1)
					printf(" ");
			}
			printf("\n");
		}
		if (t!=1)
			printf("\n");
	}
	return 0;	
}