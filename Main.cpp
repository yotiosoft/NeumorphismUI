#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	
	double d = 0.5;
	int count = 0;
	
	Font font24(24);
	//NeumorphismUI::RectButtonObject 	rectButton(Size(100, 100), U"Push", font24, false);
	//NeumorphismUI::CircleButtonObject	circleButton(50, U"Push", font24, false);
	NeumorphismUI::Slider		slider(d, Vec2{400, 100}, 200, 30);
	NeumorphismUI::Switch		switchButton(true, 400, 300, 50, 30);
	//NeumorphismUI::RectButtonObject 	countButton(Size(200, 50), U"Count", font24, true);
	bool rectButtonPushed = true;
	bool circleButtonPushed = false;
	while (System::Update()) {
		NeumorphismUI::RectSwitch(Point(100, 100), Size(100, 100), U"Push", font24, rectButtonPushed);
		if (rectButtonPushed) {
			font24(U"ON").draw(250, 130, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 130, Palette::Black);
		}
		
		NeumorphismUI::CircleSwitch(Point(150, 320), 50, U"Push", font24, circleButtonPushed);
		if (circleButtonPushed) {
			font24(U"ON").draw(250, 300, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 300, Palette::Black);
		}
		
		d = slider.draw();
		font24(U"{:.2f}"_fmt(d)).draw(550, 150, Palette::Black);
		
		if (switchButton.draw()) {
			font24(U"ON").draw(550, 300, Palette::Black);
		}
		else {
			font24(U"OFF").draw(550, 300, Palette::Black);
		}
		
		if (NeumorphismUI::RectButton(Point(100, 450), Size(200, 50), U"Push", font24)) {
			count ++;
		}
		font24(count).draw(350, 460, Palette::Black);
    }
}
