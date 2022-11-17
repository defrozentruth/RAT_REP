cmake_minimum_required(VERSION 3.0.0)
project(THE_GAME VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(THE_GAME
                main.cpp
                Events/Map_Events/earthquake.hpp
                Events/Map_Events/earthquake.cpp
                Events/Map_Events/sledge.hpp
                Events/Map_Events/sledge.cpp
                Events/Player_Events/enemy.hpp
                Events/Player_Events/enemy.cpp
                Events/Player_Events/overseer.hpp
                Events/Player_Events/overseer.cpp
                Events/Player_Events/trap.hpp
                Events/Player_Events/trap.cpp
                Events/Player_Events/win.hpp
                Events/Player_Events/win.cpp
                Events/event.hpp
                Events/map_events.hpp
                Events/player_events.hpp
                Execute/controller.hpp
                Execute/controller.cpp
                Execute/execute.hpp
                Execute/execute.cpp
                Execute/fieldview.hpp
                Execute/fieldview.cpp
                Logs/ConsoleLog.hpp
                Logs/ConsoleLog.cpp
                Logs/FileLog.hpp
                Logs/FileLog.cpp
                Logs/Logger.hpp
                Logs/LogPool.hpp
                Logs/LogPool.cpp
                Logs/Message.hpp
                Logs/Message.cpp
                Map_Player/cell.hpp
                Map_Player/cell.cpp
                Map_Player/field.hpp
                Map_Player/field.cpp
                Map_Player/player.hpp
                Map_Player/player.cpp
                CmdRead/ConsoleCmdRead.cpp
                CmdRead/ConsoleCmdRead.hpp
                CmdRead/FileSettingsRead.cpp
                CmdRead/FileSettingsRead.hpp
                CmdRead/ICmdRead.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

