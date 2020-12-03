#include <iostream>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <cmath>
#include <vector>
#include <random>
#include <fstream>


using namespace
  std::chrono;

typedef enum
{
  BLACK,
  RED
} nodeColor;

template < class T > class Node
{
private:
  Node < T > *left;
  Node < T > *right;
  Node < T > *parent;
  nodeColor
    color;
  T
    data;
public:
  Node (T data)
  {
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
    this->color = BLACK;
    this->data = data;
  }
  template < typename G > friend class Tree;
};

template < typename T > class Tree
{
private:
  Node < T > *root;
  Node < T > *NIL = new Node < T > (0);

  Node < T > *find (T data)
  {
    Node < T > *current = root;
    while (current != NIL)
      if (compEQ (data, current->data))
	return (current);
      else
	current = compLT (data, current->data) ?
	  current->left : current->right;
    return (0);
  }

  void
  rotateLeft (Node < T > *x)
  {
    Node < T > *y = x->right;

    x->right = y->left;
    if (y->left != NIL)
      y->left->parent = x;

    if (y != NIL)
      y->parent = x->parent;
    if (x->parent)
      {
	if (x == x->parent->left)
	  x->parent->left = y;
	else
	  x->parent->right = y;
      }
    else
      {
	root = y;
      }

    y->left = x;
    if (x != NIL)
      x->parent = y;
  }

  void
  rotateRight (Node < T > *x)
  {
    Node < T > *y = x->left;

    x->left = y->right;
    if (y->right != NIL)
      y->right->parent = x;

    if (y != NIL)
      y->parent = x->parent;
    if (x->parent)
      {
	if (x == x->parent->right)
	  x->parent->right = y;
	else
	  x->parent->left = y;
      }
    else
      {
	root = y;
      }

    y->right = x;
    if (x != NIL)
      x->parent = y;
  }

  void
  insertFixup (Node < T > *x)
  {
    while (x != root && x->parent->color == RED)
      {
	if (x->parent == x->parent->parent->left)
	  {
	    Node < T > *y = x->parent->parent->right;
	    if (y->color == RED)
	      {

		x->parent->color = BLACK;
		y->color = BLACK;
		x->parent->parent->color = RED;
		x = x->parent->parent;
	      }
	    else
	      {

		if (x == x->parent->right)
		  {
		    x = x->parent;
		    this->rotateLeft (x);
		  }

		x->parent->color = BLACK;
		x->parent->parent->color = RED;
		this->rotateRight (x->parent->parent);
	      }
	  }
	else
	  {

	    Node < T > *y = x->parent->parent->left;
	    if (y->color == RED)
	      {

		x->parent->color = BLACK;
		y->color = BLACK;
		x->parent->parent->color = RED;
		x = x->parent->parent;
	      }
	    else
	      {

		if (x == x->parent->left)
		  {
		    x = x->parent;
		    this->rotateRight (x);
		  }
		x->parent->color = BLACK;
		x->parent->parent->color = RED;
		this->rotateLeft (x->parent->parent);
	      }
	  }
      }
    root->color = BLACK;
  }

  void
  deleteFixup (Node < T > *x)
  {
    while (x != root && x->color == BLACK)
      {
	if (x == x->parent->left)
	  {
	    Node < T > *w = x->parent->right;
	    if (w->color == RED)
	      {
		w->color = BLACK;
		x->parent->color = RED;
		this->rotateLeft (x->parent);
		w = x->parent->right;
	      }
	    if (w->left->color == BLACK && w->right->color == BLACK)
	      {
		w->color = RED;
		x = x->parent;
	      }
	    else
	      {
		if (w->right->color == BLACK)
		  {
		    w->left->color = BLACK;
		    w->color = RED;
		    this->rotateRight (w);
		    w = x->parent->right;
		  }
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->right->color = BLACK;
		this->rotateLeft (x->parent);
		x = root;
	      }
	  }
	else
	  {
	    Node < T > *w = x->parent->left;
	    if (w->color == RED)
	      {
		w->color = BLACK;
		x->parent->color = RED;
		this->rotateRight (x->parent);
		w = x->parent->left;
	      }
	    if (w->right->color == BLACK && w->left->color == BLACK)
	      {
		w->color = RED;
		x = x->parent;
	      }
	    else
	      {
		if (w->left->color == BLACK)
		  {
		    w->right->color = BLACK;
		    w->color = RED;
		    this->rotateLeft (w);
		    w = x->parent->left;
		  }
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->left->color = BLACK;
		this->rotateRight (x->parent);
		x = root;
	      }
	  }
      }
    x->color = BLACK;
  }

  void
  deleteNode (Node < T > *z)
  {
    Node < T > *x, *y;

    if (!z || z == NIL)
      return;


    if (z->left == NIL || z->right == NIL)
      {
	y = z;
      }
    else
      {
	y = z->right;
	while (y->left != NIL)
	  y = y->left;
      }

    if (y->left != NIL)
      x = y->left;
    else
      x = y->right;

    x->parent = y->parent;
    if (y->parent)
      if (y == y->parent->left)
	y->parent->left = x;
      else
	y->parent->right = x;
    else
      root = x;

    if (y != z)
      z->data = y->data;


    if (y->color == BLACK)
      this->deleteFixup (x);

    delete y;
  }

  int
  depth (Node < T > *x)
  {
    if (x == NIL)
      {
	return 0;
      }
    return (1 + std::max (depth (x->right), depth (x->left)));
  }

  std::function < bool (T, T) >
    compLT;
  std::function < bool (T, T) >
    compEQ;

  void
  kill_kids_then_myself (Node < T > *x)
  {
    if (x != NIL)
      {
	kill_kids_then_myself (x->left);
	kill_kids_then_myself (x->right);
	delete x;
      }
  }

public:
  void
  assignLT (std::function < bool (T, T) > f)
  {
    this->compLT = f;
  }

  void
  assignEQ (std::function < bool (T, T) > f)
  {
    this->compEQ = f;
  }

  Tree (T data)
  {
    root = new Node < T > (data);
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NULL;
    NIL->color = BLACK;
    NIL->data = 0;
    root->left = NIL;
    root->right = NIL;
    compLT =[](T a, T b)
    {
      return a < b;
    };
    compEQ =[](T a, T b)
    {
      return a == b;
    };
  }

  Tree ()
  {
    root = NULL;
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NULL;
    NIL->color = BLACK;
    NIL->data = 0;
    compLT =[](T a, T b)
    {
      return a < b;
    };
    compEQ =[](T a, T b)
    {
      return a == b;
    };
  }

  ~Tree ()
  {
    kill_kids_then_myself (root);
    delete NIL;
  }

  bool
  present (T data)
  {
    return this->find (data);
  }

  void
  insert (T data)
  {
    Node < T > *current, *parent;

    Node < T > *x = new Node < T > (data);

    if (!root)
      {
	x->data = data;
	x->parent = NULL;
	x->left = NIL;
	x->right = NIL;
	x->color = BLACK;
	root = x;
	return;
      }

    current = root;
    parent = 0;
    while (current != NIL)
      {
	if (compEQ (data, current->data))
	  return;
	parent = current;
	current =
	  compLT (data, current->data) ? current->left : current->right;
      }

    x->data = data;
    x->parent = parent;
    x->left = NIL;
    x->right = NIL;
    x->color = RED;

    if (parent)
      {
	if (compLT (data, parent->data))
	  parent->left = x;
	else
	  parent->right = x;
      }
    else
      {
	root = x;
      }

    insertFixup (x);
  }

  void
  erase (T data)
  {
    if (this->find (data))
      {
	this->deleteNode (this->find (data));
      }
  }

  int
  depth ()
  {
    return depth (this->root);
  }
};



template < typename T > class Profiler
{
private:
  void
  test_insert_time ()
  {
    if (!silent)
      {
	std::cout << "INSERT\n";
      }
    std::ofstream myfile;
    std::string insertion = folder + "/INSERT.txt";
    myfile.open (insertion);
    myfile << "INSERT\n";
    for (int i = 0; i < power_two; ++i)
      {
	if (!silent)
	  {
	    std::cout << i + 1 << "th step out of " << power_two << "\n";
	  }
	std::function < bool (int, int) >
	  greater =[](int a, int b)
	{ return a > b;
	};
	Tree < T > t;
	t.assignLT (greater);

	for (int j = 0; j < std::pow (2, i); ++j)
	  {
	    t.insert (std::rand ());
	  }

	auto
	  start = steady_clock::now ();
	for (int j = 0; j < test_iter; ++j)
	  {
	    t.insert (std::rand ());
	  }
	auto
	  end = steady_clock::now ();
	auto
	  elapsed = duration_cast < microseconds > (end - start);

	myfile << elapsed.count () << "\n";
      }
    myfile.close ();
  }

  void
  test_erase_time ()
  {
    if (!silent)
      {
	std::cout << "ERASE\n";
      }
    std::ofstream myfile;
    std::string erasal = folder + "/ERASE.txt";
    myfile.open (erasal);
    myfile << "ERASE\n";
    for (int i = 0; i < power_two; ++i)
      {
	if (!silent)
	  {
	    std::cout << i + 1 << "th step out of " << power_two << "\n";
	  }
	std::function < bool (int, int) >
	  greater =[](int a, int b)
	{ return a > b;
	};
	Tree < T > t;
	t.assignLT (greater);

	std::vector < int >
	numbers (std::pow (2, i), 0);
	for (int j = 0; j < std::pow (2, i); ++j)
	  {
	    int
	      a = std::rand ();
	    t.insert (a);
	    numbers[j] = a;
	  }
	auto
	  rng = std::default_random_engine {
	};
	std::shuffle (std::begin (numbers), std::end (numbers), rng);

	auto
	  start = steady_clock::now ();
	for (int j = 0; j < test_iter && j < std::pow (2, i); ++j)
	  {
	    t.erase (numbers[j]);
	  }
	auto
	  end = steady_clock::now ();
	auto
	  elapsed = duration_cast < microseconds > (end - start);

	myfile << elapsed.count () << "\n";
      }
    myfile.close ();
  }

  void
  test_find_time ()
  {
    if (!silent)
      {
	std::cout << "FIND\n";
      }
    std::ofstream myfile;
    std::string finding = folder + "/FIND.txt";
    myfile.open (finding);
    myfile << "FIND\n";
    for (int i = 0; i < power_two; ++i)
      {
	if (!silent)
	  {
	    std::cout << i + 1 << "th step out of " << power_two << "\n";
	  }
	std::function < bool (int, int) >
	  greater =[](int a, int b)
	{ return a > b;
	};
	Tree < T > t;
	t.assignLT (greater);

	std::vector < int >
	numbers (std::pow (2, i), 0);
	for (int j = 0; j < std::pow (2, i); ++j)
	  {
	    int
	      a = std::rand ();
	    t.insert (a);
	    numbers[j] = a;
	  }
	auto
	  rng = std::default_random_engine {
	};
	std::shuffle (std::begin (numbers), std::end (numbers), rng);

	auto
	  start = steady_clock::now ();
	for (int j = 0; j < test_iter && j < std::pow (2, i); ++j)
	  {
	    t.present (numbers[j]);
	  }
	auto
	  end = steady_clock::now ();
	auto
	  elapsed = duration_cast < microseconds > (end - start);

	myfile << elapsed.count () << "\n";
      }
    myfile.close ();
  }

public:
  bool
    silent;
  int
    power_two;
  std::string folder;
  int
    test_iter;

  void
  test ()
  {
    srand (time (NULL));
    test_erase_time ();
    test_insert_time ();
    test_find_time ();
  }

  Profiler ()
  {
    silent = false;
    power_two = 26;
    folder = "./";
    test_iter = 10000;
  }
};

int
main ()
{
  Profiler < int >
    pfl;
  pfl.test ();
  return 0;
}
