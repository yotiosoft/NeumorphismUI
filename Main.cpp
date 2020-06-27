#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	
	Font font24(24);
	
	bool circleButtonPushed = false;
	
	while (System::Update()) {
		NeumorphismUI::CircleSwitch(Point(150, 150), 50, circleButtonPushed, U"Push", font24);
		if (circleButtonPushed) {
			font24(U"ON").draw(250, 130, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 130, Palette::Black);
		}
	}
}
