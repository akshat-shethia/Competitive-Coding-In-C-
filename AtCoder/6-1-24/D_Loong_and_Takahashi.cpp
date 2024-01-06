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

char intToChar(int num)
{
    return static_cast<char>('0' + num);
}

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    int v[n][n];

    int minc = 0, minr = 0, maxc = n - 1, maxr = n - 1, i = 1;

    while (i <= n * n)
    {
        for (int c = minc; c <= maxc; c++)
        {
            v[minr][c] = i++;
        }
        minr++;

        for (int r = minr; r <= maxr; r++)
        {
            v[r][maxc] = i++;
        }
        maxc--;

        for (int c = maxc; c >= minc; c--)
        {
            v[maxr][c] = i++;
        }
        maxr--;

        for (int r = maxr; r >= minr; r--)
        {
            v[r][minc] = i++;
        }
        minc++;
    }

    // Placing Takahashi at the center
    int center = n / 2;
    v[center][center] = -1; // Use a special value to mark the center

    // Output the matrix
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (v[r][c] == -1)
            {
                cout << 'T' << " ";
            }
            else
            {
                cout << v[r][c] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}