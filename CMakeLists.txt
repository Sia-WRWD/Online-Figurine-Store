cmake_minimum_required(VERSION 3.22)
project(Online_Figurine_Store)

set(CMAKE_CXX_STANDARD 14)

add_executable(Online_Figurine_Store main.cpp store_controller.h store_user.h store_po.h store_client.h store_item.h store_namespacer.h store_menu.h)
