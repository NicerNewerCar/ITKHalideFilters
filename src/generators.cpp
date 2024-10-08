#include "Halide.h"

using namespace Halide;

class MyFirstGenerator : public Generator<MyFirstGenerator>
{
public:
  Input<uint8_t>             offset{ "offset" };
  Input<Buffer<uint8_t, 2>>  input{ "input" };
  Output<Buffer<uint8_t, 2>> output{ "output" };

  Var x, y;

  void
  generate()
  {
    output(x, y) = input(x, y) + offset;
    output.vectorize(x, 16).parallel(y);
  }
};

HALIDE_REGISTER_GENERATOR(MyFirstGenerator, my_first_generator)
