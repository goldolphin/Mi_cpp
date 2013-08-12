/*
 * PrimativeType.h
 *
 *  Created on: 2013年8月10日
 *      Author: goldolphin
 */

#ifndef PRIMATIVETYPE_H_
#define PRIMATIVETYPE_H_

#include "AbstractType.h"

namespace mi {
namespace lang {

class PrimativeType: public AbstractType {
public:
	virtual const mstring & getName() const {
		return _name;
	}

	virtual bool equals(const AbstractType& o) const {
		if (getCategory() != o.getCategory()) {
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
