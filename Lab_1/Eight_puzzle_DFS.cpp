#include<iostream>
#include<stack>
// #include<bool>
using namespace std;


bool visited[10] = {false};
int state[10] = {0};
int parent[10]= {-1};
int goal_mat[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

void print(int arr[][3], int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}


void DFS(int mat[][3], int row, int col, int value, int cur_state, stack<int>st){
    if (row<0 || col>0 || row>3 || col>3) return ;

    if (visited[mat[row][col]] != true){
        visited[mat[row][col]] = true;
        parent[mat[row][col]] = value;
        state[mat[row][col]] = cur_state +1;
        st.push(mat[row][col]);
        cout<<mat[row][col]<<endl;
        DFS(mat, row-1, col, mat[row][col], cur_state, st);
        DFS(mat, row+1, col, mat[row][col], cur_state, st);
        DFS(mat, row, col-1, mat[row][col], cur_state, st);
        DFS(mat, row, col+1, mat[row][col], cur_state, st);      

    }
}

void Starting(int mat[][3], int m, int n ,stack<int> st){
    int start_row = 2;
    int start_col = 2;
    state[mat[start_row][start_col]] = 1;
    int starting_state = 1;
    visited[mat[start_row][start_col]]= true;
    parent[mat[start_row][start_col]]= -1;
    st.push(mat[start_row][start_col]);
    int value = mat[start_row][start_col];
    cout<<value<<" having state - "<<starting_state<<endl
    DFS(mat, start_row-1, start_col, value, starting_state, st);
    DFS(mat, start_row+1, start_col, value, starting_state, st);
    DFS(mat, start_row, start_col+1, value, starting_state, st);
    DFS(mat, start_row, start_col-1, value, starting_state, st);
}
int main(){

    int m = 3;
    int n = 3;
    int mat[3][3]= {{4,3,2},{5,7,6},{1,8,0}};
    stack<int> st;
    cout<<"Starting"<<endl;
    Starting(mat,m,n,st);
    // print(mat,m,n);
    // print(visited)


    return 0;
}