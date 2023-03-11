//
// Created by first on 11.03.23.
//

#ifndef CPPTGBOT_START_H
#define CPPTGBOT_START_H
#include <tgbot/Bot.h>

#include <utility>


class Start{
public:

    explicit Start(std::string bot){
        this->bot_ptr = new TgBot::Bot(std::move(bot));
    }

    void Trigger(TgBot::Message::Ptr& message) {
        if (message->text.find("start") != std::string::npos) {
            bot_ptr->getApi().sendMessage(message->chat->id,
                                          "pnx");

            std::cout << "Trigger start was called\n" << "chat_id: " << message->chat->id;
            std::cout << "\ninput str: " << message->text;
            std::cout << "\nname: " << message->from->firstName << " " << message->from->username << std::endl;
        }
    }
private:

    TgBot::Bot *bot_ptr;

    void handler(TgBot::Message::Ptr& message){

    }
};
#endif
