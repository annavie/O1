cmake_minimum_required(VERSION 3.5)

project(o1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(o1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        BoundingBox.h BoundingBox.cpp
        Item.h Item.cpp
        Shape.h
        Rectangle.h rectangle.cpp
        Circle.h Circle.cpp

        Point.h
        TextItem.h TextItem.cpp
        ImageItem.h ImageItem.cpp
        Slide.h Slide.cpp
        Document.h Document.cpp
        Command.h Command.cpp
        AddSlideCommand.h AddSlideCommand.cpp
        DeleteSlideCommand.h DeleteSlideCommand.cpp
        AddItemCommand.h AddItemCommand.cpp
        MoveItemCommand.h MoveItemCommand.cpp
        ResizeItemCommand.h ResizeItemCommand.cpp
        HelpCommand.h HelpCommand.cpp
        CommandFactory.h CommandFactory.cpp
        CommandRegistrar.h CommandRegistrar.cpp
        HistoryManager.h HistoryManager.cpp
        Editor.h Editor.cpp
        Parser.h Parser.cpp
        Controller.h Controller.cpp
        ParsedCommand.h ParsedCommand.cpp
        CLIController.h CLIController.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET o1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(o1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(o1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(o1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.o1)
endif()
set_target_properties(o1 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS o1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(o1)
endif()
