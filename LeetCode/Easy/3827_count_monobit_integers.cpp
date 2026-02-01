#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countMonobit(int n)
    {
        int num = 0;
        int count = 0;
        while (num <= n)
        {
            count++;
            num = (num << 1) | 1;
        }
        return count;
    }
};