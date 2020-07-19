# 課題4 レポート

bb35319033 濱江堅登

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
ID,gender,heightのデータを配列を用いて格納し、構造体で管理する。
それぞれのデータの格納が終了したら、ファイルをクローズする。
入力したIDと、構造体で管理しているIDが一致したときに対応する性別と身長を表示したいので、
一つ目のifの条件をIDに関するものとし、さらに入れ子でgenderに関するif文ブロックを作成した。
入力されたIDが、１４個のデータに存在しない場合に"No data"と表示したいので、最後のelse文の中でk++とし、
IDが一致しないたびにkをカウントすることで、最後のif文でk==13を条件にすることにより、No　dataの場合は考慮した。

## 入出力結果

・例えば，ID 45318088のデータを調べたいとき，

input the filename1 of sample:c:\Users\kento\Documents\2020psp2\sample\heights.csv
the filename1 of sample: c:\Users\kento\Documents\2020psp2\sample\heights.csv
input the filename2 of IDs:c:\Users\kento\Documents\2020psp2\sample\IDs.csv
the filename2 of sample: c:\Users\kento\Documents\2020psp2\sample\IDs.csv
性別、身長、ID番号データのインプットが完了しました。
<ID list>
45313002        45313010        45313001        45314011        45322004
45313090        45313125        45323002        45321001        45313003
45322005        45323111        45319099        45318088
探したいIDを入力してください。>>>45318088
ID      >>>45318088
gender  >>>male
height  >>>171.10[cm]

・例えば，ID 999999999のデータを調べたいとき，
input the filename1 of sample:c:\Users\kento\Documents\2020psp2\sample\heights.csv
the filename1 of sample: c:\Users\kento\Documents\2020psp2\sample\heights.csv
input the filename2 of IDs:c:\Users\kento\Documents\2020psp2\sample\IDs.csv
the filename2 of sample: c:\Users\kento\Documents\2020psp2\sample\IDs.csv
性別、身長、ID番号データのインプットが完了しました。
<ID list>
45313002        45313010        45313001        45314011        45322004
45313090        45313125        45323002        45321001        45313003
45322005        45323111        45319099        45318088
探したいIDを入力してください。>>>999999999
No data


## 修正履歴

