// link->https://www.codingninjas.com/studio/problems/check-whether-k-th-bit-is-set-or-not_5026446

#include <bits/stdc++.h>
using namespace std;

bool kthBitSet(int n, int k)
{
    int mask = (1 << k - 1);
    return (n & mask);
}

bool isKthBitSet(int n, int k)
{
    return kthBitSet(n, k);
}
