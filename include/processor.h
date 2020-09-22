#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // DONE: See src/processor.cpp

  // DONE: Declare any necessary private members
 private:
  float idle_ = 0.0f;
  float nonIdle_ = 0.0f;
  float total_ = 0.0f;
  float cpuPercentage = 0.0f;

  float prevIdle_ = 0.0f;
  float prevNoneIdle_ = 0.0f;
  float prevTotal_ = 0.0f;};

#endif