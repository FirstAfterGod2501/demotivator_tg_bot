//
// Created by first on 11.03.23.
//

#ifndef CPPTGBOT_BOTHANDLER_H
#define CPPTGBOT_BOTHANDLER_H

#include <string>
#include <fstream>
#include <tgbot/tgbot.h>
#include "Commands/start.h"
#include "Commands/calculate_prefix_exp.h"
#include "Commands/demotivators.h"

class BotHandler{
private:

    std::string token;

    static std::string GetToknFromFile(const std::string& filename){
        std::string line;
        std::ifstream in(filename);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                return line;
            }
        }
        in.close();
        return {};
    }

    void StartBot() {
        TgBot::Bot bot(token);

        auto start = Start(token);
        auto calc = calculate(token);
        auto demotivator = Demotivators(token);

        bot.getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
            start.Trigger(message);
        });
        bot.getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
            calc.Trigger(message);
        });
        bot.getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
            demotivator.Trigger(message);
        });
        try {
            printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
            TgBot::TgLongPoll longPoll(bot);
            while (true) {
                printf("Long poll started\n");
                longPoll.start();
            }
        } catch (TgBot::TgException &e) {
            printf("error: %s\n", e.what());
        }
    }

public:

    BotHandler(){
        token = GetToknFromFile("../credentials.txt");
        StartBot();
    }
};

#endif
