/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkHalideCastImageFilter.h"
#include "cast_image_generator.h"
#include "cast_image_generator_double_unsigned_long.h"
#include <iostream>

namespace itk
{

template <>
void
HalideCastImageFilter<Image<float, 2>, Image<unsigned int, 2>>::RunHalideGenerator(
  Halide::Runtime::Buffer<const InputPixelType> & inputBuffer,
  Halide::Runtime::Buffer<OutputPixelType> &      outputBuffer)
{
  cast_image_generator(inputBuffer, outputBuffer);
}

template <>
void
HalideCastImageFilter<Image<double, 2>, Image<unsigned long, 2>>::RunHalideGenerator(
  Halide::Runtime::Buffer<const InputPixelType> & inputBuffer,
  Halide::Runtime::Buffer<OutputPixelType> &      outputBuffer)
{
  cast_image_generator_double_unsigned_long(inputBuffer, outputBuffer);
}

} // namespace itk
