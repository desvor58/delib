#pragma once

#include "delib.hpp"

namespace de
{
    // расширяемый буффер
    // по сути то же, что и std::vector, но с указанием предвыделения
    template<typename T>
    class ExBuf
    {
        u16 buf_ex_size;
        u32 buf_curr_size;
        u32 buf_index;
        T *buf;

    public:
        ExBuf(u16 _buf_size)
        {
            buf_ex_size = _buf_size;
            buf_curr_size = _buf_size;
            buf = new T[buf_ex_size];
            buf_index = 0;
        }

        void push_back(T el)
        {
check_out_of_range:
            if (buf_index >= buf_curr_size) {
                extend_buf();
                goto check_out_of_range;
            }
            buf[buf_index++] = el;
        }

        void pop_back()
        {
            buf_index--;
        }

        void erace(u32 index)
        {
            if (index >= buf_curr_size) {
                throw std::string("ExBuf::erace() out of range");
            }

            for (u32 i = index+1; i < buf_curr_size; i++) {
                buf[i-1] = buf[i];
            }
            buf_index--;
        }

        size_t size()
        {
            return buf_index;
        }

        size_t alocated_size()
        {
            return buf_curr_size;
        }

        T &operator[](u32 index)
        {
            return buf[index];
        }

        void extend_buf()
        {
            T *save_buf = new T[buf_curr_size];
            for (long i = 0; i < buf_curr_size; i++) {
                save_buf[i] = buf[i];
            }
            delete[] buf;

            buf = new T[buf_curr_size+buf_ex_size];
            for (long i = 0; i < buf_curr_size; i++) {
                buf[i] = save_buf[i];
            }
            delete[] save_buf;
            buf_curr_size+=buf_ex_size;
        }

        ~ExBuf()
        {
            delete[] buf;
        }
    };
}
