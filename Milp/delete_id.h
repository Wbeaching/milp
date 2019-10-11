//
//  delete_id.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  Copyright © 2019 徐圣源. All rights reserved.
//  贪心算法中，选择一个不等式以后去掉所有可行点，生成一个新的不等式组以及对应的不可行点

#ifndef delete_h
#define delete_h
#include <vector>
#include "delete_im.h"

vector<vector<int>> delete_id(vector<vector<int>>id,vector<int> ieq)   //输入为不可行点集以及一个不等式，输出为新的不可行点集，把该不等式去掉的点去掉之后的新的可行点
{   int j,k;
    vector<int> tmp;
    vector<vector<int>> res;
    //对固定的不等式，遍历所有不可行点
    
    for(j=0;j<id.size();j++){
        int a=0;
        //带入不等式计算取值
        for(k=0;k<id[0].size();k++){
            a+=id[j][k]*ieq[k];
        }
        a+=ieq[id[0].size()];
        //a<0代表该点对于该不等式不可行，应该删掉,a>0应当保留，不可被当前多项式删去
        if(a>=0){
            res.push_back(id[j]);       //直接将满足不等式点存到结果里，不满足的舍去
        }
        
        
    }
    return res;
}

#endif /* delete_id.h */
