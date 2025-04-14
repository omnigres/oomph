#include "doctest.h"

#include <oomph/cstring.hpp>

TEST_CASE("char * to cstring") {
  CHECK(strcmp(oomph::to_cstring(const_cast<char *>("hello")), "hello") == 0);
}

TEST_CASE("const char * to cstring") { CHECK(strcmp(oomph::to_cstring("hello"), "hello") == 0); }

TEST_CASE("std::string to cstring") {
  CHECK(strcmp(oomph::to_cstring(std::string("hello")), "hello") == 0);
}

TEST_CASE("std::string_view to cstring") {
  CHECK(strcmp(oomph::to_cstring(std::string_view(std::string("hello_world").data(), 3)), "hel") ==
        0);
}
