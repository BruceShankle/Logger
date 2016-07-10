#pragma once
#include <string>
#include "Position.h"

class Actor {
public:
	//Update based on elapsed time (seconds)
	void Update(double elapsedTime) {
		double dx = _velocity.x * elapsedTime;
		double dy = _velocity.y * elapsedTime;
		_position.x += dx;
		_position.y += dy;
	}

	Position GetPosition() { return _position; }
	void SetVelocity(double x, double y) {
		_velocity.x = x;
		_velocity.y = y;
	}

	void ReverseX() {
		_velocity.x = -_velocity.x;
	}

	void ReverseY() {
		_velocity.y = -_velocity.y;
	}

protected:
	Position _position;
	Velocity _velocity;
};