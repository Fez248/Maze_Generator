all: maze_generator bfs dfs maze_gen2

maze_generator: maze_generator.cc
	g++ -o maze_generator.exe maze_generator.cc

bfs: bfs.cc
	g++ -o bfs.exe bfs.cc

dfs: dfs.cc
	g++ -o dfs.exe dfs.cc

maze_gen2: maze_gen2.cc
	g++ -o maze_gen2.exe maze_gen2.cc

clean:
	rm maze_generator.exe bfs.exe dfs.exe maze_gen2.exe