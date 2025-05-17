#pragma once
#include "../ApplicationBase/ApplicationBase.h"

class editor_application final : public application_base
{
public:
    void init() override;
    void on_start_game_roop() override;
    void on_update_game_roop() override;
    void on_exit() override;
    
private:
    static bool check_continue_game_roop();
};