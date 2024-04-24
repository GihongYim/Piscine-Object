#pragma once
#include "Tool.hpp"
#include "Worker.hpp"

// Aggregation : Worker과 소유(Aggregation)관계이다.
// Worker가 전체 잭체 Shovel이 부분 객체인 소유 관계에 있다.
// Worker가 사라진다고 해서 Shovel이 사라지지는 않는것처럼 클래스 생명주기가 독립적이다.

class Shovel : public Tool {

private:

public:
    Shovel();
    void use() = 0;
};