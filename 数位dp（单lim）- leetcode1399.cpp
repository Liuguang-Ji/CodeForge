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
    int countLargestGroup(int nn)
    {
        string s = to_string(nn);
        int n = s.size();
        vec dp(n, vec<int>(9 * n + 1, -1));
        auto dfs = [&](this auto &&dfs, int wei, int left, bool lim) -> int
        {
            if (wei == n)
                return left == 0;
            if (!lim && dp[wei][left] != -1)
                return dp[wei][left];
            int ran = lim ? s[wei] - '0' : 9;
            int res = 0;
            for (int i = 0; i <= min(left, ran); i++)
                res += dfs(wei + 1, left - i, lim && i == ran);
            if (!lim)
                dp[wei][left] = res;
            return res;
        };
        int ans = 0, temp = 0;
        for (int i = 1; i <= 9 * n; i++)
        {
            int cal = dfs(0, i, 1);
            if (cal > temp)
                ans = 1, temp = cal;
            else if (cal == temp)
                ans++;
        }
        return ans;
    }
};