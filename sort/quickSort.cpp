#include <iostream>

using namespace std;
void quickSort(int* nums, int low, int high) {
    int i = low, j = high;
    int tmp = nums[i];//»ù×¼ÔªËØ
    while (i < j) {
        while (i < j && nums[j] >= tmp) j--;
        if (i < j) nums[i++] = nums[j];
        while (i < j && nums[i] < tmp) i++;
        if (i < j) nums[j--] = nums[i];
    }
    nums[i] = tmp;
    if (low < i) quickSort(nums, low, i - 1);
    if (i < high) quickSort(nums, j + 1, high);

}
int main() {
    int nums[] = { 1,3,2,4,6,5,8,7,9 };
    quickSort(nums, 0, 8);
    for (int i = 0;i < 9;i++) {
        cout << nums[i] << " ";
    }
    return 0;
}