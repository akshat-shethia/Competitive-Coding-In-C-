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
bool cmp(int a, int b)
{
    return a > b;
}

string trim(const string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");

    if (start == string::npos || end == string::npos)
    {
        return "";
    }

    return s.substr(start, end - start + 1);
}
int main(int argc, char const *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin.ignore();
        cin >> s;
        string ans = "";
        int plus = 0;
        int minus = 0;
        string final = "";
        loop(i, 0, n - 1)
        {
            if (s[i] == '+')
                plus++;
            else if (s[i] == '-')
                minus++;
            else
                ans += (s[i]);
        }
        sort(ans.begin(), ans.end());
        int i = 0;
        while (plus != 0 || minus != 0)
        {
            if (minus != 0)
            {
                final += ans[i];
                final += '-';
                i++;
                minus--;
            }
            else
            {
                final += ans[i];
                final += '+';
                i++;
                plus--;
            }
        }
        while (i < ans.size())
        {
            final += ans[i];
            i++;
        }
        reverse(final.begin(), final.end());
        cout << trim(final) << endl;
    }

    return 0;
}