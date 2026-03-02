#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int s = flowerbed.size();
        if (s == 0)
        {
            return false;
        }
        if (s == 1)
        {
            return (flowerbed[0] == 0 && n == 1);
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            n--;
            flowerbed[0] = 1;
            if (n == 0)
                return true;
        }
        for (int i = 1; i < flowerbed.size() - 1; i++)
        {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 &&
                flowerbed[i + 1] == 0)
            {
                n--;
                flowerbed[i] = 1;
            }
        }
        if (flowerbed[s - 2] == 0 && flowerbed[s - 1] == 0)
        {
            n--;
            flowerbed[s - 1] = 1;
        }
        return n <= 0;
    }
};