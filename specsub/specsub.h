#pragma once
#include <vector>
//��֡����     ����          ���ݳ���    ֡��    ֡��
void enframe(double *data, int length, int win, int inc);
//��ȡ����������
double *noiseSpec(double *data, int length, int win, int inc);
//  �׼�
void specsub(double *data,double *noise, int win);

void dft(double* data, int length);

void idft(double *data, int length);

double *rec(vector<double *> vec, int win,int rec);

void enframe(double *data, vector<double *> out, int length, int win);

double *noiseSpec(double *data, int length, int win);