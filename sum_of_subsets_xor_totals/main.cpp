#include<iostream>
#include<vector>
using namespace std;

int subsetXORSum(vector<int>&nums){
    int sum = 0;

    for(int i=0; i < (1 << nums.size()); i++){
        int subSetXor  = 0; 
        for(int j =0; j < nums.size(); j++){
                // Check if the j-th element is in the i-th subsets
                if( i &(1<<j )){
                    subSetXor ^= nums[j];
                }
        }
        sum += subSetXor;
    }

    return sum;
}

int main(){
    vector<int> nums{3,4,5,6,7,8};

    cout<<subsetXORSum(nums);
}