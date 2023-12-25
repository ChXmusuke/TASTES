cmake_minimum_required(VERSION 3.26)
project(TradingSimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(TradingSimulator main.cpp
        classes/Trader.h
        classes/Stock.h
        classes/Position.h
        classes/source/Trader.cpp
        classes/source/Stock.cpp
        classes/source/Position.cpp)
