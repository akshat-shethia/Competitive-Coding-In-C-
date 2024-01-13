#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        unordered_map<char, int> frequency;

        // Count character frequencies
        for (int i = 0; i < n; ++i) {
            frequency[s[i]]++;
        }

        int oddCount = 0;

        // Count characters with odd frequencies
        for (auto& ele : frequency) {
            if (ele.second % 2 != 0) {
                oddCount++;
            }
        }

        // Calculate minimum cost
        int minCost = max(0, oddCount - 1);

        cout << minCost << endl;  // Print the minimum cost
    }

    return 0;
}
