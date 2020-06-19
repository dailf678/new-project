#if true

/*
    Header GaussRand 正态分布随机
    File version 1
    TC202006171426
    https://www.cnblogs.com/yeahgis/archive/2012/07/13/2590485.html
*/

#include "GaussRand.h"

namespace MGM
{
	double GaussRand()
	{
		static double V1, V2, S;
		static int phase = 0;
		double X;
		if (phase == 0) {
			do {
				double U1 = (double)rand() / RAND_MAX;
				double U2 = (double)rand() / RAND_MAX;
				V1 = 2 * U1 - 1;
				V2 = 2 * U2 - 1;
				S = V1 * V1 + V2 * V2;
			} while (S >= 1 || S == 0);
			X = V1 * sqrt(-2 * log(S) / S);
		}
		else
			X = V2 * sqrt(-2 * log(S) / S);
		phase = 1 - phase;
		return X;
	}

	double FixedGaussRand(double Expt, double Vari)
	{
		return GaussRand() * Vari + Expt;
	}
}

/*
    Header GaussRand 正态分布随机
    End
*/

#endif