class Power
{
private:
	bool _power;
public:
	void start() { this->_power = true; }
	void stop() { this->_power = false; }
};