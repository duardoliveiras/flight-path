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

template <class T>
class Edge;
template <class T>
class Graph;
template <class T>
class Vertex;

/****************** Provided structures  ********************/

template <class T>
class Vertex
{
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

template <class T>
class Edge
{
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

template <class T>
class Graph
{
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

/**
 * @brief Constructor for Vertex class
 * @tparam T The type of the graph
 * @param in The content of the vertex
 */
template <class T>
Vertex<T>::Vertex(T in) : info(in) {}

/**
 * @brief Constructor for Edge class
 * @tparam T The type of the graph
 * @param d The destination vertex
 * @param w The weight of the edge
 * @param r The route information of the edge
 */
template <class T>
Edge<T>::Edge(Vertex<T> *d, double w, std::string r)
    : dest(d), weight(w), route(r) {}

/**
 * @brief Function to get the number of vertices in the graph
 * @tparam T The type of the graph
 * @return int The number of vertices in the graph
 */
template <class T>
int Graph<T>::getNumVertex() const
{
  return vertexSet.size();
}

// Get vector of vertices in the graph
/**
 * @brief Function to get the vector of vertices in the graph
 * @tparam T The type of the graph
 * @return vector<Vertex<T>*> The vector of vertices in the graph
 */
template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const
{
  return vertexSet;
}

/**
 * @brief Function to get the content of a vertex
 * @tparam T The type of the graph
 * @return T The content of a vertex
 */
template <class T>
T Vertex<T>::getInfo() const { return info; }

/**
 * @brief Function to set the content of a vertex
 * @tparam T The type of the graph
 * @param in The content of a vertex
 * @return void
 */
template <class T>
void Vertex<T>::setInfo(T in) { Vertex::info = in; }

/**
 * @brief Function to get the processing state of a vertex
 * @tparam T The type of the graph
 * @return bool The processing state of a vertex
 */
template <class T>
bool Vertex<T>::isProcessing() const { return processing; }

/**
 * @brief Function to set the processing state of a vertex
 * @tparam T The type of the graph
 * @param p The processing state of a vertex
 * @return void
 */
template <class T>
void Vertex<T>::setProcessing(bool p)
{
  Vertex::processing = p;
}

/**
 * @brief Function to get the destination vertex of an edge
 * @tparam T The type of the graph
 * @return Vertex<T>* The destination vertex of an edge
 */
template <class T>
Vertex<T> *Edge<T>::getDest() const { return dest; }

/**
 * @brief Function to set the destination vertex of an edge
 * @tparam T The type of the graph
 * @param d The destination vertex
 * @return void
 */
template <class T>
void Edge<T>::setDest(Vertex<T> *d) { Edge::dest = d; }

/**
 * @brief Function to get the weight of an edge
 * @tparam T The type of the graph
 * @return double The weight of an edge
 */
template <class T>
double Edge<T>::getWeight() const { return weight; }

/**
 * @brief Function to set the weight of an edge
 * @tparam T The type of the graph
 * @param weight The weight of an edge
 * @return void
 */
template <class T>
void Edge<T>::setWeight(double weight)
{
  Edge::weight = weight;
}

/**
 * @brief Function to get the route information of an edge
 * @tparam T The type of the graph
 * @return std::string The route information of an edge
 */
template <class T>
std::string Edge<T>::getRoute() const { return route; }

/**
 * @brief Function to find a vertex with a given content
 * @tparam T The type of the graph
 * @param in The content of the vertex
 * @return Vertex<T>* The vertex with the given content
 */
template <class T>
Vertex<T> *Graph<T>::findVertex(const T &in) const
{
  for (auto v : vertexSet)
    if (v->info == in)
      return v;
  return NULL;
}

/**
 * @brief Function to get the visited state of a vertex
 * @tparam T The type of the graph
 * @return bool The visited state of a vertex
 */
template <class T>
bool Vertex<T>::isVisited() const { return visited; }

/**
 * @brief Function to get the indegree of a vertex
 * @tparam T The type of the graph
 * @return int The indegree of a vertex
 */
template <class T>
int Vertex<T>::getIndegree() const { return indegree; }

/**
 * @brief Function to set the indegree of a vertex
 * @tparam T The type of the graph
 * @param indegree The indegree of a vertex
 * @return void
 */
template <class T>
void Vertex<T>::setIndegree(int indegree)
{
  Vertex::indegree = indegree;
}

/**
 * @brief Function to get the numerical identifier of a vertex
 * @tparam T The type of the graph
 * @return int The numerical identifier of a vertex
 */
template <class T>
int Vertex<T>::getNum() const { return num; }

/**
 * @brief Function to set the numerical identifier of a vertex
 * @tparam T The type of the graph
 * @param num The numerical identifier of a vertex
 * @return void
 */
template <class T>
void Vertex<T>::setNum(int num) { Vertex::num = num; }

/**
 * @brief Function to get the low value of a vertex
 * @tparam T The type of the graph
 * @return int The low value of a vertex
 */
template <class T>
int Vertex<T>::getLow() const { return low; }

/**
 * @brief Function to set the low value of a vertex
 * @tparam T The type of the graph
 * @param low The low value of a vertex
 * @return void
 */
template <class T>
void Vertex<T>::setLow(int low) { Vertex::low = low; }

/**
 * @brief Function to set the visited state of a vertex
 * @tparam T The type of the graph
 * @param v The visited state of a vertex
 * @return void
 */
template <class T>
void Vertex<T>::setVisited(bool v) { Vertex::visited = v; }

/**
 * @brief Function to get the vector of adjacent edges of a vertex
 * @tparam T The type of the graph
 * @return const vector<Edge<T>>& The vector of adjacent edges
 */
template <class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const
{
  return adj;
}

/**
 * @brief Function to set the vector of adjacent edges of a vertex
 * @param adj The vector of adjacent edges
 * @return void
 */
template <class T>
void Vertex<T>::setAdj(const vector<Edge<T>> &adj)
{
  Vertex::adj = adj;
}

/**
 * @brief Function to add a vertex to a graph
 * @tparam T The type of the graph
 * @param in The content of the vertex
 * @return bool True if the vertex was added
 */
template <class T>
bool Graph<T>::addVertex(const T &in)
{
  if (findVertex(in) != NULL)
    return false;
  vertexSet.push_back(new Vertex<T>(in));
  return true;
}

/**
 * @brief Function to add an edge to a graph
 * @tparam T The type of the graph
 * @param sourc The source vertex
 * @param dest The destination vertex
 * @param w The weight of the edge
 * @param route The route information of the edge
 * @return bool True if the edge was added
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w,
                       std::string route)
{
  auto v1 = findVertex(sourc);
  auto v2 = findVertex(dest);
  if (v1 == NULL || v2 == NULL)
    return false;
  v1->addEdge(v2, w, route);
  return true;
}

/**
 * @brief Function to add an outgoing edge to a vertex
 * @tparam T The type of the graph
 * @param d The destination vertex
 * @param w The weight of the edge
 * @param route The route information of the edge
 * @return void
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w, std::string route)
{
  adj.push_back(Edge<T>(d, w, route));
}

/**
 * @brief Function to remove an edge from a graph
 * @tparam T The type of the graph
 * @param sourc The source vertex
 * @param dest The destination vertex
 * @return bool True if the edge was removed
 */
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest)
{
  auto v1 = findVertex(sourc);
  auto v2 = findVertex(dest);
  if (v1 == NULL || v2 == NULL)
    return false;
  return v1->removeEdgeTo(v2);
}

/**
 * @brief Function to remove an outgoing edge from a vertex
 * @tparam T The type of the graph
 * @param d The destination vertex
 * @return bool True if the edge was removed
 */
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d)
{
  for (auto it = adj.begin(); it != adj.end(); it++)
    if (it->dest == d)
    {
      adj.erase(it);
      return true;
    }
  return false;
}

/**
 * @brief Function to remove a vertex from a graph
 * @tparam T The type of the graph
 * @param in The content of the vertex to remove
 * @return bool True if the vertex was removed
 */
template <class T>
bool Graph<T>::removeVertex(const T &in)
{
  for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
    if ((*it)->info == in)
    {
      auto v = *it;
      vertexSet.erase(it);
      for (auto u : vertexSet)
        u->removeEdgeTo(v);
      delete v;
      return true;
    }
  return false;
}

/**
 * @brief Function to perform a depth-first search (dfs) in a graph
 * @tparam T The type of the graph
 * @return vector<T> The vector with the contents of the vertices by dfs order
 */
template <class T>
vector<T> Graph<T>::dfs() const
{
  vector<T> res;
  for (auto v : vertexSet)
    v->visited = false;
  for (auto v : vertexSet)
    if (!v->visited)
      dfsVisit(v, res);
  return res;
}

/**
 * @brief Function to perform a depth-first search (dfs) in a graph
 * @tparam T The type of the graph
 * @param v The vertex to start the search
 * @param res The vector with the contents of the vertices by dfs order
 * @return void
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> &res) const
{
  v->visited = true;
  res.push_back(v->info);
  for (auto &e : v->adj)
  {
    auto w = e.dest;
    if (!w->visited)
      dfsVisit(w, res);
  }
}

/**
 * @brief Function to perform a depth-first search (dfs) in a graph
 * @tparam T The type of the graph
 * @param source The source vertex
 * @return vector<T> The vector with the contents of the vertices by dfs order
 */
template <class T>
vector<T> Graph<T>::dfs(const T &source) const
{
  vector<T> res;
  auto s = findVertex(source);
  if (s == nullptr)
    return res;

  for (auto v : vertexSet)
    v->visited = false;

  dfsVisit(s, res);
  return res;
}

/**
 * @brief Function to perform a breadth-first search (bfs) in a graph
 * @tparam T The type of the graph
 * @param source The source vertex
 * @return vector<T> The vector with the contents of the vertices by bfs order
 */
template <class T>
vector<T> Graph<T>::bfs(const T &source) const
{
  vector<T> res;
  auto s = findVertex(source);
  if (s == NULL)
    return res;
  queue<Vertex<T> *> q;
  for (auto v : vertexSet)
    v->visited = false;
  q.push(s);
  s->visited = true;
  while (!q.empty())
  {
    auto v = q.front();
    q.pop();
    res.push_back(v->info);
    for (auto &e : v->adj)
    {
      auto w = e.dest;
      if (!w->visited)
      {
        q.push(w);
        w->visited = true;
      }
    }
  }
  return res;
}

/**
 * @brief Function to check if a graph is a DAG
 * @tparam T The type of the graph
 * @return bool True if the graph is a DAG
 */
template <class T>
bool Graph<T>::isDAG() const
{
  for (auto v : vertexSet)
  {
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
 * @brief Function to check if a graph is a DAG
 * @tparam T The type of the graph
 * @param v The vertex to start the search
 * @return bool True if the graph is a DAG
 */
template <class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const
{
  v->visited = true;
  v->processing = true;
  for (auto &e : v->adj)
  {
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

/**
 * @brief Function to perform a topological sorting of the vertices of a graph
 * @tparam T The type of the graph
 * @return vector<T> The vector with the contents of the vertices by topological order
 */
template <class T>
vector<T> Graph<T>::topsort() const
{
  vector<T> res;

  for (auto v : vertexSet)
  {
    v->indegree = 0;
  }

  for (auto v : vertexSet)
  {
    for (auto &e : v->adj)
    {
      e.dest->indegree += 1;
    }
  }

  std::queue<Vertex<T> *> q;

  for (auto v : vertexSet)
  {
    if (v->indegree == 0)
    {
      q.push(v);
    }
  }

  while (!q.empty())
  {
    auto u = q.front();
    res.push_back(u->info);
    q.pop();

    for (auto &e : u->adj)
    {
      auto w = e.dest;
      w->indegree -= 1;
      if (w->indegree == 0)
      {
        q.push(w);
      }
    }
  }
  return res;
}

#endif /* GRAPH_H_ */
