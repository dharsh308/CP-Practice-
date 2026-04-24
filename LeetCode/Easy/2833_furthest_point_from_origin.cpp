#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dist=0;
        int space=0;
        for(char i:moves){
            if(i=='L')dist-=1;
            else if(i=='R')dist+=1;
            else{
                space++;
            }
        }
        
        return abs(dist)+space;
    }
};