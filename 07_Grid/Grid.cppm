/* Could add to the grid template, a second type parameter specifyng another templatized class
   container on wich to built the Grid. */

module;

#include <cstddef>

export module grid;

import <stdexcept>;
import <vector>;
import <utility>;
import <format>;

template <typename Container>
concept ContainerType = requires(Container c)
{
	c.resize(1);
	typename Container::value_type;
};

export template <typename T, ContainerType Container>
class Grid
{
public:
	explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
	virtual ~Grid() = default;

	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	typename Container::value_type& at(size_t x, size_t y);
	const typename Container::value_type& at(size_t x, size_t y) const;

	size_t getWidth() const { return m_width; }
	size_t getHeight() const { return m_height; }
	
	static const size_t DefaultWidth { 10 };
	static const size_t DefaultHeight { 10 };

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<Container> m_cells;
	size_t m_width{ 0 };
	size_t m_height{ 0 };
};

template <typename T, ContainerType Container>
Grid<T, Container>::Grid(size_t width, size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width);
	for (auto& column : m_cells) {
		column.resize(m_height);
	}
}

template <typename T, ContainerType Container>
void Grid<T, Container>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range{ std::format("{} must be less than {}.", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range{ std::format("{} must be less than {}.", y, m_height) };
	}
}

template <typename T, ContainerType Container>
const typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template <typename T, ContainerType Container>
typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y)
{
	return const_cast<typename Container::value_type&>(
		std::as_const(*this).at(x, y));
}

