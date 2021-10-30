cmake_minimum_required(VERSION 3.19)
project(DesignPattern_2021)
set(CMAKE_CXX_STANDARD 14)


file(GLOB SRC_LIST "./Customer/*.*")
#add_library(DPlib Basic/welcome.cpp Basic/welcome.h
#        Shop/shop.cpp Shop/shop.h Shop/shopFilter.cpp Shop/shopFilter.h Shop/shopInterface.h Shop/shopInterface.cpp
#        Customer/ChatRoom.cpp Customer/ChatRoom.h Customer/Customer.cpp Customer/Customer.h Customer/CustomerMain.cpp Customer/Customers.cpp Customer/Customers.h Customer/Information.h Customer/Information.cpp Customer/UserInterface.cpp Customer/UserInterface.h
#        Commodity/Commodity.cpp Commodity/Commodity.h)
#add_executable(DesignPattern_2021
#        Application.cpp)
#target_link_libraries(DesignPattern_2021 DPlib)

add_executable(DesignPattern_2021
        ${SRC_LIST})
