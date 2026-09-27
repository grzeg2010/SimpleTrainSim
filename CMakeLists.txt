#[[
SimpleTrainSim - application immitating train HUD.
Copyright (C) 2026 Grzegorz Śnieżko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
]]

cmake_minimum_required(VERSION 3.16)

project(SimpleTrainSim VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.10)

# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

include_directories(
    src
    src/model
    src/model/engine
    src/controller
    src/controller/indicator
)

qt_add_executable(appSimpleTrainSim
    src/main.cpp
    SimpleTrainSim.qrc
)

qt_add_qml_module(appSimpleTrainSim
    URI SimpleTrainSim
    QML_FILES
        SOURCES src/model/train.h src/model/train.cpp
        SOURCES src/model/engine/engine.h src/model/engine/engine.cpp
        SOURCES src/model/engine/electricengine.h src/model/engine/electricengine.cpp
        SOURCES src/model/engine/combustionengine.h src/model/engine/combustionengine.cpp
        RESOURCES SimpleTrainSim.qrc
        SOURCES src/model/brakes.h src/model/brakes.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSimpleTrainSim PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSimpleTrainSim
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSimpleTrainSim
    PRIVATE Qt6::Core Qt6::Quick Qt6::QuickControls2
)

install(TARGETS appSimpleTrainSim
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
