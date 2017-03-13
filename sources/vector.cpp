#include <algorithm>
#include <utility>
#include "vector.hpp"

vector_t::vector_t() noexcept : size_{0}, capacity_{0}, ptr_{nullptr}
{
}

vector_t::vector_t(unsigned int size) : size_{size}, capacity_{size}, ptr_{new int[size]{}}
{
}

auto vector_t::capacity() const noexcept -> unsigned int
{
    return capacity_;
}

auto vector_t::size() const noexcept -> unsigned int
{
    return size_;
}

auto vector_t::operator[](unsigned int index) const noexcept -> int
{
  return ptr_[index];
}

vector_t::~vector_t() noexcept
{
  delete[] ptr_;
}

vector_t::vector_t(const vector_t& other) : size_{other.size_}, capacity_{other.capacity_}, ptr_{new int[other.size_]}
{
  std::copy(other.ptr_, other.ptr_ + other.size_, ptr_);
}

auto vector_t::operator=(const vector_t& other) -> vector_t&
{
  if (this != &other) {
    vector_t{other}.swap(*this);
  }

  return *this;
}

auto vector_t::swap(vector_t& other) -> void
{
  using std::swap;
  swap(size_, other.size_);
  swap(capacity_, other.capacity_);
  swap(ptr_, ptr_);
}

auto vector_t::push_back(int value) -> void
{
  if (size_ == capacity_) {
    const unsigned int capacity = capacity_ != 0 ? capacity_ * 2 : 1;
    int* ptr = new int[capacity];
    std::copy(ptr_, ptr_ + size_, ptr);

    capacity_ = capacity;
    ptr_ = ptr;
  }

  ptr_[size_] = value;
  ++size_; 
}  
