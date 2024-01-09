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

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// link->https://www.spoj.com/problems/ACODE/
vi dp;
int f(string &s, int i)
{
    if (i == s.size())
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int ans = 0;
    if (s[i] >= '1')
        ans += f(s, i + 1);
    if (i + 1 < s.size() && s[i] == '1')
        ans += f(s, i + 2);
    if (i + 1 < s.size() && s[i] == '2' && s[i + 1] <= '6')
        ans += f(s, i + 2);
    return dp[i] = ans;
}
int main(int argc, char const *argv[])
{
    string s;
    while (1)
    {
        dp.clear();
        dp.resize(10005, -1);
        cin >> s;
        if (s[0] == '0')
            break;
        cout << f(s, 0) << "\n";
    }
    return 0;
}