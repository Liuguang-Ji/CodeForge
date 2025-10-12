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
// 在文本串 txt 中查找模式串 ptn，返回所有成功匹配的位置（ptn[0] 在 txt 中的下标）
vector<int> kmp(const string &txt, const string &ptn)
{
    int n = ptn.size();
    vector<int> pi(n);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        char b = ptn[i];
        while (cnt && ptn[cnt] != b)
            cnt = pi[cnt - 1];
        if (ptn[cnt] == b)
            cnt++;
        pi[i] = cnt;
    }

    vector<int> pos;
    cnt = 0;
    for (int i = 0; i < txt.size(); i++)
    {
        char b = txt[i];
        while (cnt && ptn[cnt] != b)
            cnt = pi[cnt - 1];
        if (ptn[cnt] == b)
            cnt++;
        if (cnt == n)
        {
            pos.pb(i - n + 1);
            cnt = pi[cnt - 1];
        }
    }
    return pos;
}
