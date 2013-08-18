/*
 * IValue.h
 *
 *  Created on: 2013年8月17日
 *      Author: goldolphin
 */

#ifndef IVALUE_H_
#define IVALUE_H_

namespace mi {
namespace lang {

class IValue {
public:
	const IType& getType() const {
		return _type;
	}

	virtual ~IValue();
private:
	const IType& _type;
};

} /* namespace lang */
} /* namespace mi */
#endif /* IVALUE_H_ */
