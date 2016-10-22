graph_example: graph.cpp ../include/graph
	g++ -O0 -g -std=c++14 graph.cpp -o graph_example


phony dots: graph_example
	./graph_example

graph.dot: dots

graph_mst_kruskal.dot: dots

graph_mst_prim.dot: dots

graph.png: graph.dot
	dot -Tpng graph.dot -o graph.png

graph_mst_kruskal.png: graph_mst_kruskal.dot
	dot -Tpng graph_mst_kruskal.dot -o graph_mst_kruskal.png

graph_mst_prim.png: graph_mst_prim.dot
	dot -Tpng graph_mst_prim.dot -o graph_mst_prim.png

phony png: graph.png graph_mst_kruskal.png graph_mst_prim.png


