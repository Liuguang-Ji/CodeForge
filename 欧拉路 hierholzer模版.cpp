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
const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &t)
    {
        unordered_map<string, priority_queue<string, vec<string>, greater<string>>> mp;
        vec<string> st;
        auto dfs = [&](this auto &&dfs, string cur) -> void
        {
            while (mp.count(cur) && mp[cur].size() > 0)
            {
                string temp = mp[cur].top();
                mp[cur].pop();
                dfs(temp);
            }
            st.pb(cur);
        };
        for (auto &it : t)
            mp[it[0]].push(it[1]);
        dfs("JFK");
        ranges::reverse(st);
        return st;
    }
};
