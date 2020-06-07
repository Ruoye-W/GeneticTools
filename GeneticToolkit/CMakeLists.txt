project(GeneticToolkit)

include_directories(Gene/include MersenneTwister/include GASolver/include)
add_subdirectory(Gene)
add_subdirectory(MersenneTwister)
add_subdirectory(GASolver)
