#include <iostream>

#include "Vector.h"
#include "Matrix.h"


int main()
{
	std::cout << "Vectors: " << std::endl;

	rn::vector3f v1(2, 4, 1);
	std::cout << "Vector 1: " << v1 << std::endl;
	rn::vector3f v2(2, 1, 4);
	std::cout << "Vector 2: " << v2 << std::endl;

	rn::vector3f v3 = v1 + v2;
	std::cout << "Add Vector 1 and 2 to get Vector 3: " << v3 << std::endl;

	v3 += v1;
	std::cout << "Add Vector 3 and 1: " << v3 << std::endl;

	v3 = v3 - v2;
	std::cout << "Subtract Vector 3 by 2: " << v3 << std::endl;

	v3 -= v1;
	std::cout << "Subtract Vector 3 by 1: " << v3 << std::endl << std::endl;

	v3 = v1 * 2.f;
	std::cout << "Multiply Vector 3 by value of 2: " << v3 << std::endl;

	v2 = v2 * v1;
	std::cout << "Vector 2 is now the Scalar product of Vector 2 and Vector 1: " << v2 << std::endl;

	v3 *= 2.f;
	std::cout << "Multiply Vector 3 by value of 2 again: " << v3 << std::endl;

	v3 = v3 / 2.f;
	std::cout << "Divide Vector 3 by value of 2: " << v3 << std::endl;

	v3 /= 2.f;
	std::cout << "Divide Vector 3 by value of 3: " << v3 << std::endl << std::endl;

	v3.normalize();
	std::cout << "Normalize Vector 3: " << v3 << std::endl << std::endl;

	v3 = v1.cross(v2);
	std::cout << "Cross Vector 1 and 2 to get Vector 3: " << v3 << std::endl << std::endl;

	v3.addScaledVector(v1, 1.5f);
	std::cout << "Add scaled vector " << v1 << " scaled by 1.5f to Vector 3: " << v3 << std::endl;
	std::cout << "Scaled vector is " << (1.5f * v1) << std::endl << std::endl;

	std::cout << "___________________________________________" << std::endl;
	std::cout << "Matrices:" << std::endl;

	rn::matrix m1(3, 3);
	std::cout << "Matrix 1:" << std::endl << m1 << std::endl;

	m1(1, 2) = 2.5f;
	std::cout << "Change row 1, column 2 value to 2.5:" << std::endl << m1 << std::endl;

	rn::matrix m2(m1);
	std::cout << "Matrix 2 is copied from Matrix 1: " << std::endl << m2 << std::endl;
	
	m2 = m2 * 2.f;
	std::cout << "Matrix 2 is multiplied by 2:" << std::endl << m2 << std::endl;

	m2 *= 2.f;
	std::cout << "Matrix 2 is multiplied by 2 again:" << std::endl << m2 << std::endl;

	m2 = m2 / 2.f;
	std::cout << "Matrix 2 is divided by 2:" << std::endl << m2 << std::endl;

	m1 += m2;
	std::cout << "Matrix 2 is added to Matrix 1:" << std::endl << m1 << std::endl;

	for (int x = 0; x < m1.columnSize; x++)
		for (int y = 0; y < m1.rowSize; y++)
			m1(x, y) = x + y;

	std::cout << "Matrix 1:" << std::endl << m1 << std::endl;

	for (int x = 0; x < m2.columnSize; x++)
		for (int y = 0; y < m2.rowSize; y++)
			m2(x, y) = 1 + x;

	std::cout << "Matrix 2:" << std::endl << m2 << std::endl;

	m1 = m1*m2;
	std::cout << "Matrix 1 is the dot product of Matrix 1 and Matrix 2:" << std::endl << m1 << std::endl;

	v1 = v1 * m1;
	std::cout << "Vector 1 dotted by Matrix 1 is:" << std::endl << v1 << std::endl;

	//system("PAUSE");
    return 0;
}

