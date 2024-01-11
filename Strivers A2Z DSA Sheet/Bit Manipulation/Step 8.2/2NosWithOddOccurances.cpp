// link->https://www.codingninjas.com/studio/problems/two-numbers-with-odd-occurrences_8160466



// SOLUTION USING A HASHMAP
// vector<int> twoOddNum(vector<int> arr)
// {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         mp[arr[i]]++;
//     }
//     vector<int> a;
//     for (auto ele : mp)
//     {
//         int element = ele.first;
//         int freq = ele.second;
//         if (freq % 2 != 0)
//             a.push_back(element);
//     }
//     sort(a.begin(), a.end());
//     reverse(a.begin(), a.end());
//     return a;
// }


// SOLUTION USING BIT MANIPULATION
vector<int> twoOddNum(vector<int> arr) {
    int XorAns = 0;
    for (int i = 0; i < arr.size(); i++) {
        XorAns ^= arr[i];
    }

    int i = 0;
    while (true) {
        if (XorAns & (1 << i))
            break;
        i++;
    }

    vector<int> v;
    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] & (1 << i))
            v.push_back(arr[j]);
    }

    int a = 0;
    for (int j = 0; j < v.size(); j++) {
        a ^= v[j];
    }

    vector<int> ans;
    ans.push_back(a);

    int b = XorAns ^ a;
    ans.push_back(b);
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    return ans;
}