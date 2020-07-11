<p align="center"><img width=100% src="media/roninMathLibrary.png"></p>

<h4 align="center">Light-weight and Unburdened Vector & Matrix Header-Only Library</p>

[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue.svg)](http://unlicense.org/)

---
***
## Purpose


When creating small projects with light-weight OpenGL interfaces, like [SDL](https://www.libsdl.org/), I often found the need for a light-weight alternative to [GLM](https://github.com/g-truc/glm) - which was swelling my project size unnecessarily given how much of it I never used.

This gave birth to the *Ronin Math Library* ~~and evolved the standard of modern computational mathematics~~.

This library has been updated as my project's call for different functionality. This helps keep things exactly where I need it, not too much bloat or edge-case functionality. I really just enjoy writing my own libraries, since it's nice knowing how they work and knowing it's tailored to my specific uses.

***
## Functionality

What's supported? Well I'll tell ya'!

* Basic Vector Functionality Overview:
  * Vector & Vector: =, +, -, &(cross product), *(dot product), ```-```(negation)
  * Vector Access: .r(), .g(), .b(), .a(), [](by reference and value)
  * Matrix: *, OrthonormalBasis(v1, v2, v3)
  * Scalar: *, /
  * Output Stream Support: <<  
  * Other: .normalize(), .magnitude(), .unit(), .invert(), .squareMagnitude(), .angleBetween(vector), .addScaledVector(vector), .componentProduct(vector)

* Basic Matrix Functionality Overview:
  * Matrix & Matrix: =, +, -, *
  * Matrix Access: (row, column), >>
  * Scalar: *, /
  * Output Stream Support: <<

***
## Usage

When developing this library, I focused primarily on readability, as can be seen below.

The sample code below should explain the basic functionality of the library:

``` c++
    // Instantiate Three-Dimensional Vectors
	rn::vector3f v1(2, 4, 1);
	rn::vector3f v2(2, 1, 4);

    // Instantiate a vector from the product of two vectors
	rn::vector3f v3 = v1 + v2;

    /// Basic operations ///
	v3 += v1;

	v3 = v3 - v2;

	v3 -= v1;

	v3 = v1 * 2.f;

    // This one looks a little strange, just know it's setting the [0]th element to the scalar value calculated
    // Vector 2 is now the Scalar product of Vector 2 and Vector 1
	v2 = v2 * v1;

	v3 *= 2.f;

	v3 = v3 / 2.f;

	v3 /= 2.f;

	v3.normalize();

	v3 = v1.cross(v2);

	v3.addScaledVector(v1, 1.5f);

	rn::matrix m1(3, 3);
	m1(1, 2) = 2.5f;

	rn::matrix m2(m1);
	
	m2 = m2 * 2.f;

	m2 *= 2.f;

	m2 = m2 / 2.f;

	m1 += m2;

	for (int x = 0; x < m1.columnSize; x++)
		for (int y = 0; y < m1.rowSize; y++)
			m1(x, y) = x + y;

	for (int x = 0; x < m2.columnSize; x++)
		for (int y = 0; y < m2.rowSize; y++)
			m2(x, y) = 1 + x;

	m1 = m1*m2;

	v1 = v1 * m1;

	rn::vector3f v4(0.5f, 0.5f, 0.f);
	rn::vector3f v5(1.f, 0.f, 0.f);

    float f = rn::toDegrees(v4.angleBetween(v5))

```

***
## Q&A

### *Q*: How do I use this library?

**A**: All you need to do is drop these header files (matrix.h, vector.h, precision.h) into your project and ```#include``` them.

### *Q*: Why make it header-only?

**A**: In keeping with the light-weight theme, it only felt right. This is a very small library and being able to avoid compiling and packaging for different systems is a great advantage. Do note that header-only libraries can slow down compile times, but that is also fairly irrelevant given the size.

### *Q*: Will you continue developing this library?

**A**: Certainly! However, only when I find a need to add something will I add it to the master branch. I am doing my best to avoid bloat. (```randomInUnitSphere()``` is more useful than it seems, I swear! )