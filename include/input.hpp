#pragma once
#include <iostream>
#include "value.hpp"
#include "output.hpp"


struct Input : public Typed
{
	Input() = default;

	Input(Typed::Type type)
		: Typed(type)
	{}

	const Value& read() {
		if (output) {
			if (checkType(*output)) {
				value = output->read();
			}
		}
		value.type = Typed::None;
		return value;
	}

	Output::const_ptr output;
	Value value;
	bool ready;
};
