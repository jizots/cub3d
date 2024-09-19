# About this project
レイキャストを利用して3D空間を表現しました。  
これによって画像をどのように拡大縮小するか、効率的な障害物（壁）の位置の把握方法を学ぶことができます。  

# Example
https://github.com/user-attachments/assets/f1ee178a-57df-46df-affb-85c4d70a95b0  
プログラムを起動すると、3D空間の散策ができます。  

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

## マップを自作して試してみる
```
```

## Wall paperを変更してみる


# Learning
- Depth-first Search: 深さ優先探索による、マップの検証
- ブレゼンハムのアルゴリズム: 壁の位置の把握
- ライブラリの自作：minilibxを利用しやすくするための追加のライブラリ
