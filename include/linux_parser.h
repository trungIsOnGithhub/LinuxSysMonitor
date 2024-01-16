#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H

#include<fstream>
#include<string>
#include<regex>

namespace LinuxParser {
  // All Paths
  const std::string path_proc_dir = "/proc/";

  const std::string cmdline_filename = "/cmdline";
  const std::string cpuinfo_filename = "/cpuinfo";
  const std::string status_filename = "/status";
  const std::string stat_filename{"/stat"};
  const std::string uptime_filename{"/uptime"};
  const std::string meminfo_filename{"/meminfo"};
  const std::string version_filename{"/version"};
  const std::string os_path{"/etc/os-release"};
  const std::string kPasswordPath{"/etc/passwd"};

  // System Functions
  float get_mem_usage();
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