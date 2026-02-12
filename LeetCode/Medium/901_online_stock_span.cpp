#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<int> stockPrice;
    stack<int> res;
    StockSpanner() {}

    int next(int price) {
        int count = 1;
        while (!stockPrice.empty() && price >= stockPrice.top()) {
            stockPrice.pop();
            count += res.top();
            res.pop();
        }
        stockPrice.push(price);
        res.push(count);
        return count;
    }
};