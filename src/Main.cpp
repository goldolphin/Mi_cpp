//============================================================================
// Name        : Main.cpp
// Author      : goldolphin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
	if (n <= 1) {
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

class IExpr {
public:
	virtual ~IExpr() {};
	virtual int evaluate() = 0;
};

class Number : public IExpr {
public:
	Number(int value) : value(value) {}

	virtual int evaluate() {
		return value;
	}

private:
	const int value;
};

class If : public IExpr {
public:
	If (IExpr& predicate, IExpr& consequent, IExpr& alternative)
		: predicate(predicate), consequent(consequent), alternative(alternative) {}

	virtual int evaluate() {
		if (predicate.evaluate() != 0) {
			return consequent.evaluate();
		} else {
			return alternative.evaluate();
		}
	}

private:
	IExpr& predicate;
	IExpr& consequent;
	IExpr& alternative;
};

class Environment {
private:

};

class Function {
public:
	Function(int paramNum, IExpr& body)
		: paramNum(paramNum), body(body) {
	}

	int apply(Environment env, vector<IExpr&> params) {
		return 0;
	}

private:
	int paramNum;
	IExpr& body;
};

int main() {
	for (int i = 0; i < 5; i ++) {
		cout << fib(i) << endl;
	}

	return 0;
}
