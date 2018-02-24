#ifndef BATTLESHIPS_FIELD_H_
#define BATTLESHIPS_FIELD_H_

#include <cstddef>
#include <utility>

namespace ts {

class Field {
public:
	Field(std::size_t y, std::size_t x);
	virtual ~Field() = default;

private:
    std::pair<std::size_t, std::size_t> position;
};

} // namespace ts

#endif // BATTLESHIPS_FIELD_H_
