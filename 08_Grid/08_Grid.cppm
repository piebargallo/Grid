module;

#include <cstddef>

export module grid;

import <stdexcept>;
import <vector>;
import <optional>;
import <utility>;
import <format>;

export 
template <typename T,
	template <typename E, typename allocator = std::allocator<E>> 
	class Container = std::vector>
class Grid
{

public:
	explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
	virtual ~Grid() = default;

	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<Container<std::optional<T>>> m_cells;
	size_t m_width{ 0 };
	size_t m_height{ 0 };

};

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
void Grid<T, Container>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range{ std::format("{} must be less than {}.", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range{ std::format("{} must be less than {}.", y, m_height) };
	}
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
const std::optional<T>& Grid<T, Container>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
std::optional<T>& Grid<T, Container>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}