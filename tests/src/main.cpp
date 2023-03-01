#include <corgi/string/string.h>
#include <corgi/test/test.h>

using namespace corgi;

using corgi::test::equals;

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
            assert_that(corgi::string::starts_with(str, "Hello"), equals(true));
            assert_that(corgi::string::starts_with(str, "coin"), equals(false));

            str = "";
            assert_that(corgi::string::starts_with(str, "hoi"), equals(false));
        });

    test::add_test("string", "lowered",
                   []() -> void
                   {
                       std::string str = "Hello There";
                       corgi::string::to_lower(str);
                       assert_that(str, corgi::test::equals(std::string("hello there")));
                   });

    test::add_test("string", "to_upper",
                   []() -> void
                   {
                       std::string str = "Hello There";
                       corgi::string::to_upper(str);
                       assert_that(str, corgi::test::equals(std::string("HELLO THERE")));
                   });

    test::add_test(
        "string", "is_lower",
        []() -> void
        {
            std::string str = "hello there";
            assert_that(corgi::string::is_lower(str), corgi::test::equals(true));

            str = "Hello there";
            assert_that(corgi::string::is_lower(str), corgi::test::equals(false));
        });

    test::add_test(
        "string", "is_upper",
        []() -> void
        {
            std::string str = "HELLO THERE";
            assert_that(corgi::string::is_upper(str), corgi::test::equals(true));
            str = "Hello There";
            assert_that(corgi::string::is_upper(str), corgi::test::equals(false));
        });

    test::add_test("string", "capitalize",
                   []() -> void
                   {
                       std::string str = "heLLo ThErE";
                       corgi::string::capitalize(str);
                       assert_that(str, corgi::test::equals(std::string("Hello there")));

                       str = "";
                       corgi::string::capitalize(str);
                       assert_that(str, corgi::test::equals(std::string("")));
                   });

    test::add_test("string", "is_alpha_num",
                   []() -> void
                   {
                       std::string str = "Hello There #";
                       assert_that(corgi::string::is_alpha_num(str), equals(false));

                       str = "Hello15";
                       assert_that(corgi::string::is_alpha_num(str), equals(true));
                   });

    test::add_test("string", "is_alpha",
                   []() -> void
                   {
                       std::string str = "Hello15";
                       assert_that(corgi::string::is_alpha(str), equals(false));

                       str = "Hello";
                       assert_that(corgi::string::is_alpha(str), equals(true));
                   });

    test::add_test("string", "is_decimal",
                   []() -> void
                   {
                       std::string str = "12345";
                       assert_that(corgi::string::is_decimal(str), equals(true));

                       str = "hello there";
                       assert_that(corgi::string::is_decimal(str), equals(false));

                       str = "1234.43";
                       assert_that(corgi::string::is_decimal(str), equals(false));
                   });

    test::add_test("string", "is_number",
                   []() -> void
                   {
                       std::string str = "12345";
                       assert_that(corgi::string::is_number(str), equals(true));

                       str = "hello there";
                       assert_that(corgi::string::is_number(str), equals(false));

                       str = "1234.43";
                       assert_that(corgi::string::is_number(str), equals(true));
                   });

    test::add_test("string", "ljust",
                   []() -> void
                   {
                       std::string str = "cat";
                       corgi::string::ljust(str, 10);
                       assert_that(str, equals(std::string("cat       ")));
                   });

    test::add_test("string", "rjust",
                   []() -> void
                   {
                       std::string str = "cat";
                       corgi::string::rjust(str, 10);
                       assert_that(str, equals(std::string("       cat")));
                   });

    test::add_test("string", "lstrip",
                   []() -> void
                   {
                       std::string str = "     Hello there";
                       corgi::string::lstrip(str);
                       assert_that(str, equals(std::string("Hello there")));

                       str = "     Hello there";
                       corgi::string::lstrip(str, " H");
                       assert_that(str, equals(std::string("ello there")));
                   });

    test::add_test("string", "rstrip",
                   []() -> void
                   {
                       std::string str = "Hello there     ";
                       corgi::string::rstrip(str);
                       assert_that(str, equals(std::string("Hello there")));

                       str = "Hello there      ";
                       corgi::string::rstrip(str, " e");
                       assert_that(str, equals(std::string("Hello ther")));
                   });

    corgi::test::run_all();
    return 0;
}