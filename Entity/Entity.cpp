#include "Entity.h"
#include <fstream>
#include <cereal/archives/json.hpp>

entity entity::spawn()
{
    entity e;

    std::ifstream is("entity.json");
    if (is)
    {
        cereal::JSONInputArchive archive(is);
        archive(cereal::make_nvp("Entity", e));
    }

    return e;
}

void entity::despawn()
{
    std::ofstream os("entity.json");
    cereal::JSONOutputArchive archive(os);
    archive(cereal::make_nvp("Entity", *this));
}