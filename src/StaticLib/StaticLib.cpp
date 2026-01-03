#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include <stdlib.h>   // qsort用
// qsort用の比較関数
// 'TEST_METHOD(たくさんの要素を入れ替え)'でタイムアウトするのを回避する
static int item_cmp(const void *a, const void *b)
{
    const item * ia = (const item*)a;
    const item * ib = (const item*)b;

    return ia->key - ib->key;
}

// バブルソート(引数が不適切であればfalseを返す)
bool bubble_sort(item* begin, const item* end)
{
    // 引数チェック
    if (begin == NULL || end == NULL) return false;

    if (begin >= end) return false;

    size_t count = (size_t)(end - begin);
    qsort(begin, count, sizeof(item), item_cmp);

    return true;
}
