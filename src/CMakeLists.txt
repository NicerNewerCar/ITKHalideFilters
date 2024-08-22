find_package(Halide REQUIRED shared)

add_executable(my_generators generators.cpp)
target_link_libraries(my_generators PRIVATE Halide::Generator)
add_halide_library(my_first_generator FROM my_generators HEADER my_first_generator_h)
add_halide_library(cast_image_generator FROM my_generators HEADER cast_image_generator_float_unsigned_int_h PARAMS input.type=float32 output.type=uint32)
add_halide_library(cast_image_generator_double_unsigned_long FROM my_generators
  GENERATOR cast_image_generator
  HEADER cast_image_generator_double_unsigned_long_h
  PARAMS input.type=float64 output.type=uint64
)

set(HalideFilters_SRCS
  itkMinimalStandardRandomVariateGenerator.cxx
  itkHalideCastImageFilter.cxx
  ${my_first_generator_h}
  ${cast_image_generator_float_unsigned_int_h}
  ${cast_image_generator_double_unsigned_long_h}
  )

itk_module_add_library(HalideFilters ${HalideFilters_SRCS})
target_include_directories(HalideFilters PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(HalideFilters PRIVATE Halide::RunGenMain cast_image_generator cast_image_generator_double_unsigned_long)
