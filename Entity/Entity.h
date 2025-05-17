#pragma once
#include <memory>
#include <vector>
#include "../Component/Component.h"

class entity final
{
    std::vector<std::shared_ptr<component>> components_;

public:
    static entity spawn();
    void despawn();

    template <class Archive>
    void serialize(Archive& archive)
    {
        archive(CEREAL_NVP(components_));
    }
};