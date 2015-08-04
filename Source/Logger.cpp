#include "..\\Headers\\Logger.h"

using namespace Ants;
using namespace Ants::Logger;


namespace {
std::string file_name = "log.txt";
std::unique_ptr<std::ofstream> out_stream(new std::ofstream);
std::stringstream log_stream;

  void WriteToLog(const std::string& data) {
    (*out_stream) << data << std::endl;
  }

  void Close_ostream() {
    if (out_stream) {
      out_stream->close();
    }
  }

  void DestroyLogger() {
    std::string msg = "Logging Complete!";
    WriteToLog(msg);
    Close_ostream();
  }

  void Open_ostream() {
    out_stream->open(file_name.c_str(), std::ios_base::binary | std::ios_base::out);
    if (!out_stream->is_open()) {
      throw(std::runtime_error("LOGGER: Unable to open an output stream"));
    }
  }

  void Annotate_impl() {
    WriteToLog(log_stream.str());
    log_stream.str("");
  }

  template<typename First, typename...Rest >
  void Annotate_impl(First& param1, Rest&...param) {
    log_stream << param1;
    Annotate_impl(param...);
  }
}

void Ants::Logger::LOG(std::string msg) {
  Annotate_impl(msg);
}
