#include "doctest.h"

#include <oomph/variant.hpp>

TEST_CASE("variant index") {
  using t = std::variant<int, std::string>;
  REQUIRE(oomph::variant_index_v<int, t> == 0);
  REQUIRE(std::is_same_v<
          int, std::variant_alternative_t<oomph::variant_index_v<int, t>, t>>);
  REQUIRE(oomph::variant_index_v<std::string, t> == 1);
  REQUIRE(std::is_same_v<std::string,
                         std::variant_alternative_t<
                             oomph::variant_index_v<std::string, t>, t>>);
}
