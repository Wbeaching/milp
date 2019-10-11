//
//  read_ieq.h
//  Milp
//
//  Created by 徐圣源 on 2019/9/21.
//  从txt文件中读取不等式（不等式来自于sage软件输出）

#ifndef read_ieq_h
#define read_ieq_h
#include <vector>
#include <math.h>
#include <fstream>
vector<vector<int>> read_ieq()
{
//    ifstream in("/Users/xushengyuan/Desktop/code/Milp/present_ieq.txt");
//    ifstream in("/Users/xushengyuan/Desktop/code/Milp/rectangle_ieq.txt");
//    ifstream in("/Users/xushengyuan/Desktop/code/present_ieq_mid.txt");
        ifstream in("/Users/xushengyuan/Desktop/code/lblock_ieq_mid.txt");
//    ifstream in("/Users/xushengyuan/Desktop/code/twine_ieq_mid.txt");
//    ifstream in("/Users/xushengyuan/Desktop/code/serpents0_ieq_mid.txt");
//        ifstream in("/Users/xushengyuan/Desktop/code/present_ieq_mid.txt");


    int t,i=0;
    vector<vector<int>> res;
    vector<int> tmp;
    
    // 有该文件
    if(in){
        while (in>>t){
            tmp.push_back(t);
            if(++i%10==0){
                res.push_back(tmp);
                tmp.clear();
            }
        }
    }
    else // 没有该文件
    {
        cout <<"no ieq file found" << endl;
    }
    return res;
}

#endif /* read_ieq_h */
