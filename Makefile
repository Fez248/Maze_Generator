all: maze_generator bfs dfs

maze_generator: maze_generator.cc
	g++ -o maze_generator.exe maze_generator.cc

bfs: bfs.cc
	g++ -o bfs.exe bfs.cc

dfs: dfs.cc
	g++ -o dfs.exe dfs.cc

clean:
	rm maze_generator.exe bfs.exe dfs.exe