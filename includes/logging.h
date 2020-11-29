#ifndef LOGGING_HEADER
#define LOGGING_HEADER

extern void _log(char* file, int line, char* level, char* message);

#define LOG_FATAL(message) _log(__FILE__, __LINE__, "FATAL", message)
#define LOG_ERROR(message) _log(__FILE__, __LINE__, "ERROR", message)
#define LOG_WARNING(message) _log(__FILE__, __LINE__, "WARNING", message)
#define LOG_INFO(message) _log(__FILE__, __LINE__, "INFO", message)
#define LOG_DEBUG(message) _log(__FILE__, __LINE__, "DEBUG", message)

#endif
