#include "Workshop.hpp"

Workshop::Workshop() {
    std::cout << "Workshop created" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop destructed" << std::endl;
}

void Workshop::addWorker(Worker *worker) {
    if (worker == NULL) {
        std::cerr << "Workshop.addWorker : NULL worker added" << std::endl;
        return ;
    }
    if (find(this->workList.begin(), this->workList.end(), worker) == this->workList.end()) {
        this->workList.push_back(worker);
        std::cout << "Workshop.addWorker : worker added" << std::endl;
    } else {
        std::cerr << "Workshop.addWorker : worker already exist" << std::endl;
    }
}

void Workshop::dropWorker(Worker *worker){
    std::vector<Worker *>::iterator it;

    if (worker == NULL) {
        std::cerr << "Workshop.dropWorker : NULL worker added" << std::endl;
        return ;
    }
    it = find(this->workList.begin(), this->workList.end(), worker);
    if (it == this->workList.end()) {
        std::cerr << "Workshop.dropWorker : worker does not exist" << std::endl;
    } else {
        this->workList.erase(it);
    }
}

void Workshop::executeWorkDay(){

    std::cout << "Workshop.executeWorkDay called" << std::endl;

    if (this->workList.size() == 0) {
        std::cerr << "Workshop.executeWorkDay : no worker assigned" << std::endl;
        return ;
    }

    for (size_t i = 0; i < this->workList.size(); i++) {
        if (this->workList[i] == NULL) {
            std::cerr << "Workshop.excuteWorkDay : NULL Worker exists" << std::endl;
        } else {
            this->workList[i]->work();
            std::cout << "Workshop.executeWorkDay : Worker " << i << " worked" << std::endl;
        }
    }
}