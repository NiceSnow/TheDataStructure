//
//  test.c
//  TheDataStructure
//
//  Created by madongdong on 2021/2/17.
//

#include "test.h"
/*
 n 没开瓶的汽水
 b 瓶子
 c 瓶盖
 count 总数
 */
int bottlesOfDrinks(int n,int b,int c,int count)
{

    b += n;
    c += n;
    count += n;
    n = 0;
    if (b<4 && c<2) {
        return count;
    }
    n += b/4;
    n += c/2;
    return bottlesOfDrinks(n, b%4, c%2,count);
}
