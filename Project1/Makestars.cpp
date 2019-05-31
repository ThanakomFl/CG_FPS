#include "Makestars.h"



Makestars::Makestars()
{

}

void Makestars::Makestar(float r, int n, float kx, float ky, float red, float green, float blue)
{
	glBegin(GL_POLYGON);
	for (int i = 1; i <= n; i++)
	{
		theta = 2.0 * pi * (float)i / n;
		x = kx + r * cos(theta);
		y = ky + r * sin(theta);
		glColor3f(red, green, blue);
		glVertex2f(x, y);
	}
	glEnd();
}



float Makestars::makeOrbitX(int r, float rotate, int n, float mx)
{
	float x;
	theta = 2.0 * pi * rotate / n;
	x = mx + r * cos(theta);
	return x;
}

float Makestars::makeOrbitY(int r, float rotate, int n, float my)
{
	float y;
	theta = 2.0 * pi * rotate / n;
	y = my + r * sin(theta);
	return y;
}


void Makestars::MakeangleR(float r, float kx, float ky, float red, float green, float blue)
{
	glLineWidth(1);
	glColor3f(red, green, blue);
	glBegin(GL_POLYGON);
	glVertex2f(kx - r - 1, ky);
	glVertex2f(kx - r, ky + r / 6);
	glVertex2f(kx + r, ky + r / 3);
	glVertex2f(kx + r + 1, ky);
	glVertex2f(kx + r, ky - r / 6);
	glVertex2f(kx - r, ky - r / 8);
	glEnd();
}

void Makestars::MakeangleL(float r, float kx, float ky, float red, float green, float blue)
{
	glLineWidth(1);
	glColor3f(red, green, blue);
	glBegin(GL_POLYGON);
	glVertex2f(kx - r - 1, ky);
	glVertex2f(kx - r, ky + r / 6);
	glVertex2f(kx + r, ky + r / 8);
	glVertex2f(kx + r + 1, ky);
	glVertex2f(kx + r, ky - r / 6);
	glVertex2f(kx - r, ky - r / 3);
	glEnd();
}

void Makestars::starline(float r, float kx, float ky, float red, float green, float blue, float widthz)
{
	glLineWidth(widthz);
	glColor3f(red, green, blue);
	glBegin(GL_LINES);
	glVertex2f(kx - r, ky - r);
	glVertex2f(kx + r, ky + r);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(kx + r, ky - r);
	glVertex2f(kx - r, ky + r);
	glEnd();
}

void Makestars::randomstar()
{
	int v1, v2;
	for (int i = -180; i <= 180; i += 3)
	{
		for (int j = -180; j <= 180; j += 3)
		{
			v1 = rand() % 121;
			v2 = rand() % 4;
			if (v1 == 3)
			{
				if (v2 == 0)
				{
					Makestar(1, n, i, j, 0.278, 0.352, 0.407);
				}
				else if (v2 == 1)
				{
					Makestar(1.5, n, i, j, 0.278, 0.352, 0.407);
				}
				else if (v2 == 2)
				{
					starline(1.5, i, j, 0.278, 0.352, 0.407, 3);
				}
				else
				{
					starline(1, i, j, 0.278, 0.352, 0.407, 2);
				}
			}
		}
	}
}

float Makestars::Update_X(float time, float m, float b)
{
	cout << "time:" << time << " m:" << m << " b:" << b << endl;
	x = m * time + b;
	return x;
}

float Makestars::Update_Y(float time, float m, float b)
{
	y = m * time + b;
	return y;
}

Makestars::~Makestars()
{
}
