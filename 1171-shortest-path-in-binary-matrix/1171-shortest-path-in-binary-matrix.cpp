class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& A) {
        
        int n=A.size();
        if(A[0][0]==1 || A[n-1][n-1]==1) return -1;
        if(n==1) return !A[0][0];


        vector<pair<int,int>> dirn={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}};

        queue<pair<int,int>> q;
        q.push({0,0});A[0][0]=1;
        int dis=1;
        while(!q.empty())
        {
            int s=q.size();
            dis++;
            while(s--)
            {
                auto [i,j]=q.front(); q.pop();
                for(auto& dir:dirn)
                {  int x=i+dir.first,y=j+dir.second;
                    if(x>=0 && x<n && y>=0 && y<n && A[x][y]==0)
                        A[x][y]=dis,
                        q.push({x,y});
                }
            }
        } return !A[n-1][n-1]?-1:A[n-1][n-1];
    }
};