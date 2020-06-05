cmake_minimum_required(VERSION 2.6)



#
# Ràng buộc về version
#


#
# Tên project
#
project (parking_lot)



#
# Nơi chưa các file header(.h)
#
include_directories(include)



#
#
file(GLOB SOURCES "src/*.cpp")

#
# File chạy sẽ được tạo như thế nào
# Sử dụng thư viện đã khai báo qua PROJECT_LINK_LIBS
#
add_executable(parking_lot ${SOURCES})
