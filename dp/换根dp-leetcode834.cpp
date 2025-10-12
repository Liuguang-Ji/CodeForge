#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define vec vector
#define fir first
#define sec second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mxe max_element
#define mne min_element
#define ppc __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz // 二进制前导零的个数
#define pcs(n) cout << fixed << setprecision(n)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull;
typedef __int128_t lll;
const int mod = 1e9 + 7;
const int N = 100005;
const int inf = 2e9 + 10;
const int bs = 433;
class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vec<int> g[n], ans(n), sz(n, 1);
        for (auto &v : edges)
        {
            g[v[0]].pb(v[1]);
            g[v[1]].pb(v[0]);
        }
        auto dfs = [&](this auto &&dfs, int u, int fa, int dep) -> void
        {
            ans[0] += dep;
            for (auto v : g[u])
            {
                if (v == fa)
                    continue;
                dfs(v, u, dep + 1);
                sz[u] += sz[v];
            }
        };
        dfs(0, -1, 0);
        auto rer = [&](this auto &&rer, int u, int fa) -> void
        {
            for (auto v : g[u])
            {
                if (v == fa)
                    continue;
                ans[v] = ans[u] + n - 2 * sz[v];
                rer(v, u);
            }
        };
        rer(0, -1);
        return ans;
    }
};