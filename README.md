# About this project
レイキャストを利用して3D空間を表現しました。  
プログラムを起動すると、3D空間の散策ができます。  

# Example
![Untitled](https://github.com/user-attachments/assets/137971a5-dbfc-4873-a754-f9226e3e2dd6)
  

# 機能
- Mapを自由に作成して散策
- Wall Paperの変更  

# Build
以下のコマンドで実行プログラム（cub3D）が作成されます。  
```
make
```

# Usage
## すでにある準備してあるマップと壁紙で試してみる
実行ファイルの引数に、Mapへのパスを含めてください
```example
./cub3D map/0.cub
```
WASDキー：前後左右の移動  
左右キー：視点の左右への移動

## マップを自作して試してみる
```
comming soon
```

## Wall paperを変更してみる
```
comming soon
```

# Learning
- Depth-first Search: 深さ優先探索による、マップの検証
- ブレゼンハムのアルゴリズム: 壁の位置の把握
- ライブラリの自作：minilibxを利用しやすくするための追加のライブラリ
- 画像の拡大縮小: 対象物との距離によって画像のどのピクセルを表示するか選択
たい
