#include <mstd/graph>
#include <fstream>
using namespace mstd;

void kruskal_minimum_spanning_tree_demo() {

	vector<string> al={
	"0 1 4",
	"0 7 8",
	"1 7 11",
	"1 2 8",
	"7 8 7",
	"2 8 2",
	"7 6 1",
	"6 8 6",
	"2 5 4",
	"6 5 2",
	"2 3 7",
	"3 5 14",
	"3 4 9",
	"5 4 10"};

	graph<> g(al,graph<>::undirected);

	{
	cout << "written dot file: graph.dot" << endl;
	ofstream f("graph.dot");
	g.dot(f);
	}

	cout << g.vertexes_size() << " vertexes, " << g.edges_size() << " edges " << endl;

	auto v=g.sort_edges_no_descendent();
	cout << "Weight Src Dst" << endl;
	for (auto& i:v) {
		cout << g.get_edata(*i).value << " " << i->from->id << " " << i->to->id << endl;
	}

	auto mstk=g.minimum_spanning_tree_kruskal();

	{
	cout << "written dot file: graph_mst_kruskal.dot" << endl;
	ofstream f("graph_mst_kruskal.dot");
	mstk.dot(f);
	}

}


int main() {
	kruskal_minimum_spanning_tree_demo();
	return 0;

	vector<string> al;
	al.push_back("1 2");
	al.push_back("1 3");
	al.push_back("1 4");
	al.push_back("2 5");
	al.push_back("2 6");
	al.push_back("3 7");
	al.push_back("4 8");
	al.push_back("4 9");
	al.push_back("5 10");
	al.push_back("5 11");
	al.push_back("6 12");
	al.push_back("7 13");
	al.push_back("8 14");
	al.push_back("14 8");
	al.push_back("9 2");
	al.push_back("6 2");
	al.push_back("12 3");
	
	graph<> g(al);

	{
	cout << "written dot file: graph.dot" << endl;
	ofstream f("graph.dot");
	g.dot(f);
	}

	struct vis:basic_graph::visitor {
		void start(const vertex&) override {};
		void visit(const edge& e) override {
			cout << "   " << (e.from!=0?e.from->id:-1) << " -> " << e.to->id << endl;
		}
		void finished() override {};
	};

	vis vis_;
	cout << "breath first traversal" << endl;
	g.breath_first(1,vis_);
	cout << "depth first traversal" << endl;
	g.depth_first(1,vis_);

	cout << "best path" << endl;
	vector<string> distances;
	distances.push_back("1 2 1");
	distances.push_back("1 3 1");
	distances.push_back("1 4 1");
	distances.push_back("2 5 1");
	distances.push_back("2 6 1");
	distances.push_back("3 7 1");
	distances.push_back("4 8 1");
	distances.push_back("4 9 1");
	distances.push_back("5 10 1");
	distances.push_back("5 11 1");
	distances.push_back("6 12 1");
	distances.push_back("7 13 1");
	distances.push_back("8 14 1");
	distances.push_back("14 8 1");
	distances.push_back("9 2 1");
	distances.push_back("6 2 1");
	distances.push_back("12 3 1");

	typedef best_path<scalar<int>> pathfinder;
	pathfinder bp(g,distances);
	{
	cout << "best path from 1 to 11 )" << endl;
	auto r=bp.compute(1,11,pathfinder::breath_first);
	r.dump(cout);
	}
	{
	cout << "best path from 14 to 2 )" << endl;
	auto r=bp.compute(14,2,pathfinder::breath_first);
	r.dump(cout);
	}
	{
	cout << "best path from 1 to 2 )" << endl;
	auto r=bp.compute(1,2,pathfinder::depth_first);
	r.dump(cout);
	}


	return 0;
}

