#include <iostream>
#include <ctime>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <cerrno>
#include <string>
#include <cstring> 
#include <vector>
#include <unistd.h> 

int main(int argc, char** argv) { 
    std::vector<std::string> prevTimes;
        for (unsigned int i = 1; i <= argc - 1; ++i) { 
            struct stat fileInfo;
            stat(argv[i], &fileInfo); 
            prevTimes.push_back(std::string(std::ctime(&(fileInfo.st_mtime))));
        }
    while (true) { 
        sleep(1);
        for (unsigned int i = 1; i <= argc - 1; ++i) { 
            struct stat fileInfo;
            stat(argv[i], &fileInfo); 
            auto currentTime = std::string(std::ctime(&(fileInfo.st_mtime))); 
            if (currentTime != prevTimes[i - 1]) { 
                system("clear");
                system("make");
                prevTimes[i - 1] = currentTime;
            }

        }
    }
}
