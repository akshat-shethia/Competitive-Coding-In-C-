// link->https://www.codingninjas.com/studio/problems/binary-search-trees_8160443

bool isValidBST(vector<int> &order)
{
    vector<int> v = order;
    sort(v.begin(), v.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    for (auto ele : mp)
    {
        int freq = ele.second;
        if (freq == 2)
            return false;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != order[i])
        {
            return false;
        }
    }
    return true;
}
