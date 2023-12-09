#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
    public:
        Process(int pid);
        int Pid();             
        std::string User();    
        std::string Command(); 
        float CpuUtilization();
        std::string Ram();     
        long int get_up_time();     
        bool operator<(Process const& a) const;

    private:
        int pid_;
        std::string user_;
        std::string command_;
        std::string ram_;
        float cpu_utilization_;
        long int uptime_;
};

#endif