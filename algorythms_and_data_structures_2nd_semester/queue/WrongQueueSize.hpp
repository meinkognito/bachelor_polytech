#ifndef QUEUE_BELOSHITSKIY_DR_WRONGQUEUESIZE_HPP
#define QUEUE_BELOSHITSKIY_DR_WRONGQUEUESIZE_HPP

class WrongQueueSize: public std::exception
{
public:
  std::string what();
};

std::string WrongQueueSize::what()
{
  return "Wrong Queue Size";
}

#endif //QUEUE_BELOSHITSKIY_DR_WRONGQUEUESIZE_HPP
