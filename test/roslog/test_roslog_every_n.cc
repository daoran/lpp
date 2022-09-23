//
// Created by 4c3y (acey) on 08.09.22.
//

#include <gtest/gtest.h>
#include <test_utils.h>
#include <log++.h>

using namespace lpp;

TEST(roslog_LogEveryN, lpp_syntax_severity_debug) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDOUT(LOG_EVERY(D, 3, "Test"));

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::debug, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, lpp_syntax_severity_info) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDOUT(LOG_EVERY(I, 3, "Test"));

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::info, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, lpp_syntax_severity_warning) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output  = LPP_CAPTURE_STDERR(LOG_EVERY(W, 3, "Test"));

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::warning, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, lpp_syntax_severity_error) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDERR(LOG_EVERY(E, 3, "Test"));

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::error, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, lpp_syntax_severity_fatal) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDERR(LOG_EVERY(F, 3, "Test"));

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::fatal, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, glog_syntax_severity_debug) {
  //TODO implement
  /*
  for (int i = 0; i < 5; i++) {
    DLOG_EVERY_N(INFO, 3) << "Test";
  }*/
}

TEST(roslog_LogEveryN, glog_syntax_severity_info) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDOUT(LOG_EVERY_N(INFO, 3) << "Test");

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::info, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, glog_syntax_severity_warning) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDERR(LOG_EVERY_N(WARNING, 3) << "Test");

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::warning, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, glog_syntax_severity_error) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDERR(LOG_EVERY_N(ERROR, 3) << "Test");

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::error, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}

TEST(roslog_LogEveryN, glog_syntax_severity_fatal) {
  LOG_INIT(*test_argv);

  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDERR(LOG_EVERY_N(FATAL, 3) << "Test");

    if (i % 3 == 0) {
      ASSERT_EQ(rostest::fatal, removeNumbersFromString(output));
    } else {
      ASSERT_EQ("", removeNumbersFromString(output));
    }
  }
}