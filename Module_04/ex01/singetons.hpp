#pragma once

#include <vector>

template <typename T>
class ObjectList
{
public:
    static ObjectList<T>& instance() {
        static ObjectList<T> instance;
        return instance;  
    }

    void add(T* obj) {
        _objects.push_back(obj);
    }

    const std::vector<T*>& getAllObjects() const {
        return _objects;
    }

    ObjectList(const ObjectList&) = delete;
    ObjectList& operator=(const ObjectList&) = delete;

private:
    ObjectList() = default;
    ~ObjectList() = default;

    std::vector<T*> _objects;
};