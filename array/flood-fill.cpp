class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int k, int color){
        int m = image.size();
        int n = image[0].size(); 
        if(i>=m || i<0 || j>=n || j<0 || k==color ||image[i][j] != k) return;
        image[i][j] = color;
        dfs(image, i+1, j, k, color);
        dfs(image, i-1, j, k, color);
        dfs(image, i, j+1, k, color);
        dfs(image, i, j-1, k, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int k = image[sr][sc];
        dfs(image, sr, sc, k, color);
        return image;
    }
};