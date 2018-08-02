#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util.h"
#include <doctest.h>

SCENARIO( "Convert characters to hex" ) {
    GIVEN( "a valid char" ) {
        WHEN( "'a' is passed in" ) {
            THEN( "should receive 49" ) {
                REQUIRE(to_hex('a') == 49);
            }
        }
    }
}

SCENARIO( "Convert characters from hex" ) {
    GIVEN( "a valid digit" ) {
        char* inputs = "0123456789";
        WHEN( "a digit is passed in" ) {
            THEN( "should receive the numeric version of the character" ) {
                for (char expected = 0; expected < 10; ++expected) {
                    CAPTURE(expected);
                    REQUIRE(from_hex(inputs[expected]) == expected);
                }
            }
        }
    }
        GIVEN( "a valid char" ) {
        WHEN( "'a' is passed in" ) {
            THEN( "should receive 10" ) {
                REQUIRE(from_hex('a') == 10);
            }
        }
    }
}



SCENARIO( "Compute the invariants of to_hex" ) {

    GIVEN( "an invalid char" ) {
        THEN( "false should be returned for int input" ) {
            //REQUIRE(to_hex(1) == false);
        }
    }
}

SCENARIO ("Check if json_header works") {
    std::string expected = "Status: 200 OK\nContent-type: application/json\n\n";
    WHEN ("json header is called with no parameters") {
        THEN("content type for json and 200 OK returned") {
            CHECK(expected == json_header());
        }

    }
    WHEN ("json header is passed StatusCode::ok") {
        THEN("content type for json and 200 OK returned") {
            CHECK(expected == json_header(StatusCode::ok));
        }

    }
    WHEN ("json header is passed StatusCode::bad") {
        THEN("content type for json and 400 Bad Request returned") {
            expected = "Status: 400 Bad Request\nContent-type: application/json\n\n";
            CHECK(expected == json_header(StatusCode::bad));
        }

    }

}
