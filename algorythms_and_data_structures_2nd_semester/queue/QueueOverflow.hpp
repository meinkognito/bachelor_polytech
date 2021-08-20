#ifndef QUEUE_BELOSHITSKIY_DR_QUEUEOVERFLOW_HPP
#define QUEUE_BELOSHITSKIY_DR_QUEUEOVERFLOW_HPP

class QueueOverflow: public std::exception
{
public:
  std::string what();
};

std::string QueueOverflow::what()
{
  return "Queue Overflow";
}

#endif //QUEUE_BELOSHITSKIY_DR_QUEUEOVERFLOW_HPP
