//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int> (m,0));
	    vector<vector<int>> dis(n,vector<int> (m,0));
	    queue< pair< pair<int,int>,int >> q; 
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if (grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	            else
	            {
	                vis[i][j]=0;
	            }
	        }
	    }
	    int drow[]={-1,0,+1,0};
	    int dcol[]={0,+1,0,-1};
	    while (!q.empty())
	    {
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int steps=q.front().second;
	        q.pop();
	        dis[r][c]=steps;
	        for(int i=0;i<4;i++)
	        {
	            int nr=drow[i]+r;
	            int nc=dcol[i]+c;
	            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0)
	            {
	                vis[nr][nc]=1;
	                q.push({{nr,nc},steps+1});
	            }
	        }
	    }
	    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
