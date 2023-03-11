//
// Created by first on 11.03.23.
//

#ifndef CPPTGBOT_CALCULATE_PREFIX_EXP_H
#define CPPTGBOT_CALCULATE_PREFIX_EXP_H

#include <tgbot/Bot.h>
#include "../infix_to_prefix_cast.h"
#include "../Calculate_prefix_expression.h"

class calculate{
public:

    explicit calculate(std::string bot){
        this->bot_ptr = new TgBot::Bot(std::move(bot));
    }

    void Trigger(TgBot::Message::Ptr& message) {
        if (message->text.find("/c") != std::string::npos) {
            handler(message);
            std::cout << "Trigger calculate_prefix_exp was called\n" << "chat_id: " << message->chat->id;
            std::cout << "\ninput str: " << message->text;
            std::cout << "\nname: " << message->from->firstName << " " << message->from->username << std::endl;
        }
    }
private:

    TgBot::Bot *bot_ptr;

    void handler(TgBot::Message::Ptr& message) {
        message->text.erase(0,3);
        bot_ptr->getApi().sendMessage(message->chat->id, std::to_string(
                calculator::evaluatePrefix(infix_to_prefix::infixToPrefix(message->text))));
    }
};
#endif