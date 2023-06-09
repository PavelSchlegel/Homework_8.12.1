#include "user_message.hpp"

Message::Message(const std::string& text, const std::string& sender, const std::string receiver)
:_text(text)
,_sender(sender)
,_receiver(receiver) {

}

std::istream& operator >>(std::istream& is, Message& message) {
	std::getline(is, message._sender, '\0');
	std::getline(is, message._receiver, '\0');
	std::getline(is, message._text, '\0');
	return is;
}

std::ostream& operator <<(std::ostream& os, const Message& message) {
	os << message._sender;
	os << '\0';
	os << message._receiver;
	os << '\0';
	os << message._text;
	return os;
}