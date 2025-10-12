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
    int countBalls(int lowLimit, int highLimit)
    {
        string num1 = to_string(lowLimit), num2 = to_string(highLimit);
        int n = num2.size();
        num1.insert(num1.begin(), n - num1.size(), '0');
        vec dp(n, vec<int>(9 * n + 1, -1));
        auto dfs = [&](this auto &&dfs, int wei, int sum, bool limit_low, bool limit_high) -> int
        {
            if (sum < 0)
                return 0;
            if (wei == n)
                return sum == 0;
            if (!limit_low && !limit_high && dp[wei][sum] != -1)
                return dp[wei][sum];
            int lo = limit_low ? num1[wei] - '0' : 0;
            int hi = limit_high ? num2[wei] - '0' : 9;
            int res = 0;
            for (int i = lo; i <= hi; i++)
                res = (res + dfs(wei + 1, sum - i, limit_low && i == lo, limit_high && i == hi)) % mod;
            if (!limit_low && !limit_high)
                dp[wei][sum] = res;
            return res;
        };
        int ans = 0;
        for (int i = 1; i <= 9 * n; i++)
        {
            int cal = dfs(0, i, 1, 1);
            ans = max(ans, cal);
        }
        return ans;
    }
};
