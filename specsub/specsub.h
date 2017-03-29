#pragma once
#include <vector>
//分帧函数     数据          数据长度    帧长    帧移
void enframe(double *data, int length, int win, int inc);
//获取基底噪声谱
double *noiseSpec(double *data, int length, int win, int inc);
//  谱减
void specsub(double *data,double *noise, int win);

void dft(double* data, int length);

void idft(double *data, int length);

double *rec(vector<double *> vec, int win,int rec);

void enframe(double *data, vector<double *> out, int length, int win);

double *noiseSpec(double *data, int length, int win);