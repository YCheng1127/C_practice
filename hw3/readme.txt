●作者：電機109 乙班 E24056051 林倚丞

●程式檔案名稱：hw3.c

●使用說明：在Linux環境中輸入gcc hw3.c -o hw3.out編譯hw3，之後輸入./hw3.out執行。

遊戲規則: 四子棋是一種供兩人對弈的棋類游戲。在棋盤中，任何一方先令自己四只棋子在橫、豎或斜方向連成一條直線，即可獲勝。
          另外，若是玩到最後無欄位可放置棋子，則後手玩家獲勝。

此程式在開啟後即開啟四子棋遊戲新局，並顯示棋盤

N N N N N N N

N N N N N N N

N N N N N N N

N N N N N N N

N N N N N N N

N N N N N N N

之後程式會要求玩家一輸入想要放下棋子的欄位(行)1~7，若輸入錯誤程式會告知使用者重新輸入。
若輸入正確，棋子會安置在該欄位(行)的最下方空格。

例如若玩家一輸入1，則棋盤會由

N N N N N N N         N N N N N N N
       
N N N N N N N         N N N N N N N

N N N N N N N  變成   N N N N N N N
               ======>  
N N N N N N N         R N N N N N N

Y N N N N N N         Y N N N N N N

R N N N N N N         R N N N N N N

若是遊戲進行中，玩家輸入該欄位無空格，則程式會邀糗使用者重新輸入


若是其中一方玩家達到勝利條件，則程式會顯示勝利者並結束程式。

讀檔功能說明:

在輸入指令執行程式時，可輸入./hw3.out file.txt來開啟txt檔，其中file為txt檔名。
txt檔內容格式應如棋盤格式

example:

N N N N N N N

N N N N N N N

N N N N N N N

N N N N N N N

N N N N N N N

N R Y R N N N

程式將根據棋盤狀況選擇讓玩家一獲玩家二下棋。