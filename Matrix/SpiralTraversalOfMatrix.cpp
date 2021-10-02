// Problem link : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int i=0, j=0, maxr = r-1, minr = 1, maxc = c-1, minc = 0; 
        vector<int> res;
        char dir='r';
        if (maxc==0) dir = 'd';
        
        for (int k=0; k<r*c; k++) {
            res.push_back(matrix[i][j]);
            switch (dir) {
                case 'r':
                    j++;
                    if (j==maxc) {
                        dir = 'd';
                        maxc--;
                    }
                    break;
                case 'l':
                    j--;
                    if (j==minc) {
                        dir = 'u';
                        minc++;
                    }
                    break;
                case 'u':
                    i--;
                    if (i==minr) {
                        dir = 'r';
                        minr++;
                    }
                    break;
                case 'd':
                    i++;
                    if (i==maxr) {
                        dir = 'l';
                        maxr--;
                    }
                    break;
            }
        }
        return res;
    }
};
