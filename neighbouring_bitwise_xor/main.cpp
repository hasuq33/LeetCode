#include<iostream>
#include <numeric>
#include<vector>
#include <functional>
using namespace std;

bool doesValidArrayExist(vector<int>& derived){
    return std::accumulate(derived.begin(),derived.end(),0,bit_xor<>{}) == 0;
}

int main(){
    vector<int>derived{1,1,0};
    cout << doesValidArrayExist(derived);
}