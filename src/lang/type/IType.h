/*
 * IType.h
 *
 *  Created on: 2013年8月17日
 *      Author: goldolphin
 */

#ifndef ITYPE_H_
#define ITYPE_H_

namespace mi {
namespace lang {

class IType {
public:
	virtual const mstring & getName() const = 0;

	virtual bool equals(const IType& o) const = 0;

	virtual IValue & newInstance();

	virtual ~IType() {}

protected:
	IType() {}
};

} /* namespace lang */
} /* namespace mi */
#endif /* ITYPE_H_ */
