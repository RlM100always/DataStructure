#include <iostream>
#include <vector>
using namespace std;

void merge(vector<long long int>& arr, int left, int mid, int right, int exp) {
    int i = left, j = mid + 1, k = 0;

    vector<long long int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (((arr[i] / exp) % 10) <= ((arr[j] / exp) % 10)) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void merge_sort(vector<long long int>& arr, int left, int right, int exp) {
    if (left >= right || exp == 0) {
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid, exp);
    merge_sort(arr, mid + 1, right, exp);

    merge(arr, left, mid, right, exp);
}

void radix_sort(vector<long long int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    int max_val = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int exp = 1;
    while (max_val / exp > 0) {
        merge_sort(arr, 0, arr.size() - 1, exp);
        exp *= 10;
    }
}

int main() {
    vector<long long int> arr = { 170, 45, 75, 90, 802333666666666333, 2444, 2, 66 };
    radix_sort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
