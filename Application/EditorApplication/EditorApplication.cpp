#include <DxLib.h>
#include "EditorApplication.h"
#include "../../Library/ImGuiWrapper.h"
#include "../../Library/ImGui/imgui.h"
#include "../ApplicationBase/EditorApplicationParam.h"

void editor_application::init()
{
    DxLib::DxLib_Init();

    SetGraphMode(window_width_scale, window_height_scale, window_color_scale);
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(true);

    ImGuiWrapper::CreateInstance();
}

void editor_application::on_start_game_roop()
{
    while (check_continue_game_roop())
    {
        on_update_game_roop();
    }
}

void editor_application::on_update_game_roop()
{
    ClearDrawScreen();

    auto& im_gui_wrapper = ImGuiWrapper::Instance();
    im_gui_wrapper.Update();

    // UpdatableForGameRoopManager::ClearAllOnRemoveContent();
    // UpdatableForGameRoopManager::OnUpdate();
    // GameObject::OnDestroyAllDestroyedGameObejct();

    RenderVertex();
    im_gui_wrapper.Draw();
    ImGui::EndFrame();

    ScreenFlip();
}

void editor_application::on_exit()
{
}

bool editor_application::check_continue_game_roop()
{
    return ProcessMessage() >= 0 && !CheckHitKey(KEY_INPUT_ESCAPE);
}
