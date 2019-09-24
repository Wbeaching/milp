//
//  delete_im.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  Copyright © 2019 徐圣源. All rights reserved.
//  输入为不等式k和不可能的点，输出为每个不等式去掉的点（十进制表示）

#ifndef delete_im_h
#define delete_im_h
#include<vector>
using namespace std;
int convert2to10(vector<int> id);
vector<vector<int>> delete_im(vector<vector<int>> id,vector<vector<int>> ieq){
    int i,j,k,a;
    vector<int> tmp;
    vector<vector<int>> res;
    //对每个不等式进行操作
    for(i=0;i<ieq.size();i++){
        tmp.clear();
        //固定每个不等式，遍历所有不可行点
        for(j=0;j<id.size();j++){
            a=0;
            //带入不等式计算取值
            for(k=0;k<id[0].size();k++){
                a+=id[j][k]*ieq[i][k];
            }
            a+=ieq[i][id[0].size()];        //加常数项
            //不可行点以十进制形式存入,i表示第i个不等式，res[i]对应数组为第i个不等式去掉的点
            if(a<0){
                tmp.push_back(convert2to10(id[j]));
            }
        }
        res.push_back(tmp);
    }
    return res;
}
#endif /* delete_im_h */
