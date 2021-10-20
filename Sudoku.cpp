// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}// } Driver Code Ends

bool check(int grid[N][N], int i, int j, int val){
    for(int t=0;t<N;t++){
        if(val==grid[t][j] || val==grid[i][t]){
            return false;
        }
    }
    int p = (i/3)*3;
    int q = (j/3)*3;
    for(int t=p;t<p+3;t++){
        for(int s=q;s<q+3;s++){
            if(val==grid[t][s]){
                return false;
            }
        }
    }
    return true;
}
void solve(int grid[][N],int i, int j, bool &ans){

    if(i==N){
        ans = true;
        return;
    }
    int ni=0,nj=0;
    if(j==N-1){
        ni = i+1;
        nj = 0;
    }
    else{
        ni = i;
        nj = j+1;
    }
    if(grid[i][j]!=0){
        solve(grid,ni,nj,ans);
    }
    else{
        for(int t=1;t<=9;t++){
            if(check(grid,i,j,t)==true){
                grid[i][j]=t;
                solve(grid,ni,nj,ans);
                if(ans==true){
                    return;
                }
                grid[i][j]=0;
            }
        }
    }
}
bool SolveSudoku(int grid[N][N])  
{ 
    int a[N][N];
    bool ans = false;
    solve(grid,0,0,ans);
    return ans;
}

void printGrid (int grid[N][N]) 
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}