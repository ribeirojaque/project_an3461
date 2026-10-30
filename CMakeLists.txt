cmake_minimum_required(VERSION 3.14)
project(TiltSensorApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclui a pasta include/ para achar os headers (.hpp)
include_directories(include)

# Compila o executável unindo a main e a classe
add_executable(tilt_app src/main.cpp src/TiltSensor.cpp)