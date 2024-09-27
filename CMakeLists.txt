cmake_minimum_required(VERSION 3.27)
project(qsh)

set(CMAKE_CXX_STANDARD 17)

set(QSH_SERVERURL "https://qsh.ech0.dev" )

#include_directories(include)

add_subdirectory(qsh-server)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Oz -fPIC -ffast-math -mllvm -inline-threshold=0 ")
#set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC" )
#set(CMAKE_EXE_LINKER_FLAGS "-flto=full -s -fPIC")
set(CMAKE_CXX_FLAGS "-g -O0")
set(CMAKE_C_FLAGS  "-g -O0" )

