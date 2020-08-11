/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

vector<vector<string>>ans;
    int f(int x,int y,vector<string>v){
        for(int j=0;j<y;j++)
            for(int i=0;i<v.size();i++)
                if(v[i][j]=='Q' and ((i-j)==(x-y) or ((i+j)==(x+y)) or (i==x)))
                    return 0;
        return 1;
    }
    int dfs(int j,vector<string>v){
        int ok=0;
        if(j==v.size()){
            ans.push_back(v);
            return 1;
        }
        for(int i=0;i<v.size();i++){
            if(f(i,j,v)){
                v[i][j]='Q';
                ok|=dfs(j+1,v);
                v[i][j]='.';
            }
        }
        return ok;
    }
    vector<vector<string>> Solution::solveNQueens(int n) {
        auto v=vector<string>(n,string(n,'.'));
        ans.clear();
        dfs(0,v);
        return ans;
    }
