cmake_minimum_required(VERSION 3.10)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files here
set(SOURCE_FILES
        src/model/main.cpp src/model/Board.cpp include/model/Board.h src/model/Square.cpp include/model/Square.h src/model/Piece.cpp include/model/Piece.h src/model/Pawn.cpp
        include/model/Pawn.h src/model/Bishop.cpp include/model/Bishop.h src/model/Knight.cpp include/model/Knight.h src/model/King.cpp include/model/King.h src/model/Rook.cpp
        include/model/Rook.h src/model/Queen.cpp include/model/Queen.h include/typedefs.h src/model/Interface.cpp include/model/Interface.h src/model/Game.cpp include/model/Game.h
        src/model/Player.cpp include/model/Player.h src/model/UserInterface.cpp include/model/UserInterface.h src/model/ComputerInterface.cpp include/model/ComputerInterface.h
        src/exceptions/PlayerException.cpp include/exceptions/PlayerException.h src/exceptions/SquareExceptions.cpp include/exceptions/SquareExceptions.h src/exceptions/GameExceptions.cpp include/exceptions/GameExceptions.h)

add_executable(Project ${SOURCE_FILES} )

target_include_directories(Project PUBLIC include)

#TESTs
find_package(Boost 1.65 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)


enable_testing()

#Test source files here
set(SOURCE_TEST_FILES
        src/model/Board.cpp include/model/Board.h src/model/Square.cpp include/model/Square.h src/model/Piece.cpp include/model/Piece.h src/model/Pawn.cpp include/model/Pawn.h
        src/model/Bishop.cpp include/model/Bishop.h src/model/Knight.cpp include/model/Knight.h src/model/King.cpp include/model/King.h src/model/Rook.cpp include/model/Rook.h
        src/model/Queen.cpp include/model/Queen.h include/typedefs.h src/model/Interface.cpp include/model/Interface.h src/model/Game.cpp include/model/Game.h
        test/master.cpp test/RookTest.cpp test/PawnTest.cpp test/KingTest.cpp test/QueenTest.cpp test/BishopTest.cpp test/KnightTest.cpp
        test/BoardTest.cpp test/SquareTest.cpp test/InterfaceTest.cpp src/model/Player.cpp include/model/Player.h src/model/UserInterface.cpp
        include/model/UserInterface.h src/model/ComputerInterface.cpp include/model/ComputerInterface.h test/PlayerTest.cpp
        src/exceptions/PlayerException.cpp include/exceptions/PlayerException.h src/exceptions/SquareExceptions.cpp include/exceptions/SquareExceptions.h src/exceptions/GameExceptions.cpp include/exceptions/GameExceptions.h test/GameTest.cpp)


add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

target_link_libraries(TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
