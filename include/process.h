#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid) : pid_(pid) {}
  int Pid();                               // DONE: See src/process.cpp - DONE
  std::string User();                      // DONE: See src/process.cpp - DONE
  std::string Command();                   // DONE: See src/process.cpp
  float CpuUtilization();                  // DONE: See src/process.cpp
  std::string Ram();                       // DONE: See src/process.cpp
  long int UpTime();                       // DONE: See src/process.cpp
  bool operator<(Process const& a) const;  // DONE: See src/process.cpp

  void GetCpuUtil();


  // DONE: Declare any necessary private members
 private:
  int pid_;


  float cpuUsageNow_ = 0.0f;
  float cpuUsageOld_ = 0.0f;
  float totalProcessTimeOld_ = 0.0f;
};

#endif