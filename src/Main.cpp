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

class Frame {
public:
	void addVar(int value) {
		variables.push_back(value);
	}

	int getVar(int id) {
		return variables[id];
	}

private:
	vector<int> variables;
};

class Environment {
public:
	void addFrame() {
		frames.resize(frames.size()+1);
	}

	void removeFrame() {
		frames.resize(frames.size()-1);
	}

	void addVar(int value, int frame = 0) {
		frames[frames.size()-1-frame].addVar(value);
	}

	int getVar(int id, int frame = 0) {
		return frames[frames.size()-1-frame].getVar(id);
	}

private:
	vector<Frame> frames;
};

class IExpr {
public:
	virtual ~IExpr() {};
	virtual int evaluate(Environment& env) = 0;
};

class Number : public IExpr {
public:
	Number(int value) : value(value) {}

	virtual int evaluate(Environment& env) {
		return value;
	}

private:
	const int value;
};

class Variable : public IExpr {
public:
	Variable(int id, int frame) : id(id), frame(frame) {
	}

	virtual int evaluate(Environment& env) {
		return env.getVar(id, frame);
	}

private:
	int id;
	int frame;
};

class If : public IExpr {
public:
	If (IExpr& predicate, IExpr& consequent, IExpr& alternative)
		: predicate(predicate), consequent(consequent), alternative(alternative) {}

	virtual int evaluate(Environment& env) {
		if (predicate.evaluate(env) != 0) {
			return consequent.evaluate(env);
		} else {
			return alternative.evaluate(env);
		}
	}

private:
	IExpr& predicate;
	IExpr& consequent;
	IExpr& alternative;
};

class IFunction {
public:
	virtual ~IFunction() {};
	virtual int apply(Environment& env, vector<int>& params) = 0;
};

class Function : public IFunction {
public:
	Function(int paramNum)
		: paramNum(paramNum), body(NULL) {
	}

	void setBody(IExpr& body) {
		this->body = &body;
	}

	virtual int apply(Environment& env, vector<int>& params) {
		env.addFrame();
		for (auto p = params.begin(); p != params.end(); p ++) {
			env.addVar(*p);
		}
		int ret = body->evaluate(env);
		env.removeFrame();
		return ret;
	}

private:
	int paramNum;
	IExpr* body;
};
/*
class FuncApply : public IExpr {
public:
	FuncApply(IFunction& function, IExpr& param1)
		: function(function) {
		params.push_back(param1);
	}

	FuncApply(IFunction& function, IExpr& param1, IExpr& param2)
		: function(function) {
		params.push_back(param1);
		params.push_back(param2);
	}

	virtual int evaluate(Environment& env) {
		vector<int> evaluated;
		for (auto p = params.begin(); p != params.end(); p ++) {
			evaluated.push_back((*p).evaluate(env));
		}
		return function.apply(env, evaluated);
	}

private:
	IFunction& function;
	vector<IExpr> params;
};


class LessEqual : public IFunction {
public:
	virtual int apply(Environment& env, vector<int>& params) {
		return params[0] <= params[1];
	}
};

class Add : public IFunction {
public:
	virtual int apply(Environment& env, vector<int>& params) {
		return params[0] + params[1];
	}
};

class Minus : public IFunction {
public:
	virtual int apply(Environment& env, vector<int>& params) {
		return params[0] - params[1];
	}
};
*/

int fib(int n) {
	if (n <= 1) {
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

/*
int fib2(int n) {
	LessEqual le;
	Add add;
	Minus minus;
	Function fib(1);
	Variable N(0, 0);
	Number One(1);
	Number Two(2);

	FuncApply le1(le, N, One);
	FuncApply minus1(minus, N, One);
	FuncApply minus2(minus, N, Two);
	FuncApply alternative(add, minus1, minus2);
	If body(le1, One, alternative);
	fib.setBody(body);
	Environment env;
	return (new FuncApply(fib, *(new Number(n))))->evaluate(env);
}
*/
int main() {
	for (int i = 0; i < 5; i ++) {
		cout << fib(i) << endl;
	}

	return 0;
}
