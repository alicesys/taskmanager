#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>
#include <iomanip>
#include "extractvalue.hh"

void readCpuInfo(){
    std::ifstream inCpuFile("/proc/cpuinfo");
    std::vector<std::string> cpuinfo;
    if(inCpuFile.is_open()){
        std::string line;
        for(int i = 0; i < 9 && std::getline(inCpuFile, line); i++){
            cpuinfo.push_back(line);
        }
        inCpuFile.close();
        std::cout << "\n" << "CPU Info: " << "\n";
        std::cout << "\n" << cpuinfo[4] << "\n" << cpuinfo[7] << "\n" << cpuinfo[8] << "\n";
    }else{
        std::cout << "\n" <<"\033[1;31mError while Reading Cpu Info File\033[0m" << "\n";
    }
}

void readMemInfo(){
    std::ifstream inMemFile("/proc/meminfo");
    std::vector<std::string> meminfo;
    if(inMemFile.is_open()){
        std::string line;
        for(int i = 0; i < 3 && std::getline(inMemFile, line); i++){
            meminfo.push_back(line);
        }
        inMemFile.close();
        double memtotal = static_cast<double>(extractValue(meminfo[0]));
        double memavailable = static_cast<double>(extractValue(meminfo[2]));
        double memused = memtotal - memavailable;
        double memusedpercentage = (memused / memtotal) * 100;
        
        memtotal /= (1024.0 * 1024.0);
        memavailable /= (1024.0 * 1024.0);
        memused /= (1024.0 * 1024.0);

        std::cout << "\n" << "Memory Info: " << "\n";
        std::cout << "\n" << "MemTotal: " << std::setw(11) << std::fixed << std::setprecision(2) << memtotal << " GB" << "\n" ;
        std::cout << "MemAvailable: " << std::setw(7) << memavailable << " GB" "\n";
        std::cout << "MemUsed: " << std::setw(12) << memused << " GB" << "\n";

        if(memusedpercentage > 85.00){
            std::cout << "\033[1;31mWarning: High Memory Usage\033[0m" << "\n";
            std::cout << "MemPercentage: " << std::setw(9) << std::fixed << std::setprecision(4) << memusedpercentage << " %" << "\n";
        }else{
            std::cout << "MemPercentage: " << std::setw(9) << std::fixed << std::setprecision(4) << memusedpercentage << " %" << "\n";
        }
    }else{
        std::cout << "\n" << "\033[1;31mError while Reading Mem Info File\033[0m" << "\n";
    }   
}

int main(){
    std::cout << "Welcome to TaskManager || \033[5m\033[1;35mdeveloped by alicesys ☆\033[0m" << "\n";
    readCpuInfo();
    readMemInfo();
    return 0;
}