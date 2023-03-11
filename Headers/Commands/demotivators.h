//
// Created by first on 11.03.23.
//

#ifndef CPPTGBOT_DEMOTIVATORS_H
#define CPPTGBOT_DEMOTIVATORS_H
#include <tgbot/Bot.h>

#include <utility>
#include <codecvt>


#define CP_ACP 0
#define MB_COMPOSITE 0
class Demotivators{
public:

    explicit Demotivators(std::string bot){
        this->bot_ptr = new TgBot::Bot(std::move(bot));
    }

    void Trigger(TgBot::Message::Ptr& message) {
       // if (message->text.find("/d") != std::string::npos) {
            handler(message);
            std::cout << "Trigger demotivators was called\n" << "chat_id: " << message->chat->id;
            std::cout << "\ninput str: " << message->text;
            std::cout << "\nname: " << message->from->firstName << " " << message->from->username << std::endl;
      //  }
    }
private:

    TgBot::Bot *bot_ptr;

    void handler(TgBot::Message::Ptr& message){
        std::string tmp;
        message->text.erase(0,3);
        std::string str = message->text;
        std::string Path = "phrases.txt";
        std::string line;
        std::ofstream outfile(Path);
        outfile << str << std::endl;
        outfile.close();
        system("python3 motya.py --output tmp.png");
        bot_ptr->getApi().sendPhoto(message->chat->id, TgBot::InputFile::fromFile("tmp.png", "image/jpeg"));
    }
};
#endif
