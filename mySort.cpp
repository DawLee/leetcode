#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 冒泡排序
void bubble_sort(vector<int> &nums) {
    bool swaped = false;
    int len = nums.size();
    for (int i = len - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                swaped = true;
            }
        }
        if (!swaped) {
            return;
        }
        swaped = false;
    }
}

// 选择排序
void selection_sort(vector<int> &nums) {
    int len = nums.size();
    int index = 0;
    for (int i = 0; i < len; ++i) {
        index = i;
        for (int j = i; j < len; ++j) {
            index = nums[index] < nums[j] ? index : j;
        }
        swap(nums[index], nums[i]);
    }
}

// 插入排序
void insertion_sort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            swap(nums[j], nums[j - 1]);
        }
    }
}

// 希尔排序
void shell_sort(vector<int> &nums) {
    int len = nums.size();
    int h = 1;
    while (h < len / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < len; ++i) {
            for (int j = i; j >= h && nums[j] < nums[j - h]; j -= h) {
                swap(nums[j], nums[j - h]);
            }
        }
        h /= 3;
    }
}

// 并归排序
void merge_sort(vector<int> &nums, int left, int right, vector<int> &temp) {
    if (left + 1 >= right) {
        return;
    }
    // divide
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid, temp);
    merge_sort(nums, mid, right, temp);
    // conquer
    int index1 = left;
    int index2 = mid;
    int i = left;
    while (index1 < mid || index2 < right) {
        if (index2 >= right || index1 < mid && nums[index1] <= nums[index2]) {
            temp[i++] = nums[index1++];
        } else {
            temp[i++] = nums[index2++];
        }
    }
    for (int i = left; i < right; ++i) {
        nums[i] = temp[i];
    }
}

// 快速排序 (左闭右开)
void quick_sort(vector<int> &nums, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int first = left;
    int last = right - 1;
    int key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, left, first);
    quick_sort(nums, first + 1, right);
}

int main() {
    vector<int> test0 = {1, 4, 1, 6, 2, 3, 8, 0};
    vector<int> test1 = {1};
    vector<int> test2 = {};
    vector<int> test(test2);
    int len = test.size();
    vector<int> temp(len);
    quick_sort(test, 0, test.size());
    cout << "**************************" << endl;
    for (int i = 0; i < test.size(); ++i) {
        cout << test[i] << ',';
    }
    cout << endl;
    cout << "**************************" << endl;
    getchar();
    return 0;
}
