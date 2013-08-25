/*
 * IAllocator.h
 *
 *  Created on: 2013年8月17日
 *      Author: goldolphin
 */

#ifndef IALLOCATOR_H_
#define IALLOCATOR_H_

#include <vector>

#include "../../common/Common.h"

namespace mi {
namespace lang {

template<typename T>
class IReference {
public:
	void set(T& value) = 0;
	T& get() const = 0;
};

class IBuffer {
public:

	virtual int getSize() const = 0;

	virtual byte* getData() const = 0;

	template<typename T>
	T& cast() const {
		massert(sizeof(T) == getSize());
		return *reinterpret_cast<T*>(getData());
	}

	virtual ~IBuffer() {}
};

class IAllocator {
public:
	virtual byte* allocate(int size) = 0;

	virtual ~IAllocator();
};

} /* namespace lang */
} /* namespace mi */
#endif /* IALLOCATOR_H_ */
