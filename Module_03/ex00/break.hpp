class Break
{
private:
	int _force;
	int _maxForce;
public:
	Break() : _force(0), _maxForce(10) {}

	void apply_force_on_brakes(int force) {
		if (force > this->_maxForce)
			this->_force = this->_maxForce;
		else
			this->_force = force;
	}

	void apply_emergency_brakes() {
		this->_force = this->_maxForce;
	}
};