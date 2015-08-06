#include "..\\Headers\\Ant.h"
#include "..\\Headers\\AntHelper.h"
#include "..\\Headers\\Logger.h"
#include <string>
#include <sstream>
#include <fstream>
#include <memory>

using namespace Ants::Logger;


namespace {
std::string file_name = "log.txt";
std::unique_ptr<std::ofstream> out_stream(new std::ofstream);
std::ostringstream log_stream;
bool logging_started = false;
unsigned line_count = 0;

  void WriteToLog(const std::string& data) {
    if (out_stream) {
    (*out_stream) << data << std::endl;
    }
  }

  void Close_ostream() {
    if (out_stream) {
      out_stream->close();
      std::cout << "\t\tSuccess!! Logger Closed Properly!!" << std::endl;
    }
  }

  void DestroyLogger() {
    LOG("");
    LOG("\t\t*****Logging Complete!*****");
    Close_ostream();
  }

  void Open_ostream() {
    out_stream->open(file_name.c_str(), std::ios_base::binary | std::ios_base::out);
    if (!out_stream->is_open()) {
      throw
        std::runtime_error(newline "LOGGER: Unable to open an output stream");
    }
    logging_started = true;
  }

  void Annotate_impl() {
    WriteToLog(log_stream.str());
    log_stream.str("");
  }

  template<typename First, typename...Rest >
  void Annotate_impl(First param1, Rest...param) {
    log_stream << ++line_count << '\t' << param1 << newline << std::endl;
    Annotate_impl(param...);
  }
}

void Ants::Logger::Log(std::string msg) {
  if (!logging_started) { StartLogging(); }
  Annotate_impl(msg);
}

void Ants::Logger::StartLogging() {
  log_stream.unsetf(std::ios::skipws);
  if (!logging_started) Open_ostream();
}

void Ants::Logger::Terminate_Logging() {
  if (logging_started) DestroyLogger();
}
