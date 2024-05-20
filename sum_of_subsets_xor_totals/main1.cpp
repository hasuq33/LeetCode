#include<iostream>
#include<vector>
using namespace std;


int helper(vector<int>&nums, int level, int currentXOR){
    // base consdition
    if (level == nums.size()) return currentXOR;
    // creating include
    int include = helper(nums, level+1, currentXOR^nums[level]);
    // creating exclude

    int exclude = helper(nums, level + 1, currentXOR);

    return include+exclude; 

}

int subsetXORSum(vector<int>& nums){
    return helper(nums, 0 , 0);
}

int main(){
    vector<int> nums{3,4,5,6,7,8};
    cout<<subsetXORSum(nums);
}
