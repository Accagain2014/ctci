
// Author :  Accagain
// Date   :  17/8/18
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * 
 * 做法：
 *      顺时针旋转90度，a[i][j] -> a[j][n-1-i]
 *      等价于 a[i][j] 先行交换 a[n-1-i][j] 再对称交换 a[j][n-1-i]
 *      对称交换a[i][j] -> a[j][i]
 *      反对称交换a[i][j] -> a[n-1-j][n-1-j]
 *
 *      行交换比较好写
 *
 *      可以先保存，然后同时转
 *
 * 复杂度：
 *      O(n^2)
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 0x3fffffff

using namespace std;

class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        // write code here
        reverse(mat.begin(), mat.end());
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
            {
                swap(mat[i][j], mat[j][i]);
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

