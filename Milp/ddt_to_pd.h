//
//  ddt_to_pd.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  Copyright © 2019 徐圣源. All rights reserved.
//  通过差分分布表ddt得到所有可行点

#ifndef ddt_to_pd_h
#define ddt_to_pd_h
#include <iostream>
#include "ddt.h"
vector<vector<int>> ddt_to_pd(vector<vector<int>> ddt)
{
    int i,j;
    vector<int> a;
    vector<int> b;
    vector<vector<int>> res;
    for(i=0;i<ddt.size();i++){
        for(j=0;j<ddt[0].size();j++){
            if(ddt[i][j]!=0){
                a=convert10to2(i,4);
                b=convert10to2(j,4);
                a.insert(a.end(),b.begin(),b.end());
                res.push_back(a);
            }
        }
    }
    return res;
}

#endif /* ddt_to_pd_h */
