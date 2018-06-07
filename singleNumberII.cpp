/*Given an array of integers, every element appears three times except for one. Find that single one.*/
/*这道题目可以只用一个循环，或者两个循环但是有一个循环固定循环次数，还有什么“卡洛图”。。。*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        if (0 == n)
            return -1;
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (A[i] == A[j] && i != j)
                {
                    break;
                }
                
                if (j == n - 1)
                {
                    return A[i];
                }
            }
        }
        
        return 0;
    }
};