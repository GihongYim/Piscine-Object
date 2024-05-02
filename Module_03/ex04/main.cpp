#include <iostream>
#include <vector>
#include <string>
#include "ILonger.hpp"
#include "fileLogger.hpp"
#include "ostreamLogger.hpp"

int main(void)
{
    std::vector<ILogger*> logger;

    Filelogger filelogger("FileLogger", "file1.txt");
    logger.push_back(&filelogger);
    OstreamLogger ostreamlogger("logger");
    logger.push_back(&ostreamlogger);

    for (int i = 0; i < logger.size(); i++) {
        logger[i]->write("what the fuck");
    }
    return 0;
}