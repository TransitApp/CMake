/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmGraphAdjacencyList_h
#define cmGraphAdjacencyList_h

#include "cmConfigure.h" // IWYU pragma: keep

#include <vector>

/**
 * Graph edge representation.  Most use cases just need the
 * destination vertex, so we support conversion to/from an int.  We
 * also store boolean to indicate whether an edge is "strong".
 */
class cmGraphEdge
{
public:
  cmGraphEdge()
    : Dest(0)
    , Strong(true)
  {
  }
  cmGraphEdge(int n)
    : Dest(n)
    , Strong(true)
  {
  }
  cmGraphEdge(int n, bool s)
    : Dest(n)
    , Strong(s)
  {
  }
  cmGraphEdge(cmGraphEdge const& r)
    : Dest(r.Dest)
    , Strong(r.Strong)
  {
  }
  operator int() const { return this->Dest; }

  bool IsStrong() const { return this->Strong; }
private:
  int Dest;
  bool Strong;
};
struct cmGraphEdgeList : public std::vector<cmGraphEdge>
{
};
struct cmGraphNodeList : public std::vector<int>
{
};
struct cmGraphAdjacencyList : public std::vector<cmGraphEdgeList>
{
};

#endif
