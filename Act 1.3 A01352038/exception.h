using namespace std;
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>
#include <cstdio>
//Sergio Augusto Macías Corona
//A01352038

class Exception : public std::exception {
protected:
	string text;

public:
	Exception() throw();
	~Exception() throw();
	virtual const char* what() const throw();
};

Exception::Exception() throw ()
	: text("Basic exception") {
}

Exception::~Exception() throw () {}

const char* Exception::what() const throw() {
	return text.c_str();
}

class RangeError : public Exception {
public:
	RangeError() throw();
};

RangeError::RangeError() throw () {
		text = string("RangeError");
}

class OutOfMemory : public Exception {
public:
	OutOfMemory() throw();
};

OutOfMemory::OutOfMemory() throw () {
		text = string("OutOfMemory");
}

class IndexOutOfBounds : public Exception {
public:
	IndexOutOfBounds() throw();
};

IndexOutOfBounds::IndexOutOfBounds() throw () {
	text = string("IndexOutOfBounds");
}

class NoSuchElement : public Exception {
public:
	NoSuchElement() throw();
};

NoSuchElement::NoSuchElement() throw () {
		text = string("NoSuchElement");
}

class IllegalAction : public Exception {
public:
	IllegalAction() throw();
};

IllegalAction::IllegalAction() throw () {
		text = std::string("IllegalAction");
}

class Overflow : public Exception {
public:
	Overflow() throw();
};

Overflow::Overflow() throw () {
		text = string("Overflow");
}
#endif /* EXCEPTION_H */
