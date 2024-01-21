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

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool cmp(int a, int b)
{
    return a > b;
}
int main(int argc, char const *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, m;
        cin >> n >> k;
        string s, ans = "";
        cin >> s;
        vector<bool> arr(n, false);
        bool flag = false;
        m = 0;
        for (int i = 0; i <= n - k; i++)
        {
            if ((flag && s[i] == '0') || (!flag && s[i] == '1'))
            {
                arr[i + k - 1] = true;
                flag = !flag;
            }
            ans += '0';
            if (arr[i])
                flag = !flag;
        }

        for (int i = s.size() - k + 1; i < s.size(); i++)
        {
            if (flag)
            {
                if (s[i] == '1')
                    ans += '0';
                else
                    ans += '1';
            }
            else
                ans += s[i];
            if (arr[i])
                flag = !flag;
        }
        cout << ans << endl;
    }
}