#include <iostream>
#include <glog/logging.h>

int main(int, char* argv[])
{
  google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(google::GLOG_INFO, "./log/log_chifoumi");
    std::cout << "Hello, world!\n";
    LOG(INFO)<< "Hello world!";
    return 0;
    /// test pour le doxygen
}
