#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"


#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// DONE: Return the system's CPU - DONE
Processor& System::Cpu() { return cpu_; }

// DONE: Return a container composed of the system's processes - DONE
vector<Process>& System::Processes() {
  processes_.clear();
  std::vector<int> pids = LinuxParser::Pids();

  for (int pid : pids) {
    Process process(pid);
    process.GetCpuUtil();
    processes_.emplace_back(process);
  }

  std::sort(processes_.begin(), processes_.end(),
            [](Process const& a, Process const& b) { return a < b; });
  return processes_;
}



// DONE: Return the system's kernel identifier (string) - Done
std::string System::Kernel() {
  return LinuxParser::Kernel();
}

// DONE: Return the system's memory utilization - DONE
float System::MemoryUtilization() {
  return LinuxParser::MemoryUtilization();
}

// DONE: Return the operating system name - DONE
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// DONE: Return the number of processes actively running on the system - DONE
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// DONE: Return the total number of processes on the system - DONE
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// DONE: Return the number of seconds since the system started running - DONE
long int System::UpTime() { return LinuxParser::UpTime(); }