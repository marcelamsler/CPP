#include "ring6.h"
#include <ostream>

std::ostream& operator <<(std::ostream& stream,Ring6 ring) {
	stream << ring.value();
	return stream;
}
