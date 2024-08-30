#include "Eigen/eigen"
#include "utils.h"
#include <iostream>

int main()
{
	std::vector<VectorXi> mat;
	Vector4i row1(1, 0, 1, 1);
	Vector4i row2(1, 1, 1, 1);
	Vector4i row3(0, 1, 0, 1);
	Vector4i row4(1, 1, 1, 1);
	Vector4i row5(0, 1, 0, 0);
	Vector4i row6(0, 0, 0, 1);
	mat.push_back(row1);
	mat.push_back(row2);
	mat.push_back(row3);
	mat.push_back(row4);
	mat.push_back(row5);
	mat.push_back(row6);

	row_echelon(mat);
	std::cout << mat << std::endl;
}
