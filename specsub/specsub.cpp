#include "specsub.h"
#define PI 3.1415926
using namespace std;
void dft(double* data, int length)
{
	double *temp = new double[length];
	for (int i = 0; i < length; i++)
		temp[i] = data[i];
	for (int i = 0; i < length; i++)
	{
		double re = 0.0;
		double im = 0.0;
		for (int j = 0; j < length; j++)
		{
			re += temp[j] * cos(i*j*2.0*PI / length);
			im += temp[j] * sin(i*j*2.0*PI / length);
		}
		data[i] = re*re + im*im;
	}
	delete[] temp;
}


void enframe(double *data, vector<double *> out, int length, int win, int inc)
{
	int n = (length - win) / inc;
	int num = n + 1;  // Ö¡Êý
	
	for (int i = 0; i < num; i++)
		for (int j = 0; j < win; i++)
		{
			out[i][j] = data[i*inc + j];
		}
}

void enframe(double *data, vector<double *> out, int length, int win)
{
	int n = length / win;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < win; i++)
		{
			out[i][j] = data[i*win + j];
		}
}

double *noiseSpec(double *data, int length, int win, int inc)
{
	vector<double *> noise;
	enframe(data, noise, length, win, inc);
	double *averageSpec = new double[length];
	for (int i = 0; i < noise.size(); i++)
	{
		dft(noise[i], length);
		for (int j = 0; j < length; j++)
			averageSpec[j] += noise[i][j];
	}
	return averageSpec;
}

double *noiseSpec(double *data, int length, int win)
{
	vector<double *> noise;
	enframe(data, noise, length, win);
	double *averageSpec = new double[win];
	for (int i = 0; i < noise.size(); i++)
	{
		dft(noise[i], win);
		for (int j = 0; j < win; j++)
			averageSpec[j] += noise[i][j];
	}
	return averageSpec;
}

void specsub(double *data,double *noise, int win)
{
	double a = 4;
	double b = 0.001;
	for (int i = 0; i < win; i++)
		if (data[i] > a*noise[i])
			data[i] = data[i] - noise[i];
		else
			data[i] = b*noise[i];
}

void idft(double *data, int length)
{
	double *temp = new double[length];
	for (int i = 0; i < length; i++)
		temp[i] = data[i];
	for (int i = 0; i < length; i++)
	{
		double re = 0.0;
		double im = 0.0;
		for (int j = 0; j < length; j++)
		{
			re += temp[j] * cos(i*j*2.0*PI / length);
			im += temp[j] * sin(i*j*2.0*PI / length);
		}
		data[i] = re*re + im*im;
	}
	delete[] temp;
}


double *rec(vector<double *> vec,int win,int rec)
{
	double *out = new double[vec.size()*win];
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < win; j++)
			out[i*win + j] = vec[i][j];
}


void all(double *srcdata, double *noisedata, int srclength, int noiselength, int win)
{
	vector<double *> data;
	double *avragenoise = noiseSpec(noisedata, noiselength, win);

}