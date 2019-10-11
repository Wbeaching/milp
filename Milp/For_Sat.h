//
//  For_Sat.h
//  Milp
//
//  Created by 徐圣源 on 2019/10/8.
//  Copyright © 2019 徐圣源. All rights reserved.
//

#ifndef For_Sat_h
#define For_Sat_h

#include <vector>
void For_Sat(vector<vector<int>> del,int num_id) //del[i]储存第i个不等式删去的点
{
    int i,j;
    vector<vector<int>> model(2*pow(2.0,8));
    vector<int> tmp;
    for(i=0;i<del.size();i++){              //i表示第i个不等式，del[i][j]表示某个点
        for(j=0;j<del[i].size();j++)
        model[del[i][j]-1].push_back(i+1);
    }
    
    ofstream outFile;
    outFile.open("/Users/xushengyuan/Desktop/code/For_Sat_Mid_lblock.txt",ios::out);
//    outFile.open("/Users/xushengyuan/Desktop/code/For_Sat_Mid_twine.txt",ios::out);
//        outFile.open("/Users/xushengyuan/Desktop/code/For_Sat_Mid_serpents0.txt",ios::out);
//         outFile.open("/Users/xushengyuan/Desktop/code/For_Sat_Mid_twinetest.txt",ios::out);

    outFile<<"p"<<" "<<"cnf "<<del.size()<<" "<<num_id<<" "<<endl;
    
    for(i=0;i<model.size();i++){
        if(!model[i].empty())
        {
            for(j=0;j<model[i].size();j++){
                outFile<<model[i][j]<<" ";
            }
            outFile<<0<<" "<<endl;
        }
    }
}
#endif /* For_Sat_h */
