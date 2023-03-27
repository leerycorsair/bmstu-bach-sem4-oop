#ifndef __MATRIX_BASE_INL__
#define __MATRIX_BASE_INL__

#include "exceptions.hpp"
#include "matrix_base.hpp"

std::shared_ptr<size_t> MatrixBase::alloc_size(const size_t dim)
{
    std::shared_ptr<size_t> dimPtr = nullptr;
    try
    {
        dimPtr.reset(new size_t(dim));
    }
    catch (std::bad_alloc &err)
    {
        time_t curr_time = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return dimPtr;
}

#endif // __MATRIX_BASE_INL__