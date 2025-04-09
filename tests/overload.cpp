#include "doctest.h"

#include <oomph/overload.hpp>

TEST_CASE("overload dispatch") {
  auto overloaded = oomph::overload{
      [](int) { return 0; },
      [](float) { return 1; },
  };
  REQUIRE(overloaded(1) == 0);
  REQUIRE(overloaded(1.1f) == 1);
}
