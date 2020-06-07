project(Test)

add_executable(${PROJECT_NAME} TestMain.cpp )
target_link_libraries(${PROJECT_NAME} GeneticToolkit::Gene)
target_link_libraries(${PROJECT_NAME} GeneticToolkit::MersenneTwister)
target_link_libraries(${PROJECT_NAME} GeneticToolkit::GASolver)
