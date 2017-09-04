
// Author :  Accagain
// Date   :  17/8/18
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * 
 * 做法：
 *      
 * 复杂度：
 *      开两个数组表示哪些行和哪些列需要置0， 可以简化成用第一个零行，第一个列行来存储
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 0x3fffffff

using namespace std;

#include <unordered_set>
class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        // write code here
        n = mat.size();
        int m = mat[0].size();
        bool first_row_zero = false, first_col_zero = false;
        for(int i=0; i<m; i++)
        {
            if(!mat[0][i])
                first_row_zero = true;
        }
        for(int i=0; i<n; i++)
        {
            if(!mat[i][0])
                first_col_zero = true;
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(!mat[i][j])
                {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for(int i=1; i<m; i++)
        {
            if(!mat[0][i])
            {
                for(int j=0; j<n; j++)
                    mat[j][i] = 0;
            }
        }
        for(int i=1; i<n; i++)
        {
            if(!mat[i][0])
            {
                for(int j=0; j<m; j++)
                {
                    mat[i][j] = 0;
                }
            }
        }

        if(first_row_zero)
        {
            for(int i=0; i<m; i++)
                mat[0][i] = 0;
        }
        if(first_col_zero)
        {
            for(int i=0; i<n; i++)
                mat[i][0] = 0;
        }

        return mat;
    }
};


int main() {

    return 0;
}

//
// Created by cms on 17/8/18.
//

