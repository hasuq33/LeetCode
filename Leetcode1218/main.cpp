#include<iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            unordered_map<int, int> length;  // Dictionary to store the lengths of subsequences
            
            for (int num : arr) {
                if (length.find(num - difference) != length.end()) {
                    length[num] = 1 + length[num - difference];
                } else {
                    length[num] = 1;
                }
            }
            
            int max_length = 0;
            for (const auto& pair : length) {
                max_length = max(max_length, pair.second);
            }
            
            return max_length;
        }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> arr1 = {1, 2, 3, 4};
    int difference1 = 1;
    int longest1 = solution.longestSubsequence(arr1, difference1);
    cout << "Longest Subsequence: " << longest1 << endl;  // Output: 4

    // Example 2
    vector<int> arr2 = {1, 3, 5, 7};
    int difference2 = 1;
    int longest2 = solution.longestSubsequence(arr2, difference2);
    cout << "Longest Subsequence: " << longest2 << endl;  // Output: 1

    // Example 3
    vector<int> arr3 = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference3 = -2;
    int longest3 = solution.longestSubsequence(arr3, difference3);
    cout << "Longest Subsequence: " << longest3 << endl;  // Output: 4

    return 0;
}
