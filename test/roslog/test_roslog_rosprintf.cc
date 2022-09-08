#include <gtest/gtest.h>
#include <test_utils.h>
#include <log++.h>

TEST(roslog_rosprintf, ros_info) {
  ROS_INFO("Base angle (%f) is less than the minimum angle (%f)", 3.3, 5.5);
}

TEST(roslog_rosprintf, ros_info_once) {
  ROS_INFO_ONCE("Base angle (%f) is less than the minimum angle (%f)", 3.3, 5.5);
}

TEST(roslog_rosprintf, ros_warn) {
  ROS_WARN("Base angle (%f) is less than the minimum angle (%f)", 3.3, 5.5);
}

TEST(roslog_rosprintf, ros_warn_once) {
  ROS_WARN_ONCE("Base angle (%f) is less than the minimum angle (%f)", 3.3, 5.5);
}

TEST(roslog_rosprintf, ros_error) {
  ROS_ERROR("Base angle (%f) is less than the minimum angle (%f)", 3.3, 5.5);
}

TEST(roslog_rosprintf, ros_error_once) {
  ROS_ERROR_ONCE("Base angle (%f) is less than the minimum angle (%f)", 3.3, 5.5);
}
