#include "..\\Headers\\CommandRunner.h"
#include "..\\Headers\\EventListener.h"
#include "..\\Headers\\Logger.h"
#include <iostream>

// Exits program depending on input, optional message
// Also Closes the Logger, if open
void Ants::CommandRunner::TriggerExit(bool good_exit) {
  Ants::Logger::Terminate_Logging();
  good_exit ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}

// Exits program depending on input, optional message
void Ants::CommandRunner::TriggerExit(bool good_exit, std::string msg) {
  LOG(msg);
  TriggerExit(good_exit);
}

// Starts the logging procedure
void Ants::CommandRunner::SetUpLogging() {
  try {
    Ants::Logger::StartLogging();
  } catch (std::runtime_error e) {
    std::string error_msg = e.what();
    Ants::CommandRunner::TriggerExit(false, error_msg);
  }
}
