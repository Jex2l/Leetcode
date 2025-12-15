class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1.0) return 1.0;
        if (x == -1.0) return (n & 1) ? -1.0 : 1.0;
        if (n == INT_MIN) return 0.0;
        if(n < 0) {
            x = 1/x;
            n=-n;
        }
        double result = 1;
        while( n > 0){
            result = result * x;
            n--;
        }
        return result;
    }
};

// class Solution {
// public:
//     double myPow(double x, int n) {
        
//         if(n < 0) {
//             x = 1 / x;
//         } 
        
//         long num = labs(n);
        
//         double pow = 1;
        
//         while(num){
//             if(num & 1) {
//                 pow *= x;
//             }
            
//             x *= x;
//             num >>= 1;
//         }
        
//         return pow;
//     }
// };