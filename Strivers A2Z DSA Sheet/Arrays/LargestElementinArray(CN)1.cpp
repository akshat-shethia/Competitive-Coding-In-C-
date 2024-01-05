// Link -> https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

#include <bits/stdc++.h>
int largestElement(vector<int> &arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
