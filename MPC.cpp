
#include <iostream>
#include "midaco.h"
#include "MMath.h"

using namespace std;

double rollTarget = 1;
double pitchTarget = 1;
double yawTarget = 1;

// Array declarations

double f[3][1] = { 10,5,2 };

double dx[6][1] = { 0.0001, 0.0100, -0.0001, -0.0100, 0.0000, 0.0020 };
double y[3][1] = { 0.5, 1, 1.5 };

double IqTnQ[90][6] = { {1, 0.02, 0, 0, 0, 0}, { 0,0,1,0.02,0,0 }, { 0,0,0,0,1,0.02 }, { 2,0.06,0,0,0,0 }, { 0,0,2,0.06,0,0 }, { 0,0,0,0,2,0.06 }, { 3,0.12,0,0,0,0 }, { 0,0,3,0.12,0,0 }, { 0,0,0,0,3,0.12 }, { 4,0.2,0,0,0,0 }, { 0,0,4,0.2,0,0 }, { 0,0,0,0,4,0.2 }, { 5,0.3,0,0,0,0 }, { 0,0,5,0.3,0,0 }, { 0,0,0,0,5,0.3 }, { 6,0.42,0,0,0,0 }, { 0,0,6,0.42,0,0 }, { 0,0,0,0,6,0.42 }, { 7,0.56,0,0,0,0 }, { 0,0,7,0.56,0,0 }, { 0,0,0,0,7,0.56 }, { 8,0.72,0,0,0,0 }, { 0,0,8,0.72,0,0 }, { 0,0,0,0,8,0.72 }, { 9,0.9,0,0,0,0 }, { 0,0,9,0.9,0,0 }, { 0,0,0,0,9,0.9 }, { 10,1.1,0,0,0,0 }, { 0,0,10,1.1,0,0 }, { 0,0,0,0,10,1.1 }, { 11,1.32,0,0,0,0 }, { 0,0,11,1.32,0,0 }, { 0,0,0,0,11,1.32 }, { 12,1.56,0,0,0,0 }, { 0,0,12,1.56,0,0 }, { 0,0,0,0,12,1.56 }, { 13,1.82,0,0,0,0 }, { 0,0,13,1.82,0,0 }, { 0,0,0,0,13,1.82 }, { 14,2.1,0,0,0,0 }, { 0,0,14,2.1,0,0 }, { 0,0,0,0,14,2.1 }, { 15,2.4,0,0,0,0 }, { 0,0,15,2.4,0,0 }, { 0,0,0,0,15,2.4 }, { 16,2.72,0,0,0,0 }, { 0,0,16,2.72,0,0 }, { 0,0,0,0,16,2.72 }, { 17,3.06,0,0,0,0 }, { 0,0,17,3.06,0,0 }, { 0,0,0,0,17,3.06 }, { 18,3.42,0,0,0,0 }, { 0,0,18,3.42,0,0 }, { 0,0,0,0,18,3.42 }, { 19,3.8,0,0,0,0 }, { 0,0,19,3.8,0,0 }, { 0,0,0,0,19,3.8 }, { 20,4.2,0,0,0,0 }, { 0,0,20,4.2,0,0 }, { 0,0,0,0,20,4.2 }, { 21,4.62,0,0,0,0 }, { 0,0,21,4.62,0,0 }, { 0,0,0,0,21,4.62 }, { 22,5.06,0,0,0,0 }, { 0,0,22,5.06,0,0 }, { 0,0,0,0,22,5.06 }, { 23,5.52,0,0,0,0 }, { 0,0,23,5.52,0,0 }, { 0,0,0,0,23,5.52 }, { 24,6,0,0,0,0 }, { 0,0,24,6,0,0 }, { 0,0,0,0,24,6 }, { 25,6.5,0,0,0,0 }, { 0,0,25,6.5,0,0 }, { 0,0,0,0,25,6.5 }, { 26,7.02,0,0,0,0 }, { 0,0,26,7.02,0,0 }, { 0,0,0,0,26,7.02 }, { 27,7.56,0,0,0,0 }, { 0,0,27,7.56,0,0 }, { 0,0,0,0,27,7.56 }, { 28,8.12,0,0,0,0 }, { 0,0,28,8.12,0,0 }, { 0,0,0,0,28,8.12 }, { 29,8.7,0,0,0,0 }, { 0,0,29,8.7,0,0 }, { 0,0,0,0,29,8.7 }, { 30,9.3,0,0,0,0 }, { 0,0,30,9.3,0,0 }, { 0,0,0,0,30,9.3 }};
double IqC[90][3] = { { 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 },{ 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 } };
double WyG[90][3] = { {0.039264, 0, 0}, { 0,0.012361,0 }, { 0,0,0.068789 }, { 0.15706,0,0 }, { 0,0.049446,0 }, { 0,0,0.27516 }, { 0.35338,0,0 }, { 0,0.11125,0 }, { 0,0,0.6191 }, { 0.62822,0,0 }, { 0,0.19778,0 }, { 0,0,1.1006 }, { 0.9816,0,0 }, { 0,0.30904,0 }, { 0,0,1.7197 }, { 1.4135,0,0 }, { 0,0.44501,0 }, { 0,0,2.4764 }, { 1.9239,0,0 }, { 0,0.60571,0 }, { 0,0,3.3707 }, { 2.5129,0,0 }, { 0,0.79113,0 }, { 0,0,4.4025 }, { 3.1804,0,0 }, { 0,1.0013,0 }, { 0,0,5.5719 }, { 3.9264,0,0 }, { 0,1.2361,0 }, { 0,0,6.8789 }, { 4.7509,0,0 }, { 0,1.4957,0 }, { 0,0,8.3235 }, { 5.654,0,0 }, { 0,1.7801,0 }, { 0,0,9.9057 }, { 6.6356,0,0 }, { 0,2.0891,0 }, { 0,0,11.625 }, { 7.6957,0,0 }, { 0,2.4229,0 }, { 0,0,13.483 }, { 8.8344,0,0 }, { 0,2.7813,0 }, { 0,0,15.478 }, { 10.052,0,0 }, { 0,3.1645,0 }, { 0,0,17.61 }, { 11.347,0,0 }, { 0,3.5725,0 }, { 0,0,19.88 }, { 12.722,0,0 }, { 0,4.0051,0 }, { 0,0,22.288 }, { 14.174,0,0 }, { 0,4.4625,0 }, { 0,0,24.833 }, { 15.706,0,0 }, { 0,4.9446,0 }, { 0,0,27.516 }, { 17.315,0,0 }, { 0,5.4514,0 }, { 0,0,30.336 }, { 19.004,0,0 }, { 0,5.983,0 }, { 0,0,33.294 }, { 20.771,0,0 }, { 0,6.5392,0 }, { 0,0,36.39 }, { 22.616,0,0 }, { 0,7.1202,0 }, { 0,0,39.623 }, { 24.54,0,0 }, { 0,7.7259,0 }, { 0,0,42.993 }, { 26.542,0,0 }, { 0,8.3564,0 }, { 0,0,46.502 }, { 28.623,0,0 }, { 0,9.0115,0 }, { 0,0,50.147 }, { 30.783,0,0 }, { 0,9.6914,0 }, { 0,0,53.931 }, { 33.021,0,0 }, { 0,10.396,0 }, { 0,0,57.852 }, { 35.338,0,0 }, { 0,11.125,0 }, { 0,0,61.91 }};
double R[90][1];
double F[90][1];
double temp1[90][1], temp2[90][1], temp3[1][90], temp4[1][3];

// Pointer declarations
double **_f		= ptrAlloc(3, 1, f);
double **_dx	= ptrAlloc(6, 1, dx);
double **_y		= ptrAlloc(6, 1, y);
double **_IqTnQ = ptrAlloc(90, 6, IqTnQ);
double **_IqC	= ptrAlloc(90, 3, IqC);
double **_WyG	= ptrAlloc(90, 3, WyG);
double **_R		= ptrAlloc(90, 1, R);
double **_F		= ptrAlloc(90, 1, F);
double **_temp1 = ptrAlloc(90, 1, temp1);
double **_temp2 = ptrAlloc(90, 1, temp2);
double **_temp3 = ptrAlloc(1, 90, temp3);
double **_temp4 = ptrAlloc(1, 3, temp4);

int N = 30;
  
void calculate_f()
{
	// F
	Mmultiply(_IqTnQ, _dx, 90, 6, 6, 1, _temp1);

	cout << "temp1: " << endl;
	///*for (int j = 0; j < 3*N; j++)
	//{
	//	cout << "[" << j << "]: " << _temp1[j][0] << endl;
	//}*/
	Mmultiply(_IqC, _y, 90, 3, 3, 1, _temp2);
	cout << "temp2: " << endl;
	/*for (int j = 0; j < 3 * N; j++)
	{
		cout << "[" << j << "]: " << _temp2[j][0] << endl;
	}*/
	Madd(_temp1, _temp2,90, 1, _F);
	cout << "F: " << endl;
	/*for (int j = 0; j < 3 * N; j++)
	{
		cout << "[" << j << "]: " << _F[j][0] << endl;
	}*/

	// R
	for (int i = 0; i < 90; i += 3)
	{
		R[i][0] = rollTarget;
		R[i + 1][0] = pitchTarget;
		R[i + 2][0] = yawTarget;
	}

	// f
	Msubtract(_F, _R, 90, 1, _temp1);	
	cout << "temp1: " << endl;
	/*for (int j = 0; j < 3 * N; j++)
	{
		cout << "[" << j << "]: " << _temp1[j][0] << endl;
	}*/
	Mtranspose(_temp1, 90, 1, _temp3);
	cout << "temp3: " << endl;
	/*for (int j = 0; j < 3 * N; j++)
	{
		cout << "[" << j << "]: " << _temp3[0][j] << endl;
	}*/
	Mmultiply(_temp3, _WyG, 1, 90, 90, 3, _temp4);
	cout << "temp4: " << endl;
	/*for (int j = 0; j < 3; j++)
	{
		cout << "[" << j << "]: " << _temp4[0][j] << endl;
	}*/
	MmultiplyScalar(_temp4, 1, 3, 2, _temp4);
	Mtranspose(_temp4, 1, 3, _f);
}

int main()
{
	double ftemp[3];
	calculate_f();

	std::cout << "f: " << f[0][0] << " " << f[1][0] << " " << f[2][0] << std::endl;

	ftemp[0] = f[0][0];
	ftemp[1] = f[1][0];
	ftemp[2] = f[2][0];

	solve(&*ftemp);
	system("pause");
	return 0;
}

