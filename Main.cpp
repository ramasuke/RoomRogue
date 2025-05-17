#include <memory>
#include "DxLib.h"
#include "Application/ApplicationBase/ApplicationBase.h"
#include "Application/EditorApplication/EditorApplication.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	const auto application = std::make_unique<editor_application>();
	application->init();
	application->on_start_game_roop();
	application->on_exit();
	return 0;
}