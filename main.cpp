#include <iostream>
#include <c++/cstring>
#include <c++/cmath>
#include <time.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n > 2) {
            int nums[n / 2];
            int pCount = 0, p;
            nums[0] = 2;
            pCount++;

            for (int i = 3; i < n; i++) {
                p = pCount;
                while (p-- > 0) {
                    if (i % nums[p] == 0) {
                        p = 4;
                        break;
                    }
                }
                if (p <= 0) {
                    nums[pCount] = i;
                    pCount++;
                }
            }
            return pCount;
        } else return 0;

    }

    int betterCountPrimes(int n) {
        if (n < 3)
            return 0;
        bool nums[n];
        memset(nums, 0, (sizeof(bool)) * n);
        int len = sqrt(n);
        for (int i = 2; i <= len; i++) {
            if (nums[i] == 1)
                continue;
            int j = 2, value = i * j;
            for (; value < n; j++) {
                nums[value] = 1;
                value = i * j;
            }
        }
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (!nums[i])
                ans++;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 3;
//    cin>>n;
    Solution s;
    clock_t start, end;

    start = clock();
    cout << "\n Ans: " << s.countPrimes(n) << endl;
    end = clock();
    cout << end - start << endl;

    start = clock();
    cout << "\n Ans: " << s.betterCountPrimes(n) << endl;
    end = clock();
    cout << end - start << endl;

    return 0;
}