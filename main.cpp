#include "user_message.hpp"

int main() {
    //пример сохранения состояния об. user
    User a {"Andrey", "Halk" , "qwerty"};
    user_file_record_in_file(a);
    //пример чтения об. message
    Message b;
    message_file_read(b);
    return 0;
}