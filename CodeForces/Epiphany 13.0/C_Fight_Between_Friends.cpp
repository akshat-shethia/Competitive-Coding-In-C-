#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<ll> alice(n), bob(m);
    for (ll &x : alice)
        cin >> x;
    for (ll &x : bob)
        cin >> x;

    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    ll sum1 = 0, sum2 = 0;
    for (ll x : alice)
        sum1 = (sum1 + lower_bound(bob.begin(), bob.end(), x) - bob.begin()) % mod;
    for (ll x : bob)
        sum2 = (sum2 + lower_bound(alice.begin(), alice.end(), x) - alice.begin()) % mod;

    cout << sum1 << " " << sum2 << endl;
}
