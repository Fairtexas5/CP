class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> zerw;
        unordered_set<int> zecw;

        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    zerw.insert(i);
                    zecw.insert(j);
                }
            }
        }

        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(zerw.count(i) || zecw.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};