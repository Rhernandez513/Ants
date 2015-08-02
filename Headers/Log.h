#ifndef LOG_H
#define LOG_H

#include "Logger.h"

extern Ants::Logger fileLogger();

#ifdef TURN_ON_LOGGING
#define LOG fileLogger.Annotate
#endif

#endif // LOG_H
