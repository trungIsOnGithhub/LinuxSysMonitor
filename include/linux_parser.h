#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H

#include<fstream>
#include<string>
#include<regex>

namespace LinuxParser {
  // All Paths
  const std::string path_proc_dir = "/proc/";

  const std::string cmdline_filename = "/cmdline";
  const std::string kCpuinfoFilename = "/cpuinfo";
  const std::string kStatusFilename = "/status";
  const std::string kStatFilename{"/stat"};
  const std::string kUptimeFilename{"/uptime"};
  const std::string kMeminfoFilename{"/meminfo"};
  const std::string kVersionFilename{"/version"};
  const std::string kOSPath{"/etc/os-release"};
  const std::string kPasswordPath{"/etc/passwd"};

  // System Functions
  float MemoryUtilization();
  long get_up_time();
  std::vector<int> Pids();
  int TotalProcesses();
  int RunningProcesses();
  std::string OperatingSystem();
  std::string Kernel();

  // CPU
  enum CPUStates {
  kUser_ = 0,
  kNice_,
  kSystem_,
  kIdle_,
  kIOwait_,
  kIRQ_,
  kSoftIRQ_,
  kSteal_,
  kGuest_,
  kGuestNice_
  };

  std::vector<std::string> CpuUtilization();
  long Jiffies();
  long ActiveJiffies();
  long ActiveJiffies(int pid);
  long IdleJiffies();

  // Processes
  std::string Command(int pid);
  std::string Ram(int pid);
  std::string Uid(int pid);
  std::string User(int pid);
  long int get_up_time(int pid);
  std::vector<std::string> Cpu(int pid);
};

#endif