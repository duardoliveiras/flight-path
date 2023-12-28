/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <cstddef>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

/****************** Provided structures  ********************/

template <class T> class Vertex {
  T info;              // contents
  vector<Edge<T>> adj; // list of outgoing edges
  bool visited;        // auxiliary field
  bool processing;     // auxiliary field
  int indegree;        // auxiliary field
  int num;             // auxiliary field
  int low;             // auxiliary field

  // Auxiliar Functions: edge operations
  void addEdge(Vertex<T> *dest, double w, std::string route);
  bool removeEdgeTo(Vertex<T> *d);

public:
  // Constructor
  Vertex(T in);

  // Getters
  int getIndegree() const;
  int getNum() const;
  int getLow() const;
  T getInfo() const;
  bool isVisited() const;
  bool isProcessing() const;
  const vector<Edge<T>> &getAdj() const;

  // Setters
  void setIndegree(int indegree);
  void setNum(int num);
  void setLow(int low);
  void setInfo(T in);
  void setVisited(bool v);
  void setProcessing(bool p);
  void setAdj(const vector<Edge<T>> &adj);

  // Friend class declaration
  friend class Graph<T>;
};

template <class T> class Edge {
  Vertex<T> *dest;   // destination vertex
  double weight;     // auxiliary field
  std::string route; // auxiliary field

public:
  // Constructor
  Edge(Vertex<T> *d, double w, std::string route);

  // Getters
  Vertex<T> *getDest() const;
  double getWeight() const;
  std::string getRoute() const;

  // Setters
  void setDest(Vertex<T> *dest);
  void setWeight(double weight);

  // Friend class declaration
  friend class Graph<T>;
  friend class Vertex<T>;
};

template <class T> class Graph {
  vector<Vertex<T> *> vertexSet; // vertex set
  int _index_;                   // auxiliary field
  stack<Vertex<T>> _stack_;      // auxiliary field
  list<list<T>> _list_sccs_;     // auxiliary field

  // Auxiliar Functions: Search depth-first traversal
  void dfsVisit(Vertex<T> *v, vector<T> &res) const;

  // Auxiliar Functions: Check if graph is DAG
  bool dfsIsDAG(Vertex<T> *v) const;

public:
  // Vertex operations
  Vertex<T> *findVertex(const T &in) const;
  int getNumVertex() const;
  bool addVertex(const T &in);
  bool removeVertex(const T &in);

  // Edge operations
  bool addEdge(const T &sourc, const T &dest, double w, std::string route);
  bool removeEdge(const T &sourc, const T &dest);

  // Graph Information
  vector<Vertex<T> *> getVertexSet() const;

  // Traversal Operations
  vector<T> dfs() const;
  vector<T> dfs(const T &source) const;
  vector<T> bfs(const T &source) const;

  // Topological Sort
  vector<T> topsort() const;

  // Graph Properties
  bool isDAG() const;
};

/****************** Provided constructors and functions ********************/

// Constructor for Vertex Class
template <class T> Vertex<T>::Vertex(T in) : info(in) {}

// Constructor for Edge Class
template <class T>
Edge<T>::Edge(Vertex<T> *d, double w, std::string r)
    : dest(d), weight(w), route(r) {}

// Get number of vertices in the graph
template <class T> int Graph<T>::getNumVertex() const {
  return vertexSet.size();
}

// Get vector of vertices in the graph
template <class T> vector<Vertex<T> *> Graph<T>::getVertexSet() const {
  return vertexSet;
}

// Get info of a vertex
template <class T> T Vertex<T>::getInfo() const { return info; }

// Set info of a vertex
template <class T> void Vertex<T>::setInfo(T in) { Vertex::info = in; }

// Check if vertex is in processing state
template <class T> bool Vertex<T>::isProcessing() const { return processing; }

// Set the processing state in vertex
template <class T> void Vertex<T>::setProcessing(bool p) {
  Vertex::processing = p;
}

// Get the destination vertex of an edge
template <class T> Vertex<T> *Edge<T>::getDest() const { return dest; }

// Set the destination vertex of an edge
template <class T> void Edge<T>::setDest(Vertex<T> *d) { Edge::dest = d; }

// Get the weight of an edge
template <class T> double Edge<T>::getWeight() const { return weight; }

// Set the weight of an edge
template <class T> void Edge<T>::setWeight(double weight) {
  Edge::weight = weight;
}

// Get the route information of an edge
template <class T> std::string Edge<T>::getRoute() const { return route; }

// Auxiliary function to find a vertex with a given content.
template <class T> Vertex<T> *Graph<T>::findVertex(const T &in) const {
  for (auto v : vertexSet)
    if (v->info == in)
      return v;
  return NULL;
}

// Check if a vertex has been visited during traversal
template <class T> bool Vertex<T>::isVisited() const { return visited; }

// Get the indegree of a vertex
template <class T> int Vertex<T>::getIndegree() const { return indegree; }

// Set the indegree of a vertex
template <class T> void Vertex<T>::setIndegree(int indegree) {
  Vertex::indegree = indegree;
}

// Get the numerical identifier of a vertex
template <class T> int Vertex<T>::getNum() const { return num; }

// Set the numerical identifier of a vertex
template <class T> void Vertex<T>::setNum(int num) { Vertex::num = num; }

// Get the low value of a vertex
template <class T> int Vertex<T>::getLow() const { return low; }

// Set the low value of a vertex
template <class T> void Vertex<T>::setLow(int low) { Vertex::low = low; }

// Get the low value of a vertex
template <class T> void Vertex<T>::setVisited(bool v) { Vertex::visited = v; }

// Get the vector of adjacent edges of a vertex
template <class T> const vector<Edge<T>> &Vertex<T>::getAdj() const {
  return adj;
}

// Set the vector of adjacent edges of a vertex
template <class T> void Vertex<T>::setAdj(const vector<Edge<T>> &adj) {
  Vertex::adj = adj;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already
 * exists.
 */
template <class T> bool Graph<T>::addVertex(const T &in) {
  if (findVertex(in) != NULL)
    return false;
  vertexSet.push_back(new Vertex<T>(in));
  return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex
 * does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w,
                       std::string route) {
  auto v1 = findVertex(sourc);
  auto v2 = findVertex(dest);
  if (v1 == NULL || v2 == NULL)
    return false;
  v1->addEdge(v2, w, route);
  return true;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w, std::string route) {
  adj.push_back(Edge<T>(d, w, route));
}

/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T> bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
  auto v1 = findVertex(sourc);
  auto v2 = findVertex(dest);
  if (v1 == NULL || v2 == NULL)
    return false;
  return v1->removeEdgeTo(v2);
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T> bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
  for (auto it = adj.begin(); it != adj.end(); it++)
    if (it->dest == d) {
      adj.erase(it);
      return true;
    }
  return false;
}

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template <class T> bool Graph<T>::removeVertex(const T &in) {
  for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
    if ((*it)->info == in) {
      auto v = *it;
      vertexSet.erase(it);
      for (auto u : vertexSet)
        u->removeEdgeTo(v);
      delete v;
      return true;
    }
  return false;
}

/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) traversal in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T> vector<T> Graph<T>::dfs() const {
  vector<T> res;
  for (auto v : vertexSet)
    v->visited = false;
  for (auto v : vertexSet)
    if (!v->visited)
      dfsVisit(v, res);
  return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T> void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> &res) const {
  v->visited = true;
  res.push_back(v->info);
  for (auto &e : v->adj) {
    auto w = e.dest;
    if (!w->visited)
      dfsVisit(w, res);
  }
}

/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order,
 * from the source node.
 */
template <class T> vector<T> Graph<T>::dfs(const T &source) const {
  vector<T> res;
  auto s = findVertex(source);
  if (s == nullptr)
    return res;

  for (auto v : vertexSet)
    v->visited = false;

  dfsVisit(s, res);
  return res;
}

/****************** BFS ********************/
/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by bfs order.
 */
template <class T> vector<T> Graph<T>::bfs(const T &source) const {
  vector<T> res;
  auto s = findVertex(source);
  if (s == NULL)
    return res;
  queue<Vertex<T> *> q;
  for (auto v : vertexSet)
    v->visited = false;
  q.push(s);
  s->visited = true;
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    res.push_back(v->info);
    for (auto &e : v->adj) {
      auto w = e.dest;
      if (!w->visited) {
        q.push(w);
        w->visited = true;
      }
    }
  }
  return res;
}

/****************** isDAG  ********************/
/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the stack of recursive calls (see theoretical
 * classes). Returns true if the graph is acyclic, and false otherwise.
 */

template <class T> bool Graph<T>::isDAG() const {
  for (auto v : vertexSet) {
    v->visited = false;
    v->processing = false;
  }
  for (auto v : vertexSet)
    if (!v->visited)
      if (!dfsIsDAG(v))
        return false;
  return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T> bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
  v->visited = true;
  v->processing = true;
  for (auto &e : v->adj) {
    auto w = e.dest;
    if (w->processing)
      return false;
    if (!w->visited)
      if (!dfsIsDAG(w))
        return false;
  }
  v->processing = false;
  return true;
}

/****************** toposort ********************/
/*
 * Performs a topological sorting of the vertices of a graph (this).
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */

template <class T> vector<T> Graph<T>::topsort() const {
  vector<T> res;

  for (auto v : vertexSet) {
    v->indegree = 0;
  }

  for (auto v : vertexSet) {
    for (auto &e : v->adj) {
      e.dest->indegree += 1;
    }
  }

  std::queue<Vertex<T> *> q;

  for (auto v : vertexSet) {
    if (v->indegree == 0) {
      q.push(v);
    }
  }

  while (!q.empty()) {
    auto u = q.front();
    res.push_back(u->info);
    q.pop();

    for (auto &e : u->adj) {
      auto w = e.dest;
      w->indegree -= 1;
      if (w->indegree == 0) {
        q.push(w);
      }
    }
  }
  return res;
}

#endif /* GRAPH_H_ */
