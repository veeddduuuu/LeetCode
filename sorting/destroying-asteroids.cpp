class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        long long currMass = mass;
        for(int i = 0; i<n; i++){
            if(asteroids[i]<=currMass){
                currMass+=asteroids[i];
            }
            else if(currMass<asteroids[i]){
                return false;
            }
        }
        return true;
    }
};