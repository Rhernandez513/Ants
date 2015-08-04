#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include <memory>

namespace Ants {
namespace Logger {
void Log(std::string msg);
void StartLogging();
void Terminate_Logging();
}
}
#endif //LOGGER_H
#ifdef LOGGER_H
#ifndef LOG
#define LOG Ants::Logger::Log
#endif // LOG
#endif // LOGGER_H CHECK
#if defined(_WIN32) || defined(WIN32) ||\
    defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define newline "\r\n"
#else
#define newline "\n"
#endif // newline
