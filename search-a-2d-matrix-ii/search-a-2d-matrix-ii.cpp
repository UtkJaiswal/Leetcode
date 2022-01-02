class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start1=0,end1=matrix.size()-1,mid1;
        while(start1<=end1)
        {
            mid1=start1;
            int start2=0,end2=matrix[0].size()-1,mid2;
            while(start2<=end2)
            {
                mid2=start2+(end2-start2)/2;
                if(matrix[mid1][mid2]==target)
                    return true;
                else if(matrix[mid1][mid2]>target)
                    end2=mid2-1;
                else
                    start2=mid2+1;
            }
            start1++;
        }
        return false;
    }
};