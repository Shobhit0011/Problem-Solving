#include<bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int>& boards, int k, int mid) {
    long long total = 0;
    int painters = 1;
    for (int board : boards) {
        total += board;
        if (total > mid) {
            total = board;
            ++painters;
            if (painters > k)
                return false;
        }
    }
    return true;
}

int findLargestMinDistance(const vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> a={2, 1, 5, 6, 2, 3};
    int k=2;
    int ans = findLargestMinDistance(a,k);
    cout<<"Minimum time is: "<<ans;
    return 0;
}
