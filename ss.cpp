
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<1, X> operator+(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<1, X> operator-(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x - scalar};
	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<1, X> operator*(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<1, X> operator/(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<1, X> operator%(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x % scalar};
	}

	///////////////////////////////


	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<2, X> operator+(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x + scalar, lhs.y + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<2, X> operator-(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x - scalar, lhs.y - scalar};

	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<2, X> operator*(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x* scalar, lhs.y* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<2, X> operator/(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x / scalar, lhs.y / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<2, X> operator%(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x% scalar, lhs.y% scalar};
	}

	////////////////

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<3, X> operator+(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<3, X> operator-(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar};

	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<3, X> operator*(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x* scalar, lhs.y* scalar, lhs.z* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<3, X> operator/(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<3, X> operator%(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x% scalar, lhs.y% scalar, lhs.z% scalar};
	}

	////////////

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<4, X> operator+(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar, lhs.w + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<4, X> operator-(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar, lhs.w - scalar};
	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<4, X> operator*(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x* scalar, lhs.y* scalar, lhs.z* scalar, lhs.w* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<4, X> operator/(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar, lhs.w / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	constexpr Vector<4, X> operator%(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x % scalar, lhs.y % scalar, lhs.z % scalar, lhs.w % scalar};
	}