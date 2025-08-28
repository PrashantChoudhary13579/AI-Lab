#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

// Structure to store the state of jugs
struct State {
    int jug1, jug2;
};

// Function to print the path
void printPath(map<State, State> parent, State target) {
    vector<State> path;
    State curr = target;

    while (!(parent[curr].jug1 == -1 && parent[curr].jug2 == -1)) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(curr);

    cout << "\nSteps to reach solution:\n";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << "(" << path[i].jug1 << ", " << path[i].jug2 << ")\n";
    }
}

// Comparison operator for map
bool operator<(const State &a, const State &b) {
    if (a.jug1 != b.jug1) return a.jug1 < b.jug1;
    return a.jug2 < b.jug2;
}

// BFS to solve Water Jug Problem
void waterJugBFS(int cap1, int cap2, int target) {
    queue<State> q;
    map<State, bool> visited;
    map<State, State> parent;

    State start = {0, 0};
    q.push(start);
    visited[start] = true;
    parent[start] = {-1, -1};

    while (!q.empty()) {
        State u = q.front();
        q.pop();

        // If we reach target
        if (u.jug1 == target || u.jug2 == target) {
            printPath(parent, u);
            return;
        }

        // All possible operations
        vector<State> nextStates = {
            {cap1, u.jug2},              // Fill jug1
            {u.jug1, cap2},              // Fill jug2
            {0, u.jug2},                 // Empty jug1
            {u.jug1, 0},                 // Empty jug2
            {u.jug1 - min(u.jug1, cap2 - u.jug2), u.jug2 + min(u.jug1, cap2 - u.jug2)}, // Pour jug1 -> jug2
            {u.jug1 + min(u.jug2, cap1 - u.jug1), u.jug2 - min(u.jug2, cap1 - u.jug1)}  // Pour jug2 -> jug1
        };

        for (auto v : nextStates) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << "No solution possible.\n";
}

int main() {
    int jug1 = 4, jug2 = 3, target = 2;
    cout << "Jug1 capacity = " << jug1 << ", Jug2 capacity = " << jug2 
         << ", Target = " << target << endl;
    
    waterJugBFS(jug1, jug2, target);
    return 0;
}
