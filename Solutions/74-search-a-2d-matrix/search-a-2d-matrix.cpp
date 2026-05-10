class Solution {
public:
    bool bst(vector<int> mat, int target){
        int s = 0;
        int e = mat.size()-1;
        while(s <= e){
            int mid = s + (e- s)/2;
            if(mat[mid] == target) return true;
            else if(mat[mid] < target) s = mid+1;
            else e = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans = false;
        for(int i = 0; i<matrix.size(); i++){
            if(bst(matrix[i], target)) ans = true;
        }
        return ans;
    }
};