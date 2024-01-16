#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll noOfMessages, intialCharge, chargePerHour, chargeIfStopped;
        cin >> noOfMessages >> intialCharge >> chargePerHour >> chargeIfStopped;
        ll x = 0, prev = 0;
        for (int i = 0; i < noOfMessages; i++)
        {
            cin >> x;
            intialCharge -= min(chargeIfStopped, chargePerHour * abs(x - prev));
            prev = x;
        }
        if (intialCharge > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}