#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int pop = 0;
        int res = 0;
        while (x != 0)
        {
            pop = x % 10;
            x /= 10;
            if (res > INT_MAX  / 10 || (res == INT_MAX / 10 && pop > 7))
                return 0;
            if (res < INT_MIN  / 10 || (res == INT_MIN / 10 && pop < -8))
                return 0;
            res = res * 10 + pop;
        }
        return res;
    }
};

int main()
{
    Solution test_class;
    int target = -21648;
    int result = test_class.reverse(target);
    cout << result << endl;
    getchar();
    return 0;
}
