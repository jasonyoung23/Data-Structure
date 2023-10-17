#include <iostream>
#include <vector>

using namespace std;

int quick_sort_count(vector<int>& arr) {
    if (arr.size() <= 1) {
        return 0;
    }

    int pivot = arr[0];
    vector<int> left, right;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < pivot) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }

    return arr.size() - 1 + quick_sort_count(left) + quick_sort_count(right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = quick_sort_count(arr);
    cout << result << endl;

    return 0;
}
