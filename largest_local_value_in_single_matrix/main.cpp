#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid){
    int n = grid.size();
    vector<vector<int>> res(n-2,vector<int>(n-2));

    for(int i =1; i < n-1; ++i ){
        for(int j=1; j < n-1; ++j){
            int temp = 0;

            for(int k=i-1; k<= i+1; ++k){
                for(int l = j-1; l <= j+1; ++l){
                    temp= max(temp, grid[k][l]);
                }
            }
            res[i-1][j-1] = temp;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> grid{{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    largestLocal(grid);
}
