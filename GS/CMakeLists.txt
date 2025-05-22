cmake_minimum_required(VERSION 3.16)

project(GS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=array-bounds -Werror=parentheses -Werror=vla -Wmissing-include-dirs -Wcast-qual)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(APPLE)
    set(CMAKE_PREFIX_PATH "/Users/jacekk/Qt/6.9.0/macos/lib/cmake/")
elseif (WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake/")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)


set(TS_FILES GS_pl_PL.ts)

set(PROJECT_SOURCES
        main.cpp
        connectionwindow.cpp
        connectionwindow.h
        connectionwindow.ui
        ${TS_FILES}
        SerialPort.cpp
        SerialPort.h
        SerialPortManager.cpp
        SerialPortManager.h
        DataFrame.cpp
        DataFrame.h
        Map.cpp
        Map.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GS
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mainwindow.h mainwindow.cpp mainwindow.ui
        Resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GS APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(GS SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GS
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(GS PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(GS PRIVATE Qt6::WebEngineWidgets)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GS)
endif()
set_target_properties(GS PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS GS
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GS)
endif()
