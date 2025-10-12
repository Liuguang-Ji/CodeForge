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
vector<int> calc_z(const string &s)
{
    int n = s.size();
    vector<int> z(n);
    int box_l = 0, box_r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= box_r)
            z[i] = min(z[i - box_l], box_r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            box_l = i;
            box_r = i + z[i];
            z[i]++;
        }
    }
    z[0] = n;
    return z;
}
