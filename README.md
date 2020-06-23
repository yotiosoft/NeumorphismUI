# NeumorphismUI
OpenSiv3Dでニューモーフィズム！

## 概要
ニューモーフィズムなボタンやスライダなどをOpenSiv3D上で提供するプログラムです。

## 使い方
```
#include "NeumorphismUI.hpp"
```
でヘッダファイルをincludeしてお使いください。  
  
### ボタン
#### 角丸長方形ボタン
角丸長方形のボタンです。  
  
使用例：
```
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(Color(224, 229, 236));
	
	double d = 0.5;
	int count = 0;
	
	Font font24(24);
	NeumorphismUI::RectButton rectButton(Vec2(100, 100), U"Push", font24, false);
	
	while (System::Update()) {
		if (rectButton.draw(Point(100, 100))) {
			font24(U"ON").draw(250, 130, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 130, Palette::Black);
		}
	}
}
```
押すとON、もう一度押すとOFFになります。  
draw関数は、ボタンが押されている間はtrueを返します。
  
  
押したら戻るボタンを設置したい場合は、第4引数をtrueにしてください。
```
NeumorphismUI::RectButton rectButton(Vec2(100, 100), U"Push", font24, true);
```
この場合、メンバ関数leftClicked()で押されたかどうかが判定できます。  
leftClicked()は、押しっぱなしにした場合も、ボタンがクリックされた瞬間だけtrueを返します。  
  
使用例：
```
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(Color(224, 229, 236));
	
	int count = 0;
	
	Font font24(24);
	NeumorphismUI::RectButton 	countButton(Size(200, 50), U"Count", font24, true);
	
	while (System::Update()) {
		countButton.draw(Point(100, 100));
		if (countButton.leftClicked()) {
			count ++;
		}
		font24(count).draw(350, 100, Palette::Black);
	}
}
```

#### 丸型ボタン
丸形のボタンです。  
  
使用例：
```
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(Color(224, 229, 236));
	
	Font font24(24);
	NeumorphismUI::CircleButton circleButton(50, U"Push", font24, false);
	
	while (System::Update()) {
		if (circleButton.draw(Point(150, 150))) {
			font24(U"ON").draw(250, 130, Palette::Black);
		}
		else {
			font24(U"OFF").draw(250, 130, Palette::Black);
		}
    }
}
```
ここで、座標は角丸長方形ボタンとは違い、**円の中心座標を指定する**ということに注意してください。  
  
押したら戻るボタンを設置したい場合は、第4引数をtrueにしてください。
```
NeumorphismUI::CircleButton circleButton(50, U"Push", font24, true);
```
```
この場合、メンバ関数leftClicked()で押されたかどうかが判定できます。  
leftClicked()は、押しっぱなしにした場合も、ボタンがクリックされた瞬間だけtrueを返します。  

