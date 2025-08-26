class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<float> arr;
        for(int i = 0; i<dimensions.size(); i++){
            float dia = sqrt((dimensions[i][1]*dimensions[i][1])+(dimensions[i][0]*dimensions[i][0]));
            arr.push_back(dia);
        }
        int index = 0;
        float x = 0;
        for(int i = 0; i<arr.size(); i++){
            if(x == arr[i]){
                if((dimensions[i][0] * dimensions[i][1]) > (dimensions[index][0] * dimensions[index][1])){
                    x == arr[i];
                    index = i;
                }
            }
            if(x < arr[i]){
                x = arr[i];
                index = i;
            }
        }
        return (dimensions[index][0] * dimensions[index][1]);
    }
};