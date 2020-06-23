#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(Color(224, 229, 236));
	
	double d = 0.5;
	int count = 0;
	
	Font font24(24);
	NeumorphismUI::RectButton 	rectButton(Vec2(100, 100), U"Push", font24, false);
	NeumorphismUI::CircleButton	circleButton(50, U"Push", font24, false);
	NeumorphismUI::Slider		slider(d, Vec2{400, 100}, 200, 30);
	NeumorphismUI::Switch		switchButton(true, 400, 300, 50, 30);
	NeumorphismUI::RectButton 	countButton(Size(200, 50), U"Count", font24, true);
	
	while (System::Update()) {
		if (rectButton.draw(Point(100, 100))) {
			font24(U"ON").draw(250, 130, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 130, Palette::Black);
		}
		
		if (circleButton.draw(Point(150, 320))) {
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
		
		countButton.draw(Point(100, 450));
		if (countButton.leftClicked()) {
			count ++;
		}
    }
}
