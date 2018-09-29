#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MOD 1000000007
# define INF 1000000000 //Floyd Warshall's Algo

#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
#define PI 2*acos(0.0)
#define MAX_HASH_RESERVE 10000001
//defines  
#define FILE_IO   freopen("in.txt","r",stdin); freopen("out.txt","w",stdout); 
#define sc1(a,type) type a; cin>>a;
#define sc2(a,b,type) type a,b; cin>>a>>b;
#define sc3(a, b, c,type) type a,b,c; cin>>a>>b>>c;
#define sc4(a, b, c, d,type) type a ,b,c,d; cin>>a>>b>>c>>d;
#define NL   cout<<"\n";
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
//cp3 macros----
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S)) // to get the value of the least significant on bit
#define setAll(S, n) (S = (1 << n) - 1) // sets all bits on till length n 
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (S && !(S & (S - 1))) // deals with zero
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define turnOnLastNbits(n) (n= ((n)^(n>>1) )) //
//----
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);
#define RE(i,b) for(int i=0;i<int(b);i++)
#define RE1(i,b) for(int i=1;i<=int(b);i++)
#define ALL(c) c.begin(), c.end() 
#define RALL(c) c.rbegin(),c.rend()
#define MPRESENT(container, element) (container.find(element) != container.end()) //for map,set..etc (returns true/false value)
#define VPRESENT(container, element) (find(ALL(container),element) != container.end()) //for vectors,strings,list,deque (returns true/false value)
//----
#define EB emplace_back
#define MP make_pair
#define PB push_back
#define PF push_front
#define INS insert
#define F first
#define S second
#define CLR clear()
#define SZ(x) ((int)x.size())
#define DT distance 
#define TEST(t) int t; cin>>t; while(t--)
#define csb(i) __builtin_popcount(i)
#define csbll(i) __builtin_popcountll(i)
#define clz(x) __builtin_clz(x)
#define clzll(x) __builtin_clzll(x)
#define cp(x) __builtin_parity(x)
#define ADV(v,num) advance(v,num)//used for lists and other structures that use iterators,when you can't access elements randomly ( iterator moves num positions)
#define MAX_SIZE 100000000
#define MAX_SIZE_IN_FUNCTION 100001
#define V2D(rowsize,colsize,type,name) vector<vector<type>> name(rowsize,vector<type>(colsize)); 
#define digits_in(i) (ll)log10(i)+1 // gives no of digits in a number 
#define SQR(x) (x)*(x)
#define UB upper_bound
#define LB lower_bound
#define LIM 6002
#define myname "CHIRANJEEV_THOMAS"
//typedefs
// typedef  __int128 SUPER_LL; // you cannot cin>> this, but can assign this to some cinend value( that's how you use it )
typedef string STR;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef priority_queue<int> PQI;
typedef vector<LL> VL;
typedef vector<PLL> VLL;
typedef vector<STR> VS;
typedef vector<char> VC;
typedef pair<int,int> PII;
typedef pair<STR,int> PSI;
typedef pair<int,STR> PIS; 
typedef vector<PII> VII;
typedef map<int,int> MII;
typedef map<LL,LL> MLL;
typedef map<STR,int> MSI;
typedef map<char,int> MCI;
typedef map<int,STR> MIS;
typedef set<STR> SS;
typedef set<char> SC;
typedef set<int> SI;
typedef set<LL> SLL;
typedef unordered_set<LL> USL;
typedef unordered_set<PLL> USLL;
typedef unordered_set<STR> USS;
typedef unordered_set<int> USI;
typedef unordered_set<PII> USII;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template <class T> T gcd (T a, T b) {  while (b) { T r = a % b; a = b; b = r; } return a; }
template <class T> T lcm (T a, T b) { return a / gcd (a, b) * b; }
template <class T> void vector_in(std::vector<T> & v,int n){ for(int i=0;i<n;i++){T temp;cin>>temp;v.push_back(temp);}}
//--- Templatised methods
inline double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
// int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
// template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

#define maxii 1000010
//-- code for suing SUPER_LL (128 bit int)  or 10^40--
std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
	std::ostream::sentry s( dest );
	if ( s ) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[ 128 ];
		char* d = std::end( buffer );
		do
		{
			-- d;
			*d = "0123456789"[ tmp % 10 ];
			tmp /= 10;
		} while ( tmp != 0 );
		if ( value < 0 ) {
			-- d;
			*d = '-';
		}
		int len = std::end( buffer ) - d;
		if ( dest.rdbuf()->sputn( d, len ) != len ) {
			dest.setstate( std::ios_base::badbit );
		}
	}
	return dest;
}
//-- end of code for using 128 bit int --
template<typename T>T extended_euclid(T a, T b, T &x, T &y){
T xx=0,yy=1;y=0;x=1;

while(b){
	T q=a/b,
	t=b;
	b=a%b;
	a=t;
	t=xx;
	xx=x-q*xx;
	x=t;
	t=yy;
	yy=y-q*yy;
	y=t;
}

return a;
}

LL fast_exp(LL base, LL exp,LL mod) {

	LL res=1;
	exp=(exp%MOD+MOD)%MOD;
	while(exp) {

		if(exp &1) res=(res*base)%mod;
		base=(base*base)%mod;
		exp>>=1;

	}
	return (res%mod+mod)%mod;
}


#ifndef ONLINE_JUDGE
	   #include "debug.h"
 #else
    #define debug(args...)                 
 #endif

int items;
int knapSackWeight;

int knapsackValue(int knapSackWeight,VI & value,VI & weight){
	int rowsize=items+1;
	int coulmnsize=knapSackWeight+1;


	int dp[rowsize][coulmnsize];

	memset(dp,0,sizeof(dp));

	for(int r=1;r<=items;r++)
		for( int c=1;c<=knapSackWeight;c++)
			dp[r][c]= max(dp[r-1][c],c>=weight[r]?value[r]+dp[r-1][c-weight[r]]:0);
		
		

		for(int i=1;i<=items;i++){
			
			for(int j=1;j<=knapSackWeight;j++){
				cout<<dp[i][j]<<" "; 
			}
			cout<<"\n";
		}

		return dp[items][knapSackWeight];
	}

	int main(){ FASTIO
    #ifndef ONLINE_JUDGE
		FILE_IO
 	#endif


		knapSackWeight=7;
		items =4 ;

		VI value(items+1);
		VI weight(knapSackWeight+1);

		value[1]=1;
		value[2]=4;
		value[3]=5;
		value[4]=7;

		weight[1]=1;
		weight[2]=3;
		weight[3]=4;
		weight[4]=5;

		cout<<knapsackValue(knapSackWeight,value,weight);

 	#ifndef ONLINE_JUDGE	
		cout<<"\n-------------\n"<<tick()<<" Seconds "<<"\n-------------";
 	#endif
		return 0;
	}






