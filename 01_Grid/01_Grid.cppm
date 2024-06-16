/* 01_Grid The Grid class definition */

module;

#include <cstddef>

export module grid;

import <stdexcept>;
import <vector>;
import <optional>;
import <utility>;
import <format>;

export template <typename T>
class Grid
{
public:
	explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
	virtual ~Grid() = default;

	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	std::optional<T>& at(size_t x, size_t);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	static const size_t DefaultWidth { 10 };
	static const size_t DefaultHeight { 10 };

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<T>>> m_cells;
	size_t m_width { 0 }, m_height { 0 };
};