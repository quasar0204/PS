class Solution {
public:    
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        
        while(left < right){
            for (int i = 0; i < right - left; i++) {
                int tmp = matrix[left][left + i];
                matrix[left][left + i] = matrix[right - i][left];
                matrix[right - i][left] = matrix[right][right - i];
                matrix[right][right - i] = matrix[left + i][right];
                matrix[left + i][right] = tmp;
            }
            
            left++; right--;
        }
        
    }
};