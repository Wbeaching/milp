//
//  greedy.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  Copyright © 2019 徐圣源. All rights reserved.
//  输入为不等式组和不可行点组，输出为简化后的不等式组

#ifndef greedy_h
#define greedy_h
#include <vector>
#include "delete_im.h"
#include "delete_id.h"
vector<vector<int>> greedy (vector<vector<int>> id,vector<vector<int>> ieq)
{
    vector<vector<int>> res;
    int i,flag,max,step=0;
    vector<vector<int>> del;
    while(id.size()!=0&&step<=50){
        step++;
        del.clear();
        del=delete_im(id,ieq);  //由不等式集和不可行点集生成del，用来判断最大
        flag=0;     //标记去掉最多不可行点的不等式编号
        max=del[0].size();    //去掉不可行点的个数
        for(i=0;i<del.size();i++){
            if(del[i].size()>max){
                flag=i;
                max=del[i].size();
            }
        }
        cout<<endl;
        cout<<"step"<<step<<endl;
        cout<<"使用第"<<flag+1<<"个不等式"<<"去掉点个数："<<del[flag].size();
        id=delete_id(id,ieq[flag]);      //更新不可行点集
        cout<<"->新的不可行点集点的个数："<<id.size()<<endl;
        res.push_back(ieq[flag]);
        vector<int> c(9);
        ieq[flag]=c;
        
    }
    return res;
}
#endif /* greedy_h */
