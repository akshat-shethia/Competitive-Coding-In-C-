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

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k; // n = no of elts , k = hamming distance
        vector<int> arr;
        loop(i, 0, n - 1)
        {
            int element;
            cin >> element;
            arr.pb(element);
        }
        ump<int, int> map;
        loop(i, 0, n - 1)
        {
            int temp = arr[i] & k;
            string s = to_string(temp);
            int count = 0;
            loop(j, 0, s.size() - 1)
            {
                if (s[j] == '0')
                    count++;
            }
            map[arr[i]] = count;
        }
        vector<pair<int, int>> v;
        for (auto ele : map)
        {
            int num = ele.first;
            int freq = ele.second;
            v.push_back({num, freq});
        }
        sort(v.begin(), v.end(), cmp);

        loop(i, 0, v.size() - 1)
        {
            cout << v[i].first << " ";
        }
        cout << "\n";
    }
    return 0;
}
