
#include "game.hpp"
#include "GameLog.hpp"
#include <vector>

int main(){

    Game game;
    FileLogger logger;
    LoggerPool pool;
    pool.addLogger(&logger);
    std::vector<LogType> logs = {LogType::ERROR, LogType::INFO, LogType::GAME};
    pool.setLogTypes(logs);
    GameLog(&game, &pool);
    game.run();
    pool.printLogs();
    return 0;

}