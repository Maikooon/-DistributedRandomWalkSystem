# DistributedRandomWalkSystem
## グラフの準備
・グラフは、あらかじめコード実行前に分割されている

# dataset
## source-graph
使用したいグラフを置くところ。

## gconverter
sourceに置いたテキストファイルをバイナリファイルに変換する
出力は、Converterd＿graphに格納

## spilit graph 
Congerterdに格納されたバイナリファイルを分割する。
分割されたグラフは、それぞれの分割片がフォルダに格納される
入力前のグラフは、バイナリ形式で、任意の数に分割されている


##　ファイルの実行方法に関して


# include 
├── cache.hpp
├── cache_helper.hpp
├── graph.hpp
├── message_queue.hpp
├── random_walk_config.hpp
├── random_walk_system_worker.hpp
├── random_walker.hpp
├── random_walker_manager.hpp
├── start_flag.hpp
├── start_manager.hpp
├── storage.hpp
├── type.hpp
└── util.hpp
,llllll



//jwtなしのときの実行方法
g++ main.cpp -pthread -fopenmp -std=c++2a
./a.out ../dataset/split_graph/karate/3/

//jwtありのときの実行方法
//実行サーバと名前が被るのでこちら推奨
g++ main.cpp -pthread -fopenmp -std=c++2a -I../jwt-cpp/include -o main -lcrypto
./main ../dataset/split_graph/karate/3/

//名前かぶる、非推奨
g++ main.cpp -pthread -fopenmp -std=c++2a -I../jwt-cpp/include -lcrypto
./a.out ../dataset/split_graph/karate/3/

<!-- とるときに三文字かけてる　　　　eyj -->
Received JWT:  hbGciOiJIUzI1NiJ9.eyJpZCI6IjYifQ.Wx11kP8GMJeUhnV4Th9t2tfCZyAIeidP1rcFiv_c_pY?h
Generated JWT: eyJhbGciOiJIUzI1NiJ9.eyJpZCI6IjYifQ.Wx11kP8GMJeUhnV4Th9t2tfCZyAIeidP1rcFiv_c_pY

--オフセットの計算がうまくいっていないのでは！