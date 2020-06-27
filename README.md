# NeumorphismUI

## 概要
<img width="805" alt="スクリーンショット 2020-06-27 23 35 45" src="https://user-images.githubusercontent.com/10475696/85924897-26177000-b8d0-11ea-8d41-8257aeabced9.png">
  
ニューモーフィズムなボタンやスライダなどをOpenSiv3D上で再現するプログラムです。  
※サンプルは一番下にあります

## 使い方
```
#include "NeumorphismUI.hpp"
```
でヘッダファイルをincludeしてお使いください。  
  
### ボタン/スイッチ
ボタンは押したらON（true）に、もう一度押すとOFF（false）になります。  
スイッチは押した瞬間にtrueを返します。  

#### 角丸長方形スイッチ
<img width="125" alt="スクリーンショット 2020-06-27 20 54 49" src="https://user-images.githubusercontent.com/10475696/85921644-7edb0e80-b8b8-11ea-8e77-a95af8a2ac5a.png">
  
角丸長方形のスイッチです。  
**押したらONに、もう一度押すとOFFになります。**  
  
##### 書式
```
void NeumorphismUI::RectSwitch(
	Vec2 argPosition,
	Vec2 argSize,
	bool& argVar,
	String argStr, Font& argFont,
	Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
	Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
	int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
	Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4}
)
```
指定必須な引数は第1引数（argPosition）から第5引数（argFont）までです。  
第6引数以降は指定することも可能ですが、未指定でも動作します。  
|引数名|型|概要|初期値|  
|--------|--|-----|--------|  
|**argPosition**|Vec2(Point)|描画する座標（左上） int型変数2つでも指定可能|  
|**argSize**|Vec2(Size)|サイズ {横, 縦}  int型変数2つでも指定可能|  
|**argVar**|bool&|戻り値を格納するBool型変数（参照渡し）|  
|**argStr**|String|スイッチに表示する文字列|  
|**argFont**|Font&|文字列の表示に用いるフォント|  
|argBackgroundColor|Color|背景色およびボタンの色|Color(224, 229, 236)|  
|argDarkColor|Color|影の色|Color(163, 177, 198)|  
|argLightColor|Color|光があたった部分の色|Color(255, 255, 255)|  
|argFontColot|Color|フォントの色（常時）|Palette::Gray|  
|argPushedFontColor|Color|フォントの色（スイッチ押下時）|Palette::Gray|  
|argRadius|int|角を丸める大きさ|10|  
|argBlurSize|int|影のブラーの大きさ|16|  
|argShadowSize|int|影の大きさ|2|  
|argUpperShadowPosOffset|Vec2|左上の光があたった部分/影の部分の相対描画位置|{-4, -4}|  
|argLowerShadowPosOffset|Vec2|右下の光があたった部分/影の部分の相対描画位置|{4, 4}|  
  
第５引数に指定した変数（bool型）に値が返されます。  
ONのときtrue、OFFのときfalseです。 

#### 角丸長方形ボタン
<img width="125" alt="スクリーンショット 2020-06-27 20 54 49" src="https://user-images.githubusercontent.com/10475696/85921644-7edb0e80-b8b8-11ea-8e77-a95af8a2ac5a.png">
  
角丸長方形のスイッチです。  
**押した瞬間にtrueを返します。**  

##### 書式
```
bool NeumorphismUI::RectSwitch(
	Vec2 argPosition,
	Vec2 argSize,
	String argStr, Font& argFont,
	Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, 	Color argLightColor = DEFAULT_LIGHT_COLOR,
	Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
	int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
	Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4}
)
```
指定必須な引数は第1引数（argPosition）から第4引数（argFont）までです。  
第5引数以降は指定することも可能ですが、未指定でも動作します。  
|引数名|型|概要|初期値|  
|--------|--|-----|--------|  
|**argPosition**|Vec2(Point)|描画する座標（左上） int型変数2つでも指定可能|  
|**argSize**|Vec2(Size)|サイズ {横, 縦}  int型変数2つでも指定可能|  
|**argStr**|String|スイッチに表示する文字列|  
|**argFont**|Font&|文字列の表示に用いるフォント|  
|argBackgroundColor|Color|背景色およびボタンの色|Color(224, 229, 236)|  
|argDarkColor|Color|影の色|Color(163, 177, 198)|  
|argLightColor|Color|光があたった部分の色|Color(255, 255, 255)|  
|argFontColot|Color|フォントの色（常時）|Palette::Gray|  
|argPushedFontColor|Color|フォントの色（スイッチ押下時）|Palette::Gray|  
|argRadius|int|角を丸める大きさ|10|  
|argBlurSize|int|影のブラーの大きさ|16|  
|argShadowSize|int|影の大きさ|2|  
|argUpperShadowPosOffset|Vec2|左上の光があたった部分/影の部分の相対描画位置|{-4, -4}|  
|argLowerShadowPosOffset|Vec2|右下の光があたった部分/影の部分の相対描画位置|{4, 4}|  
  
ボタンが押下されたときに戻り値がtrueになります。  

#### 丸形スイッチ
<img width="135" alt="スクリーンショット 2020-06-27 20 51 51" src="https://user-images.githubusercontent.com/10475696/85921578-1429d300-b8b8-11ea-9950-940d8c8fe7b3.png">
  
丸形のスイッチです。  
押したらONに、もう一度押すとOFFになります。  
  
##### 書式
  ```
  void NeumorphismUI::CircleSwitch(
	  Vec2 argPosition,
	  int argSize,
	  bool& argVar,
	  String argStr, Font& argFont,
	  Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
	  Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
	  int argBlurSize = 16, int argShadowSize = 2,
	  Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4}
  )
  ```
  指定必須な引数は第1引数（argPosition）から第5引数（argFont）までです。  
  第6引数以降は指定することも可能ですが、未指定でも動作します。  
  円形の場合は角丸長方形と違い、座標は中心座標、サイズは円の半径となりますので注意してください。  
  |引数名|型|概要|初期値|  
  |--------|--|-----|--------|  
  |**argPosition**|Vec2(Point)|描画する座標 **（円の中心座標）**  int型変数2つでも指定可能|  
  |**argSize**|int|サイズ **（半径）**|  
  |**argVar**|bool&|戻り値を格納するBool型変数（参照渡し）|  
  |**argStr**|String|スイッチに表示する文字列|  
  |**argFont**|Font&|文字列の表示に用いるフォント|  
  |argBackgroundColor|Color|背景色およびボタンの色|Color(224, 229, 236)|  
  |argDarkColor|Color|影の色|Color(163, 177, 198)|  
  |argLightColor|Color|光があたった部分の色|Color(255, 255, 255)|  
  |argFontColot|Color|フォントの色（常時）|Palette::Gray|  
  |argPushedFontColor|Color|フォントの色（スイッチ押下時）|Palette::Gray|  
  |argBlurSize|int|影のブラーの大きさ|16|  
  |argShadowSize|int|影の大きさ|2|  
  |argUpperShadowPosOffset|Vec2|左上の光があたった部分/影の部分の相対描画位置|{-4, -4}|  
  |argLowerShadowPosOffset|Vec2|右下の光があたった部分/影の部分の相対描画位置|{4, 4}|  
  
第５引数に指定した変数（bool型）に値が返されます。  
ONのときtrue、OFFのときfalseです。  

##### 丸型ボタン
<img width="135" alt="スクリーンショット 2020-06-27 20 51 51" src="https://user-images.githubusercontent.com/10475696/85921578-1429d300-b8b8-11ea-9950-940d8c8fe7b3.png">
  
丸形のスイッチです。  
押したらONに、もう一度押すとOFFになります。  
  
##### 書式
  ```
  bool NeumorphismUI::CircleButton(
	  Vec2 argPosition,
	  int argSize,
	  String argStr, Font& argFont,
	  Color argBackgroundColor = DEFAULT_BACKGROUND_COLOR, Color argDarkColor = DEFAULT_SHADOW_COLOR, Color argLightColor = DEFAULT_LIGHT_COLOR,
	  Color argFontColor = Palette::Gray, Color argPushedFontColor = Palette::Gray,
	  int argBlurSize = 16, int argShadowSize = 2,
	  Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4}
  )
  ```
  指定必須な引数は第1引数（argPosition）から第4引数（argFont）までです。  
  第5引数以降は指定することも可能ですが、未指定でも動作します。  
  円形の場合は角丸長方形と違い、座標は中心座標、サイズは円の半径となりますので注意してください。  
  |引数名|型|概要|初期値|  
  |--------|--|-----|--------|  
  |**argPosition**|Vec2(Point)|描画する座標 **（円の中心座標）**  int型変数2つでも指定可能|  
  |**argSize**|int|サイズ **（半径）**|  
  |**argStr**|String|スイッチに表示する文字列|  
  |**argFont**|Font&|文字列の表示に用いるフォント|  
  |argBackgroundColor|Color|背景色およびボタンの色|Color(224, 229, 236)|  
  |argDarkColor|Color|影の色|Color(163, 177, 198)|  
  |argLightColor|Color|光があたった部分の色|Color(255, 255, 255)|  
  |argFontColot|Color|フォントの色（常時）|Palette::Gray|  
  |argPushedFontColor|Color|フォントの色（スイッチ押下時）|Palette::Gray|  
  |argBlurSize|int|影のブラーの大きさ|16|  
  |argShadowSize|int|影の大きさ|2|  
  |argUpperShadowPosOffset|Vec2|左上の光があたった部分/影の部分の相対描画位置|{-4, -4}|  
  |argLowerShadowPosOffset|Vec2|右下の光があたった部分/影の部分の相対描画位置|{4, 4}|  
  
ボタンが押下されたときに戻り値がtrueになります。

### スライドスイッチ
<img width="90" alt="スクリーンショット 2020-06-27 23 42 41" src="https://user-images.githubusercontent.com/10475696/85924861-efd9f080-b8cf-11ea-97c0-d2d6d4ec684a.png">
  
スライド式のスイッチです。  
角丸長方形や丸型のボタン/スイッチとは異なり、オブジェクトとなっていますので、  
使用の際には予め宣言が必要です。  
  
##### 書式
```
SlideSwitch(bool argVar, Vec2 argPosition, Vec2 argSize)
```
|引数名|型|概要|  
 |--------|--|-----| 
 |**argVar**|bool|初期値（ONかOFFか）|  
 |**argPosition**|Vec2(Point)|描画する座標  int型変数2つでも指定可能|  
 |**argSize**|Vec2(Size)|サイズ  int型変数2つでも指定可能|  
 
 ##### 描画と値の取得方法
 例：
 ```
 #include <Siv3D.hpp> // OpenSiv3D v0.4.3
 #include "NeumorphismUI.hpp"

 void Main() {
	 Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	 
	 Font font24(24);
	 
	 bool var = true;		// 初期値
	 NeumorphismUI::SlideSwitch slideSwitch(var, Vec2{Scene::Width()/2-60, Scene::Height()/2-15}, Vec2{50, 30});
	 
	 while (System::Update()) {
		 if (slideSwitch.draw()) {
			 font24(U"ON").draw(Scene::Width()/2+10, Scene::Height()/2-15, Palette::Black);
		 }
		 else {
			 font24(U"OFF").draw(Scene::Width()/2+10, Scene::Height()/2-15, Palette::Black);
		 }
	 }
 }
```
draw関数で描画を行います。draw関数は現在のスイッチの値をbool型で返します。  

### スライダー
<img width="228" alt="スクリーンショット 2020-06-27 23 42 46" src="https://user-images.githubusercontent.com/10475696/85924869-fc5e4900-b8cf-11ea-980c-82e9df22aa04.png">
  
0.0〜1.0の実数値を返します。  
こちらも角丸長方形や丸型のボタン/スイッチとは異なり、オブジェクトとなっていますので、  
使用の際には予め宣言が必要です。  

### 書式
```
Slider(double argVar, Vec2 argPosition, Vec2 argSize)
```
|引数名|型|概要|  
|--------|--|-----| 
|**argVar**|double|初期値（0.0〜1.0）|  
|**argPosition**|Vec2 (Point)|描画する座標  int型変数2つでも指定可能|  
|**argSize**|Vec2(Size)|サイズ  int型変数2つでも指定可能|  

##### 描画と値の取得方法
例：
```
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	
	Font font24(24);
	double var = 0.5;	// 初期値
	NeumorphismUI::Slider slider(var, Vec2{Scene::Width()/2-210, Scene::Height()/2-15}, Vec2{200, 30});
	
	while (System::Update()) {
		var = slider.draw();
		font24(U"{:.2f}"_fmt(var)).draw(Scene::Width()/2+100, Scene::Height()/2-15, Palette::Black);
    }
}
```
draw関数で描画を行います。draw関数は現在のスライダーの値をdouble型で返します。  

## サンプル
```
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
```
<img width="802" alt="スクリーンショット 2020-06-27 23 35 57" src="https://user-images.githubusercontent.com/10475696/85924752-22371e00-b8cf-11ea-8943-baf048554357.png">
  
