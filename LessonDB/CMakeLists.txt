cmake_minimum_required(VERSION 3.20)

project(LessonDB)

add_executable(LessonDB main.cpp)

add_subdirectory("C:\\Users\\1\\source\\repos\\libpqxx-7.9.2" libpqxx-build) # Укажите путь к libpq++

target_compile_features(LessonDB PRIVATE cxx_std_17) # Включите C++17

target_link_libraries(LessonDB PRIVATE pqxx) # Слинкуйте libpq++ к проекту