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
#define ctz __builtin_ctz
#define clz __builtin_clz // 二进制前导零的个数
#define pcs(n) cout << fixed << setprecision(n)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull;
typedef __int128_t lll;
const int mod = 998244353;
const int N = 200005;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int bs = 433;
const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
vector<pair<int, long long>> g[N];
long long dis[N];
int n, m, s;

void dijkstra(int s)
{
    bool vis[N];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    pii a(dis[s], s);
    q.push(a);
    while (!q.empty())
    {
        pii u = q.top();
        q.pop();
        if (vis[u.sec])
            continue;
        vis[u.sec] = 1;
        for (auto y : g[u.sec])
        {
            if (vis[y.fir])
                continue;
            if (dis[y.fir] > y.sec + u.fir)
            {
                dis[y.fir] = y.sec + u.fir;
                pii b(dis[y.fir], y.fir);
                q.push(b);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}