#pragma once

struct Vector2 {
private:
    float x, y;

public:
    Vector2(float _x = 0, float _y = 0) : x(_x), y(_y) {}

    const float& getX() const { return x; }
    const float& getY() const { return y; }

    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }

    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    Vector2& operator=(const Vector2 &a) {
        if (this != &a) {
            x = a.x;
            y = a.y;
        }
        return *this;
    }

    bool operator==(const Vector2 &a) {
        if (x == a.x && y == a.y)
            return true;
        else
            return false;
    }
};
