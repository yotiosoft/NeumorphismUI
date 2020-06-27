#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	
	double sliderVar = 0.5;		// スライダーの初期値
	bool slideSwitchVar = true;	// スライドスイッチの初期値
	int count = 0;
	
	Font font24(24);
	
	// スライダーの宣言
	NeumorphismUI::Slider slider(sliderVar, Vec2{400, 100}, 200, 30);
	// スライドスイッチの宣言
	NeumorphismUI::SlideSwitch slideSwitch(slideSwitchVar, 400, 300, 50, 30);
	
	bool rectSwitchPushed = true;		// 角丸長方形スイッチの初期値（ON）
	bool circleSwitchPushed = false;	// 丸型スイッチの初期値（OFF）
	
	while (System::Update()) {
		// 角丸長方形スイッチ
		NeumorphismUI::RectSwitch(Point(100, 100), Size(100, 100), rectSwitchPushed, U"Push", font24);
		if (rectSwitchPushed) {
			font24(U"ON").draw(250, 130, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 130, Palette::Black);
		}
		
		// 丸型スイッチ
		NeumorphismUI::CircleSwitch(Point(150, 320), 50, circleSwitchPushed, U"Push", font24);
		if (circleSwitchPushed) {
			font24(U"ON").draw(250, 300, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 300, Palette::Black);
		}
		
		// スライダー
		sliderVar = slider.draw();
		font24(U"{:.2f}"_fmt(sliderVar)).draw(550, 150, Palette::Black);
		
		// スライドスイッチ
		if (slideSwitch.draw()) {
			font24(U"ON").draw(550, 300, Palette::Black);
		}
		else {
			font24(U"OFF").draw(550, 300, Palette::Black);
		}
		
		// 角丸長方形ボタン -> カウンターとして動作
		if (NeumorphismUI::RectButton(Point(100, 450), Size(200, 50), U"Push", font24)) {
			count ++;
		}
		font24(count).draw(350, 460, Palette::Black);
    }
}
