//
//  Check_Sat.h
//  Milp
//
//  Created by 徐圣源 on 2019/10/8.
//  Copyright © 2019 徐圣源. All rights reserved.
//

#ifndef Check_Sat_h
#define Check_Sat_h
vector<int> Check_Sat()
{
    vector<int> res;
        ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_lblock.txt");
//        ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_twine.txt");
//        ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_present.txt");
//        ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents0.txt");
    //    ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents1.txt");
    //    ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents2.txt");
    //    ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents3.txt");
    //    ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents4.txt");
    //    ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents5.txt");
    //    ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents6.txt");
    //    ifstream in("/Users/xushengyuan/Desktop/code/Count_Sat_serpents7.txt");

//    ifstream in("/Users/xushengyuan/Desktop/code/ttttest.txt");
//    ifstream in("/Users/xushengyuan/Desktop/twine_all_sol/10.txt");
    
    int t;
           if(in){
               while (in>>t){
                   if(t>0) res.push_back(t);
               }
               }
           else // 没有该文件
           {
               cout <<"no such file" << endl;
           }

    return res;
}

#endif /* Check_Sat_h */
