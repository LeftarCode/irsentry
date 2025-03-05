#pragma once

/// Project name.
#define IRSENTRY_NAME "IRSentry"

/// Project version.
#define IRSENTRY_VERSION "1.0.0"

/// Project author.
#define IRSENTRY_AUTHRO "Mateusz Lewczak <leftarcode@gmail.com>"

/// Year of project creation/update.
#define IRSENTRY_COPYRIGHT_YEAR 2025

/// Project license.
#define IRSENTRY_LICENSE "MIT"

/// Revision number (e.g., Git hash).
#define IRSENTRY_REVISION "abc123"

/// Build date (set automatically).
#define BUILD_DATE __DATE__

/// Build time (set automatically).
#define BUILD_TIME __TIME__

/// Compiler information.
#define COMPILER_INFO __VERSION__

/// Macro defining the platform on which the project is compiled.
#if defined(_WIN32)
#define PLATFORM "Windows"
#elif defined(__linux__)
#define PLATFORM "Linux"
#elif defined(__APPLE__)
#define PLATFORM "macOS"
#else
#define PLATFORM "Unknown"
#endif

#ifdef NDEBUG
#define IRSENTRY_DEBUG 0
#else
#define IRSENTRY_DEBUG 1
#endif
