// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(x == 1) return x;
//         if(n == INT_MAX){
//             if((n %2 == 0) && x == -1){
//                 return 1;
//             }
//             if((n %2 != 0) && x == -1){
//                 return -1;
//             }  
//         }
//         if(n == INT_MIN){
//             if((n %2 == 0) && x == -1){
//                 return 1;
//             }
//             if((n %2 != 0) && x == -1){
//                 return -1;
//             }
//             else return 0;  
//         }
//         double result = 1;
//         if(n > 0){
//             while( n > 0){
//                 result = result * x;
//                 n--;
//             }
//         }
//         if(n < 0){
//             while(n < 0){
//                 result = result/x;
//                 n++;
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){
            if(num & 1) {
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }
};