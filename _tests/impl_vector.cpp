#include <iostream>
#include <cstddef> // size_t
#include <vector>
#include <cstring> // memcpy
#include <cassert> // assert
#include <initializer_list> // initializer_list

template <typename T>
class my_vector {
private:
    size_t INIT_CAPICITY = 16;
    size_t _size;
    size_t _cap;
    T* _arr;

public:
    // default constructor
    my_vector() : _arr(nullptr), _size(0), _cap(INIT_CAPICITY) {}

    // parameter constructor
    my_vector(size_t n, T x = 0) {
        _cap = INIT_CAPICITY;
        while (_cap < n)
            _cap *= 2;
        _arr = new T[_cap];
        _size = n;
        while (n--)
            _arr[n] = x;
    }

    // copy constructor
    my_vector(const my_vector<T> & v) {
        _size = v._size;
        _cap = v._cap;
        _arr = new T[v._cap];
        memcpy(_arr, v._arr, _cap * sizeof(T));
    }

    // assignment constructor
    my_vector<T> & operator=(const my_vector& v) {
        if (this == &v)
            return *this;
        if (_arr)
            delete [] _arr;
        _size = v._size;
        _cap = v._cap;
        _arr = new T[v._cap];
        memcpy(_arr, v._arr, _cap*sizeof(T));
        return *this;
    }

    // list constructor
    my_vector(std::initializer_list<T> v) {
        _cap = INIT_CAPICITY;
        _size = v.size();
        while(_cap < _size)
            _cap *= 2;
        _arr = new T[_cap];

        size_t idx = 0;
        for (auto const &x : v)
            _arr[idx++] = x;
    }

    // destructor
    ~my_vector() {
        if (_arr)
            delete [] _arr;
    }

    // [] index
    T operator[](size_t idx) const {
        assert(idx < _size);
        return _arr[idx];
    }

    // size()
    size_t size() const {
        return _size;
    }

    // capacity()
    size_t capacity() const {
        return _cap;
    }

    // empty()
    bool empty() {
        return _size==0;
    }

    // push_back()
    void push_back(const T & x) {
        if (_size == _cap) {
            _cap *= 2;
            T* tmp = _arr;
            _arr = new T[_cap];
            memcpy(_arr, tmp, _size*sizeof(T));
            delete [] tmp;
        }
        _arr[_size++] = x;
    }

    // pop_back()
    void pop_back() {
        assert(_size > 0);
        --_size;
    }

    void insert(size_t pos, const T & x) {
        assert(pos>=0 && pos<=_size);
        if (_size == _cap) {
            _cap *= 2;
            T * tmp = _arr;
            _arr = new T[_cap];
            memcpy(_arr, tmp, _size*sizeof(T));
            delete [] tmp;
        }
        ++_size;
        for (size_t i=_size-1; i>pos; --i)
            _arr[i] = _arr[i-1];
        _arr[pos] = x;
    }

    void erase(size_t pos) {
        assert(pos>=0 && pos <_size);
        for (size_t i=pos; i<_size-1; ++i)
            _arr[i] = _arr[i+1];
        --_size;
    }

    // operator <<
    std::ostream & operator<<(std::ostream &os) {
        for (size_t i=0; i<_size; ++i)
            os << _arr[i] << " ";
        os << std::endl;
        return os;
    }
};

int main() {
    my_vector<int> v1 = my_vector<int>(5,0);
    my_vector<int> v2 = {1,2,3,4,5};
    v1 << std::cout; // 0 0 0 0 0
    std::cout << v2[2] << " " 
              <<  v2.size() << " " 
              <<  v2.capacity() << " " 
              << std::endl; // 3 5 16
    v2 << std::cout; // 1 2 3 4 5
    v2.insert(2,0);
    v2 << std::cout; // 1 2 0 3 4 5
    v2.erase(4);
    v2 << std::cout; // 1 2 0 3 5
    v1.push_back(2);
    v1 << std::cout; // 0 0 0 0 0 2
    while (v2.size()) {
        v2.pop_back();
        v2 << std::cout;
    }
    std::vector<int> v3 = {5,6,7};
    v3.insert(v3.end(), 1); // 5 6 7 1
    for (auto const & x: v3)
        std::cout << x << " ";
    return 0;
}