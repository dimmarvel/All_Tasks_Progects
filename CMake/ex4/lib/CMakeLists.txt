cmake_minimum_required(VERSION 3.5)

project(Library VERSION 0.0.2) # название проекта - версия проекта

configure_file(
    #мы говорим на этапе генерации возьми шаблон config.h.in и подставь там всё как надо
    config.h.in
    #и положи вот сюда
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    #переменная CMAKE_CURRENT_BINARY_DIR говорит сконфигурируй файл в текущую директорию сборки
    # с названием config.h
)

add_library(lib STATIC lib.cpp lib.h)
set_target_properties(
    lib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(
    #эта функция добавляет для таргета configure директорию ${CMAKE_CURRENT_BINARY_DIR} в список инклюдов
    lib
    PRIVATE # configure если поставить в зависимость другому таргету то все помеченые как PUBLIC унаследуются во второй таргет а PRIVATE нет
    ${CMAKE_CURRENT_BINARY_DIR}
    #тем самым не имея файла config.h.in в репозитории мы можем его использовать в коде
)