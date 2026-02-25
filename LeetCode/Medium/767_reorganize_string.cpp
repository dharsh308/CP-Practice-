#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class compare
{
public:
    bool operator()(pair<int, char> a, pair<int, char> b)
    {
        return a.first < b.first;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, compare> pq;
        for (auto &p : freq)
        {
            pq.push({p.second, p.first});
        }
        string res = "";
        while (pq.size() >= 2)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            res += first.second;
            res += second.second;
            if (--first.first > 0)
                pq.push(first);
            if (--second.first > 0)
                pq.push(second);
        }
        while (!pq.empty())
        {
            if (pq.top().first > 1)
                return "";
            res += pq.top().second;
            pq.pop();
        }
        return res;
    }
};