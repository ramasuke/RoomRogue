#pragma once
#include <cereal/types/memory.hpp>

class component
{
    component() = default;
public:
    virtual ~component() = default;


public:
    template <class Archive>
    void serialize(Archive&) {}  // 基底クラスに serialize 定義（空でも必要）
};