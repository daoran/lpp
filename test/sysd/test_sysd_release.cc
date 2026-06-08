#include <gtest/gtest.h>
#include <log++.h>
#include <test_utils.h>

#include "sysd_test_utils.h"

using lpp::sysdtest::entries;

TEST(sysd_release, debug_logs_are_suppressed) {
  lpp::sysdtest::init(*test_argv);

  LOG(D, "lpp debug");
  DLOG(INFO) << "glog debug";
  ROS_DEBUG("ros debug");
  ROS_DEBUG_STREAM("ros debug stream");

  FLAGS_v = 1;
  VLOG(1) << "vlog debug";

  LOG_EVERY(D, 1, "lpp every debug");
  LOG_FIRST(D, 1, "lpp first debug");
  LOG_TIMED(D, 1, "lpp timed debug");

  ASSERT_TRUE(entries().empty());
}

TEST(sysd_release, non_debug_logs_are_not_suppressed) {
  lpp::sysdtest::init(*test_argv);

  LOG(I, "Test" << 123);

  ASSERT_EQ(entries().size(), 1);
  ASSERT_EQ(entries().at(0).severity, BaseSeverity::INFO);
  ASSERT_EQ(entries().at(0).message, "Test123");
  ASSERT_EQ(entries().at(0).identifier, lpp::internal::filenameFromPath(*test_argv));
}
