#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<ll>

ll f(vi &A, vi &B, int n, ll sum, vector<vector<ll>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0 || sum < 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    ll Notpick = f(A, B, n - 1, sum, dp);
    ll pick = f(A, B, n - 1, sum ^ A[n - 1] ^ B[n - 1], dp);
    return dp[n][sum] = pick + Notpick;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll h;
        cin >> n >> h;
        vi A(n), B(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        for (int i = 0; i < n; ++i)
            cin >> B[i];
        vector<vector<ll>> dp(n, vector<ll>(h + 1, -1)); // Changed size of dp to n
        cout << f(A, B, n - 1, h, dp) << endl;           // Fixed the second parameter passed to f
    }
    return 0;
}
