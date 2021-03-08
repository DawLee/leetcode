#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int len = nums.size();
        int tmp = 0;
        int flag = false;
        for (int i = 0; i < len; ++i)
        {
            tmp = abs(nums[i]);
            if (nums[tmp] > 0)
            {
                nums[tmp] *= -1;
            }
            if (tmp = 0)
            {
                if (flag)
                {
                    return 0;
                }
                else
                {
                    flag = true;
                }
            }
        }
    }
};

int main()
{
    Solution test_class;
    string s = "()(()";
    int res = test_class.findRepeatNumber(s);
    cout << res << endl;

    getchar();
    return 0;
}