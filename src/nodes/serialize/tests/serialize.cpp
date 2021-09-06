#include "catch2/catch.hpp"
#include "nodes/serialize/serialize.h"
#include "nodes/serialize/image_format.h"

using namespace texturegenerator;
using namespace texturegenerator::nodes::serialize;

//////////
/// get_node_type
//////////

TEST_CASE("get_node_type - returns correct value", "[nodes/serialize/serialize]") {
    serialize node;

    auto result = node.get_node_type();

    auto expected { shared::graph::node_types::serialize };

    REQUIRE(expected == result);
}

//////////
/// run
//////////

TEST_CASE("run - no image type parameter - returns error", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };

    shared::graph::parameters parameters;
    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE_FALSE(result);
}

TEST_CASE("run - valid parameters - does not return error", "[nodes/serialize/serialize]") {
    serialize node;

    auto origin { glm::vec4() };
    auto frame_width { 32u };
    auto frame_height { 64u };
    auto image_format { image_formats::PNG };

    shared::graph::parameters parameters;
    parameters.set("image_format", static_cast<uint32_t>(image_format));

    std::vector<std::shared_ptr<shared::graph::socket>> sockets_in;

    auto result = node.run(origin, frame_width, frame_height, parameters, sockets_in);

    REQUIRE(result);
}
