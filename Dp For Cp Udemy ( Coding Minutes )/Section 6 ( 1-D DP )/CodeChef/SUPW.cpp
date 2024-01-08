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

vi dp;
int f(vi &arr, int i)
{
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];
    loop(j, 3, i - 1)
        dp[j] = min({dp[j - 1], dp[j - 2], dp[j - 3]}) + arr[j];
    return min({dp[i - 1], dp[i - 2], dp[i - 3]});
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    vi arr(t);
    dp.clear();
    dp.resize(t, -1);
    loop(i, 0, t - 1) cin >> arr[i];
    cout << f(arr, t) << "\n";

    return 0;
}
