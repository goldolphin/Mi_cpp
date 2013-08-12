/*
 * AbstractType.h
 *
 *  Created on: 2013年8月10日
 *      Author: goldolphin
 */

#ifndef ABSTRACTTYPE_H_
#define ABSTRACTTYPE_H_

#include <iostream>

#include "../../common/Common.h"

namespace mi {
namespace lang {

class AbstractType {
public:
	AbstractType(int category): _category(category) {}

	int getCategory() const {
		return _category;
	}

	virtual const mstring & getName() const = 0;

	virtual bool equals(const AbstractType& o) const = 0;

	virtual ~AbstractType() {}

private:
	const int _category;
};

} /* namespace lang */
} /* namespace mi */
#endif /* ABSTRACTTYPE_H_ */
