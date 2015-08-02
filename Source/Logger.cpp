#include "..\\Headers\\Logger.h"

Ants::Logger::Logger()
  : file_name("log.txt")
  , out_stream(new std::ofstream)
{
}

void Ants::Logger::WriteToLog(const std::string& data) {
  (*out_stream) << data << std::endl;
}

void Ants::Logger::Open_ostream() {
  out_stream->open(file_name.c_str(), std::ios_base::binary | std::ios_base::out );
  if(!out_stream->is_open()) {
    throw(std::runtime_error("LOGGER: Unable to open an output stream"));
  }
}

void Ants::Logger::Close_ostream() {
  if(out_stream) {
    out_stream->close();
  }
}

Ants::Logger::~Logger() {
  std::string msg = "Logging Complete!";
  WriteToLog(msg);
  Close_ostream();
}

template<typename...Args>
void Ants::Logger::Annotate(Args...args) {
  Annotate_impl(args...);  
}

 void Ants::Logger::Annotate_impl() {
  WriteToLog(log_stream.str());
  log_stream.str("");
}

template<typename First, typename...Rest >
void Ants::Logger::Annotate_impl(First param1, Rest...param) {
  log_stream << param1;
  Annotate_impl(param...);
}
