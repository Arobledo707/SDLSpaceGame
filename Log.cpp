#include "Log.h"

#include <iostream>
#include <string>
#include <SDL.h>

HANDLE Log::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO Log::csbi;

// Default logging flags
u32 Log::logFlags = 
	//LOG_FLAG_INPUT | 
	LOG_FLAG_PERFORMANCE | 
	LOG_FLAG_ANIMATION;

std::string Log::GetFilename(const char * filepath)
{
	std::string result = filepath;
	size_t last = result.find_last_of('\\');
	result = result.substr(last + 1, std::string::npos);
	return result;
}

Log::Log()
{
}


Log::~Log()
{
}


void Log::LogInfo(const char * message, int line, const char * file)
{
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, White);
	std::cout << "[Info]: (" << GetFilename(file) << " " << line << ") -- " << 
		message << std::endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
}

void Log::LogTrace(const char *message, int line, const char* file)
{
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, Teal);
	std::cout << "[Trace]: (" << GetFilename(file) << " " << line << ") -- " << message << std::endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
}

void Log::LogWarning(const char *message, int line, const char* file)
{
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, Yellow);
	std::cout << "[Warning]: (" << GetFilename(file) << " " << line << ") -- " << message << std::endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
}

void Log::LogError(const char *message, int line, const char* file)
{
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, Red);
	std::cout << "[Error]: (" << GetFilename(file) << " " << line << ") -- " << message << std::endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
}

void Log::LogSDLError(const char* functionName, int line, const char* file)
{
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, Red);
	std::cout << "[Error]: (" << GetFilename(file) << " " << line << ") -- " <<
		functionName << " error: " << SDL_GetError() << std::endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
}

void Log::LogCritical(const char *message, int line, const char* file)
{
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, Fucked);
	std::cout << "[CRITICAL]: (" << GetFilename(file) << " " << line << ") -- " << message << std::endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
}

void Log::LogData(LogType type, int line, const char * file, const char * format, ...)
{
	va_list va;
	char* message = new char[MAX_LOG_SIZE] {};
	va_start(va, format);
	vsprintf_s(message, 128, format, va);
	va_end(va);
	
	switch (type)
	{
	case LogType::Info:
		Log::LogInfo(message, line, file);
		break;
	case LogType::Trace:
		Log::LogTrace(message, line, file);
		break;
	case LogType::Warning:
		Log::LogWarning(message, line, file);
		break;
	case LogType::Error:
		Log::LogError(message, line, file);
		break;
	case LogType::Critical:
		Log::LogCritical(message, line, file);
		break;
	}

	delete[] message;
}

bool Log::HasFlag(u32 flag)
{
	return !((logFlags & flag) == 0);
}

void Log::SetFlags(u32 flags)
{
	logFlags &= flags;
}

void Log::ToggleFlags(u32 flags)
{
	logFlags ^= flags;
}

void Log::RemoveFlags(u32 flags)
{
	logFlags &= ~flags;
}
