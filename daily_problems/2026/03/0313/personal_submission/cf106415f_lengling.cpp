#include <bits/stdc++.h>
#define itn int
#define int long long
#define ind long double
#define yes cout << "Yes"
#define no cout << "No"
#define pii pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define pci pair<char, int>
#define re return;
#define rep(l, i, r) for (int i = l; i <= r; i++)
#define lep(r, i, l) for (int i = r; i >= l; i--)
using namespace std;
const int N = 4e5 + 10;
const int M = 2e3 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3f;
int x, y, t, n, z, k, m, sx, sy, u;
char ch1, ch2;
int fx, fy;
int num1, num2, num3, sum1, sum2, sum0, num;
multiset<int> st2, st1, st3;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // 上下左右
map<int, int> mp1, mp2, mp3;
map<int, int> mp;
string s1, s2, s3;
int a[N], b[N], c[N], d[N];
int maxn, minn, sum, ans, cnt;
vector<pii> e[N];
int fa[N];
void solve()
{
    cin >> n;
    map<int, int> mp;
    char ch;
    rep(1, i, n)
    {
        cin >> a[i];
    }
    auto ask = [&](int x, int y)
    {
        cout << "? " << x << ' ' << y << endl;
        char ch;
        cin >> ch >> num;
        return num;
    };
    auto w = [&](auto self, int n) -> int
    {
        if (mp.count(n))
            return mp[n];
        if ((n & (n - 1)) == 0)
        {
            int sum = ask(n, n);
            mp[n] = sum / 2;
            return mp[n];
        }

        x = (63 - __builtin_clzll(n)) + 1;
        int need = (1ull << x) - n;

        int need_val = self(self, need);

        mp[n] = ask(n, need) - need_val;

        return mp[n];
    };
    rep(1, i, n)
    {
        ans = w(w, a[i]);
        cout << "! " << ans << endl;
        cin >> ch;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    T = 1;

    /* cin >> T; */
    while (T--)
    {
        solve();
    }

    return 0;
}
