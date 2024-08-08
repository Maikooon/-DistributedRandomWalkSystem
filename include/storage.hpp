/*
指定されたファイルからエッジデータを読み込み、配列に格納
const char* fname: 読み込むファイルの名前を示す文字列。
T* &edge: 読み込んだエッジデータを格納するためのポインタの参照。関数内で動的に割り当てられます。
edge_id_t &e_num: 読み込んだエッジの数を格納するための参照。

*/

#pragma once

#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "type.hpp"

template <typename T>
void read_graph(const char *fname, T *&edge, edge_id_t &e_num)
{
    FILE *f = fopen(fname, "r");
    assert(f != NULL);
    fseek(f, 0, SEEK_END);
    size_t total_size = ftell(f);
    size_t total_e_num = total_size / sizeof(T);
    e_num = total_e_num;
    edge = new T[e_num];
    fseek(f, 0, SEEK_SET);
    auto ret = fread(edge, sizeof(T), e_num, f);
    assert(ret == e_num);
    fclose(f);
}