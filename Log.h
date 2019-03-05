#pragma once

#include <Windows.h>
#include <string>

#include "Typedefs.h"

enum class LogType
{
	Info, Trace, Warning, Error, Critical
};

#define MAX_LOG_SIZE 128

#define LOG_INFO(msg) Log::LogInfo(msg, __LINE__, __FILE__)
#define LOG_TRACE(msg) Log::LogTrace(msg, __LINE__, __FILE__)
#define LOG_WARNING(msg) Log::LogWarning(msg, __LINE__, __FILE__)
#define LOG_ERROR(msg) Log::LogError(msg, __LINE__, __FILE__)
#define LOG_SDL_ERROR(funcName) Log::LogSDLError(funcName, __LINE__, __FILE__)
#define LOG_CRITICAL(msg) Log::LogCritical(msg, __LINE__, __FILE__)

#define LOG_INFO_DATA(fmt, ...) Log::LogData(LogType::Info, __LINE__, __FILE__, fmt, __VA_ARGS__)
#define LOG_TRACE_DATA(fmt, ...) Log::LogData(LogType::Trace, __LINE__, __FILE__, fmt, __VA_ARGS__)
#define LOG_WARNING_DATA(fmt, ...) Log::LogData(LogType::Warning, __LINE__, __FILE__, fmt, __VA_ARGS__)
#define LOG_ERROR_DATA(fmt, ...) Log::LogData(LogType::Error, __LINE__, __FILE__, fmt, __VA_ARGS__)
#define LOG_CRITICAL_DATA(fmt, ...) Log::LogData(LogType::Critical, __LINE__, __FILE__, fmt, __VA_ARGS__)

#define LOG_ANIMATION_DATA(fmt, ...) { if(Log::HasFlag(LOG_FLAG_ANIMATION)) \
	{ Log::LogData(LogType::Trace, __LINE__, __FILE__, fmt, __VA_ARGS__); } }
#define LOG_INPUT_DATA(fmt, ...) { if(Log::HasFlag(LOG_FLAG_INPUT)) \
	{ Log::LogData(LogType::Trace, __LINE__, __FILE__, fmt, __VA_ARGS__); } }

#define LOG_FLAG_INPUT 1
#define LOG_FLAG_PERFORMANCE 1 << 1
#define LOG_FLAG_ANIMATION 1 << 2

class Log
{
private:
	static std::string GetFilename(const char* filepath);
	static HANDLE hConsole;
	static CONSOLE_SCREEN_BUFFER_INFO csbi;

	static const int Red = 12;
	static const int Yellow = 14;
	static const int White = 15;
	static const int Teal = 11;
	static const int Fucked = 0x4F;

	static u32 logFlags;
public:
	Log();
	~Log();

	enum class Type
	{
		Trace,
		Info,
		Warning,
		Error,
		Critical
	};

	static void LogInfo(const char* message, int line, const char* file);
	static void LogTrace(const char* message, int line, const char* file);
	static void LogWarning(const char* message, int line, const char* file);
	static void LogError(const char* message, int line, const char* file);
	static void LogSDLError(const char* functionName, int line, const char* file);
	static void LogCritical(const char* message, int line, const char* file);

	static void LogData(LogType type, int line, const char* file, const char* format, ...);

	static bool HasFlag(u32 flag);
	static void SetFlags(u32 flags);
	static void ToggleFlags(u32 flags);
	static void RemoveFlags(u32 flags);
};

