#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long total=mass;
        for(int i:asteroids){
            if(total>=i)total+=i;
            else{
                return false;
            }
        }
        return true;
    }
};