#pragma once
#include <iostream>
#include <vector>


template<typename T>
class BinaryTree
{
private:
	//Attribut
	int _depth;
	std::vector<std::vector<T>> _tree;

public:
	//Constructeurs
	BinaryTree();
	BinaryTree(int depth);

	//Méthodes
	void setNode(int, int, T);
	void display();
	void setBool(int, int, bool);
	void setDepth(int);
	int getDepth() const;
	T getNode(int, int) const ;
	bool getExercise(int, int) const;

	//Destructeurs
	~BinaryTree();
};


//Constructeur par defaut
template<typename T>
BinaryTree<T>::BinaryTree()
	: _depth(10)
{

	for (int n = 0; n <= _depth; n++) {

		std::vector<T> step;
		for (int i = 0; i <= n; i++) {

			step.push_back(0);
		}
		_tree.push_back(step);
		step.clear();
	}

	for (int n = 0; n < _depth; n++) {

		for (int i = 0; i <= n; i++) {

			_tree[n][i] = 0;
		}
	}
}

//Constructeur avec la profondeur
template<typename T>
BinaryTree<T>::BinaryTree(int depth) : _depth(depth) {

	for (int n = 0; n <= _depth; n++) {

		std::vector<T> step;
		for (int i = 0; i <= n; i++) {

			step.push_back(0);
		}
		_tree.push_back(step);
		step.clear();
	}

	for (int n = 0; n < _depth; n++) {

		for (int i = 0; i <= n; i++) {

			_tree[n][i] = 0;
		}
	}
}

//Destructeurs
template<typename T>
BinaryTree<T>::~BinaryTree() {}


//Methode
	//Affichage de l'arbre 
template<typename T>
void BinaryTree<T>::display() {

	std::cout << std::endl;
	for (size_t n = 0; n < _tree.size(); n++) {

		for (size_t i = 0; i < _tree[n].size(); i++) {

			std::cout << _tree[n][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

	//Definition de la profondeur de l'arbre
template<typename T>
void BinaryTree<T>::setDepth(int N) {
	if (N < _depth)
	{
		for (size_t n = _tree.size() - 1; n > N; n--) {

			_tree.pop_back();
		}
		_depth = N;
	}
	else {
		for (int n = _depth + 1; n <= N; n++) {

			std::vector<T> step;
			for (int i = 0; i <= n; i++) {

				step.push_back(0);
			}
			_tree.push_back(step);
			step.clear();
		}
	}

}

	//Obtention de la profondeur
template<typename T>
int BinaryTree<T>::getDepth() const {

	return _depth;
}

	//Obtention d'une valeur de l'arbre
template<typename T>
T BinaryTree<T>::getNode(int n, int i) const {

	return _tree[n][i];
}

	//Implementation une valeur de l'arbre
template<typename T>
void BinaryTree<T>::setNode(int n, int i, T k) {

	_tree[n][i] = k;
}

	//Obtention de la valeur de l'exercice
template<class T>
bool BinaryTree<T>::getExercise(int n, int i) const {

	return _tree[n][i];
}

	//Implementation un bool dans l'arbre
template<class T>
void BinaryTree<T>::setBool(int n, int i, bool a) {

	_tree[n][i] = a;
}

