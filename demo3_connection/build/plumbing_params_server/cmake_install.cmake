# Install script for directory: /home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/src/plumbing_params_server

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/build/plumbing_params_server/catkin_generated/installspace/plumbing_params_server.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/plumbing_params_server/cmake" TYPE FILE FILES
    "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/build/plumbing_params_server/catkin_generated/installspace/plumbing_params_serverConfig.cmake"
    "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/build/plumbing_params_server/catkin_generated/installspace/plumbing_params_serverConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/plumbing_params_server" TYPE FILE FILES "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/src/plumbing_params_server/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plumbing_params_server" TYPE PROGRAM FILES "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/build/plumbing_params_server/catkin_generated/installspace/demo01_param_set_p.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plumbing_params_server" TYPE PROGRAM FILES "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/build/plumbing_params_server/catkin_generated/installspace/demo02_param_get_p.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plumbing_params_server" TYPE PROGRAM FILES "/home/stoner/vscode_workplace/Object_Tracking_Algorithms/ROS_Tutorial/demo3_connection/build/plumbing_params_server/catkin_generated/installspace/demo03_param_del_p.py")
endif()

