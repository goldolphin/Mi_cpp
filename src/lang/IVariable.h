/*
 * IVariable.h
 *
 *  Created on: 2013年8月17日
 *      Author: goldolphin
 */

#ifndef IVARIABLE_H_
#define IVARIABLE_H_

#include "memory/IValue.h"
#include "type/IType.h"

namespace mi {
namespace lang {

class IVariable {
public:
	const IType& getType() const{
		return _type;
	}

	virtual const IValue& getValue() const = 0;

	virtual void setValue(const IValue& value) = 0;

	virtual ~IVariable();
private:
	const IType& _type;

};

} /* namespace lang */
} /* namespace mi */
#endif /* IVARIABLE_H_ */
