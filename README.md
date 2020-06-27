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
|引数名|型|概要|  
|--------|--|-----|  
|**argPosition**|Vec2|描画する座標（左上）|  
|**argSize**|Vec2|サイズ {横, 縦}|  
|**argVar**bool&|戻り値を格納するBool型変数（参照渡し）|  
|**argStr**|String|スイッチに表示する文字列|  
|**argFont**|Font&|文字列の表示に用いるフォント|  
|argBackgroundColor|Color|背景色およびボタンの色|  
|argDarkColor|Color|影の色|  
|argLightColor|Color|光があたった部分の色|  
|argFontColot|Color|フォントの色（常時）|  
|argPushedFontColor|Color|フォントの色（スイッチ押下時）|  
|argRadius|int|角を丸める大きさ|  
|argBlurSize|int|影のブラーの大きさ|  
|argShadowSize|int|影の大きさ|  
|argUpperShadowPosOffset|Vec2|左上の光があたった部分/影の部分の相対描画位置|  
|argLowerShadowPosOffset|Vec2|右下の光があたった部分/影の部分の相対描画位置|  
  
##### 使用例
```
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	
	Font font24(24);
	
	bool rectButtonPushed = true;
	
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
	  int argRadius = 10, int argBlurSize = 16, int argShadowSize = 2,
	  Vec2 argUpperShadowPosOffset = {-4, -4}, Vec2 argLowerShadowPosOffset = {4, 4}
  )
  ```
  指定必須な引数は第1引数（argPosition）から第5引数（argFont）までです。  
  第6引数以降は指定することも可能ですが、未指定でも動作します。  
  円形の場合は角丸長方形と違い、座標は中心座標、サイズは円の半径となりますので注意してください。  
  |引数名|型|概要|  
  |--------|--|-----|  
  |**argPosition**|Vec2|描画する座標 **（円の中心座標）**|  
  |**argSize**|int|サイズ **（半径）**|  
  |**argVar**bool&|戻り値を格納するBool型変数（参照渡し）|  
  |**argStr**|String|スイッチに表示する文字列|  
  |**argFont**|Font&|文字列の表示に用いるフォント|  
  |argBackgroundColor|Color|背景色およびボタンの色|  
  |argDarkColor|Color|影の色|  
  |argLightColor|Color|光があたった部分の色|  
  |argFontColot|Color|フォントの色（常時）|  
  |argPushedFontColor|Color|フォントの色（スイッチ押下時）|  
  |argRadius|int|角を丸める大きさ|  
  |argBlurSize|int|影のブラーの大きさ|  
  |argShadowSize|int|影の大きさ|  
  |argUpperShadowPosOffset|Vec2|左上の光があたった部分/影の部分の相対描画位置|  
  |argLowerShadowPosOffset|Vec2|右下の光があたった部分/影の部分の相対描画位置|  
  
##### 使用例
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
