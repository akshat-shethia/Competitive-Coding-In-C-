#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compare intervals based on their start times
bool compareIntervals(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int mergeAndCountIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    // Base case: if there are no intervals or only one interval, return the count
    if (n <= 1) {
        return n;
    }

    // Sort intervals based on start times
    sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 1;  // Count of non-overlapping intervals
    int end = intervals[0][1];  // Initialize end with the end time of the first interval

    // Iterate through sorted intervals and merge overlapping intervals
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] > end) {
            // If the current interval doesn't overlap with the previous one
            count++;
            end = intervals[i][1];  // Update end with the end time of the current interval
        } else {
            // If the current interval overlaps with the previous one, merge them
            end = max(end, intervals[i][1]);
        }
    }

    return count;
}

int main() {
    // Test cases
    vector<vector<int>> intervals1 = {{1, 4}, {2, 3}, {5, 8}, {6, 9}};
    cout << mergeAndCountIntervals(intervals1) << endl;  // Output: 2

    vector<vector<int>> intervals2 = {{1, 5}, {3, 9}};
    cout << mergeAndCountIntervals(intervals2) << endl;  // Output: 1

    vector<vector<int>> intervals3 = {{1, 2, 3}};
    cout << mergeAndCountIntervals(intervals3) << endl;  // Output: 1

    return 0;
}
