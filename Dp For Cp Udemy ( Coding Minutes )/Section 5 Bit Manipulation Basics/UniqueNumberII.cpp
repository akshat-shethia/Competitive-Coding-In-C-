#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 1, 2, 3, 4, 4, 5, 5};
    int XorAns = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        XorAns ^= arr[i];
    }
    int i = 0;
    while (true)
    {
        if (XorAns & (1 << i))
            break;
        i++;
    }
    vector<int> v;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] & (1 << i))
            v.push_back(arr[j]);
    }
    int a = 0;
    for (int j = 0; j < v.size(); j++)
    {
        a ^= v[j];
    }
    cout << a << endl;
    int b = XorAns ^ a;
    cout << b << endl;
}