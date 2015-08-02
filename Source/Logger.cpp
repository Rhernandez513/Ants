#include "..\\Headers\\Logger.h"



void Ants::Logger::Logger::WriteToLog(const std::string& data) {
  (*out_stream) << data << std::endl;
}

Ants::Logger::Logger::Logger(std::string input)
  : file_name(input)
  , out_stream(new std::ofstream)
{
}

void Ants::Logger::Logger::Open_ostream() {
  out_stream->open(file_name.c_str(), std::ios_base::binary | std::ios_base::out );
  if(!out_stream->is_open()) {
    throw(std::runtime_error("LOGGER: Unable to open an output stream"));
  }
}

void Ants::Logger::Logger::Close_ostream() {
  if(out_stream) {
    out_stream->close();
  }
}

Ants::Logger::Logger::~Logger() {
  std::string msg = "Logging Complete!";
  this->WriteToLog(msg);
  Close_ostream();
}

template<typename...Args>
void Ants::Logger::Logger::Annotate(Args...args) {
  Annotate_impl(args...);  
}

   void Ants::Logger::Logger::Annotate_impl() {
     Ants::Logger::Logger::WriteToLog(log_stream.str());
    this->log_stream.str("");
  }

  template<typename First, typename...Rest >
  void Ants::Logger::Logger::Annotate_impl(First param1, Rest...param) {
    log_stream << param1;
    Annotate_impl(param...);
  }

#ifdef LOGGER_H
  static Ants::Logger::Logger fileLogger("log.txt");
#define LOG fileLogger.Annotate
#endif
