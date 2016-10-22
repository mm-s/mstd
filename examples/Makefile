graph_example:
	g++ -O0 -g -std=c++14 graph.cpp -o graph_example


phony dots: graph_example ../include/graph
	./graph_example

graph.dot: dots

graph_mst_kruskal.dot: dots

graph.png: graph.dot
	dot -Tpng graph.dot -o graph.png

graph_mst_kruskal.png: graph_mst_kruskal.dot
	dot -Tpng graph_mst_kruskal.dot -o graph_mst_kruskal.png

phony png: graph.png graph_mst_kruskal.png


