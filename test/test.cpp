#include <iostream>

struct Vector3
{
	FLOAT32 x, y, z;
};

struct alignas(32) Position_BoundingSphereRadius
{
	Vector3 Position;
	FLOAT32 BoundingSphereRadius;
};

INT32 main()
{
	Position_BoundingSphereRadius a;
	std::cout << sizeof(Position_BoundingSphereRadius);
}