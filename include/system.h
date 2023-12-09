#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
  public:
    Processor& Cpu();             
    std::vector<Process>& Processes();

    float MemoryUtilization();

    long get_up_time();       
  
    int TotalProcesses();
    int RunningProcesses();

    std::string Kernel();
    std::string OperatingSystem();

  private:
    Processor cpu_ = {};

    std::vector<Process> processes_ = {};

    void RefreshProcesses();
};

#endif