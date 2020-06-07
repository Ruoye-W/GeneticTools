project(Gene)

add_library(${PROJECT_NAME} SHARED src/Gene.cpp)
add_library(GeneticToolkit::Gene ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )
