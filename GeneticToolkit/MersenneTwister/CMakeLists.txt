project(MersenneTwister)

add_library(${PROJECT_NAME} SHARED src/MersenneTwister.cpp)
add_library(GeneticToolkit::MersenneTwister ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )
