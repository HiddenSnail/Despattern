cmake_minimum_required(VERSION 3.6)
project(UndoRedo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Context/UndoableEdit.h Context/AbstractUndoableEdit.cpp Context/AbstractUndoableEdit.h Context/CompoundEdit.cpp Context/CompoundEdit.h Context/UndoManager.cpp Context/UndoManager.h SimpleReality/ICommand.h SimpleReality/CutCommand.cpp SimpleReality/CutCommand.h SimpleReality/DelCommand.cpp SimpleReality/DelCommand.h SimpleReality/ICommadManager.h SimpleReality/CommandHistoryManager.cpp SimpleReality/CommandHistoryManager.h Factory.h BaseCommand.h BaseCommandManager.h Singleton.h CommandManager.cpp CommandManager.h BaseCommandReceiver.h Command.cpp Command.h MacroCommand.cpp MacroCommand.h PrintCommand.cpp PrintCommand.h)
add_executable(UndoRedo ${SOURCE_FILES})