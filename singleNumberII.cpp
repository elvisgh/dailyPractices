/*Given an array of integers, every element appears three times except for one. Find that single one.*/
/*�����Ŀ����ֻ��һ��ѭ������������ѭ��������һ��ѭ���̶�ѭ������������ʲô������ͼ��������*/

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