#pragma once
#include <cstdint>


struct Typed
{
	enum Type {
		None,
		Integer,
		Real
	};

	Typed()
		: type(Type::None)
	{}

	Typed(Type type_)
		: type(type_)
	{}

	bool checkType(const Typed& value) const {
		return type == value.type;
	}

	Type type;
};


struct Value : public Typed
{
	Value()
	{}

	void setValue(int64_t value) {
		this->type = Typed::Integer;
		this->value.integer = value;
	}

	void setValue(double value) {
		this->type = Typed::Real;
		this->value.real = value;
	}

	union {
		int integer;
		float real;
	} value;
};
