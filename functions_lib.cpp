#include "user_message.hpp"

namespace fs = std::filesystem;

void user_file_create() {
    std::ofstream("user.txt");
    fs::permissions("user.txt",
    fs::perms::group_all | fs::perms::others_all,
    fs::perm_options::remove);
}

void user_file_record_in_file(const User& user) {
    if (fs::exists("user.txt")) {
        std::fstream user_file = std::fstream("user.txt", std::ios::out);
        if (user_file) {
            user_file << user << std::endl;
            user_file.close();
            return;
        }
    }
    user_file_create();
    user_file_record_in_file(user);
}

void user_file_read(User& user) {
    if (fs::exists("user.txt")) {
        if (std::filesystem::is_empty("user.txt")) {
            return;
        }
        std::fstream user_file = std::fstream("user.txt", std::ios::in);
        if (user_file.is_open()) {
            user_file.seekg(0, std::ios_base::beg);
            user_file >> user;
            user_file.close();
        }
    }
    user_file_create();
    user_file_read(user);
}

void message_file_create() {
    std::ofstream("message.txt");
    fs::permissions("message.txt",
    fs::perms::group_all | fs::perms::others_all,
    fs::perm_options::remove);
}

void message_file_record_in_file(const Message& message) {
    if (fs::exists("message.txt")) {
        std::fstream user_file = std::fstream("message.txt", std::ios::out);
        if (user_file) {
            user_file << message << std::endl;
            user_file.close();
            return;
        }
    }
    message_file_create();
    message_file_record_in_file(message);
}

void message_file_read(Message& message) {
    if (fs::exists("message.txt")) {
        if (std::filesystem::is_empty("message.txt")) {
            return;
        }
        std::fstream user_file = std::fstream("message.txt", std::ios::in);
        if (user_file.is_open()) {
            user_file.seekg(0, std::ios_base::beg);
            user_file >> message;
            user_file.close();
            return;
        }
    }
    message_file_create();
    message_file_read(message);
}

void demo_perms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
        << '\n';
}