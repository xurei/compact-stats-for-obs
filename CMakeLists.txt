cmake_minimum_required(VERSION 3.28...3.30)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/common/bootstrap.cmake" NO_POLICY_SCOPE)

project(${_name} VERSION ${_version})

option(ENABLE_FRONTEND_API "Use obs-frontend-api for UI functionality" ON)
option(ENABLE_QT "Use Qt functionality" ON)

include(compilerconfig)
include(defaults)
include(helpers)

set(CMAKE_AUTOMOC ON)

if(DEV_MODE)
  message("XUREILAB: DEV MODE ENABLED")
  add_compile_definitions(DEV_MODE)
  if(DEV_LOG_PATH)
    set(DEV_LOG_PATH "" CACHE STRING "Value of DEV_LOG_PATH")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEV_LOG_PATH="${DEV_LOG_PATH}")
  endif()
endif()

add_library(${CMAKE_PROJECT_NAME} MODULE)

find_package(libobs REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE OBS::libobs)

include(FetchContent)

# Dependency - YAML Parser
#FetchContent_Declare(
# yaml-cpp
#  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
#  GIT_TAG yaml-cpp-0.9.0
#)
#FetchContent_MakeAvailable(yaml-cpp)
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE yaml-cpp::yaml-cpp) # The library or executable that require yaml-cpp library

if(ENABLE_FRONTEND_API)
  find_package(obs-frontend-api REQUIRED)
  target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE OBS::obs-frontend-api)
endif()

if(ENABLE_QT)
  find_package(Qt6 COMPONENTS Widgets Core)
  target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)
  target_compile_options(
    ${CMAKE_PROJECT_NAME}
    PRIVATE $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-quoted-include-in-framework-header -Wno-comma>
  )
  set_target_properties(
    ${CMAKE_PROJECT_NAME}
    PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON
  )
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h)
file(GLOB sources_CPP
        "src/*.cpp"
        "src/**/*.cpp"
)
file(GLOB sources_HPP
        "src/*.hpp"
        "src/**/*.hpp"
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
      src/version.h
      ${sources_CPP}
)

set_target_properties_plugin(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME ${_name})

# Installer
configure_file("installer.iss.in"
        "${PROJECT_BINARY_DIR}/installer.iss"
)
