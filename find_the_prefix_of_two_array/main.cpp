#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> C;
    set<int> seenA;
    set<int> seenB;

    for(int i=0; i<n;i++){
        seenA.insert(A[i]);
        seenB.insert(B[i]);

        int comman_count = 0;
        for(auto&elem: seenA){
            if(seenB.find(elem) != seenB.end()){
                ++comman_count;
            }
        }
        C.push_back(comman_count);
    }

    return C;
}

int main(){
    vector<int> A{1,3,2,4};
    vector<int> B{3,1,2,4};

    findThePrefixCommonArray(A,B);
}