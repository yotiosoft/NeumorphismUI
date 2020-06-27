# NeumorphismUI

## 概要
ニューモーフィズムなボタンやスライダなどをOpenSiv3D上で再現するプログラムです。

## 使い方
```
#include "NeumorphismUI.hpp"
```
でヘッダファイルをincludeしてお使いください。  
  
### スイッチ
#### 角丸長方形スイッチ
<img width="125" alt="スクリーンショット 2020-06-27 20 54 49" src="https://user-images.githubusercontent.com/10475696/85921644-7edb0e80-b8b8-11ea-8e77-a95af8a2ac5a.png">
  
角丸長方形のスイッチです。  
押したらONに、もう一度押すとOFFになります。  
  
##### 引数
```
NeumorphismUI::RectSwitch(
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
|**argPosition**|Vec2|描画する座標（左上）|  
|**argSize**|Vec2|サイズ {横, 縦}|  
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
  
##### 使用例
<img width="802" alt="スクリーンショット 2020-06-27 20 54 43" src="https://user-images.githubusercontent.com/10475696/85921650-8995a380-b8b8-11ea-85cc-8fd0c702cd41.png">
  
```
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	
	Font font24(24);
	
	bool rectButtonPushed = false;
	
	while (System::Update()) {
		NeumorphismUI::RectSwitch(Point(100, 100), Size(100, 100), rectButtonPushed, U"Push", font24);
		if (rectButtonPushed) {
			font24(U"ON").draw(250, 130, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 130, Palette::Black);
		}
	}
}

```
第５引数に指定した変数（bool型）に値が返されます。  
ONのときtrue、OFFのときfalseです。  

#### 丸形スイッチ
<img width="135" alt="スクリーンショット 2020-06-27 20 51 51" src="https://user-images.githubusercontent.com/10475696/85921578-1429d300-b8b8-11ea-9950-940d8c8fe7b3.png">
  
丸形のスイッチです。  
押したらONに、もう一度押すとOFFになります。  
  
##### 引数
  ```
  NeumorphismUI::CircleSwitch(
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
  |**argPosition**|Vec2|描画する座標 **（円の中心座標）**|  
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
  
##### 使用例
<img width="803" alt="スクリーンショット 2020-06-27 20 51 45" src="https://user-images.githubusercontent.com/10475696/85921577-12f8a600-b8b8-11ea-93c4-9a47e1422d03.png">  

```
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

```
第５引数に指定した変数（bool型）に値が返されます。  
ONのときtrue、OFFのときfalseです。  
