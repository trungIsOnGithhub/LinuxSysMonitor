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

void System::RefreshProcesses()
{
    processes_ = {};
    auto process_ids = LinuxParser::Pids();
    for(int ids : process_ids)
    {
        processes_.push_back(Process(ids));
    }
}

// Return a container composed of the system's processes
vector<Process>& System::Processes() {
    RefreshProcesses();

    std::sort(processes_.begin(), processes_.end());

    return processes_;
}

Processor& System::Cpu() {
    return cpu_;
}

std::string System::Kernel() {
    return LinuxParser::Kernel();
}

float System::MemoryUtilization() {
    return LinuxParser::MemoryUtilization();
}

std::string System::OperatingSystem() {
    return LinuxParser::OperatingSystem();
}

int System::RunningProcesses() {
    return LinuxParser::RunningProcesses();
}

int System::TotalProcesses() {
    return LinuxParser::TotalProcesses();
}

long int System::get_up_time() {
    return LinuxParser::get_up_time();
}