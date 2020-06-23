//
//  	  NeumorphismUI
//
//  		ver.0.1.0
//

#ifndef NeumorphismUI_hpp
#define NeumorphismUI_hpp

#include <stdio.h>
#include <cmath>
#include <Siv3D.hpp> // OpenSiv3D v0.4.3

namespace NeumorphismUI {
	// 角丸長方形のボタン
	class RectButton {
	public:
		RectButton(int argSizeX, int argSizeY) {
			init(argSizeX, argSizeY, false);
		}
		
		RectButton(Vec2 argSize) {
			init(argSize.x, argSize.y, false);
		}
		
		RectButton(int argSizeX, int argSizeY, bool argRebound) {
			init(argSizeX, argSizeY, argRebound);
		}
		
		RectButton(Vec2 argSize, bool argRebound) {
			init(argSize.x, argSize.y, argRebound);
		}
		
		RectButton(int argSizeX, int argSizeY, String argStr, Font& argFont) {
			init(argSizeX, argSizeY, argStr, argFont, false);
		}
		
		RectButton(Vec2 argSize, String argStr, Font& argFont) {
			init(argSize.x, argSize.y, argStr, argFont, false);
		}
		
		RectButton(int argSizeX, int argSizeY, String argStr, Font& argFont, bool argRebound) {
			init(argSizeX, argSizeY, argStr, argFont, argRebound);
		}
		
		RectButton(Vec2 argSize, String argStr, Font& argFont, bool argRebound) {
			init(argSize.x, argSize.y, argStr, argFont, argRebound);
		}
		
		bool draw(Point argPosition) {
			if (buttonRect.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			
			if (rebound) {
				if (buttonRect.leftPressed()) {
					pressed = true;
				}
				if (pressed && buttonRect.leftReleased()) {
					pressed = false;
				}
			}
			else if (buttonRect.leftPressed() && !beforeLeftClicked) {
				pressed = !pressed;
			}
			beforeLeftClicked = buttonRect.leftPressed();
			
			buttonRect = RoundRect(argPosition, buttonSize.x, buttonSize.y, radius);
			if (pressed) {
				buttonRect.drawShadow(upperShadowPosOffset, blurSize, shadowSize, darkShadow).drawShadow(lowerShadowPosOffset, blurSize, shadowSize, lightShadow).draw(background);
				mat = Mat3x2::Scale(0.9, Point(argPosition.x+buttonSize.x/2, argPosition.y+buttonSize.y/2));
			}
			else {
				buttonRect.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, darkShadow).drawShadow(upperShadowPosOffset, blurSize, shadowSize, lightShadow).draw(background);
				mat = Mat3x2::Identity();
			}
			
			if (!font.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					font(str).drawAt(argPosition.x+buttonSize.x/2, argPosition.y+buttonSize.y/2, Palette::Gray);
				}
			}
			
			return pressed;
		}
		
		bool leftClicked() {
			return buttonRect.leftClicked();
		}
		
	private:
		RoundRect buttonRect;
		
		Size buttonSize;
		String str;
		
		Font font;
		
		int radius;
		
		bool rebound;
		
		Vec2 upperShadowPosOffset;
		Vec2 lowerShadowPosOffset;
		int blurSize;
		int shadowSize;
		
		Color background;
		Color darkShadow;
		Color lightShadow;
		
		bool pressed;
		bool beforeLeftClicked;
		
		Mat3x2 mat;
		
		void init(int argSizeX, int argSizeY, bool argRebound) {
			buttonSize.x = argSizeX;
			buttonSize.y = argSizeY;
			
			radius = 10;
			
			rebound = argRebound;
			
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			background = Color(224, 229, 236);
			darkShadow = Color(163, 177, 198);
			lightShadow = Color(255, 255, 255);
			
			pressed = false;
			beforeLeftClicked = false;
		}
		
		void init(int argSizeX, int argSizeY, String argStr, Font& argFont, bool argRebound) {
			buttonSize.x = argSizeX;
			buttonSize.y = argSizeY;
			str = argStr;
			
			radius = 10;
			
			rebound = argRebound;
			
			font = argFont;
			
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			background = Color(224, 229, 236);
			darkShadow = Color(163, 177, 198);
			lightShadow = Color(255, 255, 255);
			
			pressed = false;
			beforeLeftClicked = false;
		}
	};
	
	// 円形のボタン
	class CircleButton {
	public:
		CircleButton(int argSize) {
			init(argSize, false);
		}
		
		CircleButton(int argSize, bool argRebound) {
			init(argSize, argRebound);
		}
		
		CircleButton(int argSize, String argStr, Font& argFont) {
			init(argSize, argStr, argFont, false);
		}
		
		CircleButton(int argSize, String argStr, Font& argFont, bool argRebound) {
			init(argSize, argStr, argFont, argRebound);
		}
		
		bool draw(Point argPosition) {
			if (buttonCircle.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			
			if (rebound) {
				if (buttonCircle.leftPressed()) {
					pressed = true;
				}
				if (pressed && buttonCircle.leftReleased()) {
					pressed = false;
				}
			}
			else if (buttonCircle.leftPressed() && !beforeLeftClicked) {
				pressed = !pressed;
			}
			beforeLeftClicked = buttonCircle.leftPressed();
			
			buttonCircle = Circle(argPosition, buttonSize);
			
			if (pressed) {
				buttonCircle.drawShadow(upperShadowPosOffset, blurSize, shadowSize, Color(163, 177, 198)).drawShadow(lowerShadowPosOffset, blurSize, shadowSize, Palette::White).draw(background);
				mat = Mat3x2::Scale(0.9, argPosition);
			}
			else {
				buttonCircle.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, Color(163, 177, 198)).drawShadow(upperShadowPosOffset, blurSize, shadowSize, Palette::White).draw(background);
				mat = Mat3x2::Identity();
			}
			
			{
				// 座標変換行列を適用
				const Transformer2D t(mat, false);
				font(str).drawAt(argPosition, Palette::Gray);
			}
			
			return pressed;
		}
		
		bool leftClicked() {
			return buttonCircle.leftClicked();
		}
		
	private:
		Circle buttonCircle;
		
		int buttonSize;
		String str;
		
		Font font;
		Font smallFont;
		
		bool rebound;
		
		Vec2 upperShadowPosOffset;
		Vec2 lowerShadowPosOffset;
		int blurSize;
		int shadowSize;
		
		Color background;
		Color darkShadow;
		Color lightShadow;
		
		bool pressed;
		bool beforeLeftClicked;
		
		Mat3x2 mat;
		
		void init(int argSize, bool argRebound) {
			buttonSize = argSize;
			
			rebound = argRebound;
			
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			background = Color(224, 229, 236);
			darkShadow = Color(163, 177, 198);
			lightShadow = Color(255, 255, 255);
			
			pressed = false;
			beforeLeftClicked = false;
		}
		
		void init(int argSize, String argStr, Font& argFont, bool argRebound) {
			buttonSize = argSize;
			str = argStr;
			
			font = argFont;
			
			rebound = argRebound;
			
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			background = Color(224, 229, 236);
			darkShadow = Color(163, 177, 198);
			lightShadow = Color(255, 255, 255);
			
			pressed = false;
			beforeLeftClicked = false;
		}
	};

	// スライドスイッチ
	class Switch {
	public:
		Switch(bool argBool, int argPositionX, int argPositionY, int argSizeW, int argSizeH) {
			init(argBool, argPositionX, argPositionY, argSizeW, argSizeH);
		}
		
		Switch(bool argBool, int argPositionX, int argPositionY, Vec2 argSize) {
			init(argBool, argPositionX, argPositionY, argSize.x, argSize.y);
		}
		
		Switch(bool argBool, Vec2 argPosition, int argSizeW, int argSizeH) {
			init(argBool, argPosition.x, argPosition.y, argSizeW, argSizeH);
		}
		
		Switch(bool argBool, Vec2 argPosition, Vec2 argSize) {
			init(argBool, argPosition.x, argPosition.y, argSize.x, argSize.y);
		}
		
		bool draw() {
			switchRect
				.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, darkShadow)
				.drawShadow(upperShadowPosOffset, blurSize, shadowSize, lightShadow)
				.draw(background);
			
			innerSliderRect
				.drawShadow(upperShadowPosOffset, blurSize, shadowSize, darkShadow)
				.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, lightShadow)
				.draw(background);
			
			knobCircle = Circle(position.x+10/2+knobX, position.y+10/2+(size.y-10)/2, (size.y-10/2)/2);
			knobCircle.drawShadow(Vec2{0, 0}, blurSize, shadowSize, darkShadow);
			
			barRect = RoundRect(position.x+10/2, position.y+10/2, knobX, size.y-10, size.y/2);
			barRect.draw(Color(52, 152, 219));
			
			knobCircle.draw(background);
			
			if (knobCircle.mouseOver() || barRect.mouseOver() || innerSliderRect.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			
			if (knobCircle.leftClicked() || barRect.leftClicked() || innerSliderRect.leftClicked()) {
				b = !b;
				sliding = true;
				slidingCount = 0.0;
			}
			
			if (sliding) {
				slidingCount += 0.1;
				if (slidingCount > M_PI/2) {
					sliding = false;
				}
				else {
					if (b) {
						knobX = sin(slidingCount)*(size.x-10);
					}
					else {
						knobX = (size.x-10) - sin(slidingCount)*(size.x-10);
					}
				}
			}
			
			return b;
		}
		
	private:
		bool b;
		bool sliding;
		
		Vec2 upperShadowPosOffset;
		Vec2 lowerShadowPosOffset;
		int blurSize;
		int shadowSize;
		
		Vec2 position;
		Size size;
		
		Color background;
		Color darkShadow;
		Color lightShadow;
		
		RoundRect switchRect;
		RoundRect innerSliderRect;
		RoundRect barRect;
		Circle knobCircle;
		
		int knobX;
		double slidingCount;
		
		void init(bool argBool, int argPositionX, int argPositionY, int argSizeW, int argSizeH) {
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			b = argBool;
			position.x = argPositionX;
			position.y = argPositionY;
			size.x = argSizeW;
			size.y = argSizeH;
			
			background = Color(224, 229, 236);
			darkShadow = Color(163, 177, 198);
			lightShadow = Color(255, 255, 255);
			
			sliding = false;
			knobX = b*(argSizeW-10);
			
			switchRect = RoundRect(position, size, size.y/2);
			innerSliderRect = RoundRect(position.x+10/2, position.y+10/2, size.x-10, size.y-10, (size.y-10)/2);
		}
	};

	// スライダー
	class Slider {
	public:
		Slider(double argRet, int argPositionX, int argPositionY, int argSizeW, int argSizeH) {
			init(argRet, argPositionX, argPositionY, argSizeW, argSizeH);
		}
		
		Slider(double argRet, int argPositionX, int argPositionY, Vec2 argSize) {
			init(argRet, argPositionX, argPositionY, argSize.x, argSize.y);
		}
		
		Slider(double argRet, Vec2 argPosition, int argSizeW, int argSizeH) {
			init(argRet, argPosition.x, argPosition.y, argSizeW, argSizeH);
		}
		
		Slider(double argRet, Vec2 argPosition, Vec2 argSize) {
			init(argRet, argPosition.x, argPosition.y, argSize.x, argSize.y);
		}
		
		double draw() {
			sliderRect
			.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, darkShadow)
			.drawShadow(upperShadowPosOffset, blurSize, shadowSize, lightShadow)
			.draw(background);
			
			innerSliderRect
			.drawShadow(upperShadowPosOffset, blurSize, shadowSize, darkShadow)
			.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, lightShadow)
			.draw(background);
			
			knobCircle = Circle(position.x+10/2+(size.x-10)*value, position.y+10/2+(size.y-10)/2, (size.y-10/2)/2);
			knobCircle.drawShadow(Vec2{0, 0}, blurSize, shadowSize, darkShadow);
			
			barRect = RoundRect(position.x+10/2, position.y+10/2, (size.x-10)*value, size.y-10, size.y/2);
			barRect.draw(Color(52, 152, 219));
			
			knobCircle.draw(background);
			
			if (knobCircle.mouseOver() || barRect.mouseOver() || innerSliderRect.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			
			if (knobCircle.leftPressed() || barRect.leftPressed() || innerSliderRect.leftPressed() || knobClicked) {
				if (knobCircle.leftPressed()) {
					knobClicked = true;
				}
				
				value = (Cursor::Pos().x-position.x-10/2)/(size.x-10);
				
				if (value > 1.0) {
					value = 1.0;
				}
				if (value < 0.0) {
					value = 0.0;
				}
			}
			if (knobClicked && !MouseL.pressed()) {
				knobClicked = false;
			}
			
			return value;
		}
		
	private:
		RoundRect sliderRect;
		RoundRect innerSliderRect;
		RoundRect barRect;
		Circle knobCircle;
		bool knobClicked;
		
		double value;
		
		Vec2 upperShadowPosOffset;
		Vec2 lowerShadowPosOffset;
		int blurSize;
		int shadowSize;
		
		Vec2 position;
		Size size;
		
		Color background;
		Color darkShadow;
		Color lightShadow;
		
		void init(double argRet, int argPositionX, int argPositionY, int argSizeW, int argSizeH) {
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			value = argRet;
			
			position.x = argPositionX;
			position.y = argPositionY;
			size.x = argSizeW;
			size.y = argSizeH;
			
			background = Color(224, 229, 236);
			darkShadow = Color(163, 177, 198);
			lightShadow = Color(255, 255, 255);
			
			sliderRect = RoundRect(argPositionX, argPositionY, argSizeW, argSizeH, argSizeH/2);
			innerSliderRect = RoundRect(argPositionX+10/2, argPositionY+10/2, argSizeW-10, argSizeH-10, (argSizeH-10)/2);
		}
	};
}

#endif /* NeumorphismUI_hpp */
