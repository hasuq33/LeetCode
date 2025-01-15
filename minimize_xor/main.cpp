#include<iostream>
using namespace std; 

int minimizeXor(int num1, int num2) {
    int a = __builtin_popcount(num1); //This function is used to count the number of set bits in an unsigned 
    // integer. In other words, it counts the number of 1’s in the binary form of a positive integer.
    int b = __builtin_popcount(num2);
    int res = num1; 

    for(int i=0; i < 32; ++i){
        if(a>b && (1 << i) & num1){
            
            res ^= 1 << i;
            --a;
        }
        if(a < b && !((1 << i) &num1)){
            res ^= 1 << i; 
            ++a;
        }
    }

    return res;
}

int main(){
    int num1 = 3; 
    int num2 = 5;

    cout << minimizeXor(num1, num2) << endl;
}