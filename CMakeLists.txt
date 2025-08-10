cmake_minimum_required(VERSION 3.28)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/paklibConfigVersion.cmake"
  VERSION 0.0.2
  COMPATIBILITY AnyNewerVersion
)

project(paklib)

add_library(paklib
    src/pak-file.cpp
)

set_property(TARGET paklib PROPERTY CXX_STANDARD 20)

target_include_directories(paklib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE src
)

install(TARGETS paklib
    EXPORT paklibTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    
    CONFIGURATIONS Debug Release
)

install(DIRECTORY include/ DESTINATION include/paklib)

configure_package_config_file(
  "${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/paklibConfig.cmake"
  INSTALL_DESTINATION lib/cmake/paklib

)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/paklibConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/paklibConfigVersion.cmake"
  DESTINATION lib/cmake/paklib
)

install(EXPORT paklibTargets
    FILE paklibTargets.cmake
    NAMESPACE ploinky::
    DESTINATION lib/cmake/paklib
)

set_target_properties(paklib PROPERTIES
    DEBUG_POSTFIX d
)