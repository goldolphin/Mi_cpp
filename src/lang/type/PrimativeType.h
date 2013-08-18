/*
 * PrimativeType.h
 *
 *  Created on: 2013年8月10日
 *      Author: goldolphin
 */

#ifndef PRIMATIVETYPE_H_
#define PRIMATIVETYPE_H_

#include "IType.h"

namespace mi {
namespace lang {

class PrimativeType: public IType {
public:
	virtual const mstring & getName() const {
		return _name;
	}

	virtual bool equals(const IType& o) const {
		if (typeid(o) != typeid(PrimativeType)) {
			return false;
		}
		auto that = static_cast<const PrimativeType&>(o);
		return _name == that._name;
	}

private:
	const mstring _name;
};

} /* namespace lang */
} /* namespace mi */
#endif /* PRIMATIVETYPE_H_ */
