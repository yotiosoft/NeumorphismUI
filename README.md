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
  
使用例：
```
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "NeumorphismUI.hpp"

void Main() {
	Scene::SetBackground(DEFAULT_BACKGROUND_COLOR);
	
	Font font24(24);
	
	bool rectButtonPushed = true;
	
	while (System::Update()) {
		NeumorphismUI::RectSwitch(Point(100, 100), Size(100, 100), U"Push", font24, rectButtonPushed);
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
この場合、メンバ関数leftClicked()で押されたかどうかが判定できます。  
leftClicked()は、押しっぱなしにした場合も、ボタンがクリックされた瞬間だけtrueを返します。  

