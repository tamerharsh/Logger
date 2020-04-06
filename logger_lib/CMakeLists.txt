#For including fmt lib for formatting.
add_subdirectory(include/thirdparty/fmt EXCLUDE_FROM_ALL)

#Finding fmt package from predefined path.
find_package(fmt PATHS ${CMAKE_CURRENT_SOURCE_DIR}/include/fmt/)

#Interface target for logger lib.
add_library(logger_lib_target INTERFACE )

#Include Directories for logger lib target.
target_include_directories(logger_lib_target INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  
)

#linking logger lib target to fmt target .
target_link_libraries(logger_lib_target INTERFACE  fmt::fmt)

