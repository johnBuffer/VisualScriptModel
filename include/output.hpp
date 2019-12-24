#pragma once
#include "value.hpp"
#include <memory>
#include <mutex>


struct Output : public Typed
{
	using ptr = std::shared_ptr<Output>;
	using const_ptr = std::shared_ptr<const Output>;

	Output(Typed::Type type)
		: Typed(type)
		, value()
	{}

	const Value& read() const {
		return value;
	}

	void write(const Value& value) {

	}

	static ptr create(Typed::Type type) {
		return std::make_shared<Output>(type);
	}

	Value value;
	std::mutex mutex;
};
