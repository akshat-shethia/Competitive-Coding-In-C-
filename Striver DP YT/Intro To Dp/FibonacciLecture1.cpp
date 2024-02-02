#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb emplace_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp map
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define arrinp(arr, a, b)            \
    for (int i = (a); i <= (b); i++) \
        cin >> (arr[i]);
#define print(a) cout << a << endl
#define pyes print("YES")
#define pno print("NO")
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
#define token(str, ch) (std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) { v.pb(t); } return v;)
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

int fREC(int n, vi &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fREC(n - 1, dp) + fREC(n - 2, dp);
}

int fITER(int n, vi &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    loop(i, 2, n - 1) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vi dp;
    dp.resize(t + 1, -1);
    print(fREC(t, dp));
    print(fITER(t, dp));
    return 0;
}
