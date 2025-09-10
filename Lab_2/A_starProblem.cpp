#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
#define M 1000000
#define N 6

struct neighbor{
    int row;
    int col;
    int fn;

    neighbor(int r ,int c, int f){
        row = r;
        col = c;
        fn = f;
    }
};

int distance(int x1, int y1, int x2, int y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool isGoalState(int )

int row_list[] = {1,-1,0,0};
int col_list[] = {0,0,1,-1};

void A_star(vector<vector<int>> mat, int s_row, int s_col, int d_row, int d_col ){
    // starting point
    int fn = 0;
    int gn = 0;
    int z = mat[s_row][s_col];
    int hn = z + distance(s_row, s_col, d_row, d_col);

    fn = gn + hn;
    int val = M;
    if(isGoalState())
    for(int i=0; i<4; i++){
        int row = s_row + row_list[i];
        int col = s_col + col_list[i];
        gn += 1;
        int hn1 = mat[row][col] + distance(s_row, s_col, d_row, d_col);
        int fn1 = gn + hn1 ;

        if(fn1 > val){
            neighbor * temp = new neighbor(row, col, fn1);
        }
        if(isvalid(neighbor->row, neighbor->col)){

        }

    }
    
    


}

int main(){
    vector<vector<int>> matrix ={
        {0,0,0,0,0,0},
        {0,0,M,0,M,0},
        {0,M,0,M,0,0},
        {0,0,0,M,M,0},
        {0,0,0,0,0,0},
        {0,M,M,0,0,0}
    }

    start_row = 1;
    start_col = 1;
    
    d_row = 4;
    d_col = 5;


}
