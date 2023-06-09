#ifndef USER_MESSAGE
#define USER_MESSAGE

#include <fstream>
#include <iostream>
#include <string>
#include <ostream>
#include <filesystem>

class User {
	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User() = default;
	User(const std::string& name, const std::string& login, const std::string pass);
	
	friend std::istream& operator >>(std::istream& is, User& user);
	friend std::ostream& operator <<(std::ostream& os, const User& user);
};

class Message {
    std::string _text;
    std::string _sender;
    std::string _receiver;
    
public:
	Message() = default;
    Message(const std::string& text, const std::string& sender, const std::string receiver);
	
	friend std::istream& operator >>(std::istream& is, Message& message);
	friend std::ostream& operator <<(std::ostream& os, const Message& message);
};

void user_file_create();
void user_file_record_in_file(const User& user);
void user_file_read(User& user);
void demo_perms(std::filesystem::perms p);
void message_file_create();
void message_file_record_in_file(const Message& message);
void message_file_read(Message& message);

#endif