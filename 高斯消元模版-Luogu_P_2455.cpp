#include <bits/stdc++.h>
using namespace std;
#define int long long
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
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define pcs(n) cout << fixed << setprecision(n)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull;
typedef __int128_t lll;
const int mod = 998244353;
const int N = 200005;
const int inf = 0x3f3f3f3f3f3f3f;
const int bs = 433;
const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
const double eps = 1e-8;

// 高斯消元法解线性方程组
int gauss(vector<vector<double>> &a)
{
    int n = a.size();
    int c, r;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;
        // 找到当前列绝对值最大的行
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        if (fabs(a[t][c]) < eps)
            continue;

        // 将绝对值最大的行换到最顶端
        for (int i = c; i <= n; i++)
            swap(a[t][i], a[r][i]);

        // 将当前行的首位变成1
        for (int i = n; i >= c; i--)
            a[r][i] /= a[r][c];

        // 用当前行将下面所有的列消成0
        for (int i = r + 1; i < n; i++)
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
        r++;
    }
    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return -1; // 无解
        return 0;          // 无穷多解
    }
    // 回代求解
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[i][j] * a[j][n];
    return 1; // 有唯一解
}

void Thirstarfish()
{
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];
    int res = gauss(a);
    if (res == -1)
        cout << -1 << endl;
    else if (res == 0)
        cout << 0 << endl;
    else
    {
        pcs(2);
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << "=" << a[i][n] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _; // 如果是单测记得注释掉这一行
    while (_--)
        Thirstarfish();
    return 0;
}