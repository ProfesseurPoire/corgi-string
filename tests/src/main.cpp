#include <corgi/string/string.h>
#include <corgi/test/test.h>

using namespace corgi;

int main()
{
    test::add_test("string", "chop",
                   []() -> void
                   {
                       std::string str = "Hello there";
                       corgi::string::chop(str, 6);

                       assert_that(str, test::equals(std::string("Hello")));

                       corgi::string::chop(str, 10);
                       assert_that(str, test::equals(std::string("")));

                       str = "Hello there";
                       corgi::string::chop(str, str.size());
                       assert_that(str, test::equals(std::string("")));
                   });

    test::add_test("string", "chopped",
                   []() -> void
                   {
                       std::string str    = "Hello there";
                       auto        result = corgi::string::chopped(str, 6);

                       assert_that(result, test::equals(std::string("Hello")));

                       result = corgi::string::chopped(result, 10);
                       assert_that(result, test::equals(std::string("")));

                       str    = "Hello there";
                       result = corgi::string::chopped(str, str.size());
                       assert_that(result, test::equals(std::string("")));
                   });

    test::add_test(
        "string", "ends_with",
        []() -> void
        {
            std::string str = "Hello there";
            assert_that(corgi::string::ends_with(str, "there"), test::equals(true));
            assert_that(corgi::string::ends_with(str, "coin"), test::equals(false));
        });

    test::add_test(
        "string", "starts_with",
        []() -> void
        {
            std::string str = "Hello there";
            assert_that(corgi::string::starts_with(str, "Hello"), test::equals(true));
            assert_that(corgi::string::starts_with(str, "coin"), test::equals(false));

            str = "";
            assert_that(corgi::string::starts_with(str, "hoi"), test::equals(false));
        });

    corgi::test::run_all();
    return 0;
}