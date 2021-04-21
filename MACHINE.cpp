#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

long n;
long dp[MAX] = {0}, s[MAX]={0}, t[MAX]={0};
long ans = -1;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n;
    for (long i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
    }

    for (long i = 1; i <= n; i ++) {
        dp[t[i]] = max(dp[t[i]], t[i] - s[i]);
    }
    for (long i = 1; i <= n; i ++) {
        cout << dp[t[i]] << " ";
    }return 0;



    for (long i = 1; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i]);
    }

    for (long i = 1; i <= n; i++) {
        if (dp[s[i] - 1] > 0) {
            ans = max(ans, dp[s[i] - 1] + t[i] - s[i]);
        }
    }

    cout << ans;
    return 0;
}