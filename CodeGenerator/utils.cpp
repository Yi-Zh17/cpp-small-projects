#include "utils.h"

void row_echelon(std::vector<VectorXi>& mat)
{
	for (int i = 0; i < mat[0].size(); i++)
	{
		// First row should have a leading 1 if there is one, and so forth
		for (int j = i; j < mat.size(); j++)
		{
			if (mat[j][i] == 1 && j == 0) break;
			else if (mat[j][i] == 1 && j != 0)
			{
				swap(mat, j, i);
				break;
			}
		}
		// Gaussian elimination
		if (mat[i][i] == 1)
		{
			for (int j = i+1; j < mat.size(); j++)
			{
				if (mat[j][i] == 1)
				{
					mat[j] = mat[j] - mat[i];
					adjustValue(mat[j]);
				}
			}
		}
	}
	removeDuplicate(mat);
	removeZero(mat);
}

void adjustValue(VectorXi& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 2) vec[i] = 0;
		else if (vec[i] == -1) vec[i] = 1;
	}
}

void swap(std::vector<VectorXi>& mat, int i, int j)
{
	VectorXi temp = mat[i];
	mat[i] = mat[j];
	mat[j] = temp;
}

std::ostream& operator<<(std::ostream& os, std::vector<VectorXi>& mat)
{
	for (VectorXi vec : mat)
	{
		for (int i : vec)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	return std::cout;
}

void removeDuplicate(std::vector<VectorXi>& mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = i + 1; j < mat.size(); j++)
		{
			if (mat[i] == mat[j]) mat[j] = mat[i] - mat[j];
		}
	}
}

void removeZero(std::vector<VectorXi>& mat)
{
	// Remove zero rows from the back
	for (int i = mat.size() - 1; i >= 0; i--)
	{
		for (int j : mat[i])
		{
			if (j != 0) return;
		}
		mat.pop_back();
	}
}

