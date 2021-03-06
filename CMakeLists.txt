CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )
project( chifoumi )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14 ${CMAKE_CXX_FLAGS} ")

find_package( PkgConfig REQUIRED )
pkg_check_modules( Pkg REQUIRED libglog cpputest)
include_directories( ${Pkg_INCLUDE_DIRS} )

ADD_EXECUTABLE( chifoumi.out 
  src/chifoumi.cpp
  )

TARGET_LINK_LIBRARIES( chifoumi.out 
  ${Pkg_LIBRARIES})

ADD_EXECUTABLE(main_test.out
  src/TU/main_test.cpp
  src/TU/chifoumi_test.cpp
  )

TARGET_LINK_LIBRARIES( main_test.out 
    ${Pkg_LIBRARIES})

install (TARGETS chifoumi.out DESTINATION bin)

# build doxygen documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(Doxyfile.in ${CMAKE_BINARY_DIR}/Doxyfile)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    install(DIRECTORY ${CMAKE_BINARY_DIR}/doc/html 
        DESTINATION share/doc/${CMAKE_PROJECT_NAME})
endif()