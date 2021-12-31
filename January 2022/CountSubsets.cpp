#include <bits/stdc++.h>


using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define sz(v) (long long)(v).size()
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define ll long long

const int MAX_N = 1e3 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long 

#define disp(v) for(auto i:v)cout<<i<<" ";cout<<"\n";
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<'\n';
#define show(l) for(auto it = l.begin(); it != l.end(); it++)cout<<*it<<" ";cout<<"\n";
#define dispvp(v) for(auto i:v)cout<<i.first<<" "<<i.second<<endl;
#define dispv2(v) for(int i=0; i<(int)v.size(); i++){ db1(i);for(int j:v[i]) cout<<j<<" "; cout<<endl;}
#define dispp(x) cout<<(x).first<<" "<<(x).second<<"\n";
#define logarithm2(n) floor(log2((long double)n))
#define input(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define inputvp(v, n) for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
#define setBits(n) __builtin_popcountll(n)

int dp[MAX_N][MAX_N];

int CountSubset(vector<int> &a, int n, int sum)
{
	if(n == 0)
	{
		if(sum == 0)
			return 1;
		return 0;
	}

	if(dp[n][sum] != -1)
		return dp[n][sum];

	if(a[n-1] <= sum)
	{
		dp[n][sum] = (CountSubset(a, n-1, sum - a[n-1]) + CountSubset(a, n-1, sum));
	}
	else
	{
		dp[n][sum] = (CountSubset(a, n-1, sum));
	}

	return dp[n][sum];
}

void solve()
{
    vector<int> a = {0,0,0,0,0,0,0,0,1};
    int sum = 1, n = 9;

    
    for(int i=0; i<=n; i++)
    {
    	for(int j=0; j<=sum; j++)
    		dp[i][j] = -1;
    }
   cout<<CountSubset(a, n, sum);

    cout<<endl;

    //Iterative approach

    dp[0][0] = 1;

    
    for(int i=1; i<=n; i++){
    	
    	if(a[i-1] == 0)
    		dp[i][0] = dp[i-1][0]*2;
    	else
    		dp[i][0] = dp[i-1][0];
    }
    for(int j=1; j<=sum; j++)
    	dp[0][j] = 0;

    for(int i=1; i<=n; i++)
    {
    	for(int j=1; j<=sum; j++)
    	{
    		if(a[i-1] <= j)
    		{
    			dp[i][j] = dp[i-1][j - a[i-1]] + dp[i-1][j];
    		}
    		else
    		{
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }

    cout<<dp[n][sum]<<endl;

}

int32_t main()
{
    speed;
    int t = 1;
    //cin>>t;

    for(int tc = 1; tc <= t; tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
