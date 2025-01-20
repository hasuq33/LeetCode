#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
     int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>> positionMap;
        vector<int> rowCount(rows, cols), colCount(cols, rows);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                positionMap[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            pair<int , int> position = positionMap[val];
            int row = position.first; 
            int col = position.second;

            if (--rowCount[row] == 0 || --colCount[col] == 0) {
                return i;
            }
        }

        return -1;
}

int main() {
    vector<int> arr{2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat{{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    cout << firstCompleteIndex(arr, mat);
    return 0;
}
