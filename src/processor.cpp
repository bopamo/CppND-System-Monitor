#include "processor.h"
#include <vector>
#include <string>
#include "linux_parser.h"

// DONE: Return the aggregate CPU utilization
/**
* https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
*/
float Processor::Utilization() {
  std::vector<std::string> cpuJiffies = LinuxParser::CpuUtilization();
  idle_ = stof(cpuJiffies[3]) + stof(cpuJiffies[4]);
  nonIdle_ = stof(cpuJiffies[0]) + stof(cpuJiffies[1]) + stof(cpuJiffies[2]) +
             stof(cpuJiffies[5]) + stof(cpuJiffies[6]) + stof(cpuJiffies[7]);
  total_ = idle_ + nonIdle_;

  cpuPercentage = 1.f * ((total_ - prevTotal_) - (idle_ - prevIdle_)) /
                   (total_ - prevTotal_);
  prevIdle_ = idle_;
  prevTotal_ = total_;
  prevNoneIdle_ = nonIdle_;
  return cpuPercentage;
}