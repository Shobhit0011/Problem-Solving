#include <iostream>
#include <vector>
using namespace std;

bool sum_of_subarrays(const vector<int>& A, int k, int S) {
    long long sum_subarrays = 0;
    for (int i = 0; i < k; ++i)
        sum_subarrays += A[i];

    if (sum_subarrays > S)
        return false;

    for (int i = k; i < A.size(); ++i) {
        sum_subarrays += A[i] - A[i - k];
        if (sum_subarrays > S)
            return false;
    }
    return true;
}

int max_subarray_size(const vector<int>& A, int S) {
    int left = 1, right = A.size();
    int max_size = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sum_of_subarrays(A, mid, S)) {
            max_size = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return max_size;
}
int main() {
    vector<int> A = {1, 3, 4, 2};
    int S = 7;

    cout << "Maximum subarray size: " << max_subarray_size(A, S) << endl;
    return 0;
}
