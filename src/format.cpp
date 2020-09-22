#include "format.h"

#include <chrono>
#include <ratio>
#include <iomanip>
#include <sstream>
#include <string>

using std::string;

// DONE: Complete this helper function - DONE
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {


//  std::chrono::seconds sec{seconds};
//
//
//
//  auto hh = std::chrono::duration_cast<std::chrono::hours> (sec / 60*60 );   // truncated
//
//  auto mm = std::chrono::duration_cast<std::chrono::minutes> (hh - (sec / 60));   // truncated
//
//  auto ss = std::chrono::duration_cast<std::chrono::minutes> (mm - sec);   // truncated
//
//
//  string formatted_time = std::to_string(hh.count()) + ":" + std::to_string(mm.count()) + ":" + std::to_string(ss.count());
//
//  return formatted_time;

  int hour = 0;
  int min = 0;
  int sec = 0;
  string time{};

  hour = seconds / 3600;
  seconds = seconds % 3600;
  min = seconds / 60;
  seconds = seconds % 60;
  sec = seconds;

  time = std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(sec);

  return time;

}