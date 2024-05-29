#include<iostream>
#include<stdlib.h>
#include <string>

using namespace std;

int numSteps(string s){
    int l = s.length()-1;
    int carry = 0;
    int count = 0;

    while(l> 0){
        // even number with carry = 0. results even 
        if(s[l] - '0' + carry  ==0){
            carry = 0;
            count++;
            // odd number with carry =1 , result even 
        }else if(s[l] - '0' + carry == 2){
            carry =1 ; 
            count++;
            // Even number with carry =1 , result odd
            // odd number with carry  =0 result odd
        }else{
            carry = 1; 
            count+=2;
        }

        l--;
    }
    if(carry == 1) count++;
    return count;
}

int main(){
   cout << numSteps("1");
}