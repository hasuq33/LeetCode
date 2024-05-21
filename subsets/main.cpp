#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> substes(vector<int> &nums){
    vector<vector<int>> res;
    res.push_back({});
    for(int i=0; i < nums.size(); i++){
        int n = res.size();
        for(int j =0; j < n; j++){
            vector<int> subset = res[j];
            subset.push_back(nums[i]);
            res.push_back(subset);
        }
    }
    return res;
}

int main(){
    vector<int> nums{1,2,3};
    vector<vector<int>> subsets = substes(nums);

    for(vector<int> subset: subsets){
        for(int num: subset){
            cout<< num << " ";
        }
        cout<< endl;
    }
}