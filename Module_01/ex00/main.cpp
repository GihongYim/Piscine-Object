// #include <iostream>

// #include "Shovel.hpp"
// #include "Hammer.hpp"
// #include "Tool.hpp"
// #include "Workshop.hpp"

// int main()
// {
// 	std::cout << "[main] Generating Workshop" << std::endl;
// 	Workshop workshop;
// 	std::vector<Worker*> workers;
// 	std::vector<Tool*> tools;

// 	// Worker와 Tool 생성 및 등록
// 	for (int i = 0; i < 5; i++) {
// 		std::cout << "[main] Generating Worker " << i << std::endl;
// 		Worker *worker = new Worker();
// 		Tool *tool;
// 		if (i % 2 == 0) {
// 			tool = new Shovel();
// 			std::cout << "[main] Created Shovel for Worker " << i << std::endl;
// 		} else {
// 			tool = new Hammer();
// 			std::cout << "[main] Created Hammer for Worker " << i << std::endl;
// 		}
// 		worker->getTool(tool);
// 		workers.push_back(worker);
// 		tools.push_back(tool);
// 		workshop.addWorker(worker);
// 	}

// 	// 예외 상황 테스트: 중복 등록
// 	std::cout << "[main] Try to add first worker again (should error)" << std::endl;
// 	workshop.addWorker(workers[0]);

// 	// Worker가 Tool을 반환
// 	std::cout << "[main] Worker 0 drops their tool" << std::endl;
// 	workers[0]->dropTool(tools[0]);

// 	// Worker가 Workshop에서 탈퇴
// 	std::cout << "[main] Worker 1 leaves the workshop" << std::endl;
// 	workers[1]->leaveWorkshop(&workshop);
// 	workshop.dropWorker(workers[1]);

// 	// 보너스: getTool<Shovel>() 사용 예시
// 	std::cout << "[main] Worker 2 tries to get their Shovel" << std::endl;
// 	Shovel* shovel = workers[2]->getTool<Shovel>();
// 	if (shovel)
// 		std::cout << "[main] Worker 2 has a Shovel" << std::endl;
// 	else
// 		std::cout << "[main] Worker 2 does not have a Shovel" << std::endl;

// 	// 메모리 해제
// 	for (size_t i = 0; i < workers.size(); ++i) {
// 		std::cout << "[main] Deleting Worker " << i << std::endl;
// 		delete workers[i];
// 	}
// 	for (size_t i = 0; i < tools.size(); ++i) {
// 		std::cout << "[main] Deleting Tool " << i << std::endl;
// 		delete tools[i];
// 	}

// 	std::cout << "[main] Program finished" << std::endl;
// 	return 0;
// }

#include <iostream>

#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

int main()
{
	Workshop workshop;
	std::cout << "1st workday" << std::endl;
	workshop.executeWorkDay();

	Worker *worker1 = new Worker();
	worker1->work();

	Tool *shovel = new Shovel();
	worker1->getTool(shovel);

	workshop.addWorker(worker1);

	std::cout << "2nd workday" << std::endl;
	workshop.executeWorkDay();

	Worker *worker2 = new Worker();
	worker2->getTool(shovel);

	workshop.addWorker(worker2);

	workshop.addWorker(worker1); // add exist worker

	std::cout << "3rd workday" << std::endl;
	workshop.executeWorkDay();

	workshop.dropWorker(worker2);

	std::cout << "4th workday" << std::endl;
	workshop.executeWorkDay();

	workshop.dropWorker(worker1);

	// delete not exist in workList
	std::cerr << "delete not exist in workList" << std::endl;
	workshop.dropWorker(worker2);

	worker1->signUpWorkshop(&workshop);

	std::cout << "5th workday" << std::endl;
	workshop.executeWorkDay();

	delete worker1;
	delete worker2;
	delete shovel;
	return 0;
}