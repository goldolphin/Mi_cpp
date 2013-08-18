/*
 * Value.h
 *
 *  Created on: 2013年8月17日
 *      Author: goldolphin
 */

#ifndef VALUE_H_
#define VALUE_H_

#include "type/IType.h"

namespace mi {
namespace lang {

class Value {
public:
	virtual ~Value();
private:
	const IType& type;

};

} /* namespace lang */
} /* namespace mi */
#endif /* VALUE_H_ */
