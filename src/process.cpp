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

Process::Process(int pid) : pid_(pid)
{
    user_ = LinuxParser::User(pid_);
    command_ = LinuxParser::Command(pid_);
}

int Process::Pid() { 
    return pid_;
}

float Process::CpuUtilization() { 
    vector<string> cpu_utils = LinuxParser::Cpu(pid_);

    long total_time = stol(cpu_utils[0])
                    + stol(cpu_utils[1])
                    + stol(cpu_utils[2])
                    + stol(cpu_utils[3]);

    float seconds = float(get_up_time());

    float cpu_utilization_ = ((total_time / sysconf(_SC_CLK_TCK)) / seconds );
    return cpu_utilization_;

}

string Process::Command() { 
    return command_;
}

string Process::Ram() {     
    if(ram_ == "")
        ram_ = LinuxParser::Ram(pid_);
    return ram_;
 }


string Process::User() {
    return user_;
}

long int Process::get_up_time() { 
    return LinuxParser::get_up_time(pid_);
}

// TODO: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { 
    long ram_o = stol(LinuxParser::Ram(pid_));
    long ram_a = stol(LinuxParser::Ram(a.pid_));

    return ram_o > ram_a;
}