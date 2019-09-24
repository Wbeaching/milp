//
//  milp_for_sbox.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/23.
//  Copyright © 2019 徐圣源. All rights reserved.
//  输入不等式删掉表的点，建立milp模型

#ifndef milp_for_sbox_h
#define milp_for_sbox_h
#include <vector>
void milp_for_sbox(vector<vector<int>> del,vector<vector<int>> id) //del[i]储存第i个不等式删去的点
{
    int i,j;
    vector<vector<int>> model(pow(2.0,8));
    vector<int> tmp;
    for(i=0;i<del.size();i++){
        for(j=0;j<del[i].size();j++)
        model[del[i][j]].push_back(i);
    }
    ofstream outFile;
    outFile.open("/Users/xushengyuan/Desktop/code/milp_for_sbox.txt",ios::out);        //将结果写入txt中，进而放入gurobi计算优化模型
//    for(i=0;i<model.size();i++)
//    {
//        for(j=0;j<model[i].size()-1;j++)
//        {
//            outFile<<"z"<<model[i][j]<<"+";
//        }
//        outFile<<"z"<<model[i][j]<<endl;
//    }
//        for(i=0;i<model.size();i++)
//        {
//
//        }
    outFile<<"Minimize"<<endl;
    for(i=0;i<=del.size()-1;i++){
        outFile<<"z"<<i<<"+";
    }
    outFile<<"z"<<i<<endl;
    for(i=0;i<model.size();i++){
        if(!model[i].empty())
        {
            for(j=0;j<model[i].size()-1;j++){
                outFile<<"z"<< model[i][j]<<"+";
            }
                outFile<<"z"<< model[i][j]<<">="<<"-1"<<endl;
            }
    }
    outFile<<"Binary"<<endl;
    for(i=0;i<del.size();i++){
        outFile<<"z"<<i<<endl;
    }

}
#endif /* milp_for_sbox_h */
