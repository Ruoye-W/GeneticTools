project(GASolver)

add_library(${PROJECT_NAME} SHARED src/GASolver.cpp)
add_library(GeneticToolkit::GASolver ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )
