#pragma once
#include <cmath>
#include <string>
#include "../Application/ApplicationBase/EditorApplicationParam.h"
#include "../Library/ImGui/imgui.h"

struct vector2
{
    float x;
    float y;

    explicit vector2(const float x = 0.0, const float y = 0.0) : x(x), y(y)
    {
    }

    vector2 operator+(const vector2& other) const { return vector2(x + other.x, y + other.y); }
    vector2 operator-(const vector2& other) const { return vector2(x - other.x, y - other.y); }
    vector2 operator*(const float scalar) const { return vector2(x * scalar, y * scalar); }
    vector2 operator/(const float scalar) const { return vector2(x / scalar, y / scalar); }

    vector2& operator+=(const vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    vector2& operator-=(const vector2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    vector2& operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    float dot(const vector2& other) const { return x * other.x + y * other.y; }
    float magnitude() const { return std::sqrt(x * x + y * y); }

    vector2 normalize() const
    {
        const float mag = magnitude();
        return (mag > 0) ? (*this / mag) : vector2();
    }

    float sqrt_magnitude() const { return std::sqrt(magnitude()); }

    std::string to_string() const
    {
        std::string string_builder = std::to_string(x);
        string_builder.append(", ");
        string_builder.append(std::to_string(y));
        return string_builder;
    }

    void on_draw_debug_window()
    {
        if (ImGui::CollapsingHeader("Position"))
        {
            ImGui::SliderFloat("x", &x, 0, window_width_scale);
            ImGui::SliderFloat("y", &y, 0, window_height_scale);
        }
    }

    static vector2 one()
    {
        return vector2(1, 1);
    }

    template <class Archive>
    void serialize(Archive& archive)
    {
        archive(CEREAL_NVP(x), CEREAL_NVP(y));
    }
};
