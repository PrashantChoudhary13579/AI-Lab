#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define R 9
#define C 10

typedef pair<int, int> P;
typedef pair<double, pair<int,int>> Ppair;

struct cell{
    int parent_i, parent_j;
    double f, g, h;
};

bool isValid(int row, int col){
    return (row>= 0 && row <R && col>=0 && col< C);
}

bool isUnBlocked(int grid[][C], int row ,int col){
    if(grid[row][col] ==  1) {
        return true;
    }
    else return false;
}

bool isDestination(int row, int col, Pair dest){
    if(row == dest.first && col == dest.second){
        return true;
    }
    else return false;
}

double calculate_h_value(int row, int col, Pair dest){
    return ((double)sqrt((row - dest.first)*(row - dest.first) + (col - dest.second)*(col - dest.second)));
}

void tracePath(cell cellDetails[][C], Pair, dest){
    cout<<"The path is as follows: "<<endl;
    int row = dest.first;
    int col = dest.second;

    stack<Pair> Path;

    while(!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)){
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;

        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    while(!Path.empty()){
        pair<int,int> p = Path.top();
        Path.pop();
        cout<<"-> ("<<p.first<<","<<p.second<<")";

    }
    return ;
}

void aStarSearch(int grid[][C], Pair src, int Pair dest){
    if(isValid(src.first, src.second) == false){
        cout<<"Source is not valid"<<endl;
        return;
    }
    if(isValid(dest.first, dest.second) == false){
        cout<<"Destination is not valid"<<endl;
        return;
    }

    if(isUnBlocked(grid, src.first, src.second) == false || isUnBlocked(grid, dest.first, dest.second)){
        cout<<"Source or Destination is blocked"<<endl;
        return;
    }

    if(isDestination(src.first, src.second, dest) == true){
        cout<<"Already present at the destination"<<endl;
    }

    bool closedList[R][C];
    memset(closedList, false, sizeof(closedList))
}

int main(){
    int grid[R][C]={ 
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } };

    Pair src = make_pair(8,0);
    Pair dest = make_pair(0,0);

    aStarSearch(grid, src, dest);

    return 0;
}
