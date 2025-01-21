#include<iostream>
#include<vector>
#include<climits>
#include <numeric>
#include<algorithm>
#include<math.h>
using namespace std;

long long gridGame(vector<vector<int>>& grid){
    int c=0;
    long long min_number = LLONG_MAX;
    long long row1_sum = accumulate(grid[0].begin(),grid[0].end(),0LL);
    long long row2_sum = 0;
    while(c<grid[0].size()){
        row1_sum -= grid[0][c];
        min_number = min(min_number , max(row1_sum,row2_sum));
        row2_sum += grid[1][c];
        ++c;
    }
    return min_number;
}

int main(){
    vector<vector<int>> grid{{1,3,1,15},{1,3,3,1}};
    cout << gridGame(grid);
    return 0;
}