#pragma once
#include "Eigen/Dense"
#include <vector>
#include <iostream>
#include <cmath>
using namespace Eigen;

// Function that takes a matrix of unknown size and find its row-echelon form
// Represent matrix with a vector of row vectors
void row_echelon(std::vector<VectorXi>& mat);

// Keep code binary after row operations (2 -> 0, -1 -> 1)
void adjustValue(VectorXi& vec);

// Swap two row vectors
void swap(std::vector<VectorXi>& mat, int i, int j);

// Overload std::cout for VectorXi
std::ostream& operator<<(std::ostream& os, std::vector<VectorXi>& mat);

// Remove duplicate after Gaussian elimination
void removeDuplicate(std::vector<VectorXi>& mat);

// Remove zero rows from mat
void removeZero(std::vector<VectorXi>& mat);
