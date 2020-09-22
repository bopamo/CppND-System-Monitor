#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;



// DONE: Return this process's ID
int Process::Pid() { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() { return cpuUsageNow_; }



// DONE: Return the command that generated this process - DONE
string Process::Command() { return LinuxParser::Command(Process::Pid()); }

// DONE: Return this process's memory utilization - DONE
string Process::Ram() { return LinuxParser::Ram(Process::Pid()); }

// DONE: Return the user (name) that generated this process -DONE
string Process::User() { return LinuxParser::User(Process::Pid()); }

// DONE: Return the age of this process (in seconds) - DONE
long int Process::UpTime() { return (LinuxParser::UpTime(Process::Pid())); }

// DONE: Overload the "less than" comparison operator for Process objects - DONE
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return this->pid_ > a.pid_; }


void Process::GetCpuUtil() {
  // Reference:
  // https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599
  auto totalTimeJiff =
      LinuxParser::ActiveJiffies(pid_); /* Active CPU jiffie. */
  float cpuUsageTime = static_cast<float>(
      totalTimeJiff / sysconf(_SC_CLK_TCK)); /* Number of ticks. */
  float totalProcessTime = static_cast<float>(
      LinuxParser::UpTime(pid_)); /* Process uptime sine bootup. */
  this->cpuUsageNow_ =
      (cpuUsageTime - cpuUsageOld_) /
      (totalProcessTime - totalProcessTimeOld_); /* Current Process CPU usage.
                                                    Compare with previous one.*/

  cpuUsageOld_ = cpuUsageTime;
  totalProcessTimeOld_ = totalProcessTime;
}
