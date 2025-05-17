#pragma once
#include <type_traits>

#include "../../EntityContainer/EntityContainer.h"

class application_base
{
    static application_base* instance_;
    entity_container entity_container_;
    
public:
    application_base();
    virtual ~application_base() = default;
    static application_base& get_instance();

protected:
    virtual void init() = 0;
    virtual void on_start_game_roop() = 0;
    virtual void on_update_game_roop() = 0;
    virtual void on_exit() = 0;
};
