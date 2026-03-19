struct  Obj;

template<typename T>
class RefPtr {
private:

    T* ptr;
    int* count;


public:

    RefPtr(T* p = nullptr) : ptr(p), count(new int(1)) {}

    RefPtr(const RefPtr& other) : ptr(other.ptr), count(other.count) {
        if (count) (*count)++;
    }

    RefPtr& operator=(const RefPtr& other){
        if (this != &other) {
            if (count) {
                (*count)--;
                if (*count == 0) {
                    delete ptr;
                    delete count;
                }
            }
            ptr = other.ptr;
            count = other.count;
            if (count) (*count)++;
        }
    return *this;
}

T& operator*() const {
    return *ptr;
}

~RefPtr() {
    if (count) {
        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }
}

T* operator->() const {
    return ptr;
}

int use_count() const { return *count; };
};

// std запрещён, кроме <assert.h>

#include <assert.h>

struct Obj {
    int value;
    Obj(int v) : value(v) {}
};

int main() {

    RefPtr p1(new Obj(10));
    assert(p1.use_count() == 1);
    assert(p1->value == 10);

    RefPtr p2 = p1; // ещё одна ссылка на тот же объект
    assert(p1.use_count() == 2);
    assert(p2.use_count() == 2);

    {
        RefPtr p3 = p2;
        assert(p1.use_count() == 3);
        p3->value = 20;
        assert(p1->value == 20);
    }

    assert(p1.use_count() == 2);

    return 0; // здесь объект должен быть удалён ровно один раз
}