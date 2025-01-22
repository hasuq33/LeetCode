#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater){
    // 1 is Water Height it must be convert into 0
    int row = isWater.size();
    int col = isWater[0].size();
    vector<vector<int>> ans(row,vector<int>(col,row+col));

    // First pass: set water cells to 0 and propagate height from top-left to bottom-right
    for(int i=0; i < isWater.size(); i++){
        for(int j=0; j < isWater[0].size(); j++){
            if(isWater[i][j] == 1){
                ans[i][j] = 0; 
            }else{
                if(i>0){
                    ans[i][j] = min(ans[i][j], ans[i-1][j]+1);//Check from the TOP
                }
                if(j>0){
                    ans[i][j] = min(ans[i][j], ans[i][j-1]+1);// Check from the left
                }
            }
        }
    }

    // Second pass: propagate height from bottom-right to top-left
    for(int i = row -1; i >=0; i--){
        for(int j=col-1; j>=0; j--){
            if(i < row -1){
                ans[i][j] = min(ans[i][j],ans[i+1][j]+1); // Check from bottom
            }
            if(j < col-1){
                ans[i][j] = min(ans[i][j],ans[i][j+1]+1); //Check from right 
            }
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> isWater{{0,1},{0,0}};
    highestPeak(isWater);
    return 0;
}