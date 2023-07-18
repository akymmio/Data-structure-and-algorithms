void InsertSort(int a[], int n) {
    for (int i = 0;i < n - 1;i++) {
        int tmp = a[i + 1];
        int j = i;
        while (j > -1 && a[j] > tmp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}
void shellsort() {

}
void SelectSort(int a[], int n) {

    for (int i = 0;i < n - 1;i++) {//倒数第二个排序好，最后一个也就排序好了
        int small = i;
        for (int j = i + 1;j < n;j++) {
            if (a[j] < a[small]) small = j;
        }
        if (small != i) {
            int tmp = a[i];
            a[i] = a[small];
            a[small] = tmp;
        }
    }
};

void BubbleSort(int a[], int n) {
    int flag = 1;
    for (int i = 1;i < n && flag == 1;i++) {
        flag = 0;
        for (int j = 0;j < n - i;j++) {
            if (a[j] > a[j + 1]) {
                flag = 1;
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void QuickSort(int* a, int low, int high) {
    int i = low, j = high;
    int tmp = a[low];
    while (i < j) {
        while (i < j && tmp < a[j]) j--;
        if (i < j) {
            a[i] = a[j];
            i++;
        }

        while (i < j && tmp > a[i]) i++;
        if (i < j) {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = tmp;
    if (low < i) QuickSort(a, low, i - 1);
    if (i < high) QuickSort(a, j + 1, high);
}