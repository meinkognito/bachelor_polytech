#ifndef QUEUE_BELOSHITSKIY_DR_QUEUEARRAY_HPP
#define QUEUE_BELOSHITSKIY_DR_QUEUEARRAY_HPP

#include "Queue.hpp"
#include "QueueOverflow.hpp"
#include "QueueUnderflow.hpp"
#include "WrongQueueSize.hpp"

template<typename T>
class QueueArray final: public Queue<T>
{
public:
  explicit QueueArray(size_t size);

  QueueArray(const QueueArray<T> &src) = delete;

  QueueArray(QueueArray<T> &&src) noexcept;

  QueueArray<T> &operator=(QueueArray<T> &&src) noexcept;

  void enQueue(const T &e) override;

  T deQueue() override;

  [[nodiscard]] bool isEmpty() const override;

  void swap(QueueArray<T> &right);

private:
  std::unique_ptr<T[]> array_;
  size_t head_{};
  size_t tail_{};
  size_t size_{};

};

template<typename T>
QueueArray<T>::QueueArray(size_t size):
  size_(size + 1),
  head_(0),
  tail_(0)
{
  try
  {
    array_ = std::unique_ptr<T[]>(new T[size_]);
  }
  catch (std::bad_alloc &ex)
  {
    throw WrongQueueSize();
  }
}

template<typename T>
void QueueArray<T>::swap(QueueArray<T> &right)
{
  std::swap((*this).array_, right.array_);
  std::swap((*this).head_, right.head_);
  std::swap((*this).tail_, right.tail_);
  std::swap((*this).size_, right.size_);
}

template<typename T>
QueueArray<T>::QueueArray(QueueArray<T> &&src) noexcept
{
  swap(src);
}

template<typename T>
QueueArray<T> &QueueArray<T>::operator=(QueueArray<T> &&src) noexcept
{
  if (this != &src)
  {
    delete this->array_;
    swap(src);
  }
  return *this;
}

template<typename T>
void QueueArray<T>::enQueue(const T &e)
{
  if (head_ == (tail_ + 1))
  {
    throw QueueOverflow();
  }
  array_[tail_] = e;
  tail_ = (tail_ + 1) % size_;
}

template<typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
  {
    throw QueueUnderflow();
  }
  size_t index = head_;
  head_ = (head_ + 1) % size_;
  return std::move(array_[index]);
}

template<typename T>
bool QueueArray<T>::isEmpty() const
{
  return head_ == tail_;
}

#endif //QUEUE_BELOSHITSKIY_DR_QUEUEARRAY_HPP
