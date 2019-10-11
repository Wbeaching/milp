//
//  double_point.h
//  Milp
//
//  Created by 徐圣源 on 2019/10/8.
//  Copyright © 2019 徐圣源. All rights reserved.
//  加入中点后需要将原来点的坐标变为两倍，方便表示中点

#ifndef double_point_h
#define double_point_h

vector<vector<int>> double_point(vector<vector<int>>  a)
{
    int i,j;
    vector<vector<int>> result;
    vector<int> tmp(a[0].size());
    
    for(i=0;i<a.size();i++){
        result.push_back(tmp);   }
    
    for(i=0;i<a.size();i++){
        for(j=0;j<a[i].size();j++){
            result[i][j]=2*a[i][j];
        }
    }
    return result;
}
#endif /* double_point_h */
