cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Event/Event.h Player/Player.cpp Player/Player.h Cell/Cell.cpp Cell/Cell.h Cell/CellView.cpp Cell/CellView.h Field/Field.cpp Field/Field.h Field/FieldView.cpp Field/FieldView.h Runner/Runner.cpp Runner/Runner.h Field/FieldMaker.cpp Field/FieldMaker.h Event/PlayerEvent/PlayerEvent.h Event/PlayerEvent/Heal.cpp Event/PlayerEvent/Heal.h Event/PlayerEvent/Enemy.cpp Event/PlayerEvent/Enemy.h Event/MapEvent/PressurePlate.cpp Event/MapEvent/PressurePlate.h Event/MapEvent/MapEvent.h Event/MapEvent/Victory.cpp Event/MapEvent/Victory.h Message/Message.h Logger/ConsoleLogger.cpp Logger/ConsoleLogger.h Logger/Logger.h Logger/FileLogger.cpp Logger/FileLogger.h Logger/LoggerPool.cpp Logger/LoggerPool.h Logger/LoggerCreator.cpp Logger/LoggerCreator.h Logger/Logger.h Observer/Observer.cpp Observer/Observer.h Message/Message.cpp Runner/CommandReader.cpp Runner/CommandReader.h Runner/Control.cpp Runner/Control.h Runner/Mediator.cpp Runner/Mediator.h)
