#ifndef __FILELOGGER_HPP__
#define __FILELOGGER_HPP__

#include <fstream>
#include "ILonger.hpp"

class Filelogger : public ILogger
{
protected:
    std::string     _filename;
    std::ofstream   _fout;
public:
    Filelogger(std::string name="FileLogger",std::string filename="logfile.txt")
        : ILogger(name), _filename(filename)
    {
        _fout.open(filename);
    }
    ~Filelogger() {
        _fout.close();
    }
    void write(std::string log) {
        time_t timer = time(NULL);
        struct tm* t = localtime(&timer);
        _fout << "[" <<  ILogger::_name << ":";
        _fout << t->tm_year + 1900 << '/' << t->tm_mon << '/' << t->tm_mday << '/';
        _fout << t->tm_hour << '/' << t->tm_min << '/' << t->tm_sec << "] : ";
        _fout << log << std::endl;
    }
};

#endif