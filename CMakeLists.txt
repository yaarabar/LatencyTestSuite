cmake_minimum_required(VERSION 3.14)
project(benchmark)

set(CMAKE_CXX_STANDARD 14)

include_directories($ENV{INSTALL_DIR}/include)

set(FLAGS  "-I$ENV{INSTALL_DIR}/include -L$ENV{INSTALL_DIR}/lib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAGS}")

find_package(rpclib REQUIRED)

add_executable(benchClient MainClient.cpp
        LibuvCLient.cpp LibuvCLient.h AsioClient.cpp AsioClient.h
        AbstractClient.cpp AbstractClient.h Utilitis.h ClientFactory.cpp ClientFactory.h
        RpcClient.cpp RpcClient.h Client.cpp Client.h Massage.cpp Massage.h
        Session.cpp Session.h)



add_executable(benchServer MainServer.cpp
        LibuvServer.cpp LibuvServer.h AsioServer.cpp AsioServer.h
        AbstractServer.cpp AbstractServer.h ServerFactory.cpp ServerFactory.h
        Utilitis.h RpcServer.cpp RpcServer.h Server.cpp Server.h Massage.cpp Massage.h
        Session.cpp Session.h)

target_link_libraries(benchClient $ENV{INSTALL_DIR}/lib/libuv.so -lpthread rpclib::rpc -lboost_system)
target_link_libraries(benchServer $ENV{INSTALL_DIR}/lib/libuv.so -lpthread rpclib::rpc -lboost_system)
