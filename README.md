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


