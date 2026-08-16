#define ll long long
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<ll>> matrix(n, vector<ll>(n, LLONG_MAX));
        for(auto it : edges){
            ll u = it[0];
            ll v = it[1];
            ll w = it[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        for(ll i = 0; i<n; i++) matrix[i][i] = 0;
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<n; j++){
                for(ll k = 0; k<n; k++){
                    if(matrix[j][i] == LLONG_MAX || matrix[i][k] == LLONG_MAX) continue;
                    matrix[j][k] = min(matrix[j][k], matrix[j][i]+matrix[i][k]);            
                }
            }
        }
        ll countCity = n;
        ll cityNo = -1;
        for(ll i = 0; i<n; i++){
            ll count = 0;
            for(ll j = 0; j<n; j++){
                if(matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count<=countCity){
                countCity = count;
                cityNo = i;
            }
        }
        return int(cityNo);
    }
};