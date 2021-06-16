//
//  tree.c
//  TheDataStructure
//
//  Created by madongdong on 2020/12/25.
//

#include "tree.h"
#include "math.h"

int pos_num(int num, int cnt)
{
    int res;
    if (num == 0) {
        res = 0;
    }else if (num == 1){
        res = cnt;
    }else if (num == 2){
        res = cnt*cnt;
    }else if (num == 3){
        res = cnt*cnt*cnt;
    }else{
        res = 0;
        res += pos_num(num - 3, cnt) * (cnt - 1);
        res += pos_num(num - 2, cnt) * (cnt - 1);
        res += pos_num(num - 1, cnt) * (cnt - 1);

    }
    return res;
}

int pos_num1(int num, int cnt){
    int count = cnt;
    if (num == 0) {
        count = 0;
    }else if (num == 1){
        count = cnt;
    }
    for (int i = 1; i<num; i++) {
        count = count*cnt;
        if (i>=3) {
            count = (count - cnt*(i-2));
        }
    }
    return count;
}
