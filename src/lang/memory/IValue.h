/*
 * IValue.h
 *
 *  Created on: 2013年8月17日
 *      Author: goldolphin
 */

#ifndef IVALUE_H_
#define IVALUE_H_

#include "../../common/Common.h"
#include "../../type/IType.h"

namespace mi {
namespace lang {

class IValue {
public:
	const IType& getType() const {
		return _type;
	}

	virtual int getSize() const = 0;

	virtual byte* getBytes() const = 0;

	template<typename T>
	T& cast() const {
		massert(sizeof(T) == getSize());
		return *reinterpret_cast<T*>(getBytes());
	}

	virtual void assign(const IValue& o) = 0;

	virtual ~IValue();
private:
	const IType& _type;
};

} /* namespace lang */
} /* namespace mi */
#endif /* IVALUE_H_ */
