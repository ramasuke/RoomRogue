#pragma once
#include <DxLib.h>
#include "../Component.h"
#include "../../Vector2/Vector2.h"

class transform final : public component
{
public:
    vector2 position;
    float rotation;
    vector2 scale;

    template <class Archive>
    void serialize(Archive& archive)
    {
        archive(
            cereal::base_class<component>(this),
            CEREAL_NVP(position),
            CEREAL_NVP(rotation),
            CEREAL_NVP(scale)
        );
    }
};