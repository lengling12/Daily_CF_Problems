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
