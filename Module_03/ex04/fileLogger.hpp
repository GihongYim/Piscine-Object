#ifndef __FILELOGGER_HPP__
#define __FILELOGGER_HPP__

#include <fstream>
#include "ILonger.hpp"

class Filelogger : public ILogger
{
private:
    std::string     _filename;
    std::ofstream   fout;
public:
    Filelogger(std::string name="FileLogger",std::string filename): ILogger(name), _filename(filename)
    {
        fout.open(filename);
    }
    ~Filelogger() {
        fout.close();
    }
    void write(std::string log) {
        time_t timer = time(NULL);
        struct tm* t = localtime(&timer);
        fout << "[" <<  ILogger::_name << ":";
        fout << t->tm_year << '-' << t->tm_mon << '-' << t->tm_mday << '-';
        fout << t->tm_hour << '-' << t->tm_min << '-' << t->tm_sec << "] : ";
        fout << log << std::endl;
    }
};

#endif