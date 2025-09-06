class Engine
{
private:
	int _speed;
public:
	void accelerate(int speed) { this->_speed = speed; }
	void reverse() { this->_speed = -10; }
};