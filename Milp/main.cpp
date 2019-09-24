//
//  main.cpp
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  Copyright © 2019 徐圣源. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "delete_im.h"
#include "delete_id.h"
#include "greedy.h"
#include "read_ieq.h"
#include "truth_table.h"
#include "ddt.h"
#include "ddt_to_pd.h"
#include "milp_for_sbox.h"
using namespace std;
const int n=8;
vector<vector<int>> imp(vector<vector<int>> a)   //已知可行点求所有不可行点
{
    vector<int> tmp;    //用来储存所有可行点的10进制表示
    vector<int> tmp2;   //用来储存所有不可行点的10进制表示
    int i;
    for(i=0;i<a.size();i++){
        tmp.push_back(convert2to10(a[i]));
    }
    for(i=0;i<pow(2.0,n);i++){
        vector<int>::iterator it = find(tmp.begin(), tmp.end(), i);
        if (it == tmp.end())        //若不在可行点集合内
            tmp2.push_back(i);
    }
    vector<vector<int>> res;
    vector<int> x;
    for(i=0;i<tmp2.size();i++){
        x=convert10to2(tmp2[i],8);
        res.push_back(x);
    }
    return res;
}

int main() {
    int i=0,j;
    ifstream in("test.txt");
    vector<vector<int>> pd;     //possible diffierential pattern
        vector<int> sbox={12,5,6,11,9,0,10,13,3,14,15,8,4,7,1,2};
//    vector<int> sbox={6,5,12,10,1,14,7,9,11,0,3,13,8,15,4,2};       //rectangle
    vector<vector<int>> pre =ddt(sbox);
    cout<<"差分分布表大小:"<<pre.size()<<"x"<<pre[0].size()<<endl;       //输出差分表
    for(i=0;i<pre.size();i++){
        for(j=0;j<pre[0].size();j++)
            cout<<pre[i][j]<<" ";
        cout<<endl;
    }
    pd=ddt_to_pd(pre);
    vector<int> tmp;
    ofstream outFile;
    outFile.open("/Users/xushengyuan/Desktop/code/pd.txt",ios::out);        //将pd写入txt中，进而放入sage计算不等式
    for(i=0;i<pd.size();i++){   outFile<<"[";
        for(j=0;j<pd[0].size();j++){
            outFile<<pd[i][j];
            if(j<pd[0].size()-1)
                outFile<<" , ";
        }
        outFile<<"] ,\\";
        outFile<<endl;
    }
    vector<vector<int>> id=imp(pd);     //id表示不可能差分模式，通过排除所有可行点计算得到
 
    //    for(i=0;i<pd.size();i++)        //输出所有可行点
    //    {
    //        for(j=0;j<pd[0].size();j++){
    //            cout<<pd[i][j];
    //        }
    //        cout<<endl;
    //
    //    }
    
    //    for(i=0;i<id.size();i++)          //输出所有不可行点
    //    {
    //        for(j=0;j<id[0].size();j++)
    //            cout<<id[i][j];
    //        cout<<endl;
    //    }
  
    truth_table(pd,id);         //输出真值表，放在两个csv中
    cout<<"可行点个数:"<<pd.size()<<" 不可行点个数:"<<id.size()<<" 总个数:"<<pd.size()+id.size()<<endl;
    vector<vector<int>> ieq=read_ieq();         //从txt中读取不等式
   
        cout<<"不等式个数:"<<ieq.size()<<endl;//输出不等式
//        for(i=0;i<ieq.size();i++) {
//            for(j=0;j<ieq[0].size();j++) cout<<ieq[i][j]<<" ";
//            cout<<endl;
//        }
    vector<vector<int>> del=delete_im(id,ieq);
    for(i=0;i<del.size();i++){
        cout<<"第"<<i+1<<"个不等式删去不可行点个数"<<del[i].size()<<endl;
    }
    vector<vector<int>> result;
    vector<vector<int>> id2;
    id2=id;
    result=greedy(id2,ieq);         //执行完贪心算法以后选出的不等式组
    vector<vector<int>> del2=delete_im(id,result);
    cout<<"使用不等式个数:"<<result.size()<<endl;
    milp_for_sbox(del,pd);
    return 0;
}
