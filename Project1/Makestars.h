#pragma once
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class Makestars
{
public:
	Makestars();
	~Makestars();
	float radius, originx, originy;
	const float pi = 3.14;
	int n = 200;
	float theta, r, kx, ky;
	float x, y;
	float merx, mery, moonx, moony;
	float merj = 1, vej = 1, eaj = 1, marj = 1, juj = 1, saj = 1, urj = 1, nej = 1;
	float moonj = 5;
	void Makestar(float r, int n, float kx, float ky, float red, float green, float blue);
	float makeOrbitX(int r, float rotate, int n, float mx);
	float makeOrbitY(int r, float rotate, int n, float my);
	void MakeangleL(float r, float kx, float ky, float red, float green, float blue);
	void MakeangleR(float r, float kx, float ky, float red, float green, float blue);
	void starline(float r, float kx, float ky, float red, float green, float blue, float widthz);
	void randomstar();
	float Update_X(float time, float m, float b);
	float Update_Y(float time, float m, float b);
};

