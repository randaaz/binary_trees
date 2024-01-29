# 0x1D. C - Binary Trees

## Description

This is a group project on binary trees, a fundamental concept in computer science. The project aims to enhance your understanding of binary trees, binary search trees, and related topics. It involves the implementation of various functions and adheres to specific coding and documentation standards.

## Learning Objectives

At the end of this project, you are expected to be able to explain:

### General
- What is a binary tree
- The difference between a binary tree and a Binary Search Tree
- Possible gain in terms of time complexity compared to linked lists
- Depth, height, and size of a binary tree
- Different traversal methods to go through a binary tree
- What is a complete, a full, a perfect, a balanced binary tree

## Copyright - Plagiarism

- You must come up with solutions for the tasks independently.
- Copying and pasting someone else’s work is strictly forbidden.
- Publishing any content of this project is not allowed.
- Plagiarism will result in removal from the program.

## Requirements

### General
- Allowed editors: vi, vim, emacs
- Compilation on Ubuntu 20.04 LTS using gcc with specified options
- Files end with a new line
- Mandatory README.md file at the root of the project folder
- Code should use the Betty style and will be checked using betty-style.pl and betty-doc.pl
- No global variables allowed
- No more than 5 functions per file
- Use of the standard library is allowed
- Prototypes of all functions should be included in the header file named `binary_trees.h`
- Don't forget to push your header file
- Include guards for all header files
- One project repository per group; cloning/forking a repository with the same name before the second deadline results in a 0% score

## GitHub

- Each group should have one project repository.

## tasks
  - 18 mandatory
  - 23 advanced

## More Info

### Data Structures

Please use the following data structures and types for binary trees:

#### Basic Binary Tree
```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
