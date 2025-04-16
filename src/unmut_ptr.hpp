#pragma once

#include <iostream>

#define UnmutPtr_operator_overload_RET_T_tmpl(op)                   \
    auto operator op (const T &other) const                         \
    {                                                               \
        if (raw_ptr == nullptr) throw "unmut ptr not initialized";  \
        return (*raw_ptr) op other;                                 \
    }                                                               \

#define UnmutPtr_operator_overload_unary_RET_T_tmpl(op)             \
    auto operator op () const                                       \
    {                                                               \
        if (raw_ptr == nullptr) throw "unmut ptr not initialized";  \
        return op(*raw_ptr);                                        \
    }                                                               \
    
#define UnmutPtr_operator_overload_RET_UMPTR_tmpl(op)               \
    auto operator op (const T &other) const                         \
    {                                                               \
        if (raw_ptr == nullptr) throw "unmut ptr not initialized";  \
        *raw_ptr op other;                                          \
        return *this;                                               \
    }                                                               \

namespace de
{
    // указатель, который в выражениях вызывает операторы своего типа
    // в отличии от ссылки может быть неинициализированым
    template<typename T>
    class UnmutPtr
    {
    private:
        T *raw_ptr;

    public:
        UnmutPtr()
        {
            raw_ptr = nullptr;
        }

        UnmutPtr(T *iptr)
        {
            raw_ptr = iptr;
        }

        UnmutPtr_operator_overload_RET_UMPTR_tmpl(+=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(-=)
        //UnmutPtr_operator_overload_RET_UMPTR_tmpl(%=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(/=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(*=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(%=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(<<=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(>>=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(^=)
        UnmutPtr_operator_overload_RET_UMPTR_tmpl(|=)

        auto operator [] (const int &index) const
        {
            return (*raw_ptr)[index];
        }

        UnmutPtr_operator_overload_RET_T_tmpl(+)
        UnmutPtr_operator_overload_RET_T_tmpl(-)
        UnmutPtr_operator_overload_RET_T_tmpl(%)
        UnmutPtr_operator_overload_RET_T_tmpl(/)
        UnmutPtr_operator_overload_RET_T_tmpl(*)
        UnmutPtr_operator_overload_RET_T_tmpl(&)
        UnmutPtr_operator_overload_RET_T_tmpl(&&)
        UnmutPtr_operator_overload_RET_T_tmpl(<)
        UnmutPtr_operator_overload_RET_T_tmpl(>)
        UnmutPtr_operator_overload_RET_T_tmpl(<<)
        UnmutPtr_operator_overload_RET_T_tmpl(>>)
        UnmutPtr_operator_overload_RET_T_tmpl(<=)
        UnmutPtr_operator_overload_RET_T_tmpl(>=)
        UnmutPtr_operator_overload_RET_T_tmpl(^)
        UnmutPtr_operator_overload_RET_T_tmpl(|)
        UnmutPtr_operator_overload_RET_T_tmpl(||)

        UnmutPtr_operator_overload_unary_RET_T_tmpl(+)
        UnmutPtr_operator_overload_unary_RET_T_tmpl(++)
        UnmutPtr_operator_overload_unary_RET_T_tmpl(-)
        UnmutPtr_operator_overload_unary_RET_T_tmpl(--)
        UnmutPtr_operator_overload_unary_RET_T_tmpl(*)
        UnmutPtr_operator_overload_unary_RET_T_tmpl(&)
        UnmutPtr_operator_overload_unary_RET_T_tmpl(!)
    };
}
