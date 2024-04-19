#include <bits/stdc++.h>

using namespace std;

bool isInsideBoard(int x, int y, int A, int B) {
    return (x >= 1 && x <= A && y >= 1 && y <= B);
}

int minStepsToReachDestination(int A, int B, int C, int D, int E, int F) {
    vector<pair<int, int>> moves = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
    };
    
    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));
    
    queue<pair<pair<int, int>, int>> q;
    
    visited[C][D] = true;
    q.push({{C, D}, 0});
    
    while (!q.empty()) {
        pair<int, int> curr = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if (curr.first == E && curr.second == F) {
            return steps;
        }
        
        for (auto move : moves) {
            int newX = curr.first + move.first;
            int newY = curr.second + move.second;
            if (isInsideBoard(newX, newY, A, B) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({{newX, newY}, steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    
    int A = 8, B = 8, C = 1, D = 1, E = 8, F = 8;
    cout << minStepsToReachDestination(A, B, C, D, E, F) << endl;
    
     // Output: 6


    return 0;
}
