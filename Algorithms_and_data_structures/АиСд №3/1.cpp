#include <assert.h>

// 1. Опережающее объявление
struct Obj;

class RefPtr {
private:
    Obj* ptr;
    int* count;

public:
    RefPtr(Obj* p = nullptr) : ptr(p), count(new int(1)) {}
    RefPtr(const RefPtr& other) : ptr(other.ptr), count(other.count) {
        if (count) (*count)++;
    }

    // Только ОБЪЯВЛЯЕМ, реализация будет в самом конце
    RefPtr& operator=(const RefPtr& other);
    ~RefPtr();

    Obj* operator->() const { return ptr; }
    int use_count() const { return count ? *count : 0; }
};

// 2. Ваша структура Obj
struct Obj {
    int value;
    Obj(int v) : value(v) {}
};

// 3. Ваш неизменяемый main
int main() {
    RefPtr p1(new Obj(10));
    assert(p1.use_count() == 1);
    assert(p1->value == 10);

    RefPtr p2 = p1;
    assert(p1.use_count() == 2);
    assert(p2.use_count() == 2);

    {
        RefPtr p3 = p2;
        assert(p1.use_count() == 3);
        p3->value = 20;
        assert(p1->value == 20);
    }

    assert(p1.use_count() == 2);

    return 0;
}

// 4. РЕАЛИЗАЦИЯ МЕТОДОВ (в самом низу файла)

RefPtr& RefPtr::operator=(const RefPtr& other) {
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

RefPtr::~RefPtr() {
    if (count) {
        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }
}
