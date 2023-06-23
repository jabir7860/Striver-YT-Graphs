 int MinimumEffort(vector<vector<int>>& heights)
{
       int n = heights.size(),m = heights[0].size();
vector <vector<int>> dis(n,vector <int>(m,INT_MAX));
int dx[] = {-1,1,0,0},dy[] = {0,0,1,-1};
dis[0][0] = 0;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
pq.push({0,{0,0}});
while (!pq.empty())
{
    int effort = pq.top().first,x = pq.top().second.first,y = pq.top().second.second;
    if (x == n-1 && y == m-1) return effort;
    pq.pop();
    for (int i = 0; i < 4; i++){
        int nr = x+dx[i],nc = y+dy[i];
        if(nr < 0 || nc < 0 || nr == n || nc == m) continue;
        int newEffort = max(effort,abs(heights[nr][nc]-heights[x][y]));
        if (newEffort < dis[nr][nc]){
            dis[nr][nc] = newEffort;
            pq.push({newEffort,{nr,nc}});
        }
    }
}
return -1;
    }
