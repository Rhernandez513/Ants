#ifndef LOGGER_H
#define LOGGER_H
#define TURN_ON_LOGGING
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include <memory>

namespace Ants {
 class Logger {
    private:
      
      std::string file_name;
      std::unique_ptr<std::ofstream> out_stream;
      std::stringstream log_stream;
      void Open_ostream();
      void Close_ostream();
      void WriteToLog(const std::string& data);

      void Annotate_impl();
      template<typename First, typename...Rest >
      void Annotate_impl(First param1, Rest...param);
    public:
      template<typename...Args>
      void Annotate(Args...args);
      Logger();
      ~Logger();
  };
}
#endif //LOGGER_H
