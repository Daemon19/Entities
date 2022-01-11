#pragma once

#include <string>

void LogSdlError(const std::string &message);
void LogError(const std::string &message);

inline int randint(int end) { return rand() % (end + 1); }
inline int randint(int start, int end) { return randint(end - start) + start; }