#ifndef QUEUE_BELOSHITSKIY_DR_QUEUE_HPP
#define QUEUE_BELOSHITSKIY_DR_QUEUE_HPP

template<class T>
class Queue
{
public:
  virtual ~Queue() = default;
  virtual void enQueue(const T &) = 0;
  virtual T deQueue() = 0;
  virtual bool isEmpty() const = 0;
};

#endif //QUEUE_BELOSHITSKIY_DR_QUEUE_HPP
