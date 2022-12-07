CATKIN_PATH="$(which catkin)"

if [ "$CATKIN_PATH" = "" ]; then
    echo "Installing ros melodic"

    sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
    sudo apt install curl
    curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
    sudo apt update
    sudo apt install ros-melodic-ros-base

    source /opt/ros/melodic/setup.bash

    sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential python-catkin-tools libgoogle-glog-dev

    sudo rosdep init
    rosdep update

else
  sudo apt install -y libgoogle-glog-dev
  echo "catkin found"
fi

export DEBIAN_FRONTEND=noninteractive
BUILD_DIR=cmake-build
mkdir $BUILD_DIR
cmake CMakeLists.txt -B $BUILD_DIR/
cd $BUILD_DIR || exit
cmake --build . --target test_default -- -j 6
cmake --build . --target test_glog -- -j 6
cmake --build . --target test_lpp -- -j 6
cmake --build . --target test_roslog -- -j 6
./test_default
./test_roslog
./test_lpp
./test_roslog