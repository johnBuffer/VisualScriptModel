#pragma once
#include <map>
#include <cstring>
#include <thread>

#include "input.hpp"
#include "output.hpp"


struct Node
{
	Node()
		: stop_required(false)
	{}

	void addInput(const std::string& in_name, Typed::Type type) {
		inputs[in_name] = Input(type);
	}

	void addOutput(const std::string& out_name, Typed::Type type) {
		outputs[out_name] = Output::create(type);
	}

	void start() {
		thread = std::thread([&] { process(); });
	}

	void process() {
		while (!stop_required) {
			for (auto in : inputs) {
				in.second.read();
			}

			core();
		}
	}

	void stop() {
		stop_required = true;
	}

	virtual void core() = 0;

	std::map<std::string, Input> inputs;
	std::map<std::string, Output::ptr> outputs;

	bool stop_required;
	std::thread thread;
};