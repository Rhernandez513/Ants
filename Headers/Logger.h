#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include <memory>

namespace Ants {
namespace Logger {
  class Logger {
    private:
      
      std::string file_name;
      std::unique_ptr<std::ofstream> out_stream;
      std::stringstream log_stream;
      void Open_ostream();
      void Close_ostream();
      void WriteToLog(const std::string& data);

      template<typename First, typename...Rest >
      void Annotate_impl(First param1, Rest...param);
      void Ants::Logger::Logger::Annotate_impl();
    public:
      template<typename...Args>
      void Annotate(Args...args);
      Logger(std::string input);
      ~Logger();
  };
}
}

#endif //LOGGER_H

