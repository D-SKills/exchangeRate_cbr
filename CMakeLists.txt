cmake_minimum_required(VERSION 3.10)
project(ExchangeRateCbr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Используем pkg-config для поиска libpqxx
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

# Поиск CURL
find_package(CURL REQUIRED)

# Исходные файлы
file(GLOB SOURCES "*.cpp")

# Создание исполняемого файла
add_executable(ExchangeRateCbr ${SOURCES})

# Подключение библиотек
target_link_libraries(ExchangeRateCbr PRIVATE 
    CURL::libcurl 
    ${PQXX_LIBRARIES}
)

# Добавляем пути к заголовкам
target_include_directories(ExchangeRateCbr PRIVATE 
    ${PQXX_INCLUDE_DIRS}
)

# Добавляем флаги компиляции
target_compile_options(ExchangeRateCbr PRIVATE 
    ${PQXX_CFLAGS_OTHER}
)
