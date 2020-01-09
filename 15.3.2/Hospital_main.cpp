//
//  Hospital_main.cpp
//  医院选址问题
//
//  Created by Noah on 2020/1/10.
//  Copyright © 2020 Noah. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Hospital.cpp"


int main( )
{
char vertex[N] = {'A','B','C','D','E'};
int edge[N][N] = {{0,13,MaxValue,4,MaxValue},
{13,0,15,MaxValue,5},
{MaxValue,MaxValue,0,12,MaxValue},
{4,MaxValue,12,0,MaxValue},
{MaxValue,MaxValue,6,3,0}};
int minPoint;
Hospital H{vertex, edge, 5}; //定义对象H
minPoint = H.Center( ); //调用函数Center求中心点
cout << "应该设在点:" << vertex[minPoint] << endl;
return 0;
}
