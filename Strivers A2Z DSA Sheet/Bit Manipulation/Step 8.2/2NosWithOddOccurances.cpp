// link->https://www.codingninjas.com/studio/problems/two-numbers-with-odd-occurrences_8160466

vector<int> twoOddNum(vector<int> arr)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    vector<int> a;
    for (auto ele : mp)
    {
        int element = ele.first;
        int freq = ele.second;
        if (freq % 2 != 0)
            a.push_back(element);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    return a;
}