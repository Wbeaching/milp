//
//  ddt.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  Copyright © 2019 徐圣源. All rights reserved.
//  输入s盒，输出s盒对应的差分分布表

#ifndef ddt_h
#define ddt_h
#include <vector>
extern const int n;
vector<int> convert10to2(int a,int t)       //t为比特数
{
    vector<int> c(t);
    int i=1;
    while(a!=0)
    {
        c[t-i]=a%2;
        a=a/2;
        i++;
    }
    return c;
}
int convert2to10(vector<int> c)
{
    int a=0,i;
    for(i=c.size()-1;i>=0;i--)
    {
        a+=c[i]*(pow(2.0,(c.size()-1-i)));
    }
    return a;
}
int Xor(int a,int b,int t)    //两个10进制数，按位xor以后变成另一个十进制数,t表示长度
{
    int i=1;
    vector<int> aa(t);
    vector<int> bb(t);
    while(a!=0)
    {
        aa[t-i]=a%2;
        a=a/2;
        i++;
    }
    int j=1;
    while(b!=0)
    {
        bb[t-j]=b%2;
        b=b/2;
        j++;
    }
    vector<int> res;
    for(i=0;i<4;i++)
    {
        res.push_back(aa[i]^bb[i]);
    }
    return(convert2to10(res));
}
vector<vector<int>> ddt(vector<int> sbox)
{
    int i,j,a,b;        //a代表输入差分
    vector<vector<int>> res;    //res是16x16的表
    vector<int> tmp;
    for(i=0;i<16;i++)
    {
        tmp.clear();
        for(j=0;j<16;j++)
        {
            tmp.push_back(0);
        }
        res.push_back(tmp);
    }
    vector<vector<int>> diff;   //储存所有可能的4bit数据
    for(i=0;i<16;i++)
    {
        diff.push_back(convert10to2(i,n/2));
    }
    //i遍历所有的输入
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            a=Xor(i,j,n/2);
            b=Xor(sbox[i],sbox[j],n/2);
            res[a][b]++;
        }
    }
    return res;
}
#endif /* ddt_h */
