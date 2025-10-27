//模板https://www.luogu.com.cn/problem/P4777
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2e5 + 10;
const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[N], b[N];

ll fmul(ll a, ll b, ll mod)
{
    ll ret = 0;
    while(b)
    {
        if(b & 1)
            ret = (ret + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ret;
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll exCRT(ll n)
{
    ll ret = 0;
    ll M = 1;
    for(int i = 1; i <= n; ++i)
    {
        ll c = b[i] - ret;
        ll x, y;
        ll d = exgcd(M, a[i], x, y);
        if(abs(b[i] - ret) % d)
            return -1;
        c = (c % a[i] + a[i]) % a[i];
        x = fmul(x, c / d, a[i] / d);
        x = (x % (a[i] / d) + (a[i] / d)) % (a[i] / d);
        ll tmp = M * (a[i] / d);
        ret = (ret + fmul(M, x, tmp)) % tmp;
        M = tmp;
    }
    return ret;
}
void solve()
{
    ll n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    ll ans = exCRT(n);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)
        solve();
    return 0;
}