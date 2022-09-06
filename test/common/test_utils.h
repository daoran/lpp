//
// Created by acey on 23.08.22.
//

#ifndef LOG_TEST_TEST_UTILS_H_
#define LOG_TEST_TEST_UTILS_H_

#include <string>
#include <gtest/gtest.h>

extern char** test_argv;

inline static bool isSubstring(const std::string& string, const std::string& substring) {
  return (string.find(substring) != std::string::npos);
}

//! Macros to capture stdout and stderr and assign output directly to std::string
#define LPP_CAPTURE_STDOUT(x) []() {testing::internal::CaptureStdout(); (x); \
return testing::internal::GetCapturedStdout();}()

#define LPP_CAPTURE_STDERR_LOG(x) []() {testing::internal::CaptureStderr(); (x); \
return testing::internal::GetCapturedStderr();}()

#endif //LOG_TEST_TEST_UTILS_H_