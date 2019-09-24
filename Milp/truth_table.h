//
//  truth_table.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  Copyright © 2019 徐圣源. All rights reserved.
//  输入为所有可行点，输出为真值表

#ifndef truth_table_h
#define truth_table_h
#include <vector>
#include <math.h>
#include <fstream>

void truth_table(vector<vector<int>> pd,vector<vector<int>> id)
{   int i,j,a,b;
    vector<int> tmp;
    vector<vector<int>> tt;
    for(i=0;i<16;i++){
        tmp.clear();
        for(j=0;j<16;j++){
            tmp.push_back(0);
        }
        tt.push_back(tmp);
    }
//    cout<<"真值表大小："<<tt.size()<<"x"<<tt[0].size();
    //遍历所有可行点；
    for(i=0;i<pd.size();i++){
        a=pd[i][0]*pow(2.0,3)+pd[i][1]*pow(2.0,2)+pd[i][2]*2+pd[i][3];
        b=pd[i][4]*pow(2.0,3)+pd[i][5]*pow(2.0,2)+pd[i][6]*2+pd[i][7];
        tt[a][b]=1;
    }
    ofstream outFile;
    ofstream outFile2;
    outFile.open("tt.csv",ios::out);
    for(i=0;i<pd.size();i++){
        for(j=0;j<pd[0].size();j++){
            outFile<<pd[i][j]<<',';
        }
        outFile<<endl;
    }
    
    outFile2.open("tt2.csv",ios::out);
    for(i=0;i<id.size();i++){
        for(j=0;j<id[0].size();j++){
            outFile2<<id[i][j]<<',';
        }
        outFile2<<endl;
    }
    
    
}

#endif /* truth_table_h */
