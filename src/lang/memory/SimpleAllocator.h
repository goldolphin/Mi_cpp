/*
 * SimpleAllocator.h
 *
 *  Created on: 2013年8月17日
 *      Author: goldolphin
 */

#ifndef SIMPLEALLOCATOR_H_
#define SIMPLEALLOCATOR_H_

#include <vector>

#include "../../common/Common.h"

namespace mi {
namespace lang {

class Buffer {
public:
	Buffer(int size): _bytes(size) {
	}

	int getSize() const {
		return _bytes.size();
	}

	template<typename T>
	T& cast() const {
		massert(sizeof(T) == getSize());
		return reinterpret_cast<T&>(*_bytes.data());
	}

private:
	std::vector<byte> _bytes;
};

class SimpleAllocator {
public:
	virtual ~SimpleAllocator();
};

} /* namespace lang */
} /* namespace mi */
#endif /* SIMPLEALLOCATOR_H_ */
