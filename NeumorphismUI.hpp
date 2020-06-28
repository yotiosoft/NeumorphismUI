//
//  	  NeumorphismUI
//
//  		ver.0.1.0
//

#ifndef NeumorphismUI_hpp
#define NeumorphismUI_hpp

#include <stdio.h>
#include <cmath>
#include <Siv3D.hpp>

#define DEFAULT_BACKGROUND_COLOR	Color(224, 229, 236)
#define DEFAULT_SHADOW_COLOR		Color(163, 177, 198)
#define DEFAULT_LIGHT_COLOR			Color(255, 255, 255)

namespace NeumorphismUI {
	// 角丸長方形スイッチ
	void RectSwitch(int argPositionX, int argPositionY,
					int argSizeX, int argSizeY,
					bool& argVar,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		
		Mat3x2 mat;
		
		RoundRect switchRect(argPositionX, argPositionY, argSizeX, argSizeY, argRadius);
		
		// マウスオーバー時にマウスポインタを変更
		if (switchRect.mouseOver()) {
			Cursor::RequestStyle(CursorStyle::Hand);
		}
		// クリックされたら状態を切り替え
		bool isClicked = switchRect.leftClicked();
		if (isClicked) {
			argVar = !argVar;
		}
		
		// ONの時の表示
		if (argVar) {
			switchRect.drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Scale(0.9, Point(argPositionX+argSizeX/2, argPositionY+argSizeY/2));
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX+argSizeX/2, argPositionY+argSizeY/2, argPushedFontColor);
				}
			}
		}
		// OFFの時の表示
		else {
			switchRect.drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Identity();
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX+argSizeX/2, argPositionY+argSizeY/2, argFontColor);
				}
			}
		}
	}

	void RectSwitch(Vec2 argPosition,
					int argSizeX, int argSizeY,
					bool& argVar,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		RectSwitch(argPosition.x, argPosition.y, argSizeX, argSizeY, argVar, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argRadius, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	void RectSwitch(int argPositionX, int argPositionY,
					Vec2 argSize,
					bool& argVar,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		RectSwitch(argPositionX, argPositionY, argSize.x, argSize.y, argVar, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argRadius, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	void RectSwitch(Vec2 argPosition,
					Vec2 argSize,
					bool& argVar,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		RectSwitch(argPosition.x, argPosition.y, argSize.x, argSize.y, argVar, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argRadius, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	// 角丸長方形ボタン
	int RectButton(int argPositionX, int argPositionY,
					int argSizeX, int argSizeY,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		
		Mat3x2 mat;
		
		RoundRect buttonRect(argPositionX, argPositionY, argSizeX, argSizeY, argRadius);
		
		// マウスオーバー時にマウスポインタを変更
		if (buttonRect.mouseOver()) {
			Cursor::RequestStyle(CursorStyle::Hand);
		}
		bool clicked = buttonRect.leftClicked();
		
		// 押下時の表示
		if (buttonRect.leftPressed()) {
			buttonRect.drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Scale(0.9, Point(argPositionX+argSizeX/2, argPositionY+argSizeY/2));
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX+argSizeX/2, argPositionY+argSizeY/2, argPushedFontColor);
				}
			}
		}
		// 押下時以外の表示
		else {
			buttonRect.drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Identity();
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX+argSizeX/2, argPositionY+argSizeY/2, argFontColor);
				}
			}
		}
		
		return clicked;
	}

	int RectButton(Vec2 argPosition,
					int argSizeX, int argSizeY,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		return RectButton(argPosition.x, argPosition.y, argSizeX, argSizeY, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argRadius, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	int RectButton(int argPositionX, int argPositionY,
					Vec2 argSize,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		return RectButton(argPositionX, argPositionY, argSize.x, argSize.y, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argRadius, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	int RectButton(Vec2 argPosition,
					Vec2 argSize,
					String argStr, Font& argFont,
					Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
					Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		return RectButton(argPosition.x, argPosition.y, argSize.x, argSize.y, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argRadius, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	// 丸型スイッチ
	void CircleSwitch(int argPositionX, int argPositionY,
					  int argSize,
					  bool& argVar,
					  String argStr, Font& argFont,
					  Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					  Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					  int argBlurSize = 16, int argShadowSize = 2,
					  Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		
		Mat3x2 mat;
		
		Circle switchCircle(argPositionX, argPositionY, argSize);
		
		// マウスオーバー時にマウスポインタを変更
		if (switchCircle.mouseOver()) {
			Cursor::RequestStyle(CursorStyle::Hand);
		}
		// クリックされたら状態を切り替え
		bool isClicked = switchCircle.leftClicked();
		if (isClicked) {
			argVar = !argVar;
		}
		
		// ONの時の表示
		if (argVar) {
			switchCircle.drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Scale(0.9, Point(argPositionX, argPositionY));
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX, argPositionY, argPushedFontColor);
				}
			}
		}
		// OFFの時の表示
		else {
			switchCircle.drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Identity();
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX, argPositionY, argFontColor);
				}
			}
		}
	}

	void CircleSwitch(Vec2 argPosition,
					  int argSize,
					  bool& argVar,
					  String argStr, Font& argFont,
					  Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					  Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					  int argBlurSize = 16, int argShadowSize = 2,
					  Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		CircleSwitch(argPosition.x, argPosition.y, argSize, argVar, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	// 丸型ボタン
	int CircleButton(int argPositionX, int argPositionY,
					 int argSize,
					 String argStr, Font& argFont,
					 Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					 Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					 int argBlurSize = 16, int argShadowSize = 2,
					 Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		
		Mat3x2 mat;
		
		Circle buttonCircle(argPositionX, argPositionY, argSize);
		
		// マウスオーバー時にマウスポインタを変更
		if (buttonCircle.mouseOver()) {
			Cursor::RequestStyle(CursorStyle::Hand);
		}
		bool clicked = buttonCircle.leftClicked();
		
		// 押下時の表示
		if (buttonCircle.leftPressed()) {
			buttonCircle.drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Scale(0.9, Point(argPositionX, argPositionY));
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX, argPositionY, argPushedFontColor);
				}
			}
		}
		// 押下時以外の表示
		else {
			buttonCircle.drawShadow(argLowerShadowPosOffset, argBlurSize, argShadowSize, argDarkColor).drawShadow(argUpperShadowPosOffset, argBlurSize, argShadowSize, argLightColor).draw(argBackgroundColor);
			mat = Mat3x2::Identity();
			
			if (!argFont.isEmpty()) {
				{
					// 座標変換行列を適用
					const Transformer2D t(mat, false);
					argFont(argStr).drawAt(argPositionX, argPositionY, argFontColor);
				}
			}
		}
		
		return clicked;
	}

	int CircleButton(Vec2 argPosition,
					 int argSize,
					 String argStr, Font& argFont,
					 Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
					 Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
					 int argBlurSize = 16, int argShadowSize = 2,
					 Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4})
	{
		return CircleButton(argPosition.x, argPosition.y, argSize, argStr, argFont, argBackgroundColor, argDarkColor, argLightColor, argFontColor, argPushedFontColor, argBlurSize, argShadowSize, argUpperShadowPosOffset, argLowerShadowPosOffset);
	}

	// スライドスイッチ
	class SlideSwitch {
	public:
		SlideSwitch(bool argVar, int argPositionX, int argPositionY, int argSizeW, int argSizeH) {
			init(argVar, argPositionX, argPositionY, argSizeW, argSizeH);
		}
		
		SlideSwitch(bool argVar, int argPositionX, int argPositionY, Vec2 argSize) {
			init(argVar, argPositionX, argPositionY, argSize.x, argSize.y);
		}
		
		SlideSwitch(bool argVar, Vec2 argPosition, int argSizeW, int argSizeH) {
			init(argVar, argPosition.x, argPosition.y, argSizeW, argSizeH);
		}
		
		SlideSwitch(bool argVar, Vec2 argPosition, Vec2 argSize) {
			init(argVar, argPosition.x, argPosition.y, argSize.x, argSize.y);
		}
		
		bool draw() {
			switchRect
				.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, darkShadow)
				.drawShadow(upperShadowPosOffset, blurSize, shadowSize, lightShadow)
				.draw(background);		// スイッチの外枠
			
			innerSliderRect
				.drawShadow(upperShadowPosOffset, blurSize, shadowSize, darkShadow)
				.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, lightShadow)
				.draw(background);		// スイッチの内枠
			
			knobCircle = Circle(position.x+10/2+knobX, position.y+10/2+(size.y-10)/2, (size.y-10/2)/2);
			knobCircle.drawShadow(Vec2{0, 0}, blurSize, shadowSize, darkShadow);
			
			barRect = RoundRect(position.x+10/2, position.y+10/2, knobX, size.y-10, size.y/2);
			barRect.draw(Color(52, 152, 219));
			
			knobCircle.draw(background);
			
			// マウスオーバー時にマウスポインタを変更
			if (knobCircle.mouseOver() || barRect.mouseOver() || innerSliderRect.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			// 押されたら状態変更
			if (knobCircle.leftClicked() || barRect.leftClicked() || innerSliderRect.leftClicked()) {
				b = !b;
				sliding = true;
				slidingCount = 0.0;
			}
			
			// スライド中の動作
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
		
		// コンストラクタから呼び出す
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
		Slider(double argVar, int argPositionX, int argPositionY, int argSizeW, int argSizeH) {
			init(argVar, argPositionX, argPositionY, argSizeW, argSizeH);
		}
		
		Slider(double argVar, int argPositionX, int argPositionY, Vec2 argSize) {
			init(argVar, argPositionX, argPositionY, argSize.x, argSize.y);
		}
		
		Slider(double argVar, Vec2 argPosition, int argSizeW, int argSizeH) {
			init(argVar, argPosition.x, argPosition.y, argSizeW, argSizeH);
		}
		
		Slider(double argVar, Vec2 argPosition, Vec2 argSize) {
			init(argVar, argPosition.x, argPosition.y, argSize.x, argSize.y);
		}
		
		double draw() {
			sliderRect
			.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, darkShadow)
			.drawShadow(upperShadowPosOffset, blurSize, shadowSize, lightShadow)
			.draw(background);	// スイッチの外枠
			
			innerSliderRect
			.drawShadow(upperShadowPosOffset, blurSize, shadowSize, darkShadow)
			.drawShadow(lowerShadowPosOffset, blurSize, shadowSize, lightShadow)
			.draw(background);	// スイッチの内枠
			
			knobCircle = Circle(position.x+10/2+knobX, position.y+10/2+(size.y-10)/2, (size.y-10/2)/2);
			knobCircle.drawShadow(Vec2{0, 0}, blurSize, shadowSize, darkShadow);
			
			barRect = RoundRect(position.x+10/2, position.y+10/2, knobX, size.y-10, size.y/2);
			barRect.draw(Color(52, 152, 219));
			
			knobCircle.draw(background);
			
			// マウスオーバー時にマウスポインタを変更
			if (knobCircle.mouseOver() || barRect.mouseOver() || innerSliderRect.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			
			// クリックされたら状態変更
			if (knobCircle.leftPressed() || barRect.leftPressed() || innerSliderRect.leftPressed() || knobClicked) {
				if (knobCircle.leftPressed()) {
					knobClicked = true;
				}
				
				// マウスがクリックされっぱなしのときにスライドし続ける
				if (barRect.leftPressed() || innerSliderRect.leftPressed()) {
					beforeX = knobX;
					clickedX = Cursor::Pos().x-position.x+10/2;
					sliding = true;
					slidingCount = 0.0;
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
			
			// スライド中の動作
			if (sliding) {
				slidingCount += 0.2;
				if (slidingCount > M_PI/2) {
					slidingCount = 0;
					sliding = false;
				}
				else {
					if (beforeX > clickedX) {
						knobX = beforeX - sin(slidingCount)*(beforeX-clickedX+(size.y-10)/2);
					}
					else {
						knobX = beforeX + sin(slidingCount)*(clickedX-beforeX-(size.y-10)/2);
					}
				}
			}
			if (knobClicked) {
				knobX = value*(size.x-10);
			}
			
			return value;
		}
		
	private:
		RoundRect sliderRect;
		RoundRect innerSliderRect;
		RoundRect barRect;
		Circle knobCircle;
		
		bool knobClicked;
		bool sliding;
		
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
		
		int knobX;
		int clickedX;
		int beforeX;
		double slidingCount;
		
		// コンストラクタから呼び出す
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
			
			knobClicked = false;
			sliding = false;
			knobX = (size.x-10)*value;
		}
	};
}

#endif /* NeumorphismUI_hpp */
