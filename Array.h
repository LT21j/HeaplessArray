//
// Created by prejohn on 5/2/24.
//

#ifndef HEAPLESSARRAY_ARRAY_H
#define HEAPLESSARRAY_ARRAY_H

#include <utility>
#include <cstdio>

template <class T, std::size_t cap>
class Array
{
public:
    Array() = default;
    Array(std::size_t size, const T& t);
    ~Array();

    virtual void push_back(const T& el);
    virtual void push_back(T&& el);

    [[nodiscard]] virtual std::size_t size() const {return size_;}
private:
    char data_[cap*alignof(T)*sizeof(T)];
    std::size_t size_ = 0;
};

template <class T, std::size_t cap>
Array<T, cap>::~Array()
{
    T* ptr = static_cast<T*>(data_);
    if constexpr (!std::is_trivially_destructible_v<T>)
        for(int i=0; i<size_; i++)
            (ptr+i)->~T();
}

template <class T, std::size_t cap>
Array<T, cap>::Array(std::size_t size, const T& t)
{

}

template <class T, std::size_t cap>
void Array<T, cap>::push_back(const T& el)
{

}

template <class T, std::size_t cap>
void Array<T, cap>::push_back(T&& el)
{

}

#endif //HEAPLESSARRAY_ARRAY_H
