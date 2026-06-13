#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        unordered_map<int, int> freqA;
        unordered_map<int, int> freqB;
        int c=0;
        for (int i = 0; i < n; i++) {
            freqA[A[i]];
            freqB[B[i]];

            if (freqB.count(A[i]))
                c++;

            if (A[i] != B[i] && freqA.count(B[i]))
                c++;

            C[i] = c;
        }

        return C;
    }
};