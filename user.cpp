#include "user_message.hpp"

User::User(const std::string& name, const std::string& login, const std::string pass)
:_name(name)
, _login(login)
, _pass(pass) {

}

std::istream& operator >>(std::istream& is, User& user) {
	is >> user._name;
	is >> user._login;
	is >> user._pass;
	return is;
}

std::ostream& operator <<(std::ostream& os, const User& user) {
	os << user._name;
	os << ' ';
	os << user._login;
	os << ' ';
	os << user._pass;
	return os;
}