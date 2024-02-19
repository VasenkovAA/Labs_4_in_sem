# указывайте последнюю доступную вам версию CMake
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# название проекта
project(ProgrammingLabsWork_2022_2023)

# затем следует список инструкций для подключения проектов из подкаталогов

include(cmake/function.cmake)    # подхватываем функции, реализованные в файле function.cmake
                                 # для простоты мы объединили наборы команд для создания статической библиотеки
								 # и для создания исполняемого проекта в отдельные функции
add_subdirectory(main)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем main
add_subdirectory(list)           # подключаем дополнительный CMakeLists.txt из подкаталога с именем list
add_subdirectory(TFraction)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем TFraction
add_subdirectory(TMonoms)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем TMonoms
add_subdirectory(TPolinoms)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем TPolinoms


option(BTEST "build test?" ON)   # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(tests)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()
