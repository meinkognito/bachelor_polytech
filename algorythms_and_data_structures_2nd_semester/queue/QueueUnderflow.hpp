#ifndef QUEUE_BELOSHITSKIY_DR_QUEUEUNDERFLOW_HPP
#define QUEUE_BELOSHITSKIY_DR_QUEUEUNDERFLOW_HPP

class QueueUnderflow: public std::exception
{
public:
  std::string what();
};

std::string QueueUnderflow::what()
{
  return "Queue Underflow";
}

#endif //QUEUE_BELOSHITSKIY_DR_QUEUEUNDERFLOW_HPP
