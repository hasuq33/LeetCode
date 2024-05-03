#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMaxK(vector<int>& nums) {
        // Sorting is done
        sort(nums.begin(), nums.end());
        for(int i =0; i < nums.size();i++){
            if(nums[i] >= 0){
                break;
            }
            for(int j=nums.size()-1; j >=0; j--){
                if(nums[j] == -nums[i]){
                    return nums[j];
                }
            }
        }

        return -1; 
}

int main(){
    vector<int> nums{-1,10,6,7,-7,1};
    cout<<findMaxK(nums);
}