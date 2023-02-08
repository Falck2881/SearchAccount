cmake_minimum_required(VERSION 3.21)

project(SearchAccount VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Xml)

qt_add_resources(RCC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/RccFileAccount/DataUser.qrc"
                           "${CMAKE_CURRENT_SOURCE_DIR}/RccImage/Image.qrc"
                           "${CMAKE_CURRENT_SOURCE_DIR}/Style/Style.qrc")

set(SRC_COMMANDS Commands/Commands.h
                 Commands/AuthenticationCommand.cpp Commands/AuthenticationCommand.h
                 Commands/AuthorizationLinker.cpp Commands/AuthorizationLinker.h
                 Commands/CreateAvlTree.cpp Commands/CreateAvlTree.h
                 Commands/CreateB_Tree.cpp Commands/CreateB_Tree.h
                 Commands/CreatePBBT.cpp  Commands/CreatePBBT.h
                 Commands/CreateRBT.cpp Commands/CreateRBT.h
                 Commands/CreateTwo_Three_Tree.cpp Commands/CreateTwo_Three_Tree.h
                 Commands/DisableButtonCommand.cpp Commands/DisableButtonCommand.h
                 Commands/EnabledAllButtonsChoiceCommand.cpp Commands/EnabledAllButtonsChoiceCommand.h
                 Commands/EnabledButtonCommand.cpp Commands/EnabledButtonCommand.h
                 Commands/HideWinCommand.cpp Commands/HideWinCommand.h
                 Commands/IDCommand.cpp Commands/IDCommand.h
                 Commands/LoadingCommand.cpp Commands/LoadingCommand.h
                 Commands/ManagerChoice.cpp Commands/ManagerChoice.h
                 Commands/ManagerLinkerCommand.cpp Commands/ManagerLinkerCommand.h
                 Commands/OffCheckedButtonsCommand.cpp Commands/OffCheckedButtonsCommand.h
                 Commands/OpenWinCommand.cpp Commands/OpenWinCommand.h
                 Commands/ResetProgressBarCommand.cpp Commands/ResetProgressBarCommand.h)


set(SRC_BINARY_TREE
                    StructureData/BalancedTree.cpp StructureData/BalancedTree.h
                    StructureData/BinaryTree.cpp StructureData/BinaryTree.h
                    StructureData/BuilderAvlTree.cpp StructureData/BuilderAvlTree.h
                    StructureData/BuilderBalancedTree.cpp StructureData/BuilderBalancedTree.h
                    StructureData/BuilderPBBT.cpp StructureData/BuilderPBBT.h
                    StructureData/BuilderRBT.cpp StructureData/BuilderRBT.h
                    StructureData/BuilderTree.cpp StructureData/BuilderTree.h
                    StructureData/Tree.cpp StructureData/Tree.h)

set(SRC_WINDOWS Warnings/Warning.cpp  Warnings/Warning.h
                Windows/Window.h Windows/Window.cpp
                Windows/PropertyInput.h
                Windows/Window.cpp Windows/Window.h
                Windows/WindowChoice.cpp Windows/WindowChoice.h Windows/WindowChoice.ui
                Windows/WindowDisplay.cpp Windows/WindowDisplay.h
                Windows/WindowExamples.cpp Windows/WindowExamples.h Windows/WindowExamples.ui
                Windows/WindowLoad.cpp Windows/WindowLoad.h Windows/WindowLoad.ui
                Windows/WindowStatistics.cpp Windows/WindowStatistics.h Windows/WindowStatistics.ui
                Windows/WindowUser.cpp Windows/WindowUser.h Windows/WindowUser.ui)

set(OTHER_SRC
                StructureData/Account.cpp StructureData/Account.h
                Stream/XmlStreamRead.h Stream/XmlStreamRead.cpp
                Stream/XmlStreamWrite.h Stream/XmlStreamWrite.cpp
                MainWindow.cpp MainWindow.h MainWindow.ui
                Observers/Observers.h Observers/ManagerBuilders.cpp Observers/ManagerBuilders.h
                main.cpp)

if(WIN32)
    add_executable(SearchAccount WIN32 ${SRC_COMMANDS} ${SRC_BINARY_TREE}
                                       ${SRC_WINDOWS}  ${OTHER_SRC} ${RCC_FILES})
else()
    add_executable(SearchAccount ${SRC_COMMANDS} ${SRC_BINARY_TREE}
                                 ${SRC_WINDOWS}  ${OTHER_SRC} ${RCC_FILES})
endif()

target_include_directories(SearchAccount PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Stream"
                                                 "${CMAKE_CURRENT_SOURCE_DIR}/Observers"
                                                 "${CMAKE_CURRENT_SOURCE_DIR}/StructureData"
                                                 "${CMAKE_CURRENT_SOURCE_DIR}/Windows"
                                                 "${CMAKE_CURRENT_SOURCE_DIR}/Warnings"
                                                 "${CMAKE_CURRENT_SOURCE_DIR}/Commands")

target_link_libraries(SearchAccount PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                            Qt${QT_VERSION_MAJOR}::Core
                                            Qt${QT_VERSION_MAJOR}::Xml)

