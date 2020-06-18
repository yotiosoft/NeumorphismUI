//
//  NeumorphismUI.hpp
//  Siv3DNeumorphism
//
//  Created by YotioSoft on 2020/06/16.
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
		RectButton(Size argSize, String argStr, Font& argLargeFont, Font& argSmallFont, bool argRebound) {
			buttonSize = argSize;
			str = argStr;
			
			radius = 10;
			
			rebound = argRebound;
			
			largeFont = argLargeFont;
			smallFont = argSmallFont;
			
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
				smallFont(str).drawAt(argPosition.x+buttonSize.x/2, argPosition.y+buttonSize.y/2, Palette::Gray);
			}
			else {
				buttonRect.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, darkShadow).drawShadow(upperShadowPosOffset, blurSize, shadowSize, lightShadow).draw(background);
				largeFont(str).drawAt(argPosition.x+buttonSize.x/2, argPosition.y+buttonSize.y/2, Palette::Gray);
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
		
		Font largeFont;
		Font smallFont;
		
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
	};
	
	// 円形のボタン
	class CircleButton {
	public:
		CircleButton(int argSize, String argStr, Font& argLargeFont, Font& argSmallFont, bool argRebound) {
			buttonSize = argSize;
			str = argStr;
			
			largeFont = argLargeFont;
			smallFont = argSmallFont;
			
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
				smallFont(str).drawAt(argPosition, Palette::Gray);
			}
			else {
				buttonCircle.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, Color(163, 177, 198)).drawShadow(upperShadowPosOffset, blurSize, shadowSize, Palette::White).draw(background);
				largeFont(str).drawAt(argPosition, Palette::Gray);
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
		
		Font largeFont;
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
	};

	// スライドスイッチ
	class Switch {
	public:
		Switch(bool argBool, Vec2 argPosition, int argSizeW, int argSizeH) {
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			b = argBool;
			position = argPosition;
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
	};

	// スライダー
	class Slider {
	public:
		Slider(double argRet, Vec2 argPosition, int argSizeW, int argSizeH) {
			upperShadowPosOffset = {-4, -4};
			lowerShadowPosOffset = {4, 4};
			blurSize = 16;
			shadowSize = 2;
			
			value = argRet;
			
			position = argPosition;
			size.x = argSizeW;
			size.y = argSizeH;
			
			background = Color(224, 229, 236);
			darkShadow = Color(163, 177, 198);
			lightShadow = Color(255, 255, 255);
			
			sliderRect = RoundRect(argPosition, argSizeW, argSizeH, argSizeH/2);
			innerSliderRect = RoundRect(argPosition.x+10/2, argPosition.y+10/2, argSizeW-10, argSizeH-10, (argSizeH-10)/2);
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
	};
}

#endif /* NeumorphismUI_hpp */
