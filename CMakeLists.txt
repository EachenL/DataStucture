cmake_minimum_required(VERSION 3.8)
project(DataStucture)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SeqList.cpp SeqList.h LinkList.cpp LinkList.h DobLinkList.cpp DobLinkList.h head.h SeqStack.cpp SeqStack.h Queue.h Queue.cpp LinkQueue.cpp LinkQueue.h LinkBinTree.cpp LinkBinTree.h FuncHead.h ThreadNode.cpp ThreadNode.h Sort.cpp Sort.h)
add_executable(DataStucture ${SOURCE_FILES} "map.cpp" "map.h")