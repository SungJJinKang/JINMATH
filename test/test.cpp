#include <iostream>

struct Vector3
{
	float x, y, z;
};

struct alignas(32) Position_BoundingSphereRadius
{
	Vector3 Position;
	float BoundingSphereRadius;
};

int main()
{
	Position_BoundingSphereRadius a;
	std::cout << sizeof(Position_BoundingSphereRadius);
}