#include "Workshop.hpp"

void Workshop::addWorker(Worker *worker) {
    if (worker == NULL) {
        std::cerr << "Workshop.addWorker : NULL worker added" << std::endl;
        return ;
    }
    if (find(this->workList.begin(), this->workList.end(), worker) != this->workList.end()) {
        this->workList.push_back(worker);
    } else {
        std::cerr << "Workshop.addWorker : worker already exist" << std::endl;
    }
}
void Workshop::addWorker(std::vector<Worker *> workers){
    for (int i = 0; i < workers.size(); i++) {
        this->addWorker(workers[i]);
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
void Workshop::excuteWorkDay(){
    for (int i = 0; i < this->workList.size(); i++) {
        if (this->workList[i] == NULL) {
            std::cerr << "Workshop.excuteWorkDay : NULL Worker exists" << std::endl;
        } else {
            this->workList[i]->work();
        }
    }
}