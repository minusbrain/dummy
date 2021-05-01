#include <getopt.h>
#include <chrono>
#include <iostream>
#include <iterator>
#include <thread>

void print_help()
{
    std::cout << "Dummy tool - Tell me what to do and I'll do it.\n";
    std::cout << "I might be useful for testing stuff related to stdin, stdout, stderr or concurrency\n\n";
    std::cout << "dummy [-h] [-s <seconds>] [-t] [-o <text>] [-e <text>] [-r <integer>]\n\n";
    std::cout << "-h            : Print this help statement\n";
    std::cout << "-s <seconds>  : Process sleeps num of seconds\n";
    std::cout << "-t            : Tunnel stdin to stdout\n";
    std::cout << "-o <text>     : Text to print to stdout\n";
    std::cout << "-e <text>     : Text to print to stderr\n";
    std::cout << "-r <byte>     : Return value to exit process with\n";
}

int main(int argc, char** argv)
{
    int sleep_seconds = 0;
    char return_value = 0;
    bool tunnel_stdin_2_stdout = false;
    std::string text_stdout;
    std::string text_stderr;

    if (argc <= 1) 
    {
        print_help();
        return 1;
    }

    for (;;)
    {
        switch (getopt(argc, argv, "hs:to:e:r:"))
        {
            case '?':
            case 'h':
            default:
                print_help();
                break;

            case -1:
                break;

            case 's':
                sleep_seconds = atoi(optarg);
                continue;

            case 't':
                tunnel_stdin_2_stdout = true;
                continue;

            case 'o':
                text_stdout.assign(optarg);
                continue;

            case 'e':
                text_stderr.assign(optarg);
                continue;

            case 'r':
                return_value = atoi(optarg);
                continue;
        }

        break;
    }

    if (tunnel_stdin_2_stdout)
    {
        std::noskipws(std::cin);
        std::copy(std::istream_iterator<char>(std::cin), std::istream_iterator<char>(),
                  std::ostream_iterator<char>(std::cout));
    }
    if (text_stdout.compare("") != 0) std::cout << text_stdout;
    if (text_stderr.compare("") != 0) std::cerr << text_stderr;

    std::this_thread::sleep_for(std::chrono::seconds(sleep_seconds));
    std::cout << "\n";

    return return_value;
}
