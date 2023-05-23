// BinaryTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

typedef struct _BinaryTree {
    int value;
    _BinaryTree* left;
    _BinaryTree* right;
} BinaryTree;

BinaryTree* CreateNode(int value) {
    BinaryTree* node = new BinaryTree;
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

void Delete(int value) {
    // ищем узел
    // если нет потомков просто удаляем
    // если 1 потомок, то ставим его на это место
    // если два потомка то берем самый левый из правого и ставим его на это место
}

void Insert(BinaryTree* tree, int value) {
    if (tree == NULL)
        return;

    if (value < tree->value) {
        if (tree->left == NULL) {
            BinaryTree* node = CreateNode(value);
            tree->left = node;
            return;
        }
        Insert(tree->left, value);
    }

    if (value >= tree->value) {
        if (tree->right == NULL) {
            BinaryTree* node = CreateNode(value);
            tree->right = node;
            return;
        }
        Insert(tree->right, value);
    }
}

void PrintTree(BinaryTree* node) {
    if (node == NULL)
        return;

    PrintTree(node->left);
    std::cout << node->value << " ";
    PrintTree(node->right);
}

int main()
{
    BinaryTree* head = CreateNode(12);
    Insert(head, 5);
    Insert(head, 8);
    Insert(head, 3);
    Insert(head, 17);
    Insert(head, 1);
    Insert(head, 44);

    PrintTree(head);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
