#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main() {
    vector<int> nums = { 72,73,71,23,94,16,5,68 };
    vector<int> tmp(nums.size());
    mergerSort(0, nums.size() - 1, nums, tmp);
    for (int i = 0;i < nums.size();i++) {
        cout << nums[i] << " ";
    }
}

void mergerSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
    if (l >= r) {
        return;
    }
    int m = (l + r) >> 1;//左数组的有边界，右数组的左边界
    mergerSort(l, m, nums, tmp);
    mergerSort(m + 1, r, nums, tmp);
    int i = l, j = m + 1;
    for (int k = l;k <= r;k++) {
        tmp[k] = nums[k];
    }
    for (int k = l;k <= r;k++) {
        if (i == m + 1) nums[k] = tmp[j++];
        else if (j == r + 1 || tmp[i] <= tmp[j]) {
            nums[k] = tmp[i++];
        }
        else {
            nums[k] = tmp[j++];//构成逆序对
        }
    }
}